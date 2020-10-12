#pragma once
#include "TunnelTraveler.h"
#include "ColorType.h"

/**
 Traveler whose color changes according to its colorType.
*/
class ColorableTraveler :
	public TunnelTraveler
{
public:
	/**
	 Constructor for ColorableTraveler.
	 Constructs an new ColorableTraveler.

	 @param ent The Entity to which this ColorableTraveler is attached.
	*/
	ColorableTraveler(Entity* ent) : TunnelTraveler(ent) {
		colorType = ColorType::Color::white;
	};

	/**
	 The color type of this ColorableTraveler.
	 The color type determines the color in which the Entity is rendered and which Entities it can interact with.
	*/
	ColorType::Color colorType;

	virtual void Update(float deltaTime) override;
};

