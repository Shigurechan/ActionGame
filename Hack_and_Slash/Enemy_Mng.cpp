#include "Enemy_Mng.hpp"
#include "Player.hpp"
#include "MapChip.hpp"


//�R���X�g���N�^
Enemy_Mng::Enemy_Mng(int Enemy_Handle, int Enemy_Bullet_Hanlde, int Stage_HitEffect_Handle[3], int Player_HitEffect_Handle[3])
{
	enemy = std::make_shared<std::vector<Enemy>>();	//�x�N�^�[�ϐ�
	enemy->clear();
	newStage = true;	//�V�����X�e�[�W�ɂȂ邩�ǂ����H

	mEnemy_sprite = Enemy_Handle;
	mEnemy_Bullet_sprite = Enemy_Bullet_Hanlde;

	mStage_HitEffect_sprite[0] = Stage_HitEffect_Handle[0];
	mStage_HitEffect_sprite[1] = Stage_HitEffect_Handle[1];
	mStage_HitEffect_sprite[2] = Stage_HitEffect_Handle[2];

	mPlayer_HitEffect_sprite[0] = Player_HitEffect_Handle[0];
	mPlayer_HitEffect_sprite[1] = Player_HitEffect_Handle[1];
	mPlayer_HitEffect_sprite[2] = Player_HitEffect_Handle[2];
}


//�G�l�~�[��Ԃ�
std::shared_ptr<std::vector<Enemy>> Enemy_Mng::getEnemy()
{
	return enemy;
}



//�v���C���[�ƃo���b�g�Ƃ̓����蔻��
void Enemy_Mng::ColPlayer_Bullet(std::shared_ptr<Player> player)
{
	printf("������\n");

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
				if (itr == enemy->end())
				{
					break;
				}
				b->mIsEnemyHit = true;				//�q�b�g�G�t�F�N�g���Đ�
				//b->setPosition(itr->getPosition());	//���W���C��
			}	
		}	

		if (itr != enemy->end())
		{
			itr++;
		}

	}

	printf("��������");

}


//���݂̃G�l�~�[�̐��𓾂�
bool Enemy_Mng::getEnemyEmpty()
{
//	std::shared_ptr<std::vector<Enemy>> getEnemy();					//�G�l�~�[���

	return enemy->empty();

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

		newStage = false;
	}
}




//�X�V
void Enemy_Mng::Update()
{

	//printf("Size: %d\n",getEnemyNum());



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

