#pragma once
#include "Attachment.h"
#include "../LinkedList.h"
#include "travelers/Travelers.h"

/**
 Attachment defining the properties and behaviour of a Tunnel.
 The tunnel keeps track of and updates the TunnelTravelers that have been attached to it.
*/
class Tunnel :
	public Attachment
{
public:
	/**
	 Constructor for Tunnel.
	 Constructs an new Tunnel.

	 @param ent The Entity to which this Tunnel is attached.
	*/
	Tunnel(Entity* ent);

	/**
	 Destructor for Tunnel.
	 Destructs the Tunnel by deleting the TunnelTravelers in it.
	*/
	~Tunnel();

	/**
	 Method to add a TunnelTraveler to the Tunnel.
	*/
	void AddTraveler(TunnelTraveler* traveler);

	/**
	 Method to remove a TunnelTraveler from the Tunnel.
	*/
	void RemoveTraveler(TunnelTraveler* traveler);

	/**
	 Destroys all TunnelTravelers on the Tunnel.
	*/
	void ClearTunnel();

	/**
	 The tunnels's inner radius
	*/
	float innerRadius;

	/**
	 The polygon's outer radius
	*/
	float outerRadius;

	/**
	 The speed at which the tunnel spins in radians per second.
	*/
	float spinSpeed;

	/**
	 The number of tracks on the tunnel
	*/
	int trackCount;

	virtual void Init() override;

	virtual void Update(float deltaTime) override;

private:
	LinkedList<TunnelTraveler>* travelers;
};

