#include "Player.hpp"
#include "Enemy_Mng.hpp"

#include <iostream>
#include <vector>

#include "Entry.hpp"
#include "Entry.hpp"
#include "Input.hpp"
#include "Collision.hpp"






//�R���X�g���N�^
Player::Player(Entry* e, int Player_Handle[8], int Player_Bullet_Handle, int Enemy_HitEffect_Handle[3], int Stage_HitEffect_Handle[3]) : Actor(e),anim(1)
{

	//�v���C���[���@�̃X�v���C�g
	mPlayer_sprite_Up[0] = Player_Handle[0];
	mPlayer_sprite_Up[1] = Player_Handle[1];

	mPlayer_sprite_Left[0] = Player_Handle[2];
	mPlayer_sprite_Left[1] = Player_Handle[3];

	mPlayer_sprite_Down[0] = Player_Handle[4];
	mPlayer_sprite_Down[1] = Player_Handle[5];

	mPlayer_sprite_Right[0] = Player_Handle[6];
	mPlayer_sprite_Right[1] = Player_Handle[7];



	mPlayer_Bullet_sprite = Player_Bullet_Handle;
	
	mEnemy_HitEffect_sprite[0] = Enemy_HitEffect_Handle[0];
	mEnemy_HitEffect_sprite[1] = Enemy_HitEffect_Handle[1];
	mEnemy_HitEffect_sprite[2] = Enemy_HitEffect_Handle[2];

	mStage_HitEffect_sprite[0] = Stage_HitEffect_Handle[0];
	mStage_HitEffect_sprite[1] = Stage_HitEffect_Handle[1];
	mStage_HitEffect_sprite[2] = Stage_HitEffect_Handle[2];

	
	mBullet = std::make_shared<std::vector<Bullet>>();

	GetGraphSize(mPlayer_sprite_Up[0], &mSize.x, &mSize.y);	//�T�C�Y��ݒ�
	//printf("size X: %d\n", mSize.x);
	//printf("size Y: %d\n", mSize.y);

	mSpeed = 0;
	mSpeed_Max = 10;	//�ő呬�x


	//�������W
	
	//�X�N���[�����W
	mPosition.x = SCREEN_WIDTH / 2;		
	mPosition.y = SCREEN_HEIGHT / 2;

	//�X�e�[�W���W
	mStagePosition.x = STAGE_WIDTH / 2;
	mStagePosition.y = STAGE_HEIGHT / 50 * 20;

	stagePosition = mStagePosition;	//�X�e�[�W�����W


	mVector = VECTOR_UP;	//��������
	mMenu = false;			//�V���b�v���J�����ǂ����H
}

//���W���C��
void Player::FixPos(glm::ivec2 pos)
{
	if (mVector == VECTOR_UP)
	{
//		printf("UP\n"); 
		mPosition.y = pos.y + CELL + CELL / 2;
	}
	else if (mVector == VECTOR_DOWN)
	{
//		printf("DOWN\n");

		mPosition.y = pos.y - (CELL / 2);
	}
	else if (mVector == VECTOR_LEFT)
	{
//		printf("LEFT\n");

		mPosition.x = pos.x + (CELL + CELL / 2);
	}
	else if (mVector == VECTOR_RIGHT)
	{
//		printf("RIGHT\n");

		mPosition.x = pos.x - (CELL / 2);
	}
	else {
//		printf("None\n");
	}
}

//���W���J�n�n�_�ɖ߂��B
void Player::setReset()
{
	//�X�N���[�����W
	mPosition.x = SCREEN_WIDTH / 2;
	mPosition.y = SCREEN_HEIGHT / 2;

	//�X�e�[�W���W
	mStagePosition.x = STAGE_WIDTH / 2;
	mStagePosition.y = STAGE_HEIGHT / 50 * 20;

	stagePosition = mStagePosition;	//�X�e�[�W���W�Ə������W����v������B
}

//�ʒu�̃I�t�Z�b�g���W���C��
void Player::OffsetFixPos(glm::ivec2 pos)
{
#define OFFSET 20

	//�@��A��
	if (mVector == VECTOR_UP || mVector == VECTOR_DOWN)
	{
//
		//printf("VECTOR_UP , VECTOR_DOWN\n");
		//		printf("player: %d\n",mPosition.x);
		//		printf("block: %d\n",pos.x);

		int PB = (mPosition.x - (CELL / 2)) - pos.x;	//�ǂ��������邩�H

		if (PB > 0)
		{
//			printf("Right: %d\n", PB);

			int cp = CELL - PB; // �߂荞�ݗ�
//			printf("�߂肱�ݗʁ@cp: %d\n", cp);

			if (cp < OFFSET)
			{
//				printf("Right �C��\n");
				mPosition.x = pos.x + CELL + (CELL / 2);
			}
		}
		else if (PB < 0)
		{
//			printf("Left: %d\n", PB);

			int cp = CELL - std::abs(PB); // �߂荞�ݗ�
//			printf("�߂肱�ݗʁ@cp: %d\n", cp);

			if (cp < OFFSET)
			{
//				printf("Left �C��\n");
				mPosition.x = pos.x - CELL + (CELL / 2);
			}
		}
	}	
	else if (mVector == VECTOR_LEFT || mVector == VECTOR_RIGHT)
	{
		//���E

//		printf("VECTOR_LEFT , VECTOR_RIGHT\n");
		//		printf("player: %d\n",mPosition.x);
		//		printf("block: %d\n",pos.x);

		int PB = (mPosition.y - (CELL / 2)) - pos.y;	//�ǂ��������邩�H

		if (PB > 0)
		{
//			printf("down: %d\n", PB);

			int cp = CELL - PB; // �߂荞�ݗ�
//			printf("�߂肱�ݗʁ@cp: %d\n", cp);

			if (cp < OFFSET)
			{
//				printf("down �C��\n");
				mPosition.y = pos.y + CELL + (CELL / 2);
			}
		}
		else if (PB < 0)
		{
//			printf("Up: %d\n", PB);

			int cp = CELL - std::abs(PB); // �߂荞�ݗ�
//			printf("�߂肱�ݗʁ@cp: %d\n", cp);

			if (cp < OFFSET)
			{
//				printf("Up �C��\n");
				mPosition.y = pos.y - CELL + (CELL / 2);
			}
		}
	}
#undef OFFSET
}



//�G�l�~�[�̃o���b�g�Ƃ̓����蔻��
void Player::ColEnemy_Bullet(std::shared_ptr<Enemy_Mng> enemy)
{
	//�G�l�~�[
	for (std::vector<Enemy>::iterator itr = enemy->getEnemy()->begin(); itr != enemy->getEnemy()->end(); itr++)
	{	
		//�o���b�g
		for (std::vector<Bullet>::iterator it = itr->getBullet()->begin(); it != itr->getBullet()->end(); it++)
		{
			//��������	
			if (Box_Collision::Intersect(mCol, it->mCol) == true)
			{

				it->FixPos(mCol.getPosition());	//���W�C��
				it->mIsEnemyHit = true;			//�G�l�~�[�ƃq�b�g
			}
		}
	}
}




//�o���b�g�@�X�V
void Player::Bullet_Update()
{
	// �U���@�o���b�g
	if (Owner->InputKey->getKeyDown(KEY_INPUT_SPACE) == true)
	{
		//printf("�U��\n");
		mBullet->push_back(Bullet(mPosition, mVector, mPlayer_Bullet_sprite, mStage_HitEffect_sprite, mEnemy_HitEffect_sprite));
	}

	//�o���b�g���X�V
	for (std::vector<Bullet>::iterator itr = mBullet->begin(); itr != mBullet->end(); itr++)
	{
		//printf("�o���b�g�X�V\n");

		itr->Update();
	}
}


int Player::getSpeed()
{
	return mSpeed;
}

//�X�V
void Player::Update()
{
	DrawFormatString(0,0,GetColor(0,255,0),"Position: %d , %d ",mPosition.x,mPosition.y);



	//printf("%d\n",mSpeed_Max);

	Player_Update();	//�v���C���[�X�V
	Bullet_Update();	//�o���b�g���X�V
}

//�X�e�[�^�X��ݒ�
void Player::set_Bulid(ItemData data)
{

	mSpeed_Max += data.mSpeed_Max;

	HP_Max += data.HP_Max;
	HP += data.HP_Rec;			
	HP_autoRec += data.HP_autoRec;

	Attack += data.Attack;

	Coin += data.Coin;

}





//�v���C���[�@�X�V
void Player::Player_Update()
{
	//printf("��������\n");

	
	mSpeed = mSpeed_Max;
	//�L�[����
	if (Owner->InputKey->getKeyDownHold(KEY_INPUT_LEFT) > 0)
	{
	//	printf("LEFT\n");
		mVector = VECTOR_LEFT;	//����
		stagePosition.x -= mSpeed;
	}
	else if (Owner->InputKey->getKeyDownHold(KEY_INPUT_RIGHT) > 0)
	{
	//	printf("RIGHT\n");
		mVector = VECTOR_RIGHT;	//����
		stagePosition.x += mSpeed;

	}
	else if (Owner->InputKey->getKeyDownHold(KEY_INPUT_UP) > 0)
	{
	//	printf("UP\n");
		mVector = VECTOR_UP;	//����
		stagePosition.y -= mSpeed;

	}
	else if (Owner->InputKey->getKeyDownHold(KEY_INPUT_DOWN) > 0)
	{
	//	printf("DOWN\n");
		mVector = VECTOR_DOWN;	//����
		stagePosition.y += mSpeed;

	}
	else {
		mSpeed = 0;
	}



	mPosition += mVector * mSpeed;


	//�����蔻��

	//�X�v���C�g�̒��S����̂��ߏC��
	glm::ivec2 pos = mPosition;
	pos.x += -(CELL / 2);
	pos.y += -(CELL / 2);
	mCol.setPosition(pos);
	mCol.setSize(mSize - 1);
	mCol.setTrigger(false);
	mCol.setVector(mVector);


}

//�`��
void Player::Draw()
{
	Bullet_Draw();	//�o���b�g�`��
	Player_Draw();	//�v���C���[�`��

	// �f�o�b�O�`��
	DrawFormatString(0,32,GetColor(255,255,255),"# Position: %d , %d  ",stagePosition.x,stagePosition.y);


}

//���x��ݒ�
void Player::setSpeed(int speed)
{
	mSpeed = speed;
}



//�v���C���[�@�`��
void Player::Player_Draw()
{
#define ANIMETION_SPEED 5

	printf("%d\n",anim.getClip_loop(ANIMETION_SPEED));

	//����
	if (mVector == VECTOR_UP)
	{
		if (mSpeed != 0)
		{
			DrawRotaGraph(mPosition.x, mPosition.y, 1.0, 0, mPlayer_sprite_Up[anim.getClip_loop(ANIMETION_SPEED)], true, false);
		}
		else {
			DrawRotaGraph(mPosition.x, mPosition.y, 1.0, 0, mPlayer_sprite_Up[0], true, false);

		}
	}
	else if (mVector == VECTOR_DOWN)
	{
		if (mSpeed != 0)
		{
			DrawRotaGraph(mPosition.x, mPosition.y, 1.0, 0, mPlayer_sprite_Down[anim.getClip_loop(ANIMETION_SPEED)], true, false);
		}
		else {
			DrawRotaGraph(mPosition.x, mPosition.y,1.0, 0, mPlayer_sprite_Down[0], true, false);

		}

		//DrawRotaGraph(mPosition.x, mPosition.y, 1.0, PI, mPlayer_sprite, true, false);
	}
	else if (mVector == VECTOR_LEFT)
	{
		

		if (mSpeed != 0)
		{
			DrawRotaGraph(mPosition.x, mPosition.y, 1.0, 0, mPlayer_sprite_Left[anim.getClip_loop(ANIMETION_SPEED)], true, false);
		}
		else {
			DrawRotaGraph(mPosition.x, mPosition.y, 1.0, 0, mPlayer_sprite_Left[0], true, false);

		}



		//DrawRotaGraph(mPosition.x, mPosition.y, 1.0, -(PI * 2) / 4, mPlayer_sprite, true, false);
	}
	else if (mVector == VECTOR_RIGHT)
	{

		if (mSpeed != 0)
		{
			DrawRotaGraph(mPosition.x, mPosition.y, 1.0, 0, mPlayer_sprite_Right[anim.getClip_loop(ANIMETION_SPEED)], true, false);
		}
		else {
			DrawRotaGraph(mPosition.x, mPosition.y, 1.0, 0, mPlayer_sprite_Right[0], true, false);

		}




		//DrawRotaGraph(mPosition.x, mPosition.y, 1.0, (PI * 2) / 4, mPlayer_sprite, true, false);
	}

	//DrawPixel(mPosition.x, mPosition.y,GetColor(0,255,0));

#undef ANIMETION_SPEED
}


//�o���b�g�@�`��
void Player::Bullet_Draw()
{
	for (std::vector<Bullet>::iterator itr = mBullet->begin(); itr != mBullet->end(); itr++)
	{		
		//printf("�o���b�g�X�V\n");
		itr->Draw();	//�o���b�g�`��		
	}
}



//�V���b�v��ʂ��J�����ǂ����H
bool Player::getIsMenu()
{
	return mMenu;
}

//�V���b�v��ʂ��J�����ǂ����H
void Player::setIsMenu(bool b)
{
	mMenu = b;
}

//�o���b�g���擾
std::shared_ptr<std::vector<Bullet>> Player::getBullet()
{
	return mBullet;
}



//�f�X�g���N�^
Player::~Player()
{

}
