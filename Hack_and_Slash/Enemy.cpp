#include "Enemy.hpp"


//�R���X�g���N�^
Enemy::Enemy(int handle) : Actor(nullptr)
{
	mSprite = handle;
	//Rand_Action = GetRand(3);
	Rand_Action = 2;
	Prev_Rand_Action = 2;

	mPosition.x = SCREEN_WIDTH / 2;
	mPosition.y = SCREEN_HEIGHT / 2;
	mSpeed = 4;


	//�����蔻��
	mCol.setStageObjectType(StageObjectType::Enemy);

}

//�X�V
void Enemy::Update()
{
	
	//�����蔻��
	glm::ivec2 pos = mPosition;
	pos.y += -(CELL / 2 - 1);
	pos.x += -(CELL / 2 - 1);
	mCol.setPosition(pos);
	mCol.setSize(glm::ivec2(CELL - 1, CELL - 1));

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

	//�ړ�
	mPosition.x += mVector.x * mSpeed;
	mPosition.y += mVector.y * mSpeed;


}

//�ړ��������Đݒ�
void Enemy::setMove_Rand()
{
	//�Ⴄ�����������܂Ŗ������[�v
	while (true) {
		Rand_Action = GetRand(1);

		//���������������ĂȂ���
		if (Prev_Rand_Action != Rand_Action) {
			Prev_Rand_Action = Rand_Action;

			break;
		}
	}

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
