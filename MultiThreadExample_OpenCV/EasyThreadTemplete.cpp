#include "EasyThreadTemplete.h"
#include <conio.h>
#include <iostream>

EasyThreadTemplete::EasyThreadTemplete(void):shutdown_flag(false)
{
	std::cout<<"Ctr"<<std::endl;

}


EasyThreadTemplete::~EasyThreadTemplete(void)
{
	std::cout<<"Dtr"<<std::endl;
}

void EasyThreadTemplete::Worker(std::string _stringParam/*="hoge"*/,int _numParam/*=0*/)
{
	int loopCounter=_numParam;
	while (shutdown_flag==false)
	{

		std::this_thread::sleep_for(std::chrono::seconds(1));

		std::cout<<loopCounter<<std::endl;
		loopCounter++;
	}
	return;
}

void EasyThreadTemplete::Shutdown()
{
	shutdown_flag=true;
	if(th.joinable()){
		th.join();
		std::cout<<"thread join"<<std::endl;
	}

	return;
}

void EasyThreadTemplete::InitAndRounch(std::string _stringParam/*="hoge"*/,int _numParam/*=0*/)
{
	th=std::thread(&EasyThreadTemplete::Worker,this,_stringParam,_numParam );
}

//キーボードの何かキーを押すまで別スレッドが回るサンプル
void TESTCODE_EASY_THREAD_TEMPLETE()
{
	EasyThreadTemplete thread;
	thread.InitAndRounch();
	std::this_thread::sleep_for(std::chrono::seconds(2));

	while (!_kbhit())
	{
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout<<"mainloop"<<std::endl;
	}
	thread.Shutdown();
	std::this_thread::sleep_for(std::chrono::seconds(2));

}
