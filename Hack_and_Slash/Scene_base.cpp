#include "Scene_Base.hpp"


//�R���X�g���N�^
Scene_base::Scene_base(Scene_Type t)
{
	Type = t;	//�V�[���Ƀ^�C�v��ݒ�
}

//�V�[���^�C�v���擾
Scene_Type Scene_base::getSceneType()
{
	return Type;
}

//�f�X�g���N�^
Scene_base::~Scene_base()
{
	
}