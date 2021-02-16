#include "Collision.hpp"

//�R���X�g���N�^
Box_Collision::Box_Collision()
{

	mIsTrigger = false;
}


//��`���m�̌�������
bool Box_Collision::Intersect( Box_Collision &a, Box_Collision &b)
{
//	printf("X: %d\n", a.getPosition().x);
//	printf("Y: %d\n",a.getPosition().y);

//	printf("size X: %d\n", a.getSize().x);
//	printf("size Y: %d\n",a.getSize().y);


	//printf("X: %d\n", b.getPosition().x);
	//printf("Y: %d\n",b.getPosition().y);

//	printf("size X: %d\n", b.getSize().x);
//	printf("size Y: %d\n",b.getSize().y);

	if ((a.getPosition().x + a.getSize().x > b.getPosition().x && b.getPosition().x + b.getSize().x > a.getPosition().x)
		&& (a.getPosition().y + a.getSize().y > b.getPosition().y && b.getPosition().y + b.getSize().y > a.getPosition().y))
	{
		return true;
	}
	else
	{
		return false;
	}
}




// #################################### �擾�@�֌W

//�g���K�[�^�C�v���擾
bool Box_Collision::getTrigger()
{
	return mIsTrigger;
}


//���W���擾
glm::ivec2 Box_Collision::getPosition()
{
	return mPosition;
}

//�T�C�Y���擾
glm::ivec2 Box_Collision::getSize()
{
	return mSize;
}

//�I�u�W�F�N�g�^�C�v���擾
StageObjectType Box_Collision::getObjectType()
{
	return Type;
}

//�I�u�W�F�N�g�^�C�v��ݒ�
glm::ivec2 Box_Collision::getVector()
{
	return mVector;
}



// #################################### �ݒ�@�֌W

//�g���K�[�^�C�v��ݒ�
void Box_Collision::setTrigger(bool tri)
{
	mIsTrigger = tri;
}


//���W��ݒ�
void Box_Collision::setPosition(glm::ivec2 pos)
{
	mPosition = pos;
}

// �T�C�Y��ݒ�
void Box_Collision::setSize(glm::ivec2 size)
{
	mSize = size;
}

//�I�u�W�F�N�g�^�C�v��ݒ�
void Box_Collision::setStageObjectType(StageObjectType type)
{
	Type = type;
}

//�I�u�W�F�N�g�^�C�v��ݒ�
void Box_Collision::setVector(glm::ivec2 vec)
{
	mVector = vec;
}


//�f�X�g���N�^
Box_Collision::~Box_Collision()
{

}