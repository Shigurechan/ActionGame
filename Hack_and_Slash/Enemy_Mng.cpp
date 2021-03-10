#include "Enemy_Mng.hpp"
#include "Player.hpp"
#include "MapChip.hpp"


//�R���X�g���N�^
Enemy_Mng::Enemy_Mng(int Enemy_Handle, int Enemy_Bullet_Hanlde, int Stage_HitEffect_Handle[3], int Player_HitEffect_Handle[3])
{
	enemy = std::make_shared<std::vector<Enemy>>();	//�x�N�^�[�ϐ�
	newStage = true;	//�V�����X�e�[�W�ɂȂ邩�ǂ����H

	mEnemy_sprite = Enemy_Handle;
	mEnemy_Bullet_sprite = Enemy_Bullet_Hanlde;

	mStage_HitEffect_sprite[0] = Stage_HitEffect_Handle[0];
	mStage_HitEffect_sprite[1] = Stage_HitEffect_Handle[1];
	mStage_HitEffect_sprite[2] = Stage_HitEffect_Handle[2];

	mPlayer_HitEffect_sprite[0] = Player_HitEffect_Handle[0];
	mPlayer_HitEffect_sprite[1] = Player_HitEffect_Handle[1];
	mPlayer_HitEffect_sprite[2] = Player_HitEffect_Handle[2];




	//enemy->push_back(Enemy(mEnemy_sprite, mEnemy_Bullet_sprite, mStage_HitEffect_sprite, mPlayer_HitEffect_sprite));	//�ǉ�
}


//�G�l�~�[��Ԃ�
std::shared_ptr<std::vector<Enemy>> Enemy_Mng::getEnemy()
{
	return enemy;
}



//�v���C���[�ƃo���b�g�Ƃ̓����蔻��
void Enemy_Mng::ColPlayer_Bullet(std::shared_ptr<Player> player)
{
	bool b = false;

	//�G�l�~�[
	for (std::vector<Enemy>::iterator itr = enemy->begin(); itr != enemy->end();)
	{
		

		//�o���b�g
		for (std::vector<Bullet>::iterator b = player->getBullet()->begin(); b != player->getBullet()->end(); b++)
		{

			//��������
			if (Box_Collision::Intersect(itr->mCol, b->mCol) == true)
			{
				itr = enemy->erase(itr);
	
				b->mIsEnemyHit = true;				//�q�b�g�G�t�F�N�g���Đ�
				//b->setPosition(itr->getPosition());	//���W���C��
			}	
		}	

		if (itr != enemy->end())
		{
			itr++;
		}
	}




}


//���݂̃G�l�~�[�̐��𓾂�
int Enemy_Mng::getEnemyNum()
{
	//printf("enemy->size: %d\n", (int)enemy->size());
	return (int)enemy->size();
	
	//return (int)enemy->size();
}

//�G�l�~�[���o��������
void Enemy_Mng::setEnemy(std::shared_ptr<Stage> stage)
{
	



	//�V�����X�e�[�W���ǂ����H
	if (newStage == true)
	{
		int x, y;
		x = y = 0;

			enemy->push_back(Enemy(glm::ivec2(0,0),mEnemy_sprite, mEnemy_Bullet_sprite, mStage_HitEffect_sprite, mPlayer_HitEffect_sprite));	//�ǉ�


		/*
		for (std::vector<std::vector<byte>>::iterator itr = stage->begin(); itr != stage->end(); itr++)
		{
			for (std::vector<byte>::iterator it = itr->begin(); it != itr->end(); it++)
			{
				if (*it == 0x00)
				{
					//�o���m��
					if (GetRand(2000 ) == 1) {
					//	enemy->push_back(Enemy(glm::ivec2(x * CELL,y * CELL),mEnemy_sprite, mEnemy_Bullet_sprite, mStage_HitEffect_sprite, mPlayer_HitEffect_sprite));	//�ǉ�
					}
				}
				x++;
			}
			y++;
		}
		*/
		newStage = false;
	}


	//printf("size: %zd\n",enemy->size());
}




//�X�V
void Enemy_Mng::Update()
{
	if (getEnemyNum() == 0)
	{
		newStage = true;
	}

	//printf("enemey->size(): %d\n",enemy->size());


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

