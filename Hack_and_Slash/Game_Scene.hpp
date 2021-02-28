#ifndef ___GAME_SCENE_HPP_
#define ___GAME_SCENE_HPP_

#include "Scene_base.hpp"
#include "Player.hpp"
#include "Stage.hpp"
#include "Shop.hpp"
#include "Enemy_Mng.hpp"

#include <iostream>
#include <vector>


//�O���錾
class Player;
class Stage;
class Shop;
class Entry;
class Enemy_Mng;
enum class Scene_Type;

/*####################################################
* ���C���Q�[���@�V�[��
*
* ����
* ���C���̃Q�[�����
######################################################*/
class Game_Scene : public Scene_base
{
public:
	Game_Scene(Scene_Type t,Entry* e);	//�R���X�g���N�^
	~Game_Scene();						//�f�X�g���N�^

	void Update();	//�X�V
	void Draw();	//�`��


private:

	std::shared_ptr<Player> player;			//�v���C���[
	std::shared_ptr<Stage> stage;			//�X�e�[�W
	std::shared_ptr<Shop> shop;				//�V���b�v
	std::shared_ptr<Enemy_Mng> enemy_mng;	//�G�l�~�[






	bool flag;	//�V���b�v���ǂ����̃t���O
	Entry* Owner;	//Entry �N���X

};

#endif
