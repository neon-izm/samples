//�����d��������ʃX���b�h�Ɉڂ��������Ɏg���e���v���[�g�I�ȃN���X
//���̃N���X���p������std::mutex�ŕی삵�āA�f�[�^������肷��
//C++11�������R���p�C����z��(����m�F��VisualStudio2012�ōs����)

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

	//���̊֐������C���X���b�h����ĂԂƁA�ʃX���b�h�𗧂��グ��Worker�֐����Ă�
	virtual void InitAndRounch(std::string _stringParam="hoge",int _numParam=0);

	//���̊֐������C���X���b�h����ĂԂƁA���̃N���X����Worker�֐��̃��[�v���~�܂�
	virtual void Shutdown();
protected:
	//�ʃX���b�h�̃��C�����[�v�̊֐�
	virtual void Worker(std::string _stringParam="hoge",int _numParam=0);

	//�X���b�h���Ǘ����郁���o�ϐ�
	//���̃N���X���p�����Ďg���ꍇ�́A���܂�ӎ����Ȃ��Ă��ǂ��͂�
	std::atomic<bool> shutdown_flag;
	std::thread th;
	std::mutex mtx;

};

//�g�����̗�
void TESTCODE_EASY_THREAD_TEMPLETE();

#endif