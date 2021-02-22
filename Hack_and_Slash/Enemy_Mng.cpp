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
