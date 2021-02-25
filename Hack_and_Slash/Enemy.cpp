#include "Enemy.hpp"


//�R���X�g���N�^
Enemy::Enemy(int handle, int Bullet_handle) : Actor(nullptr)
{
	//�X�v���C�g
	mSprite = handle;					//�G�l�~�[�n���h��
	mBullet_Sprite = Bullet_handle;		//�o���b�g�n���h��

	Rand_Action = GetRand(3);		//����
	Prev_Rand_Action = Rand_Action;	//�O�̗���
	MovePixel = 0;					//�ړ���

	// �������W
	mPosition.x = SCREEN_WIDTH / 2;
	mPosition.y = SCREEN_HEIGHT / 2 - CELL * 4;

	mSpeed = 10; //�X�s�[�h

	//�����蔻��
	mCol.setStageObjectType(StageObjectType::Enemy);


	bullet = std::make_shared<std::vector<Bullet>>();

}

//�X�V
void Enemy::Update()
{
	
	//�����蔻��
	glm::ivec2 pos = mPosition;
	pos.y += -(CELL / 2);
	pos.x += -(CELL / 2);
	mCol.setPosition(pos);
	mCol.setSize(glm::ivec2(CELL - 1, CELL - 1));

	Rand_Attack = GetRand(5);

	//����
	if (Rand_Action == 0)
	{
		mVector = VECTOR_UP;
	}
	else if (Rand_Action == 1)
	{
		mVector = VECTOR_RIGHT;
	}
	else if (Rand_Action == 2)
	{
		mVector = VECTOR_DOWN;
	}
	else if (Rand_Action == 3)
	{
		mVector = VECTOR_LEFT;
	}
	
	//�U��
	if (Rand_Attack == 1)
	{
	//	bullet->push_back(Bullet(mPosition,mVector,mBullet_sprite,mEffect_sprite));
	}




	MovePixel += mSpeed;	//�ړ��ʂɉ��Z
	if (MovePixel > CELL * 2)
	{
		setMove_Rand();
		MovePixel = 0;	//�ړ��ʂ����Z�b�g
	}



	//�ړ�
	mPosition.x += mVector.x * mSpeed;
	mPosition.y += mVector.y * mSpeed;


}

//�ړ��������Đݒ�
void Enemy::setMove_Rand()
{
	//�Ⴄ�����������܂Ŗ������[�v
	while (true) {
		Rand_Action = GetRand(3);

		//���������������ĂȂ���
		if (Prev_Rand_Action != Rand_Action) {
			Prev_Rand_Action = Rand_Action;

			break;
		}
	}

}

//�ړ��ʂ����Z�b�g
void Enemy::setMovePixel()
{
	MovePixel = 0;
}


//���W���C��
void Enemy::FixPos(glm::ivec2 pos)
{
	
	if (mVector == VECTOR_UP)
	{
		mPosition.y = pos.y + CELL + CELL / 2;
	}
	else if (mVector == VECTOR_DOWN)
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

//�`��
void Enemy::Draw()
{
	DrawRotaGraph(mPosition.x, mPosition.y, 1.0, 0, mSprite, true, false);

}


//�f�X�g���N�^
Enemy::~Enemy()
{

}
