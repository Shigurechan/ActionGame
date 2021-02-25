#ifndef ___ENEMY_HPP_
#define ___ENEMY_HPP_

#include "Actor.hpp"
#include "Collision.hpp"
#include "Entry.hpp"
#include "Bullet.hpp"


class Entry;
/*####################################################
* �G�l�~�[
* 
* ����
* �G�̈ړ��ƍs������N���X
######################################################*/

class Enemy :public Actor
{
public:
	Enemy(int handle,int Bullet_handle);	//�R���X�g���N�^
	~Enemy();			//�f�X�g���N�^

	void Update();	//�X�V
	void Draw();	//�`��

	// ### �ݒ�@�֌W
	void FixPos(glm::ivec2 pos);	//���W���C��
	void setMove_Rand();			//�ړ��������Đݒ�
	void setMovePixel();			//�ړ��ʂ����Z�b�g


	Box_Collision mCol;	//�����蔻��
private:

	int mSprite;			//�摜�n���h��
	int mBullet_Sprite;		//�o���b�g�n���h��


	int Rand_Action;		//�s���̗���
	int Rand_Attack;		//�U�����邩�ǂ����H

	int Prev_Rand_Action;	//�O�̍s���̗���
	int mSpeed;				//�ړ����x
	int MovePixel;			//�ړ���

	std::shared_ptr<std::vector<Bullet>> bullet;	//�o���b�g




};


#endif

