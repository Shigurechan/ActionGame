#ifndef ___INPUT_HPP_
#define ___INPUT_HPP_

#include "dxlib.h"


/*#################################################### 
* �L�[����
######################################################*/

class Input {

public:
	Input();	//�R���X�g���N�^
	~Input();	//�f�X�g���N�^
	
	void Update();								//�L�[���͏�Ԃ��X�V

	bool getKeyDown(unsigned char KeyCode);		//�L�[�������ꂽ�u�Ԃ���
	int  getKeyDownHold(unsigned char KeyCode);	//�L�[��������Ă����

private:
	int Key[256];	//�L�[���

};



#endif
