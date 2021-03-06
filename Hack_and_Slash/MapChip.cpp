#include "MapChip.hpp"

//コンストラクタ
MapChip::MapChip(StageObjectType t, glm::ivec2 pos, glm::ivec2 size,int handle) : Actor(nullptr)
{


	//printf("size X : %d\n", mSize.x);
	//printf("size Y : %d\n",mSize.y);


	mPosition = pos;	//座標
	mSize = size;		//サイズ
	mSprite = handle;	//スプライト
	HP = 3;				//耐久値


	//当たり判定
	mCol.setPosition(mPosition);
	mCol.setSize(mSize);
	mCol.setTrigger(true);
	mCol.setStageObjectType(t);



}


void MapChip::Update()
{
	//printf("あああ\n");

	//当たり判定
	mCol.setPosition(mPosition);
	mCol.setSize(mSize - 1);
	mCol.setTrigger(true);
	

}

void MapChip::Draw()
{
	DrawGraph(mPosition.x, mPosition.y,mSprite,true);
}


//デストラクタ
MapChip::~MapChip()
{

}
