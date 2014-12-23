#ifndef EASY_THREAD_TEMPLETE
#define EASY_THREAD_TEMPLETE
#include <thread>
#include <memory>
#include <mutex>
#include <string>
#include <atomic>

class EasyThreadTemplete
{
public:
	EasyThreadTemplete(void);
	virtual ~EasyThreadTemplete(void);
	virtual void InitAndRounch(std::string _stringParam="hoge",int _numParam=0);
	virtual void Shutdown();
protected:
	std::thread th;
	std::mutex mtx;
	virtual void Worker(std::string _stringParam="hoge",int _numParam=0);
	std::atomic<bool> shutdown_flag;

};


void TESTCODE_EASY_THREAD_TEMPLETE();

#endif