#ifndef ___WINDOW_HPP_
#define ___WINDOW_HPP_

#include "glm/glm.hpp"
#include "dxlib.h"
#include <string>
#include <vector>
#include <iostream>

#include "Entry.hpp"
#include "Input.hpp"
#include "UI.hpp"





// ���j���[����
enum class MenuMove
{
	Main,//�ŏ��̉��

	Item,	//�A�C�e��

	//���C�����j���[
	Buy_Menu,
	Sell_Menu,

	//����
	Buy_Conf,
	Sell_Conf,

	Check,


	//�߂�@�I��
	End,

	Back,


	Invalid,

};

//�E�C���h�E�̍���
typedef struct Window_Item
{
	glm::ivec2 pos;		//���W
	std::string name;	//���O
	MenuMove menu;		//���j���[����

}Window_Item;


// �Q�[���A�C�e��
typedef struct ItemData
{
	int HP;		//�̗�
	int Diff;	//�h��
	int Attak;	//�U��
	glm::ivec2 pos;		//���W
	std::string name;	//�A�C�e����

}ItemData;

/*####################################################
* �E�C���h�E���
*
* ����
* �\���I�����郁�j���[���
######################################################*/
class Window
{
public:

	Window(MenuMove m,glm::ivec2 pos,glm::ivec2 size, std::string str);	//�R���X�g���N�^
	~Window();															//�f�X�g���N�^

	void AddItem(MenuMove m, std::string name);				//�E�C���h�E�ɍ��ڂ�ǉ�
	void AddItem_Parameter(ItemData);						//�A�C�e����\��

	MenuMove getChange();						//�V�[���J��ւ�
	void setChange(MenuMove m);					//�V�[���w��


	void Update();	//�v�Z
	void Draw();	//�`��

private:

	RectangleData window;			//��ʃT�C�Y
	std::shared_ptr<Input> mInput;	//�L�[����

	glm::ivec2 mPosition;	//���W
	glm::ivec2 mSize;		//�T�C�Y

	std::string WindowTitle;			//�^�C�g��
	std::vector<Window_Item> Item;		//���j���[����
	std::vector<ItemData> Game_Item;	//�A�C�e�����擾
	int Cursor;		//�J�[�\���ړ�

	MenuMove Menu;	//���j���W������
	MenuMove Move;	//���j������






	//�ꎞ�ϐ��@�֌W
	glm::ivec2 ItemPos;	//���ڂ̍��W





};


#endif
