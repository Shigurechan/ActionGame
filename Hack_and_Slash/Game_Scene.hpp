#ifndef ___GAME_SCENE_HPP_
#define ___GAME_SCENE_HPP_

#include "Scene_base.hpp"
#include "Player.hpp"
#include "Stage.hpp"
#include "Shop.hpp"
//#include "Entry.hpp"

#include <iostream>


//�O���錾
class Player;
class Stage;
class Shop;
class Entry;
enum class Scene_Type;
//class Scene_base;
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

	std::shared_ptr<Player> player;	//�v���C���[
	std::shared_ptr<Stage> stage;	//�X�e�[�W
	std::shared_ptr<Shop> shop;	//�V���b�v
	
	bool flag;	//�V���b�v���ǂ����̃t���O
	Entry* Owner;

};

#endif
