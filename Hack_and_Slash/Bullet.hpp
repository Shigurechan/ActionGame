#ifndef ___BULLET_HPP_
#define ___BULLET_HPP_

#include "DxLib.h"
#include "glm/glm.hpp"
#include "Actor.hpp"
#include "Entry.hpp"
#include "Collision.hpp"


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
	Bullet(glm::ivec2 pos, glm::ivec2 vec, int handle);	//�R���X�g���N�^
	~Bullet();											//�f�X�g���N�^

	void Update();	//�X�V
	void Draw();	//�`��


	Box_Collision mCol;	//�����蔻��
private:
	int mSprite;	//�X�v���C�g
	int mSpeed;		//�o���b�g�̑��x
};


#endif






