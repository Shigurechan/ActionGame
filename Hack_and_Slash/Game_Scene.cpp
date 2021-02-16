#include "Game_Scene.hpp"

//�R���X�g���N�^
Game_Scene::Game_Scene(Scene_Type t) : Scene_base(t)
{
	player = std::make_shared<Player>();
	stage = std::make_shared<Stage>();
}

//�X�V
void Game_Scene::Update()
{
	player->Update();
	stage->Update();

	stage->ColPlayer(*player);	//�v���C���[�ƃ}�b�v�Ƃ̓����蔻��




}

//�`��
void Game_Scene::Draw()
{
	player->Draw();
	stage->Draw();
}

//�f�X�g���N�^
Game_Scene::~Game_Scene()
{

}
