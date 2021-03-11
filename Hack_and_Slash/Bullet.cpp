#include "Bullet.hpp"

//�R���X�g���N�^
Bullet::Bullet(glm::ivec2 pos , glm::ivec2 vec, int handle,int MapEffect_Handle[3], int EnemyEffect_Handle[3]) : Actor(nullptr,pos,vec),anim(2)
{
	GetGraphSize(handle,&mSize.x, &mSize.y);	//�X�v���C�g�̑傫��

	mSpeed = 8;		//�o���b�g�̑��x
	mSprite = handle;	//�X�v���C�g
	
	//�}�b�v�ƃq�b�g�������̃G�t�F�N�g
	mMapEffect_Sprite[0] = MapEffect_Handle[0];
	mMapEffect_Sprite[1] = MapEffect_Handle[1];
	mMapEffect_Sprite[2] = MapEffect_Handle[2];

	//�G�l�~�[�ƃq�b�g�������̃G�t�F�N�g
	mEnemyEffect_Sprite[0] = EnemyEffect_Handle[0];
	mEnemyEffect_Sprite[1] = EnemyEffect_Handle[1];
	mEnemyEffect_Sprite[2] = EnemyEffect_Handle[2];
	

	//����֌W��������
	mIsMapHit = false;
	mIsEnemyHit = false;
	mIsDelete = false;
}



//���W���C��
void Bullet::FixPos(glm::ivec2 pos)
{
	if (mVector == VECTOR_UP)
	{
		mPosition.y = pos.y + (CELL);
	}
	else if (mVector == VECTOR_DOWN)
	{
		mPosition.y = pos.y;
	}
	else if (mVector == VECTOR_LEFT)
	{
		mPosition.x = pos.x + (CELL);
	}
	else if (mVector == VECTOR_RIGHT)
	{
		mPosition.x = pos.x;		
	}
}




//�X�V
void Bullet::Update()
{
	//�o���b�g�̒e��
	if (mIsMapHit == false && mIsEnemyHit == false) {
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



}

//�`��
void Bullet::Draw()
{
	//�o���b�g���ړ�
	
	if (mIsMapHit == false && mIsEnemyHit == false) 
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
	else if (mIsMapHit == true) 
	{
		//�}�b�v�@�q�b�g�G�t�F�N�g

		int num = 0;
		if (anim.getClip(num, BULLET_EFFECT_SPEED) == false) {
			DrawRotaGraph(mPosition.x, mPosition.y, 1.0, 0, mMapEffect_Sprite[num], true, false);
		}
		else
		{
			mIsDelete = true;
		}
	}
	else if (mIsEnemyHit == true)
	{
		//�G�l�~�[�@�q�b�g�G�t�F�N�g

		int num = 0;
		if (anim.getClip(num, BULLET_EFFECT_SPEED) == false) {
			DrawRotaGraph(mPosition.x, mPosition.y, 1.0, 0, mEnemyEffect_Sprite[num], true, false);
		}
		else
		{
			mIsDelete = true;
		}
	}






}

//�f�X�g���N�^
Bullet::~Bullet()
{

}
