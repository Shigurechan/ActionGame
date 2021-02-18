#include "Player.hpp"

//�R���X�g���N�^
Player::Player() : Actor()
{
	mSprite = LoadGraph("Assets/Player.png");			//�v���C���[�X�v���C�g
	mBullet_Sprite = LoadGraph("Assets/Bullet.png");	//�o���b�g�X�v���C�g

	GetGraphSize(mSprite, &mSize.x, &mSize.y);	//�T�C�Y��ݒ�
	//printf("size X: %d\n", mSize.x);
	//printf("size Y: %d\n", mSize.y);




	mInput = std::make_shared<Input>();	//�L�[����
	
	//�������W
	mPosition.x = SCREEN_WIDTH / 2;
	mPosition.y = SCREEN_HEIGHT / 2;

	mVector = VECTOR_UP;	//��������


	mMenu = false;	//�V���b�v���J�����ǂ����H



}

//���W���C��
void Player::FixPos(glm::ivec2 pos)
{
	if (mVector == VECTOR_UP)
	{
		mPosition.y = pos.y + CELL + CELL / 2;
	}else if (mVector == VECTOR_DOWN)
	{
		mPosition.y = pos.y - (CELL / 2);
	}
	else if (mVector == VECTOR_LEFT)
	{
		mPosition.x = pos.x + (CELL + CELL / 2);
	}
	else if (mVector == VECTOR_RIGHT)
	{
		mPosition.x = pos.x - (CELL / 2);
	}


}



//�o���b�g�@�X�V
void Player::Bullet_Update()
{
	// �U���@�o���b�g
	if (mInput->getKeyDown(KEY_INPUT_SPACE) == true)
	{
		mBullet.push_back(Bullet(mPosition, mVector, mBullet_Sprite));
	}

	//�o���b�g���X�V
	for (std::vector<Bullet>::iterator itr = mBullet.begin(); itr != mBullet.end(); itr++)
	{
		itr->Update();
	}
}

//�X�V
void Player::Update()
{
	Bullet_Update();	//�o���b�g���X�V
	mInput->Update();	//�L�[���͂��X�V
	Player_Update();	//�v���C���[�X�V	
}

//�v���C���[�@�X�V
void Player::Player_Update()
{
	//printf("��������\n");

	

	//�L�[����
	if (mInput->getKeyDownHold(KEY_INPUT_LEFT) > 0)
	{
		mVector = VECTOR_LEFT;	//����
		mSpeed = SPEED;
		mPosition.x += -mSpeed;

	}
	else if (mInput->getKeyDownHold(KEY_INPUT_RIGHT) > 0)
	{
		mVector = VECTOR_RIGHT;	//����
		mSpeed = SPEED;
		mPosition.x += mSpeed;

	}
	else if (mInput->getKeyDownHold(KEY_INPUT_UP) > 0)
	{
		mVector = VECTOR_UP;	//����
		mSpeed = SPEED;
		mPosition.y += -mSpeed;

	}
	else if (mInput->getKeyDownHold(KEY_INPUT_DOWN) > 0)
	{
		mVector = VECTOR_DOWN;	//����
		mSpeed = SPEED;
		mPosition.y += mSpeed;
	}
	else {
		mSpeed = 0;
	}

	//�����蔻��

	//�X�v���C�g�̒��S����̂��ߏC��
	glm::ivec2 pos = mPosition;
	pos.x += -(CELL / 2);
	pos.y += -(CELL / 2);
	mCol.setPosition(pos);
	mCol.setSize(mSize);
	mCol.setTrigger(false);
	mCol.setVector(mVector);


}

//�`��
void Player::Draw()
{
	Bullet_Draw();	//�o���b�g�`��
	Player_Draw();	//�v���C���[�`��
}


//�v���C���[�@�`��
void Player::Player_Draw()
{
	//����
	if (mVector == VECTOR_UP)
	{
		DrawRotaGraph(mPosition.x, mPosition.y, 1.0, 0, mSprite, true, false);
	}
	else if (mVector == VECTOR_DOWN)
	{
		DrawRotaGraph(mPosition.x, mPosition.y, 1.0, PI, mSprite, true, false);
	}
	else if (mVector == VECTOR_LEFT)
	{
		DrawRotaGraph(mPosition.x, mPosition.y, 1.0, -(PI * 2) / 4, mSprite, true, false);
	}
	else if (mVector == VECTOR_RIGHT)
	{
		DrawRotaGraph(mPosition.x, mPosition.y, 1.0, (PI * 2) / 4, mSprite, true, false);
	}

	DrawPixel(mPosition.x, mPosition.y,GetColor(0,255,0));
}


//�o���b�g�@�`��
void Player::Bullet_Draw()
{
	for (std::vector<Bullet>::iterator itr = mBullet.begin(); itr != mBullet.end(); itr++)
	{
		itr->Draw();
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





//�f�X�g���N�^
Player::~Player()
{

}
