#include "Enemy_Mng.hpp"


//�R���X�g���N�^
Enemy_Mng::Enemy_Mng()
{
	Handle = LoadGraph("Assets/Enemy.png");

	enemy = std::make_shared<std::vector<Enemy>>();

	enemy->push_back(Enemy(Handle));	//�ǉ�
}


//�G�l�~�[��Ԃ�
std::shared_ptr<std::vector<Enemy>> Enemy_Mng::getEnemy()
{
	return enemy;
}

//�v���C���[�Ƃ̓����蔻��
void Enemy_Mng::ColPlayer(Player& player)
{
	for (std::vector<Enemy>::iterator itr = enemy->begin(); itr != enemy->end(); itr++)
	{
		//��������
		if (Box_Collision::Intersect(itr->mCol, player.mCol) == true)
		{
			itr->FixPos(player.getPosition());
		}
	}

}

//�o���b�g�Ƃ̓����蔻��
void Enemy_Mng::ColBullet(std::shared_ptr<std::vector<Bullet>> bullet)
{

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
