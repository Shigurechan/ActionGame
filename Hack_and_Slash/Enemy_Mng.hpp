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

	Enemy_Mng(int Enemy_Handle, int Enemy_Bullet_Hanlde, int Stage_HitEffect_Handle[3], int Player_HitEffect_Handle[3]);	//�R���X�g���N�^
	~Enemy_Mng();	//�f�X�g���N�^


	void Update();	//�X�V
	void Draw();	//�`��

	std::shared_ptr<std::vector<Enemy>> getEnemy();					//�G�l�~�[���
	void ColPlayer(std::shared_ptr<Player> player);					//�v���C���[�Ƃ̓����蔻��
	void ColBullet(std::shared_ptr<std::vector<Bullet>> bullet);	//�o���b�g�Ƃ̓����蔻��

private:
	

	int mEnemy_sprite;
	int mEnemy_Bullet_sprite;
	int mStage_HitEffect_sprite[3];
	int mPlayer_HitEffect_sprite[3];



	std::shared_ptr<std::vector<Enemy>> enemy;	//�G�l�~�[�@�N���X



};

#endif;