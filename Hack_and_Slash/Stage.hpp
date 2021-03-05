#ifndef ___STAGE_HPP_
#define ___STAGE_HPP_

#include "glm/glm.hpp"
#include "dxlib.h"

#include "MapChip.hpp"
#include "Collision.hpp"
#include "Player.hpp"
#include <iostream>
#include <vector>

//�O���錾
class Player;
class MapChip;
class Bullet;
class Entry;
class Enemy;

/*####################################################
* �X�e�[�W�`��
*
* ����
* �X�e�[�W��`�悷��
######################################################*/
class Stage
{
public:
	Stage(Entry *e,int Block_Handle, int Brick_Handle, int Shop_Handle);	//�R���X�g���N�^
	~Stage();			//�f�X�g���N�^

	void Update();	//�X�V
	void Draw();	//�`��

	//�����蔻��e��
	void ColPlayer(std::shared_ptr<Player> player);										//�v���C���[�Ƃ̓����蔻��
	void ColPlayer_Bullet(std::shared_ptr<std::vector<Bullet>> bullet);		//�v���C���[�̃o���b�g�Ƃ̓����蔻��
	void Scroll(std::shared_ptr<Player> player, std::shared_ptr<std::vector<Enemy>> enemey, std::shared_ptr<std::vector<Bullet>> bullet);	//��ʃX�N���[��
	void ColEnemy(std::shared_ptr<std::vector<Enemy>> enemy);			//�G�l�~�[�Ƃ̓����蔻��
	void ColEnemy_Bullet(std::shared_ptr<std::vector<Enemy>> enemy);	//�G�l�~�[�̃o���b�g�Ƃ̓����蔻��


private:

	std::vector<MapChip> mStage;	//�}�b�v�f�[�^
	glm::ivec2 mStageSize;			//��ʂɕ`�悷��Z����
	glm::ivec2 mScroll_Vec;			//�X�N���[�����Ă������

	
	std::vector<std::vector<byte>> Stage_Grid;	//�X�e�[�W

	bool mGameStart;	//�Q�[�����n�܂��čŏ��̃t���[�������ǂ����H
	bool mIsShop;	//�V���b�v���I��������ǂ����H
	Entry* Owner;	//Entry�N���X

};


#endif
	