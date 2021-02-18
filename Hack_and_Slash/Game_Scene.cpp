#include "Game_Scene.hpp"

//�R���X�g���N�^
Game_Scene::Game_Scene(Scene_Type t) : Scene_base(t)
{
	flag = false;
	player = std::make_shared<Player>();	//�v���C���[
	stage = std::make_shared<Stage>();		//�X�e�[�W
	shop = std::make_shared<Shop>();		//�V���b�v���j���[
}

//�X�V
void Game_Scene::Update()
{
	//�o�g��
	if (player->getIsMenu() == false)
	{
		player->Update();			//�v���C���[�X�V
		stage->Update();			//�X�e�[�W�X�V
		stage->ColPlayer(*player);	//�v���C���[�ƃ}�b�v�Ƃ̓����蔻��			
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
			shop = std::make_shared <Shop>();
		}
	}



}

//�`��
void Game_Scene::Draw()
{

	player->Draw();	//�v���C���[�`��
	stage->Draw();	//�X�e�[�W�`��

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
