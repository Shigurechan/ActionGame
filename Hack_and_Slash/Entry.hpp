#ifndef ___ENTRY_HPP_
#define ___ENTRY_HPP_


#include "Game_Scene.hpp"
#include <iostream>


#define CELL ((int)48)	//�Z��

//��ʃT�C�Y
#define SCREEN_WIDTH ((int)16 * 70)
#define SCREEN_HEIGHT ((int)9 * 70)

//����
#define VECTOR_UP glm::ivec2(0,-1)
#define VECTOR_DOWN glm::ivec2(0,1)
#define VECTOR_LEFT glm::ivec2(-1,0)
#define VECTOR_RIGHT glm::ivec2(1,0)

#define PI ((float)3.14159265359)	//PI



// �V�[���̎��
typedef  enum class Scene_Type
{
	Title,		//�^�C�g��
	Game,		//���C���Q�[��
	GameOver,	//�Q�[���I�[�o�[


	Menu,		//���j���[
	Pause,		//�ꎞ��~
}Scene_Type;


/*####################################################
* �V�[������
* 
* ����
* �V�[���̐��ڂ��s��
######################################################*/
class Game_Scene;
class Entry
{
public:

	Entry();	//�R���X�g���N�^
	~Entry();	//�f�X�g���N�^

	void Update();	//�v�Z
	void Draw();	//�`��

private:

	std::shared_ptr<Game_Scene> game;
	Scene_Type type;

};


#endif

