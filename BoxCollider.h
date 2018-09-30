#pragma once
#include "Collider.h"

class GameObject;
class CircleCollider;

class BoxCollider : public Collider // TODO LEARN THIS MOTHERFUCKER https://learnopengl.com/In-Practice/2D-Game/Collisions/Collision-detection
{
public:
	BoxCollider();
	BoxCollider(GameObject * owner);
	virtual ~BoxCollider();

	void Initialise() override;
	void Update();

	bool IsColliding(glm::vec3 newCenter, CircleCollider * otherCollider);
	bool IsColliding(glm::vec3 otherPosition);

	float GetWidth() const;
	float GetHeight() const;

	void SetWidth(float width);
	void SetHeight(float height);

private:

	float width;
	float height;

};

