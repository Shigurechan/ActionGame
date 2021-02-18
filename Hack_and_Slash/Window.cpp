#include "Window.hpp"

//�R���X�g���N�^
Window::Window(MenuMove m,glm::ivec2 pos, glm::ivec2 size, std::string str)
{
	Menu = m;	//���j���[����

	Move = MenuMove::Invalid;	//���ݑI��

	mInput = std::make_shared<Input>();	//�L�[����

	WindowTitle = str;	//�^�C�g��
	window.pos = pos;	//���W
	window.size = size;	//�傫��

	ItemPos = window.pos;	//���ڂ̍��W
	Cursor = 0;				//�J�[�\��
}

//�V�[�����w��
void Window::setChange(MenuMove m)
{
	Move = m;
}

//�Q�[�����A�C�e����ݒ�
void Window::AddItem_Parameter(ItemData data)
{
	glm::ivec2 pos;
	//���W���C��
	pos.y += 20;
	pos.x = window.pos.x + 50;
	
	

	data.pos = pos;
	Game_Item.push_back(data);

}





//�E�C���h�E�ɍ��ڂ�ǉ�
void Window::AddItem(MenuMove m,std::string name)
{
	Window_Item item;

	item.name = name;	//���O

	//���W���C��
	ItemPos.y += 20;
	ItemPos.x = window.pos.x + 50;
	item.pos = ItemPos;
	
	item.menu = m;

	Item.push_back(item);
}

//���j���[���J��ւ�
MenuMove Window::getChange()
{
	return Move;
}



//�v�Z
void Window::Update()
{
	mInput->Update(); // �L�[���͍X�V

	//�L�[����	
	if (mInput->getKeyDown(KEY_INPUT_UP) == true)
	{
		Cursor += -1;
		if (Cursor < 0)
		{
			Cursor = 0;
		}

	}
	else if (mInput->getKeyDown(KEY_INPUT_DOWN) == true)
	{
		Cursor += 1;
		if (Cursor > Item.size() - 1)
		{
			Cursor = (int)Item.size() - 1;
		}

	}
	else if (mInput->getKeyDown(KEY_INPUT_SPACE) == true)
	{
		//����{�^��
		Move = Item.at(Cursor).menu;

	}	
}


//�`��
void Window::Draw()
{
	DrawBox(window.pos.x, window.pos.y, window.size.x, window.size.y,GetColor(100,100,0), true);	//�w�i
	DrawFormatString(window.pos.x, window.pos.y, GetColor(0, 255, 0),"%s",WindowTitle.c_str());		//�^�C�g��




	if (Item.size() > 0) {
		//���ڂ�\��
		for (std::vector<Window_Item>::iterator itr = Item.begin(); itr != Item.end(); itr++)
		{

			Window_Item item = *itr;
			if (Item.at(Cursor).pos == item.pos)
			{
				//�J�[�\���̏ꏊ
				DrawFormatString(itr->pos.x, itr->pos.y, GetColor(0, 0, 0), "->");		//�J�[�\��
				DrawFormatString(itr->pos.x + 20, itr->pos.y, GetColor(0, 255, 0), "%s", itr->name.c_str());	//����

			}
			else {
				DrawFormatString(itr->pos.x, itr->pos.y, GetColor(0, 255, 0), "%s", itr->name.c_str());	//����
			}
		}

	}
	else if (Game_Item.size() > 0)
	{
		//���ڂ�\��
		for (std::vector<ItemData>::iterator itr = Game_Item.begin(); itr != Game_Item.end(); itr++)
		{

			ItemData item = *itr;
			if (Game_Item.at(Cursor).pos == item.pos)
			{
				//�J�[�\���̏ꏊ
				DrawFormatString(itr->pos.x, itr->pos.y, GetColor(0, 0, 0), "->");		//�J�[�\��
				DrawFormatString(itr->pos.x + 20, itr->pos.y, GetColor(0, 255, 0), "%s", itr->name.c_str());	//����

			}
			else {
				DrawFormatString(itr->pos.x, itr->pos.y, GetColor(0, 255, 0), "%s", itr->name.c_str());	//����
			}
		}

	}




}



//�f�X�g���N�^
Window::~Window()
{

}


