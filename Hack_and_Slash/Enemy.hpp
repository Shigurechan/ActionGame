#ifndef ___ENEMY_HPP_
#define ___ENEMY_HPP_

#include "Actor.hpp"
#include "Collision.hpp"
#include "Entry.hpp"


class Entry;
/*####################################################
* �G�l�~�[�Ǘ��N���X
* 
* ����
* �G�̈ړ��ƍs�����Ǘ�����N���X
######################################################*/
class Enemy :public Actor
{
public:
	Enemy(int handle);	//�R���X�g���N�^
	~Enemy();			//�f�X�g���N�^

	void Update();	//�X�V
	void Draw();	//�`��

	// ### �ݒ�@�֌W
	void FixPos(glm::ivec2 pos);	//���W���C��
	void setMove_Rand();			//�ړ��������Đݒ�

	Box_Collision mCol;	//�����蔻��
private:

	int mSprite;		//�摜�n���h��
	int Rand_Action;	//�s���̗���
	int mSpeed;			//�ړ����x


};


#endif

