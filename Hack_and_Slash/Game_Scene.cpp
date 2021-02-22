#include "Game_Scene.hpp"

//�R���X�g���N�^
Game_Scene::Game_Scene(Scene_Type t,Entry *e) : Scene_base(t,e)
{
	Owner = e;


	flag = false;	//�V���b�v�����ǂ����H
	player = std::make_shared<Player>(e);					//�v���C���[
	stage = std::make_shared<Stage>(e);						//�X�e�[�W
	shop = std::make_shared<Shop>(e);						//�V���b�v���j���[
	enemy_mng = std::make_shared<Enemy_Mng>();				//�G�l�~�[�Ǘ�



}

//�X�V
void Game_Scene::Update()
{
	//�o�g��
	if (player->getIsMenu() == false)
	{	

		stage->ScrollMap(*player);				//��ʃX�N���[��
		player->Update();						//�v���C���[�X�V
		stage->ColPlayer(*player);				//�v���C���[�ƃ}�b�v�Ƃ̓����蔻��

		stage->Update();						//�X�e�[�W�X�V
		enemy_mng->Update();					//�G�l�~�[�X�V

		stage->ColBullet(player->getBullet());	//�o���b�g�ƃ}�b�v�Ƃ̓����蔻��
		stage->ColEnemy(enemy_mng->getEnemy());
	}
	else
	{
		//�V���b�v���
		if (shop->getState() == true)
		{
			shop->Update(*player);
		}
		else {
			player->setIsMenu(false);
			shop = std::make_shared <Shop>(Owner);
		}
	}



}

//�`��
void Game_Scene::Draw()
{

	player->Draw();	//�v���C���[�`��
	stage->Draw();	//�X�e�[�W�`��
	//enemy_mng->Draw();

	//�V���b�v���
	if (player->getIsMenu() == true)
	{
		shop->Draw();
	}

	

}

//�f�X�g���N�^
Game_Scene::~Game_Scene()
{

}
