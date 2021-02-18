#include "Shop.hpp"



//�R���X�g���N�^
Shop::Shop()
{

	//���C�����j���[
	MainMenu = std::make_shared<Window>(MenuMove::Main,glm::ivec2(100, 100), glm::ivec2(500, 200), "�V���b�v�@���j���[");
	MainMenu->AddItem(MenuMove::Buy_Menu,"����");
	MainMenu->AddItem(MenuMove::Sell_Menu, "����");
	MainMenu->AddItem(MenuMove::End,"�߂�");

	//�w�����j���[
	BuyMenu = std::make_shared<Window>(MenuMove::Buy_Menu,glm::ivec2(120,120),glm::ivec2(520,220),"�w���@���j���[");
	BuyMenu->AddItem_Parameter(ItemData{ 1,0,0,  "��" });
	BuyMenu->AddItem_Parameter(ItemData{ 0,1,0,  "�h��" });
	BuyMenu->AddItem_Parameter(ItemData{0,0,1,  "�U��" });
	
	//���郁�j���[
	SellMenu = std::make_shared<Window>(MenuMove::Sell_Menu, glm::ivec2(120, 120), glm::ivec2(520, 220), "����@���j���[");
	SellMenu->AddItem_Parameter(ItemData{ 1,0,0,  "��" });
	SellMenu->AddItem_Parameter(ItemData{ 1,0,0,  "��" });
	SellMenu->AddItem_Parameter(ItemData{ 1,0,0,  "��" });
	
	//�_�C�����O
	Dialogue = std::make_shared<Window>(MenuMove::Check, glm::ivec2(140, 140), glm::ivec2(540, 240), "�m�F");






	menu = MenuMove::Main;		//���ݑI�𒆂̃��j���[
	DrawMenu.push_back(menu);	//���j���[�`��
	mIsNowShop = true;			//�E�C���h�E���J���Ă��邩�ǂ����H
}

//���݃V���b�v�����ǂ����H
bool Shop::getState()
{
	return mIsNowShop;
}

//�X�V
void Shop::Update(Player &player)
{
	switch (menu)
	{
		//���C�����j���[
	case MenuMove::Main:
	{
		MainMenu->Update();	//�X�V

		//�O�̃��j���[
		if (MainMenu->getChange() == MenuMove::End)
		{
			DrawMenu.erase(DrawMenu.begin() + DrawMenu.size() - 1);		//�Ō���폜
			menu = MainMenu->getChange();								//���j���[�I��
			MainMenu->setChange(MenuMove::Invalid);						//�I�����ď�����
		}
		else if (MainMenu->getChange() != MenuMove::Invalid)
		{
			menu = MainMenu->getChange();							//���j���[��I��
			DrawMenu.push_back(MainMenu->getChange());				//�`�惁�j���[��ݒ�
			MainMenu->setChange(MenuMove::Invalid);					//�I�����ď�����
		}
	}break;

	//�������j���[
	case MenuMove::Buy_Menu:
	{
		BuyMenu->Update();	//�X�V

		//�O�̃��j���[
		if (BuyMenu->getChange() == MenuMove::Main)
		{
			DrawMenu.erase(DrawMenu.begin() + DrawMenu.size() - 1);	//�Ō���폜
			menu = BuyMenu->getChange();							//���j���[�I��
			BuyMenu->setChange(MenuMove::Invalid);					//�I�����ď�����
		}
		else if (BuyMenu->getChange() != MenuMove::Invalid)
		{
			menu = BuyMenu->getChange();							//���j���[�I��
		}
	}break;

	//���郁�j���[
	case MenuMove::Sell_Menu:
	{
		SellMenu->Update();	//�X�V

		//�O�̃��j���[
		if (SellMenu->getChange() == MenuMove::Main)
		{
			DrawMenu.erase(DrawMenu.begin() + DrawMenu.size() - 1);	//�Ō���폜
			menu = SellMenu->getChange();							//���j���[�I��
			SellMenu->setChange(MenuMove::Invalid);					//�I�����ď�����
		}
		else if (SellMenu->getChange() != MenuMove::Invalid)
		{			
			menu = SellMenu->getChange();							//���j���[�I��
		}
	}break;


		













	}

	//���j���[�𔲂���
	if (menu == MenuMove::End)
	{
		printf("������\n");
		mIsNowShop = false;
	}
}

//�`��
void Shop::Draw()
{	


	for (std::vector<MenuMove>::iterator itr = DrawMenu.begin(); itr != DrawMenu.end(); itr++)
	{
		switch (*itr)
		{
			//���C�����j���[
		case MenuMove::Main:
		{
//			printf("���C�����j���[\n");
			MainMenu->Draw();

		}
		break;

		//�w�����j���[
		case MenuMove::Buy_Menu:
		{
//			printf("�w�����j���[\n");
			BuyMenu->Draw();
		}
		break;


		//���郁�j���[
		case MenuMove::Sell_Menu:
		{
			//printf("���郁�j���[\n");
			SellMenu->Draw();
		}
		break;
		};
	}







	/*
	switch (menu)
	{
		


	}
	*/
}

//�f�X�g���N�^
Shop::~Shop()
{

}
