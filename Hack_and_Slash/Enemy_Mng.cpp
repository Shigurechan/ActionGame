#include "Enemy_Mng.hpp"


//�R���X�g���N�^
Enemy_Mng::Enemy_Mng(int Enemy_Handle, int Enemy_Bullet_Hanlde, int Stage_HitEffect_Handle[3], int Player_HitEffect_Handle[3])
{
	enemy = std::make_shared<std::vector<Enemy>>();	//�x�N�^�[�ϐ�


	mEnemy_sprite = Enemy_Handle;
	mEnemy_Bullet_sprite = Enemy_Bullet_Hanlde;

	mStage_HitEffect_sprite[0] = Stage_HitEffect_Handle[0];
	mStage_HitEffect_sprite[1] = Stage_HitEffect_Handle[1];
	mStage_HitEffect_sprite[2] = Stage_HitEffect_Handle[2];

	mPlayer_HitEffect_sprite[0] = Player_HitEffect_Handle[0];
	mPlayer_HitEffect_sprite[1] = Player_HitEffect_Handle[1];
	mPlayer_HitEffect_sprite[2] = Player_HitEffect_Handle[2];




	enemy->push_back(Enemy(mEnemy_sprite, mEnemy_Bullet_sprite, mStage_HitEffect_sprite, mPlayer_HitEffect_sprite));	//�ǉ�
}


//�G�l�~�[��Ԃ�
std::shared_ptr<std::vector<Enemy>> Enemy_Mng::getEnemy()
{
	return enemy;
}

//�v���C���[�Ƃ̓����蔻��
void Enemy_Mng::ColPlayer(std::shared_ptr<Player> player)
{
	for (std::vector<Enemy>::iterator itr = enemy->begin(); itr != enemy->end(); itr++)
	{
		//��������
		if (Box_Collision::Intersect(itr->mCol, player->mCol) == true)
		{
			//player->FixPos(itr->mCol.getPosition());
		}
	}
}

//�o���b�g�Ƃ̓����蔻��
void Enemy_Mng::ColBullet(std::shared_ptr<std::vector<Bullet>> bullet)
{
	for (std::vector<Bullet>::iterator it = bullet->begin(); it != bullet->end(); it++)
	{
		for (std::vector<Enemy>::iterator itr = enemy->begin(); itr != enemy->end();)
		{
			Enemy e = *itr;

			//����
			if (Box_Collision::Intersect(e.mCol, it->mCol) == true)
			{
				it->mIsEnemyHit = true;		//�G�l�~�[�ƃo���b�g���q�b�g
				itr = enemy->erase(itr);	//�G���폜
			}
			else {
				itr++;
			}
		}
	}
}


//�X�V
void Enemy_Mng::Update()
{
	for (std::vector<Enemy>::iterator itr = enemy->begin(); itr != enemy->end(); itr++)
	{
		itr->Update();
	}
}

//�`��
void Enemy_Mng::Draw()
{
	for (std::vector<Enemy>::iterator itr = enemy->begin(); itr != enemy->end(); itr++)
	{
		itr->Draw();
	}
}



//�f�X�g���N�^
Enemy_Mng::~Enemy_Mng()
{

}
