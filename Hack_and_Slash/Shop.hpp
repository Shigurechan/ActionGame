#ifndef ___SHOP_HPP_
#define ___SHOP_HPP_

#include "glm/glm.hpp"
#include "dxlib.h"


#include "Entry.hpp"
#include "Player.hpp"
#include "Window.hpp"
#include "Input.hpp"
#include "Window.hpp"
#include <array>
#include <vector>

//�O���錾
class Window;
enum class MenuMove;



/*####################################################
* �V���b�v
######################################################*/

class Shop
{
public:
	Shop();		//�R���X�g���N�^	
	~Shop();	//�f�X�g���N�^

	void Update(Player& player);	//�X�V
	void Draw();	//�`��


	bool getState();			//���݃V���b�v�����ǂ����H
	void setIs_State(bool b);
	void Reset_Flag();


private:

	std::shared_ptr<Window> MainMenu;	//���C�����j���[
	std::shared_ptr<Window> BuyMenu;	//�w�����j���[
	std::shared_ptr<Window> SellMenu;	//���郁�j���[

	std::shared_ptr<Window> Dialogue;	//�m�F���j���[






	bool mIsNowShop;	//�V���b�v����邩�ǂ����H
	MenuMove menu;	//���݂̑I��
	std::vector<MenuMove> DrawMenu;	//���j���[�؂�ւ��`��


};


#endif
