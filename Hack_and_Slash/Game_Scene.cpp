#include "Game_Scene.hpp"

//�R���X�g���N�^
Game_Scene::Game_Scene(Scene_Type t,Entry *e) : Scene_base(t,e)
{
	Owner = e;	//Entry �N���X


	// #####�@�X�v���C�g�����[�h #####

	int Player_Handle = Owner->LoadSprite("Assets/Player/Player_0.png");	//�v���C���[
	int Enemy_Handle = Owner->LoadSprite("Assets/Enemy.png");				//�G�l�~�[		

	int Player_Bullet_Handle = Owner->LoadSprite("Assets/Player_Bullet.png");	//�v���C���[�̃o���b�g
	int Enemy_Bullet_Handle = Owner->LoadSprite("Assets/Enemy_Bullet.png");		//�G�l�~�[�̃o���b�g

	int Block_Handle = Owner->LoadSprite("Assets/Block.png");	//�u���b�N	
	int Brick_Handle = Owner->LoadSprite("Assets/Brick.png");	//�����K
	int Shop_Handle = Owner->LoadSprite("Assets/Shop.png");		//�V���b�v
	


	//�q�b�g�G�t�F�N�g
	int Enemy_HitEffect_Handle[3];	//�G�l�~�[
	int Stage_HitEffect_Handle[3];	//�X�e�[�W
	int Player_HitEffect_Handle[3];	//�v���C���[

	int a = LoadDivGraph("Assets/Enemy_Explosion.png", 3, 3, 1, CELL, CELL, Enemy_HitEffect_Handle);	//�G�l�~�[
	

	LoadDivGraph("Assets/Stage_Explosion.png", 3, 3, 1, CELL, CELL, Stage_HitEffect_Handle);	//�X�e�[�W
	

	LoadDivGraph("Assets/Player_Explosion.png", 3, 3, 1, CELL, CELL,Player_HitEffect_Handle);	//�v���C���[
	


	flag = false;	//�V���b�v�����ǂ����H
	player = std::make_shared<Player>(Owner,Player_Handle, Player_Bullet_Handle,Enemy_HitEffect_Handle, Stage_HitEffect_Handle);	//�v���C���[
	stage = std::make_shared<Stage>(Owner,Block_Handle, Brick_Handle, Shop_Handle);													//�X�e�[�W
	shop = std::make_shared<Shop>(Owner);																							//�V���b�v���j���[
	enemy_mng = std::make_shared<Enemy_Mng>(Enemy_Handle,Enemy_Bullet_Handle,Stage_HitEffect_Handle, Player_HitEffect_Handle);		//�G�l�~�[�Ǘ�



}

//�X�V
void Game_Scene::Update()
{
	//�o�g��
	if (player->getIsMenu() == false)
	{	



		enemy_mng->Update();												//�G�l�~�[�X�V
		stage->Update();													//�X�e�[�W�X�V
		player->Update();													//�v���C���[�X�V

		stage->Scroll(player, enemy_mng->getEnemy(), player->getBullet());	//��ʃX�N���[��


		stage->ColEnemy(enemy_mng->getEnemy());								//�G�l�~�[�Ƃ̓����蔻��
		stage->ColEnemy_Bullet(enemy_mng->getEnemy());						//�G�l�~�[�̃o���b�g�Ƃ̃}�b�v�̂Ƃ̓����蔻��
		

		stage->ColPlayer(player);											//�v���C���[�Ɠ����蔻��
		stage->ColPlayer_Bullet(player->getBullet());						//�v���C���[�̃o���b�g�̓����蔻��

		player->ColEnemy_Bullet(enemy_mng->getEnemy());

		enemy_mng->ColPlayer(player);										//�G�l�~�[�ƃv���C���[�Ƃ̓����蔻��
		enemy_mng->ColBullet(player->getBullet());							//�G�l�~�[�ƃv���C���[�̃o���b�g�̓����蔻��




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
	enemy_mng->Draw();	//�G�l�~�[�`��

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
