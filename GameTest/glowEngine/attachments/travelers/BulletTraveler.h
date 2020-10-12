#pragma once
#include "ColorableTraveler.h"
#include "ColorType.h"

/**
 Traveler class representing a bullet.
*/
class BulletTraveler :
	public ColorableTraveler
{
public:
	/**
	 Constructor for BulletTraveler.
	 Constructs an new BulletTraveler.

	 @param ent The Entity to which this BulletTraveler is attached.
	*/
	BulletTraveler(Entity* ent) : ColorableTraveler(ent) {
		colorType = ColorType::RandomColor();
	};

	virtual void Update(float deltaTime) override;

};

