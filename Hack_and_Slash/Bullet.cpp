#include "Bullet.hpp"

//�R���X�g���N�^
Bullet::Bullet(glm::ivec2 pos , glm::ivec2 vec, int handle) : Actor(pos,vec)
{
	GetGraphSize(handle,&mSize.x, &mSize.y);	//�X�v���C�g�̑傫��

	mSpeed = 10;		//�o���b�g�̑��x
	mSprite = handle;	//�X�v���C�g
}

//�X�V
void Bullet::Update()
{

	//�@�ړ�
	if (mVector == VECTOR_UP)
	{
		mPosition.y += -mSpeed;
	}
	else if (mVector == VECTOR_DOWN) 
	{
		mPosition.y += mSpeed;

	}
	else if (mVector == VECTOR_LEFT)
	{
		mPosition.x += -mSpeed;

	}
	else if (mVector == VECTOR_RIGHT)
	{
		mPosition.x += mSpeed;
	}

}

//�`��
void Bullet::Draw()
{
	//�`�����
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
		DrawRotaGraph(mPosition.x, mPosition.y, 1.0, -(PI * 2) / 4, mSprite, true, true);
	}
	else if (mVector == VECTOR_RIGHT)
	{
		DrawRotaGraph(mPosition.x, mPosition.y, 1.0, (PI * 2) / 4, mSprite, true, true);
	}
}

//�f�X�g���N�^
Bullet::~Bullet()
{

}
