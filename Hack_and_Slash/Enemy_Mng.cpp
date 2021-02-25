#include "Enemy_Mng.hpp"


//�R���X�g���N�^
Enemy_Mng::Enemy_Mng()
{
	enemy = std::make_shared<std::vector<Enemy>>();	//�x�N�^�[�ϐ�

	//�X�v���C�g�����[�h
	Handle = LoadGraph("Assets/Enemy.png");					//�G�l�~�[
	Bullet_Handle = LoadGraph("Assets/Enemy_Bullet.png");	//�o���b�g




	enemy->push_back(Enemy(Handle,Bullet_Handle));	//�ǉ�
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
