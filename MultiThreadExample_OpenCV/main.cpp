#include "WebCamThread.h"

int main(){
	/*
	//別スレッドを起動する
	WebCamThread thread;
	thread.InitAndRounch();
	
	
	cv::namedWindow("webcam");
	cv::namedWindow("negaposi");

	//カメラのスレッドの準備が出来るまでの時間を
	//待ってやる必要がある。flagで管理するのが良いと思う。
	//今回は手抜きで2秒間待つ事にした。
	std::this_thread::sleep_for(std::chrono::seconds(2));

	//ここがメインループのつもり
	while (true)
	{
		//メインスレッド内で、別スレッドの計算結果を取得する
		//std::mutexでスレッドセーフにアクセスできる関数を作っているので
		//そこを通してのみ行う。
		CaptureData mainthreadImg=thread.GetCamImage();

		//受け取った後はメインスレッドでやりたいことをする
		//今回は単純に表示だけを行う
		cv::imshow("webcam", mainthreadImg.raw);
		cv::imshow("negaposi", mainthreadImg.negaposi);
		if(mainthreadImg.loopCounter%100==0){
			std::cout<<"loopCount:"<<mainthreadImg.loopCounter<<std::endl;
		}

		if(cv::waitKey(30)=='q'){
			break;
		}
	}
	
	//終了前にスレッドをシャットダウンする
	thread.Shutdown();
	//スレッドのシャットダウンが終わるまでの時間を待つ
	//手抜きで3秒くらい待つ事にした。
	std::this_thread::sleep_for(std::chrono::seconds(3));
	*/
	TESTCODE_EASY_THREAD_TEMPLETE();
	return 0;
}