#include "Actor.hpp"

//�R���X�g���N�^
Actor::Actor(glm::ivec2 pos ,glm::ivec2 vec )
{
	mVector = vec;
	mPosition = pos;
	mSize = glm::ivec2(0,0);
}

//�������擾
glm::ivec2 Actor::getVector()
{
	return mVector;
}

//���W���擾
glm::ivec2 Actor::getPosition()
{
	return mPosition;
}

//�f�X�g���N�^
Actor::~Actor()
{

}
