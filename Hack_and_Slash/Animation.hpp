#ifndef ___ANIMATION_HPP_
#define ___ANIMATION_HPP_
#include "Fps.hpp"




/*####################################################
* �A�j���[�V����
*
* ����
* �A�j���[�V�����̐��l�𑖍�����B
######################################################*/
class Animation
{
public:

	Animation(int c);	//�R���X�g���N�^
	~Animation();		//�f�X�g���N�^

	int getClip(int speed);	//�A�j���[�V�������擾

private:

	bool first;
	int Clip;		//���݂̃N���b�v
	int max_Clip;	//�N���b�v��
	int nextFrame;	//���̃N���b�v�̃t���[��
};


#endif
