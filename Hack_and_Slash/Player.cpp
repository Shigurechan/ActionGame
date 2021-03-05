#include "Player.hpp"

//�R���X�g���N�^
Player::Player(Entry* e, int Player_Handle, int Player_Bullet_Handle, int Enemy_HitEffect_Handle[3], int Stage_HitEffect_Handle[3]) : Actor(e)
{


	mPlayer_sprite = Player_Handle;

	mPlayer_Bullet_sprite = Player_Bullet_Handle;
	

	mEnemy_HitEffect_sprite[0] = Enemy_HitEffect_Handle[0];
	mEnemy_HitEffect_sprite[1] = Enemy_HitEffect_Handle[1];
	mEnemy_HitEffect_sprite[2] = Enemy_HitEffect_Handle[2];


	mStage_HitEffect_sprite[0] = Stage_HitEffect_Handle[0];
	mStage_HitEffect_sprite[1] = Stage_HitEffect_Handle[1];
	mStage_HitEffect_sprite[2] = Stage_HitEffect_Handle[2];





	
	mBullet = std::make_shared<std::vector<Bullet>>();

	GetGraphSize(mPlayer_sprite, &mSize.x, &mSize.y);	//�T�C�Y��ݒ�
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
	mStagePosition.y = STAGE_HEIGHT / 50 *20 ;



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

//�G�l�~�[�̃o���b�g�Ƃ̓����蔻��
void Player::ColEnemy_Bullet(std::shared_ptr<std::vector<Enemy>> Enemy_Bullet)
{
	//�G�l�~�[
	for (std::vector<Enemy>::iterator itr = Enemy_Bullet->begin(); itr != Enemy_Bullet->end(); itr++)
	{
		
		//�o���b�g
		for (std::vector<Bullet>::iterator it = itr->getBullet()->begin(); it != itr->getBullet()->end(); it++)
		{
			
			if (Box_Collision::Intersect(mCol, it->mCol) == true)
			{

				it->FixPos(mCol.getPosition());
				it->mIsEnemyHit = true;
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
	Bullet_Update();	//�o���b�g���X�V
	Player_Update();	//�v���C���[�X�V
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
	}
	else if (Owner->InputKey->getKeyDownHold(KEY_INPUT_RIGHT) > 0)
	{
	//	printf("RIGHT\n");
		mVector = VECTOR_RIGHT;	//����
	}
	else if (Owner->InputKey->getKeyDownHold(KEY_INPUT_UP) > 0)
	{
	//	printf("UP\n");
		mVector = VECTOR_UP;	//����
	}
	else if (Owner->InputKey->getKeyDownHold(KEY_INPUT_DOWN) > 0)
	{
	//	printf("DOWN\n");
		mVector = VECTOR_DOWN;	//����
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
}

//���x��ݒ�
void Player::setSpeed(int speed)
{
	mSpeed = speed;
}



//�v���C���[�@�`��
void Player::Player_Draw()
{
	//����
	if (mVector == VECTOR_UP)
	{
		DrawRotaGraph(mPosition.x, mPosition.y, 1.0, 0, mPlayer_sprite, true, false);
	}
	else if (mVector == VECTOR_DOWN)
	{
		DrawRotaGraph(mPosition.x, mPosition.y, 1.0, PI, mPlayer_sprite, true, false);
	}
	else if (mVector == VECTOR_LEFT)
	{
		DrawRotaGraph(mPosition.x, mPosition.y, 1.0, -(PI * 2) / 4, mPlayer_sprite, true, false);
	}
	else if (mVector == VECTOR_RIGHT)
	{
		DrawRotaGraph(mPosition.x, mPosition.y, 1.0, (PI * 2) / 4, mPlayer_sprite, true, false);
	}

	//DrawPixel(mPosition.x, mPosition.y,GetColor(0,255,0));
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
