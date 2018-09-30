#pragma once


#include "Collider.h"

class GameObject;
class BoxCollider;

// TODO check OpenGL link - https://learnopengl.com/In-Practice/2D-Game/Collisions/Collision-detection

class CircleCollider : public Collider
{
public:
	CircleCollider();
	CircleCollider(GameObject * owner);
	~CircleCollider();

	void Initialise() override;
	void Update();

	float GetRadius() const;
	void SetRadius(float newRadius);

	bool IsColliding(glm::vec3 newCenter, CircleCollider * otherCollider);
	// bool IsColliding(glm::vec3 newCenter, BoxCollider * otherCollider);

private:

	float radius;

};
