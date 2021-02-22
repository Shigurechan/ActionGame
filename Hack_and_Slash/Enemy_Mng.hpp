#ifndef ___ENEMY_MNG_HPP_
#define ___ENEMY_MNG_HPP_

#include "Enemy.hpp"
#include <vector>
#include <iostream>


class Enemy;

class Enemy_Mng {

public:

	Enemy_Mng();	//�R���X�g���N�^
	~Enemy_Mng();	//�f�X�g���N�^


	void Update();	//�X�V
	void Draw();	//�`��

	std::shared_ptr<std::vector<Enemy>> getEnemy();	//�G�l�~�[���

private:
	int Handle;	//�X�v���C�g
	std::shared_ptr<std::vector<Enemy>> enemy;	//�G�l�~�[�@�N���X



};

#endif;