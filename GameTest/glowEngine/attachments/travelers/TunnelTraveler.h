#pragma once
#include "../Attachment.h"
#include "../../Vector2.h"

class Tunnel;
/**
 Attachment for Entities that can travel in a Tunnel.
*/
class TunnelTraveler :
	public Attachment
{
public:
	/**
	 Constructor for TunnelTraveler.
	 Constructs an new TunnelTraveler.

	 @param ent The Entity to which this TunnelTraveler is attached.
	*/
	TunnelTraveler(Entity* ent) : Attachment(ent) {
		radius = 64;
		velocity = 0;
		track = 0;
	};

	/**
	 Update method to be called by a Tunnel class.
	 Handles updates related to the Tunnel.

	 @param deltaTime Time elapsed between the last frame and the current frame.
	 @param refTunnel The Tunnel that this TunnelTraveler is attached to.
	*/
	virtual void TunnelUpdate(float deltaTime, Tunnel* refTunnel);

	/**
	 Float representing the radius that the traveler is placed in within the tunnel.
	*/
	float radius;

	/**
	 Float representing the speed at which the radius is changing relative to seconds.
	*/
	float velocity;

	/**
	 Integer representing the track number that the traveler is placed in within the tunnel.
	*/
	int track;

	virtual void Init() override;

	virtual void Update(float deltaTime) override;
};

