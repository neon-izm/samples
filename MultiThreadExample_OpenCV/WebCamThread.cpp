#include "WebCamThread.h"


WebCamThread::WebCamThread(void)
{
}


WebCamThread::~WebCamThread(void)
{
}

void WebCamThread::Worker(const int cameraIndex/*=0*/)
{
	//�����ɏ���������

	cv::VideoCapture cap(cameraIndex);
	int threadLoopCounter=0;
	while (shutdown_flag==false)
	{

		std::this_thread::sleep_for(std::chrono::milliseconds(30));
		cv::Mat capImg;
		cap>> capImg;

		// NOT���Z
		cv::Mat dst_img = ~capImg;

		//////���̒��J�b�R�̃X�R�[�v����
		//���C���X���b�h�Ƃ���肵�����f�[�^���R�s�[����
		{
			std::lock_guard<std::mutex> lock(mtx); // mtx���g���ă��b�N����

			// ���̃X���b�h��mtx���g���ă��b�N�ł��Ȃ�
			// �����Ŏ󂯓n���͍s��
			images.raw=capImg;
			images.negaposi=dst_img;
			images.loopCounter=threadLoopCounter;
		} // �f�X�g���N�^�Ń��b�N���J�������
		
		threadLoopCounter++;
		
	}

}

void WebCamThread::InitAndRounch(const int cameraIndex/*=0*/)
{
	//Worker�͂��̃N���X�̖��O���g����
	th=std::thread(&WebCamThread::Worker,this,cameraIndex );

}

CaptureData WebCamThread::GetCamImage() 
{

	CaptureData ret;

	//////���̒��J�b�R�̃X�R�[�v����
	//���C���X���b�h�ɑ��肽���f�[�^���R�s�[����
	{
		std::lock_guard<std::mutex> lock(mtx); // mtx���g���ă��b�N����

		// ���̃X���b�h��mtx���g���ă��b�N�ł��Ȃ�
		// �����Ŏ󂯓n���͍s��

		ret= images;
	} // �f�X�g���N�^�Ń��b�N���J�������
	return ret;
}
