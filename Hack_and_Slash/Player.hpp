#ifndef ___PLAYER_HPP_
#define ___PLAYER_HPP_


#include <iostream>
#include <vector>

//#include "Animation.hpp"


//#include "Actor.hpp"
#include "Entry.hpp"

#include "Input.hpp"
#include "Bullet.hpp"
#include "Collision.hpp"
#include "ItemID.hpp"



/*####################################################
* �v���C���[�N���X
######################################################*/

//�O���錾
class Bullet;
class Enemy;
class Player : public Actor
{
public:
	Player(Entry* e,int Player_Handle, int Player_Bullet_Handle,int Enemy_HitEffect_Handle[3], int Stage_HitEffect_Handle[3]);	//�R���X�g���N�^
	~Player();	//�f�X�g���N�^

	
	void Update();	//�X�V
	void Draw();	//�`��
	
	// �o���b�g
	void Bullet_Update();	//�X�V
	void Bullet_Draw();		//�`��

	//�v���C���[
	void Player_Update();	//�X�V
	void Player_Draw();		//�`��


	// #################### �擾�@�֌W

	bool getIsMenu();	//�V���b�v��ʂ��J���Ă��邩�ǂ����H	
	std::shared_ptr<std::vector<Bullet>> getBullet();	//�o���b�g
	int getSpeed();		//���x���擾

	// ####################�@�ݒ�@�֌W

	void set_Bulid(ItemData data);	//�X�e�[�^�X��ݒ�
	void FixPos(glm::ivec2 pos);	//�����蔻��ō��W���C��
	void OffsetFixPos(glm::ivec2 pos);	//���W�̃I�t�Z�b�g���C��
	void setIsMenu(bool b);			//���j���[���J�����ǂ����ݒ�
	void setSpeed(int speed);		//���x��ݒ�

	void ColEnemy_Bullet(std::shared_ptr<std::vector<Enemy>> Enemy_Bullet);	//�G�l�~�[�̃o���b�g�Ƃ̓����蔻��



	glm::ivec2 mStagePosition;


	Box_Collision mCol;	//�����蔻��
private:

	

	//�X�v���C�g
	int mPlayer_sprite;
	int mEnemy_HitEffect_sprite[3];
	int mStage_HitEffect_sprite[3];
	int mPlayer_Bullet_sprite;






	std::shared_ptr<std::vector<Bullet>> mBullet;	//�o���b�g

	bool mMenu;	//�V���b�v��ʂ��J�����ǂ����H




// �X�e�[�^�X

	int mSpeed;			//���x
	int mSpeed_Max;		//�ő呬�x

	int HP_Max;			//�ő�HP
	int HP;				//HP
	int HP_autoRec;		//������

	int Attack;			//�U����

	int Coin;			//�ʉ�



};


#endif


