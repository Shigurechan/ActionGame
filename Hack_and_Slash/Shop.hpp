#ifndef ___SHOP_HPP_
#define ___SHOP_HPP_

#include "glm/glm.hpp"
#include "dxlib.h"
#include <array>
#include <vector>


#include "Entry.hpp"
//#include "Player.hpp"
#include "Window.hpp"
//#include "Input.hpp"
#include "ItemID.hpp"

//�O���錾
class Window;				//�E�C���h�N���X
enum class Window_Scene;	//�E�C���h�E�V�[��
class Player;
/*####################################################
* �V���b�v
######################################################*/

class Shop
{
public:
	Shop(Entry* e);		//�R���X�g���N�^	
	~Shop();			//�f�X�g���N�^

	void Update(Player& player);	//�X�V
	void Draw();	//�`��


	bool getState();			//���݃V���b�v�����ǂ����H
	void setIs_State(bool b);
	void Reset_Flag();


private:

	std::shared_ptr<Window> MainMenu;	//���C�����j���[
	std::shared_ptr<Window> BuyMenu;	//�w�����j���[
	std::shared_ptr<Window> SellMenu;	//���郁�j���[

	std::shared_ptr<Window> CheckMenu_Buy;	//�m�F���j���[
	std::shared_ptr<Window> CheckMenu_Sell;	//�m�F���j���[


	unsigned char Item_ID;	//�X�V����A�C�e����ID




	bool b = false;
	bool mIsNowShop;	//�V���b�v����邩�ǂ����H
	Window_Scene Scene;	//���݂̑I��
	std::vector<Window_Scene> DrawMenu;	//���j���[�؂�ւ��`��

	Entry* Owner;	//Entry �N���X

};


#endif
