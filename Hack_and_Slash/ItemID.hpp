#ifndef ITEM_ID_HPP
#define ITEM_ID_HPP


//�A�C�e��ID
enum class Item_ID
{
	Attack_UP,		//�U���́@�㏸
	Defense_UP,		//�h��́@�㏸
	HitPoint_Rec,	//HP�@��


	None,	//���ڂ₻�̑��̏ꍇ
};


// �Q�[���A�C�e��
typedef struct ItemData
{

	int mSpeed_Max;		//�ő呬�x

	int HP_Max;			//�ő�HP
	int HP_Rec;			//HP
	int HP_autoRec;		//������

	int Attack;			//�U����
	int Coin;			//�ʉ�
}ItemData;


//�A�C�e���f�[�^���擾
ItemData GetItemData(unsigned char ID);









#endif
