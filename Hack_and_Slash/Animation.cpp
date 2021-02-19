#include "Animation.hpp"

//�R���X�g���N�^
Animation::Animation(int c)
{
	Clip = 0;
	max_Clip = c;
	nextFrame = 1;
	first = false;
}


//�f�X�g���N�^
Animation::~Animation()
{

}

//�A�j���[�V�������擾
int Animation::getClip(int speed)
{
	if (first == false)
	{
		nextFrame += speed;
		nextFrame -= 60;
		first = true;
	}


	
	if (Fps::getFrame() % nextFrame == 0)
	{
		nextFrame += speed;
		nextFrame -= 60;

	}

}
