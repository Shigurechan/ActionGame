#ifndef ___ENEMY_MNG_HPP_
#define ___ENEMY_MNG_HPP_

#include "Enemy.hpp"
#include <vector>
#include <iostream>


//�O���錾
class Enemy;

/*####################################################
* �G�l�~�[�Ǘ�
*
* ����
* �G�̈ړ��ƍs������Ǘ�����N���X
######################################################*/
class Enemy_Mng {

public:

	Enemy_Mng();	//�R���X�g���N�^
	~Enemy_Mng();	//�f�X�g���N�^


	void Update();	//�X�V
	void Draw();	//�`��

	std::shared_ptr<std::vector<Enemy>> getEnemy();					//�G�l�~�[���
	void ColPlayer(Player& player);									//�v���C���[�Ƃ̓����蔻��
	void ColBullet(std::shared_ptr<std::vector<Bullet>> bullet);	//�o���b�g�Ƃ̓����蔻��

private:
	int Handle;	//�X�v���C�g
	std::shared_ptr<std::vector<Enemy>> enemy;	//�G�l�~�[�@�N���X



};

#endif;