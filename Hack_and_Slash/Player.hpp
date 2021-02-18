#ifndef ___PLAYER_HPP_
#define ___PLAYER_HPP_

#include "Actor.hpp"
#include "Input.hpp"
#include "Entry.hpp"
#include "Bullet.hpp"
#include "Collision.hpp"

#include <iostream>
#include <vector>

#define SPEED 10

/*####################################################
* �v���C���[�N���X
######################################################*/

//�O���錾
class Bullet;

class Player : public Actor
{
public:
	Player();	//�R���X�g���N�^
	~Player();	//�f�X�g���N�^

	
	void Update()override;	//�X�V
	void Draw()override;	//�`��
	
	// �o���b�g
	void Bullet_Update();	//�X�V
	void Bullet_Draw();		//�`��

	//�v���C���[
	void Player_Update();	//�X�V
	void Player_Draw();		//�`��


	bool getIsMenu();						//�V���b�v��ʂ��J���Ă��邩�ǂ����H	
	void setIsMenu(bool b);					// ���j���[���J�����ǂ����ݒ�
	void FixPos(glm::ivec2 pos);	//�����蔻��ō��W���C��


	Box_Collision mCol;	//�����蔻��
private:

	int mSprite;		//�v���C���[�@�X�v���C�g
	int mBullet_Sprite;	//�o���b�g�@�X�v���C�g

	int mSpeed;		//���x

	std::shared_ptr<Input> mInput;	//�L�[����
	std::vector<Bullet> mBullet;	//�o���b�g

	bool mMenu;	//�V���b�v��ʂ��J�����ǂ����H



};


#endif

