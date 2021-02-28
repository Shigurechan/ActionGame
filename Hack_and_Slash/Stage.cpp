#include "Stage.hpp"

//�R���X�g���N�^
Stage::Stage(Entry* e, int Block_Handle, int Brick_Handle, int Shop_Handle)
{
	Owner = e;
//	printf("screen X: %d\n", SCREEN_WIDTH / CELL);
//	printf("screen Y: %d\n",SCREEN_HEIGHT / CELL);

//	printf("stage X: %d\n", STAGE_WIDTH / CELL);
//	printf("stage Y: %d\n",STAGE_HEIGHT / CELL);

	mIsShop = false;	//�V���b�v�����ǂ����H
	mGameStart = false;

	//��ʂɕ`�悷��Z����
	mStageSize.x = STAGE_WIDTH / CELL;
	mStageSize.y = STAGE_HEIGHT / CELL;
	
	// ###### �X�v���C�g�����[�h

	//�u���b�N
	int Block_sprite = Block_Handle;
	glm::ivec2 BlockSize;	
	GetGraphSize(Block_sprite,&BlockSize.x, &BlockSize.y);	//�T�C�Y���擾

	//�����K
	int Brick_sprite = Brick_Handle;
	glm::ivec2 BrickSize;	
	GetGraphSize(Brick_sprite, &BrickSize.x, &BrickSize.y);	//�T�C�Y���擾

	//�V���b�v
	int Shop_sprite = Shop_Handle;
	glm::ivec2 ShopSize;
	GetGraphSize(Shop_sprite, &ShopSize.x, &ShopSize.y);	//�T�C�Y���擾





	// *** �X�e�[�W���[�h ***
	glm::ivec2 StageSize;	//��ʃT�C�Y
	FILE* fp = NULL;		//�t�@�C���|�C���^

	fopen_s(&fp,"sample.bin","rb");	//�ǂݍ��݃��[�h�Ńt�@�C�����J��
	byte Stage_Grid[STAGE_HEIGHT / CELL][STAGE_WIDTH / CELL];	//�X�e�[�W
	if (fp != NULL) {
		//�X�e�[�W�T�C�Y��ǂݍ���(�擪�W�o�C�g)
		fread(&StageSize.x, sizeof(int), 1, fp);
		fread(&StageSize.y, sizeof(int), 1, fp);

		for (int y = 0; y < (int)(STAGE_HEIGHT / CELL); y++)
		{
			for (int x = 0; x < (int)(STAGE_WIDTH / CELL); x++)
			{
				byte b = 0;
				fread(&b, sizeof(byte), 1, fp);
				if (b == 1)
				{
					Stage_Grid[y][x] = b;
				}
			}

		}
		fclose(fp);

	}
	else {
		printf("�t�@�C����ǂݍ��߂܂���B\n");
	}

	/*
	unsigned char Stage_Grid[STAGE_HEIGHT / CELL][STAGE_WIDTH / CELL] =
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,},
		{0,1,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	};
	*/

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

//�v���C���[�Ƃ̓����蔻��
void Stage::ColPlayer(std::shared_ptr<Player> player)
{
	for (std::vector<MapChip>::iterator itr = mStage.begin(); itr != mStage.end(); itr++)
	{
		if (Box_Collision::Intersect(itr->mCol,player->mCol) == true)
		{
			switch (itr->mCol.getObjectType())
			{
				//�V���b�v
				case StageObjectType::Shop:
				{
					if (Owner->InputKey->getKeyDown(KEY_INPUT_P) == true)
					{
						player->setIsMenu(true);
						player->FixPos(itr->mCol.getPosition());
					}
				}
				break;

				//�����K�Ƃ̓����蔻��
				case StageObjectType::Brick:
				{					
					player->FixPos(itr->mCol.getPosition());
				}
				break;

				//�u���b�N�Ƃ̓����蔻��
				case StageObjectType::Block:
				{
					
					player->FixPos(itr->mCol.getPosition());
				}
				break;
			}
		}
	}
}


//�o���b�g�Ƃ̓����蔻��
void Stage::ColPlayer_Bullet(std::shared_ptr<std::vector<Bullet>> bullet)
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


				//�u���b�N�Ƃ̓����蔻��
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
void Stage::Scroll(std::shared_ptr<Player> player, std::shared_ptr<std::vector<Enemy>> enemy, std::shared_ptr<std::vector<Bullet>> bullet)
{

#define SCROLL_OFFSET_X ((int)200)
#define SCROLL_OFFSET_Y ((int)200)


	//�ŏ��̃t���[���̎�
	if (mGameStart == false)
	{
		//X �␳
		if (player->mStagePosition.x > (SCREEN_WIDTH - SCROLL_OFFSET_X))
		{
			int p = player->mStagePosition.x - (SCREEN_WIDTH - SCROLL_OFFSET_X);

			for (std::vector<MapChip>::iterator itr = mStage.begin(); itr != mStage.end(); itr++)
			{
				glm::ivec2 pos;
				pos = itr->getPosition();
				pos.x += -p;
				itr->setPosition(pos);
			}	
		}

		//Y �␳
		if (player->mStagePosition.y > (SCREEN_HEIGHT - SCROLL_OFFSET_Y))
		{
			int p = player->mStagePosition.y - (SCREEN_HEIGHT - SCROLL_OFFSET_Y);
			//printf("%d\n",p);

			for (std::vector<MapChip>::iterator itr = mStage.begin(); itr != mStage.end(); itr++)
			{
				glm::ivec2 pos;
				pos = itr->getPosition();
				pos.y += -p;
				itr->setPosition(pos);
			}
		}
		mGameStart = true;
	}




	//���E�ړ�
	if (player->getPosition().x > (SCREEN_WIDTH - SCROLL_OFFSET_X) + player->getSpeed() && player->getVector() == VECTOR_RIGHT)
	{

		//�}�b�v�I�u�W�F�N�g���ړ�
		for (std::vector<MapChip>::iterator itr = mStage.begin(); itr != mStage.end(); itr++)
		{
			glm::ivec2 pos;
			pos = itr->getPosition();
			pos.x += -player->getSpeed();
			itr->setPosition(pos);
		}

		//�G�l�~�[���ړ�
		for (std::vector<Enemy>::iterator itr = enemy->begin(); itr != enemy->end(); itr++)
		{
			glm::ivec2 pos;
			pos = itr->getPosition();
			pos.x += -player->getSpeed();
			itr->setPosition(pos);
		}

		//�o���b�g���ړ�
		for (std::vector<Bullet>::iterator itr = bullet->begin(); itr != bullet->end(); itr++)
		{
			glm::ivec2 pos;
			pos = itr->getPosition();
			pos.x += -player->getSpeed();
			itr->setPosition(pos);
		}

		//�v���C���[���ړ����Ȃ�
		glm::ivec2 pos = player->getPosition();
		pos.x = player->getPosition().x - player->getSpeed();
		player->setPosition(pos);
	}
	else if (player->getPosition().x < (SCROLL_OFFSET_X) + player->getSpeed() && player->getVector() == VECTOR_LEFT)
	{

		//�}�b�v�I�u�W�F�N�g���ړ�
		for (std::vector<MapChip>::iterator itr = mStage.begin(); itr != mStage.end(); itr++)
		{
			glm::ivec2 pos;
			pos = itr->getPosition();
			pos.x += player->getSpeed();
			itr->setPosition(pos);
		}
		
		//�G�l�~�[���ړ�
		for (std::vector<Enemy>::iterator itr = enemy->begin(); itr != enemy->end(); itr++)
		{
			glm::ivec2 pos;
			pos = itr->getPosition();
			pos.x += player->getSpeed();
			itr->setPosition(pos);
		}

		//�o���b�g���ړ�
		for (std::vector<Bullet>::iterator itr = bullet->begin(); itr != bullet->end(); itr++)
		{
			glm::ivec2 pos;
			pos = itr->getPosition();
			pos.x += player->getSpeed();
			itr->setPosition(pos);
		}



		//�v���C���[���ړ����Ȃ�
		glm::ivec2 pos = player->getPosition();
		pos.x = player->getPosition().x + player->getSpeed();
		player->setPosition(pos);

		//�㉺�ړ�
	}else if (player->getPosition().y > (SCREEN_HEIGHT - SCROLL_OFFSET_Y) + player->getSpeed() && player->getVector() == VECTOR_DOWN)
	{
		//�}�b�v�I�u�W�F�N�g���ړ�
		for (std::vector<MapChip>::iterator itr = mStage.begin(); itr != mStage.end(); itr++)
		{	
			glm::ivec2 pos;
			pos = itr->getPosition();
			pos.y += -player->getSpeed();
			itr->setPosition(pos);
		}
		
		//�G�l�~�[���ړ�
		for (std::vector<Enemy>::iterator itr = enemy->begin(); itr != enemy->end(); itr++)
		{
			glm::ivec2 pos;
			pos = itr->getPosition();
			pos.y += -player->getSpeed();
			itr->setPosition(pos);

		}

		//�o���b�g���ړ�
		for (std::vector<Bullet>::iterator itr = bullet->begin(); itr != bullet->end(); itr++)
		{
			glm::ivec2 pos;
			pos = itr->getPosition();
			pos.y += -player->getSpeed();
			itr->setPosition(pos);
		}

		//�v���C���[���ړ����Ȃ�
		glm::ivec2 pos = player->getPosition();
		pos.y = player->getPosition().y - player->getSpeed();
		player->setPosition(pos);
	}
	else if (player->getPosition().y < (SCROLL_OFFSET_Y) + player->getSpeed() && player->getVector() == VECTOR_UP)
	{

		//�}�b�v�I�u�W�F�N�g���ړ�
		for (std::vector<MapChip>::iterator itr = mStage.begin(); itr != mStage.end(); itr++)
		{	
			glm::ivec2 pos;
			pos = itr->getPosition();
			pos.y += player->getSpeed();
			itr->setPosition(pos);
		}

		//�G�l�~�[���ړ�
		for (std::vector<Enemy>::iterator itr = enemy->begin(); itr != enemy->end(); itr++)
		{
			glm::ivec2 pos;
			pos = itr->getPosition();
			pos.y += player->getSpeed();
			itr->setPosition(pos);
		}


		//�o���b�g���ړ�
		for (std::vector<Bullet>::iterator itr = bullet->begin(); itr != bullet->end(); itr++)
		{
			glm::ivec2 pos;
			pos = itr->getPosition();
			pos.y += player->getSpeed();
			itr->setPosition(pos);
		}



		//�v���C���[���ړ����Ȃ�
		glm::ivec2 pos = player->getPosition();
		pos.y = player->getPosition().y + player->getSpeed();
		player->setPosition(pos);
	}
	else {
		
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
					itr->FixPos(chip.mCol.getPosition());	//���W���C��
					itr->setMove_Rand();					//�������Đݒ�
					itr->setMovePixel();					//�ړ��ʂ����Z�b�g
				}break;

					//�����K
				case StageObjectType::Brick:
				{
					itr->FixPos(chip.mCol.getPosition());	//���W���C��
					itr->setMove_Rand();					//�������Đݒ�
					itr->setMovePixel();					//�ړ��ʂ����Z�b�g

				}break;


				}
			}
		}
	}
}




//�G�l�~�[�̃o���b�g�Ƃ̓����蔻��
void Stage::ColEnemy_Bullet(std::shared_ptr<std::vector<Enemy>> enemy)
{
	//�G�l�~�[
	for (std::vector<Enemy>::iterator itr = enemy->begin(); itr != enemy->end(); itr++)
	{
		Enemy ene = *itr;

		//�o���b�g
		for (std::vector<Bullet>::iterator it = ene.getBullet()->begin(); it != ene.getBullet()->end(); it++)
		{
			Bullet b = *it;

			//�}�b�v�`�b�v
			for (std::vector<MapChip>::iterator i = mStage.begin(); i != mStage.end(); i++)
			{
				if (Box_Collision::Intersect(b.mCol, i->mCol) == true)
				{
					
					it->FixPos(i->mCol.getPosition());
					it->mIsHit = true;
				}
			}
		}
	}
}





//�f�X�g���N�^
Stage::~Stage()
{

}

