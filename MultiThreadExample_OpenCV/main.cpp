#include "WebCamThread.h"

int main(){
	/*
	//�ʃX���b�h���N������
	WebCamThread thread;
	thread.InitAndRounch();
	
	
	cv::namedWindow("webcam");
	cv::namedWindow("negaposi");

	//�J�����̃X���b�h�̏������o����܂ł̎��Ԃ�
	//�҂��Ă��K�v������Bflag�ŊǗ�����̂��ǂ��Ǝv���B
	//����͎蔲����2�b�ԑ҂��ɂ����B
	std::this_thread::sleep_for(std::chrono::seconds(2));

	//���������C�����[�v�̂���
	while (true)
	{
		//���C���X���b�h���ŁA�ʃX���b�h�̌v�Z���ʂ��擾����
		//std::mutex�ŃX���b�h�Z�[�t�ɃA�N�Z�X�ł���֐�������Ă���̂�
		//������ʂ��Ă̂ݍs���B
		CaptureData mainthreadImg=thread.GetCamImage();

		//�󂯎������̓��C���X���b�h�ł�肽�����Ƃ�����
		//����͒P���ɕ\���������s��
		cv::imshow("webcam", mainthreadImg.raw);
		cv::imshow("negaposi", mainthreadImg.negaposi);
		if(mainthreadImg.loopCounter%100==0){
			std::cout<<"loopCount:"<<mainthreadImg.loopCounter<<std::endl;
		}

		if(cv::waitKey(30)=='q'){
			break;
		}
	}
	
	//�I���O�ɃX���b�h���V���b�g�_�E������
	thread.Shutdown();
	//�X���b�h�̃V���b�g�_�E�����I���܂ł̎��Ԃ�҂�
	//�蔲����3�b���炢�҂��ɂ����B
	std::this_thread::sleep_for(std::chrono::seconds(3));
	*/
	TESTCODE_EASY_THREAD_TEMPLETE();
	return 0;
}