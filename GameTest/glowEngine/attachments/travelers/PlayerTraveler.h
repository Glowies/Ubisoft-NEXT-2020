#pragma once
#include "ColorableTraveler.h"
#include "ColorType.h"

/**
 Attachment for a TunnelTraveler that is player controlled using the mouse.
*/
class PlayerTraveler :
	public ColorableTraveler
{
public:
	/**
	 Constructor for PlayerTraveler.
	 Constructs an new PlayerTraveler.

	 @param ent The Entity to which this PlayerTraveler is attached.
	*/
	PlayerTraveler(Entity* ent) : ColorableTraveler(ent) {
		immuneTimer = -1;
		radius = 48;
		keyLock = false;
		mouthOpen = false;
		colorType = ColorType::Color::white;
	};

	/**
	 Method to inquire upon the openness of the player's mouth.
	*/
	bool IsMouthOpen();

	/**
	 Make the player immmune for a duration.

	 @param duration The duration for which the player remains immune in miliseconds.
	*/
	void MakeImmune(float duration);

	/**
	 Spawn a new bullet that has the same colorType as the player.
	*/
	void ShootBullet();

	virtual void Update(float deltaTime) override;

	virtual void TunnelUpdate(float deltaTime, Tunnel* refTunnel) override;

	virtual void OnCollision(Collider* other) override;

private:
	bool keyLock;
	bool mouthOpen;
	float immuneTimer;
};

