//���̃N���X��EasyThreadTemplete���g���ꍇ�̐����p�̃T���v��
//OpenCV2.4.8�œ���m�F�ς�
//�������AOpenCV�Ɍ��炸�A�e��Z���T�̒l��ǂޏꍇ��V���A���ʐM�A�\�P�b�g�ʐM�Ȃ�
//�g�������ꍇ�̖ړI�ɉ����Ďg���K�v������

#ifndef WEBCAM_THREAD
#define WEBCAM_THREAD

#include "easythreadtemplete.h"
#include <opencv2\opencv.hpp>

//���C���X���b�h�Ƃ���肵�����N���X��p�ӂ���
//����́u���[�v�񐔁v�u����WebCam�̃f�[�^�v�u�F���]����WebCam�̃f�[�^�v�����[���邱�Ƃɂ���

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



//EasyThreadTemplete���p������

class WebCamThread :
	public EasyThreadTemplete
{
public:
	WebCamThread(void);
	~WebCamThread(void);
	//����EasyThreadTemplete��InitAndRounch�֐���
	//�p�����Ă��ǂ����A���Ȃ��Ă��ǂ�(����͌p�����Ă��Ȃ�)
	void InitAndRounch(const int cameraIndex=0);

	//�����Ƀ��C���X���b�h���炱�̃X���b�h���̃f�[�^��
	//���o�����߂̊֐����`����
	//std::mutex������Ŏg���Ă���̂� const�錾�͏o���Ȃ�
	//�܂�Acv::Mat GetCamImage()const;�Ƃ͐錾�o���Ȃ����ɒ���
	CaptureData GetCamImage();

protected:
	//�����Ƀ��C���X���b�h�Ƃ���肵�����f�[�^�������Ă���
	CaptureData images;
	
	
	//�ʃX���b�h�̃��C�����[�v�̊֐�
	//����EasyThreadTemplete��Worker�֐���
	//�p�����Ă��ǂ����A���Ȃ��Ă��ǂ�(����͌p�����Ă��Ȃ�)
	void Worker(const int cameraIndex=0);

	//���C���X���b�h�Ƃ���肵�Ȃ����ǃ����o�ϐ��Ƃ��Ď����Ă�����������
	//���̑��֐��������ɏ���

};

#endif