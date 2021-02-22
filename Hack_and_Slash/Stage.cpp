#include "Stage.hpp"

//�R���X�g���N�^
Stage::Stage(Entry* e)
{
	Owner = e;
//	printf("screen X: %d\n", SCREEN_WIDTH / CELL);
//	printf("screen Y: %d\n",SCREEN_HEIGHT / CELL);

//	printf("stage X: %d\n", STAGE_WIDTH / CELL);
//	printf("stage Y: %d\n",STAGE_HEIGHT / CELL);

	mIsShop = false;	//�V���b�v�����ǂ����H


	//��ʂɕ`�悷��Z����
	mStageSize.x = STAGE_WIDTH / CELL;
	mStageSize.y = STAGE_HEIGHT / CELL;
	
	// ###### �X�v���C�g�����[�h

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
	unsigned char Stage_Grid[STAGE_HEIGHT / CELL][STAGE_WIDTH / CELL] =
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,2,0,0,0,2,0,0,0},
		{0,0,0,0,0,0,3,0,0,1,0,0,0,0,0,0,2,2,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,1,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},	
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//�v���C���[�Ƃ̓����蔻��
void Stage::ColPlayer(Player &player)
{
	for (std::vector<MapChip>::iterator itr = mStage.begin(); itr != mStage.end(); itr++)
	{
		if (Box_Collision::Intersect(itr->mCol,player.mCol) == true)
		{
			switch (itr->mCol.getObjectType())
			{
				//�V���b�v
				case StageObjectType::Shop:
				{
					if (Owner->InputKey->getKeyDown(KEY_INPUT_P) == true)
					{
						player.setIsMenu(true);
						player.FixPos(itr->mCol.getPosition());
					}
				}
				break;

				//�����K�Ƃ̓����蔻��
				case StageObjectType::Brick:
				{					
					player.FixPos(itr->mCol.getPosition());
				}
				break;

				//�u���b�N�Ƃ̓����蔻��
				case StageObjectType::Block:
				{
					
					player.FixPos(itr->mCol.getPosition());
				}
				break;
			}
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//�o���b�g�Ƃ̓����蔻��
void Stage::ColBullet(std::shared_ptr<std::vector<Bullet>> bullet)
{
	for (std::vector<MapChip>::iterator itr = mStage.begin(); itr != mStage.end(); itr++)
	{
		MapChip chip = *itr;	//�}�b�v�`�b�v
		for (std::vector<Bullet>::iterator b = bullet->begin(); b != bullet->end();)
		{
			if (Box_Collision::Intersect(chip.mCol, b->mCol) == true)
			{

				switch (chip.mCol.getObjectType())
				{
					//�����K�Ƃ̓����蔻��
				case StageObjectType::Brick:
				{
					chip.HP += -1;	//�ϋv�l�����炷
					if (chip.HP < 0)
					{
						itr = mStage.erase(itr);	//�q�b�g�����u���b�N������
					}

					b->mIsHit = true;	//�q�b�g�G�t�F�N�g���Đ�
					b->FixPos(chip.mCol.getPosition());	//�o���b�g�̍��W���C��	
				}
				break;


				//�����K�Ƃ̓����蔻��
				case StageObjectType::Block:
				{
					b->mIsHit = true;	//�q�b�g�G�t�F�N�g���Đ�
					b->FixPos(chip.mCol.getPosition());	//�o���b�g�̍��W���C��	
				}
				break;


				}
			}

			//�q�b�g�G�t�F�N�g���Đ����ꂽy�v�f���폜
			if (b->isDelete == true)
			{
				b = bullet->erase(b);
		//		printf("�o���b�g�폜\n");
			}
			else {
				b++;
			}
		}
	}
}

//��ʃX�N���[��
void Stage::ScrollMap(Player& player)
{
	//���E�ړ�
	if (player.getPosition().x > (SCREEN_WIDTH - 100) + player.getSpeed() && player.getVector() == VECTOR_RIGHT) {
		//printf("Right\n");

		for (std::vector<MapChip>::iterator itr = mStage.begin(); itr != mStage.end(); itr++)
		{
		
			glm::ivec2 pos;
			pos = itr->getPosition();
			pos.x += -player.getSpeed();

			itr->setPosition(pos);
		}
	}
	else if (player.getPosition().x < ( 100 ) + player.getSpeed() && player.getVector() == VECTOR_LEFT)
	{
		//printf("Left\n");
		for (std::vector<MapChip>::iterator itr = mStage.begin(); itr != mStage.end(); itr++)
		{
			glm::ivec2 pos;
			pos = itr->getPosition();
			pos.x += player.getSpeed();

			itr->setPosition(pos);
		}

		//�㉺�ړ�
	}else if (player.getPosition().y > (SCREEN_HEIGHT - 100) + player.getSpeed() && player.getVector() == VECTOR_DOWN) {
		//printf("Dwon\n");

		for (std::vector<MapChip>::iterator itr = mStage.begin(); itr != mStage.end(); itr++)
		{

			glm::ivec2 pos;
			pos = itr->getPosition();
			pos.y += -player.getSpeed();

			itr->setPosition(pos);
		}
	}
	else if (player.getPosition().y < (100) + player.getSpeed() && player.getVector() == VECTOR_UP)
	{
		//printf("Up\n");
		for (std::vector<MapChip>::iterator itr = mStage.begin(); itr != mStage.end(); itr++)
		{
			glm::ivec2 pos;
			pos = itr->getPosition();
			pos.y += player.getSpeed();

			itr->setPosition(pos);
		}
	}
	else {


		//�ړ�
		int speed = player.getSpeed();
		glm::ivec2 vec = player.getVector();
		glm::ivec2 pos = player.getPosition();
		pos.x += vec.x * speed;
		pos.y += vec.y * speed;

		player.setPosition(pos);
	}
}

//�G�l�~�[�Ƃ̓����蔻��
void Stage::ColEnemy(std::shared_ptr<std::vector<Enemy>> enemy)
{
	for (std::vector<MapChip>::iterator itr = mStage.begin(); itr != mStage.end(); itr++)
	{
		MapChip chip = *itr;
		for (std::vector<Enemy>::iterator itr = enemy->begin(); itr != enemy->end(); itr++)
		{
			//��������
			if (Box_Collision::Intersect(chip.mCol, itr->mCol) == true )
			{
				switch (chip.mCol.getObjectType())
				{

					//�u���b�N
				case StageObjectType::Block:
				{
					itr->FixPos(chip.mCol.getPosition());
					itr->setMove_Rand();
				}


				}
			}
		}
	}

}






//�f�X�g���N�^
Stage::~Stage()
{

}

