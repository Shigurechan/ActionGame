#include "Bullet.hpp"

//�R���X�g���N�^
Bullet::Bullet(glm::ivec2 pos , glm::ivec2 vec, int handle) : Actor(nullptr,pos,vec)
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
		//�����蔻��𒲐�
		glm::ivec2 pos = mPosition;
		pos.x += -(mSize.x / 2);
		pos.y += -(mSize.y / 2);
		mCol.setPosition(pos);
		mCol.setSize(mSize);
		mCol.setTrigger(false);
		mCol.setVector(mVector);


		mPosition.y += -mSpeed;
	}
	else if (mVector == VECTOR_DOWN) 
	{
		//�����蔻��𒲐�
		glm::ivec2 pos = mPosition;
		pos.x += -(mSize.x / 2);
		pos.y += -(mSize.y / 2);
		mCol.setPosition(pos);
		mCol.setSize(mSize);
		mCol.setTrigger(false);

		mPosition.y += mSpeed;

	}
	else if (mVector == VECTOR_LEFT)
	{
		//�����蔻��𒲐�
		glm::ivec2 pos = mPosition;
		pos.x += -(mSize.y / 2);
		pos.y += -(mSize.x / 2);
		mCol.setPosition(pos);
		glm::ivec2 size = glm::ivec2(mSize.y, mSize.x);
		mCol.setSize(size);
		mCol.setTrigger(false);




		mPosition.x += -mSpeed;

	}
	else if (mVector == VECTOR_RIGHT)
	{
		//�����蔻��𒲐�
		glm::ivec2 pos = mPosition;
		pos.x += -(mSize.y / 2);
		pos.y += -(mSize.x / 2);
		mCol.setPosition(pos);
		glm::ivec2 size = glm::ivec2(mSize.y, mSize.x);
		mCol.setSize(size);
		mCol.setTrigger(false);

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
