#include "Stage.hpp"

//�R���X�g���N�^
Stage::Stage()
{
	//printf("X: %d", SCREEN_WIDTH / CELL);
	//printf("Y: %d",SCREEN_HEIGHT / CELL);

	mIsShop = false;	//�V���b�v�����ǂ����H


	//��ʂɕ`�悷��Z����
	mStageSize.x = SCREEN_WIDTH / CELL;
	mStageSize.y = SCREEN_HEIGHT / CELL;
	
	//�X�v���C�g�����[�h

	//�u���b�N
	int Block_sprite = LoadGraph("Assets/Block.png");
	glm::ivec2 BlockSize;	
	GetGraphSize(Block_sprite,&BlockSize.x, &BlockSize.y);	//�T�C�Y���擾

	//�����K
	int Brick_sprite = LoadGraph("Assets/Brick.png");
	glm::ivec2 BrickSize;	
	GetGraphSize(Brick_sprite, &BrickSize.x, &BrickSize.y);	//�T�C�Y���擾

	//�V���b�v
	int Shop_sprite = LoadGraph("Assets/Shop.png");
	glm::ivec2 ShopSize;
	GetGraphSize(Brick_sprite, &ShopSize.x, &ShopSize.y);	//�T�C�Y���擾

	//�X�e�[�W
	unsigned char Stage_Grid[SCREEN_HEIGHT / CELL][SCREEN_WIDTH / CELL] =
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};

	//�}�b�v�I�u�W�F�N�g��ݒ�
	for (int y = 0; y < mStageSize.y; y++)
	{
		for (int x = 0; x < mStageSize.x; x++)
		{			
			switch (Stage_Grid[y][x])
			{
				//�����K
				case 1:
				{
					mStage.push_back(MapChip(StageObjectType::Brick,glm::ivec2(x * CELL, y * CELL),BrickSize,Brick_sprite));
				}
				break;

				//�u���b�N
				case 2:
				{
					mStage.push_back(MapChip(StageObjectType::Block, glm::ivec2(x * CELL, y * CELL), BlockSize, Block_sprite));
				}
				break;

				//�V���b�v
				case 3:
				{
					mStage.push_back(MapChip(StageObjectType::Shop, glm::ivec2(x * CELL, y * CELL), ShopSize, Shop_sprite));
				}
				break;
			}
		}
	}
}

//�X�V
void Stage::Update()
{
	for (std::vector<MapChip>::iterator itr = mStage.begin(); itr != mStage.end(); itr++)
	{
		itr->Update();
	}
}

//�`��
void Stage::Draw()
{
	for (std::vector<MapChip>::iterator itr = mStage.begin(); itr != mStage.end(); itr++)
	{
		itr->Draw();
	}

}

//�����蔻��
void Stage::ColPlayer(Player &player)
{
	for (std::vector<MapChip>::iterator itr = mStage.begin(); itr != mStage.end(); itr++)
	{
		if (Box_Collision::Intersect(itr->mCol,player.mCol) == true)
		{

			switch (itr->mCol.getObjectType())
			{

				//�V���b�v
				case StageObjectType::Shop :
				{
				
					player.setIsMenu(true);
				
					player.FixPos(itr->mCol.getPosition());
				}
				break;




				//�����K�Ƃ̓����蔻��
				case StageObjectType::Brick:
				{
					
					player.FixPos(itr->mCol.getPosition());
				}
				break;


			}








		}
	}

}




//�f�X�g���N�^
Stage::~Stage()
{

}

