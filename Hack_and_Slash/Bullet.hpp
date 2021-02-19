#ifndef ___BULLET_HPP_
#define ___BULLET_HPP_

#include "DxLib.h"
#include "glm/glm.hpp"
#include "Actor.hpp"
#include "Entry.hpp"
#include "Collision.hpp"

#include "Animation.hpp"

/*####################################################
* �o���b�g(�e)
*
* ����
* vector�ŊǗ�
* �v���C���[�̍U��
* 
######################################################*/

class Bullet : public Actor
{
public:
	Bullet(glm::ivec2 pos, glm::ivec2 vec, int handle,int effectHandle[3]);	//�R���X�g���N�^
	~Bullet();											//�f�X�g���N�^

	void Update();	//�X�V
	void Draw();	//�`��

	void FixPos(glm::ivec2 pos);	//���W���C��

	Box_Collision mCol;	//�����蔻��
	bool mIsHit;	//�q�b�g�������ǂ����H
	
private:
	Animation anim;			//�A�j���[�V�����N���X
	int mSprite;			//�X�v���C�g
	int mEffectSprite[3];	// �G�t�F�N�g�X�v���C�g

	int mSpeed;		//�o���b�g�̑��x
	
};


#endif






