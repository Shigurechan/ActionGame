#include "ItemID.hpp"

//�A�C�e���f�[�^���擾
ItemData GetItemData(unsigned char ID)
{
	ItemData item;

	switch (ID)
	{
		//�U��
	case 0x0001:
	{
		item = ItemData{5, 0,0,0, 0,0  };	//�p�����[�^��ݒ�

		return item;

	}break;


	};
}


