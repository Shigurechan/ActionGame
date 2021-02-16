#include "Entry.hpp"

//�R���X�g���N�^
Entry::Entry()
{
	//printf("SCRREN_WIDTH : %d\n", SCREEN_WIDTH);
	//printf("SCRREN_HEIGHT : %d\n",SCREEN_HEIGHT);


	game = std::make_shared<Game_Scene>(Scene_Type::Game);
	type = Scene_Type::Game;
}

//�v�Z
void Entry::Update()
{
	switch (type)
	{
		//���C���Q�[��
	case Scene_Type::Game:
		{
			game->Update();
			type = game->getSceneType();
		}



	};
}

//�`��
void Entry::Draw()
{
	switch (type)
	{
		//���C���Q�[��
	case Scene_Type::Game:
		{
			game->Draw();
			type = game->getSceneType();
		}




	};
}

//�f�X�g���N�^
Entry::~Entry()
{
	
}

