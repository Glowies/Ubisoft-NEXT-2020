#pragma once
#include "ColorableTraveler.h"

/**
 TunnelTraveler attachment that describes enemy ship behaviours.
*/
class EnemyTraveler :
	public ColorableTraveler
{
public:
	/**
	 Constructor for EnemyTraveler.
	 Constructs an new EnemyTraveler.

	 @param ent The Entity to which this EnemyTraveler is attached.
	*/
	EnemyTraveler(Entity* ent) : ColorableTraveler(ent) {
		colorType = ColorType::RandomColor();
		bulletTimer = 0;
		bulletInterval = 2000;
	};

	/**
	 Spawn a new random bullet.
	*/
	void ShootBullet();

	virtual void Update(float deltaTime) override;

	virtual void OnCollision(Collider* other) override;

private:
	float bulletTimer;
	float bulletInterval;
};

