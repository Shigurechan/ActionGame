#ifndef ___STAGE_HPP_
#define ___STAGE_HPP_

#include "glm/glm.hpp"
#include "dxlib.h"

#include "MapChip.hpp"
#include "Entry.hpp"
#include "Player.hpp"
#include <iostream>
#include <vector>

//�O���錾
class Player;

/*####################################################
* �X�e�[�W�`��
*
* ����
* �X�e�[�W��`�悷��
######################################################*/
class Stage
{
public:
	Stage();	//�R���X�g���N�^
	~Stage();	//�f�X�g���N�^

	void Update();	//�X�V
	void Draw();	//�`��

	void ColPlayer(Player &player);	//�v���C���[�Ƃ̓����蔻��
private:

	std::vector<MapChip> mStage;	//�}�b�v�f�[�^
	glm::ivec2 mStageSize;			//��ʂɕ`�悷��Z����
	


};


#endif
	