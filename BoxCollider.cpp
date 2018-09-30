#include "BoxCollider.h"
#include "GameObject.h"
#include "CircleCollider.h"



BoxCollider::BoxCollider()
{
}

BoxCollider::BoxCollider(GameObject * owner)
{
	this->owner = owner;
}


BoxCollider::~BoxCollider()
{
}

void BoxCollider::Initialise()
{
	center = owner->transform.position;

	width = owner->GetObjectDiamater();
	height = owner->GetObjectDiamater();
}

void BoxCollider::Update()
{
	center = owner->transform.position;

}


bool BoxCollider::IsColliding(glm::vec3 otherPosition)
{
	// If the new position is inside the other collider
	bool collisionX = otherPosition.x + width / 2 >= center.x &&
		center.x + width / 2 >= otherPosition.x;

	bool collisionY = otherPosition.y + height / 2 >= center.y &&
		center.y + height >= otherPosition.y;

	// If they are colliding
	if (collisionX && collisionY)
	{
		return true;
	}
	else
	{
		return false;
	}

}

float BoxCollider::GetWidth() const
{
	return width;
}

float BoxCollider::GetHeight() const
{
	return height;
}

void BoxCollider::SetWidth(float width)
{
	this->width = width;
}

void BoxCollider::SetHeight(float height)
{
	this->height = height;
}
