#include "stdafx.h"
#include "../../../App/app.h"
#include "PlayerTraveler.h"
#include "../../GlowEngine.h"


bool PlayerTraveler::IsMouthOpen()
{
	return mouthOpen;
}

void PlayerTraveler::MakeImmune(float duration)
{
	immuneTimer = duration;
}

void PlayerTraveler::ShootBullet()
{
	Entity* bullet = new BulletEntity();
	bullet->GetAttachment<BulletTraveler>()->colorType = colorType;
	TunnelTraveler* trav = bullet->GetAttachment<TunnelTraveler>();
	trav->radius = radius + 10;
	trav->track = track;
	trav->velocity *= -1;

	Level::FindAttachment<Tunnel>()->AddTraveler(trav);
	Level::SpawnEntity(bullet);
}

void PlayerTraveler::Update(float deltaTime)
{
	ColorableTraveler::Update(deltaTime);

	if (immuneTimer > 0)
		immuneTimer -= deltaTime;

	if (App::IsKeyPressed(' ')) {
		if (!keyLock) { // Only triggers on the update call during which SPACE is pressed
			keyLock = true;
			mouthOpen = true;

			if (colorType != ColorType::Color::white) {
				ShootBullet();
			}

			colorType = ColorType::Color::white;
		}
	}
	else {
		if (keyLock) { // Only triggers on the update call during which SPACE is released
			keyLock = false;
			mouthOpen = false;
		}
	}
}

void PlayerTraveler::TunnelUpdate(float deltaTime, Tunnel* refTunnel)
{
	int trackCount = refTunnel->trackCount;
	Vector2 center = refTunnel->GetEntity()->GetAttachment<Transform>()->position;
	float tunnelRotation = refTunnel->GetEntity()->GetAttachment<Transform>()->rotation;

	float x, y;
	App::GetMousePos(x, y);
	float mouseAngle = atan2f(y - center.y, x - center.x);

	//radius = sqrtf((y - center.y) * (y - center.y) + (x - center.x) * (x - center.x));

	const float pi = 3.14159f;
	const float angleStep = 2 * pi / trackCount;

	if(y - center.y >= 0){
		mouseAngle -= tunnelRotation;
		track = (int)(mouseAngle / angleStep);
		if (track <= 0) {
			track -= 1;
		}
	}
	else {
		mouseAngle -= tunnelRotation;
		track = trackCount + (int)(mouseAngle / angleStep) - 1;
	}

	TunnelTraveler::TunnelUpdate(deltaTime, refTunnel);
}

void PlayerTraveler::OnCollision(Collider* other)
{
	BulletTraveler* bullet = other->GetEntity()->GetAttachment<BulletTraveler>();
	if (bullet) {
		if (mouthOpen) {
			mouthOpen = false;
			colorType = bullet->colorType;
			Level::DestroyEntity(bullet->GetEntity());
		}
		else if(immuneTimer <= 0){
			GameController::EndCurrentGame();
		}
	}
	
	EnemyTraveler* enemy = other->GetEntity()->GetAttachment<EnemyTraveler>();
	WallRenderer* wall = other->GetEntity()->GetAttachment<WallRenderer>();
	if (wall || enemy) {
		if (immuneTimer <= 0) {
			GameController::EndCurrentGame();
		}
	}
}
