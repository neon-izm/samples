#include "WebCamThread.h"


WebCamThread::WebCamThread(void)
{
}


WebCamThread::~WebCamThread(void)
{
}

void WebCamThread::Worker(const int cameraIndex/*=0*/)
{
	//ここに初期化処理

	cv::VideoCapture cap(cameraIndex);
	int threadLoopCounter=0;
	while (shutdown_flag==false)
	{

		std::this_thread::sleep_for(std::chrono::milliseconds(30));
		cv::Mat capImg;
		cap>> capImg;

		// NOT演算
		cv::Mat dst_img = ~capImg;

		//////この中カッコのスコープ内で
		//メインスレッドとやり取りしたいデータをコピーする
		{
			std::lock_guard<std::mutex> lock(mtx); // mtxを使ってロックする

			// 他のスレッドでmtxを使ってロックできない
			// ここで受け渡しは行う
			images.raw=capImg;
			images.negaposi=dst_img;
			images.loopCounter=threadLoopCounter;
		} // デストラクタでロックが開放される
		
		threadLoopCounter++;
		
	}

}

void WebCamThread::InitAndRounch(const int cameraIndex/*=0*/)
{
	//Workerはこのクラスの名前を使う事
	th=std::thread(&WebCamThread::Worker,this,cameraIndex );

}

CaptureData WebCamThread::GetCamImage() 
{

	CaptureData ret;

	//////この中カッコのスコープ内で
	//メインスレッドに送りたいデータをコピーする
	{
		std::lock_guard<std::mutex> lock(mtx); // mtxを使ってロックする

		// 他のスレッドでmtxを使ってロックできない
		// ここで受け渡しは行う

		ret= images;
	} // デストラクタでロックが開放される
	return ret;
}
