#include "Bullet.hpp"

//�R���X�g���N�^
Bullet::Bullet(glm::ivec2 pos , glm::ivec2 vec, int handle,int MapEffect_Handle[3], int EnemyEffect_Handle[3]) : Actor(nullptr,pos,vec),anim(2)
{
	GetGraphSize(handle,&mSize.x, &mSize.y);	//�X�v���C�g�̑傫��

	mSpeed = 8;		//�o���b�g�̑��x
	mSprite = handle;	//�X�v���C�g
	isDelete = false;	//�폜���邩�ǂ����H

	//�}�b�v�ƃq�b�g�������̃G�t�F�N�g
	mMapEffect_Sprite[0] = MapEffect_Handle[0];
	mMapEffect_Sprite[1] = MapEffect_Handle[1];
	mMapEffect_Sprite[2] = MapEffect_Handle[2];

	//�G�l�~�[�ƃq�b�g�������̃G�t�F�N�g
	mEnemyEffect_Sprite[0] = EnemyEffect_Handle[0];
	mEnemyEffect_Sprite[1] = EnemyEffect_Handle[1];
	mEnemyEffect_Sprite[2] = EnemyEffect_Handle[2];



	mIsHit = false;			//�}�b�v�ƃq�b�g�������ǂ����H
	mIsEnemyHit = false;	//�G�l�~�[�ƃq�b�g�������ǂ����H
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
	if (mIsHit == false && mIsEnemyHit == false) {
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
	if (mIsHit == false && mIsEnemyHit == false) {
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

	//�}�b�v�ƃq�b�g
	else if(mIsHit == true) 
	{
		//�q�b�g�G�t�F�N�g
		int num = 0;
		if (anim.getClip(num, BULLET_EFFECT_SPEED) == false) {
			DrawRotaGraph(mPosition.x, mPosition.y, 1.0, 0, mMapEffect_Sprite[num], true, false);
		}
		else 
		{
			isDelete = true;
		}
	}


	//�G�l�~�[�ƃq�b�g
	else if (mIsEnemyHit == true)
	{
		//printf("������\n");
		//�q�b�g�G�t�F�N�g
		int num = 0;
		if (anim.getClip(num, BULLET_EFFECT_SPEED) == false) {
			DrawRotaGraph(mPosition.x, mPosition.y, 1.0, 0, mEnemyEffect_Sprite[num], true, false);
		}
		else
		{
			isDelete = true;
		}
	}






}

//�f�X�g���N�^
Bullet::~Bullet()
{

}
