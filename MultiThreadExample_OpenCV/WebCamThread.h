//このクラスはEasyThreadTempleteを使う場合の説明用のサンプル
//OpenCV2.4.8で動作確認済み
//もちろん、OpenCVに限らず、各種センサの値を読む場合やシリアル通信、ソケット通信など
//使いたい場合の目的に応じて使う必要がある

#ifndef WEBCAM_THREAD
#define WEBCAM_THREAD

#include "easythreadtemplete.h"
#include <opencv2\opencv.hpp>

//メインスレッドとやり取りしたいクラスを用意する
//今回は「ループ回数」「生のWebCamのデータ」「色反転したWebCamのデータ」を収納することにした

class CaptureData
{
public:
	CaptureData():loopCounter(0)
	{
	}

	~CaptureData()
	{
	}
	int loopCounter;
	cv::Mat raw;
	cv::Mat negaposi;
private:

};



//EasyThreadTempleteを継承する

class WebCamThread :
	public EasyThreadTemplete
{
public:
	WebCamThread(void);
	~WebCamThread(void);
	//元のEasyThreadTempleteのInitAndRounch関数を
	//継承しても良いし、しなくても良い(今回は継承していない)
	void InitAndRounch(const int cameraIndex=0);

	//ここにメインスレッドからこのスレッド内のデータを
	//取り出すための関数を定義する
	//std::mutexを内部で使っているので const宣言は出来ない
	//つまり、cv::Mat GetCamImage()const;とは宣言出来ない事に注意
	CaptureData GetCamImage();

protected:
	//ここにメインスレッドとやり取りしたいデータを書いておく
	CaptureData images;
	
	
	//別スレッドのメインループの関数
	//元のEasyThreadTempleteのWorker関数を
	//継承しても良いし、しなくても良い(今回は継承していない)
	void Worker(const int cameraIndex=0);

	//メインスレッドとやり取りしないけどメンバ変数として持っておきたい物や
	//その他関数をここに書く

};

#endif