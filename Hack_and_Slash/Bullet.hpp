#ifndef ___BULLET_HPP_
#define ___BULLET_HPP_

#include "DxLib.h"

#include "Actor.hpp"
#include "Entry.hpp"

/*####################################################
* �o���b�g(�e)
*
* ����
* vector�ŊǗ�
* �v���C���[�̍U��
* 
######################################################*/

class Bullet : public Actor
{
public:
	Bullet(glm::ivec2 pos, glm::ivec2 vec,int handle);	//�R���X�g���N�^
	~Bullet();											//�f�X�g���N�^

	void Update() override;	//�X�V
	void Draw() override;	//�`��

private:
	int mSprite;	//�X�v���C�g
	int mSpeed;		//�o���b�g�̑��x


	

};


#endif






