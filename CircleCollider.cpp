#include "CircleCollider.h"
#include "GameObject.h"
#include "Transform.h"


CircleCollider::CircleCollider()
{
}

CircleCollider::CircleCollider(GameObject * owner)
{
	this->owner = owner;
}


CircleCollider::~CircleCollider()
{
}

void CircleCollider::Initialise()
{
	radius = owner->GetObjectDiamater() / 2;
	center = owner->transform.position;
}

void CircleCollider::Update()
{
	// Update the collider position
	center = owner->transform.position;
}


float CircleCollider::GetRadius() const
{
	return radius;
}

void CircleCollider::SetRadius(float radius)
{
	this->radius = radius;
}


bool CircleCollider::IsColliding(glm::vec3 newCenter, CircleCollider * otherCollider)
{
	if (Transform::GetDistance2D(newCenter, otherCollider->GetCenter()) < radius + otherCollider->GetRadius())
	{
		return true;
	}
	else
	{
		return false;
	}

}

//bool CircleCollider::IsColliding(glm::vec3 newCenter, BoxCollider * otherCollider)
//{
//	return false;
//}
