#include "MapChip.hpp"

//�R���X�g���N�^
MapChip::MapChip(StageObjectType t, glm::ivec2 pos, glm::ivec2 size,int handle) : Actor(nullptr)
{


	//printf("size X : %d\n", mSize.x);
	//printf("size Y : %d\n",mSize.y);


	mPosition = pos;	//���W
	mSize = size;		//�T�C�Y
	mSprite = handle;	//�X�v���C�g
	HP = 3;				//�ϋv�l


	//�����蔻��
	mCol.setPosition(mPosition);
	mCol.setSize(mSize - 1);
	mCol.setTrigger(true);
	mCol.setStageObjectType(t);



}


void MapChip::Update()
{
	//�����蔻��
	mCol.setPosition(mPosition);
	//mCol.setSize(mSize - 1);
	mCol.setTrigger(true);
	

}

void MapChip::Draw()
{
	DrawGraph(mPosition.x, mPosition.y,mSprite,true);
}


//�f�X�g���N�^
MapChip::~MapChip()
{

}
