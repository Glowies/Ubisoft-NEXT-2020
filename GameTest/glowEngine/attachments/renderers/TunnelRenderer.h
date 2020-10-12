#pragma once
#include "Renderer.h"
#include "../Tunnel.h"

/**
 Renderer used to render a "Tempest-like" tunnel
*/
class TunnelRenderer :
	public Renderer
{
public:
	/**
	 Constructor for TunnelRenderer.
	 Constructs an new TunnelRenderer.

	 @param ent The Entity to which this TunnelRenderer is attached.
	*/
	TunnelRenderer(Entity* ent) : Renderer(ent) {
		r = 1;
		g = 192.0f / 255.0f;
		b = 203.0f / 255.0f;
	};

	void Draw() override;

	virtual void Init() override;

private:
	Tunnel* tunnel;
};

