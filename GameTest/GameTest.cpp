//------------------------------------------------------------------------
// GameTest.cpp
//------------------------------------------------------------------------
#include "stdafx.h"
//------------------------------------------------------------------------
#include <windows.h> 
#include <math.h>  
//------------------------------------------------------------------------
#include "app\app.h"
//------------------------------------------------------------------------
#include "glowEngine\GlowEngine.h"

Entity* tunnelEnt;
Level* myLevel;

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	tunnelEnt = new Entity();
	tunnelEnt->AddAttachment<GameController>();
	tunnelEnt->AddAttachment<EnemySpawner>();
	tunnelEnt->AddAttachment<TunnelRenderer>();
	tunnelEnt->AddAttachment<TextRenderer>();
	tunnelEnt->AddAttachment<TextRenderer>();
	tunnelEnt->AddAttachment<TextRenderer>();
	tunnelEnt->AddAttachment<Tunnel>()->trackCount = 9;
	tunnelEnt->GetAttachment<Transform>()->position = Vector2(512, 384);

	myLevel = new Level();
	myLevel->AddEntity(tunnelEnt);
	myLevel->Init();
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{
	myLevel->Update(deltaTime);
}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void Render()
{	
	myLevel->Render();
}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{	
	delete myLevel;
}