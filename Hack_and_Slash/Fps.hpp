#ifndef ___FPS_HPP_
#define ___FPS_HPP_

#include <math.h>
#include "DxLib.h"


/*####################################################
* �t���[�����[�g����
######################################################*/

class Fps {
	
public:
	Fps();
	bool Update();	//�X�V
	void Wait();	//�ҋ@
	
private:
	int mStartTime;				//����J�n����
	int mCount;					//�J�E���^
	float mFps;					//fps
	static const int N = 60;	//���ς����T���v����
	static const int FPS = 60;	//�ݒ肵��FPS

};
#endif