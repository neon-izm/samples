//何か重い処理を別スレッドに移したい時に使うテンプレート的なクラス
//このクラスを継承してstd::mutexで保護して、データをやり取りする
//C++11が動くコンパイラを想定(動作確認はVisualStudio2012で行った)

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

	//この関数をメインスレッドから呼ぶと、別スレッドを立ち上げてWorker関数を呼ぶ
	virtual void InitAndRounch(std::string _stringParam="hoge",int _numParam=0);

	//この関数をメインスレッドから呼ぶと、このクラス内のWorker関数のループが止まる
	virtual void Shutdown();
protected:
	//別スレッドのメインループの関数
	virtual void Worker(std::string _stringParam="hoge",int _numParam=0);

	//スレッドを管理するメンバ変数
	//このクラスを継承して使う場合は、あまり意識しなくても良いはず
	std::atomic<bool> shutdown_flag;
	std::thread th;
	std::mutex mtx;

};

//使い方の例
void TESTCODE_EASY_THREAD_TEMPLETE();

#endif