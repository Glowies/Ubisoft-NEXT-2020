#include "stdafx.h"
#include "EnemyTraveler.h"
#include "../../GlowEngine.h"

void EnemyTraveler::Update(float deltaTime)
{
	ColorableTraveler::Update(deltaTime);

	bulletTimer += deltaTime;
	if (bulletTimer > bulletInterval) {
		bulletTimer -= bulletInterval;

		ShootBullet();
	}
}

void EnemyTraveler::OnCollision(Collider* other)
{
	BulletTraveler* bullet = other->GetEntity()->GetAttachment<BulletTraveler>();
	if (bullet) {
		if (bullet->colorType == colorType) {
			Level::DestroyEntity(GetEntity());
			GameController::IncrementScore();
		}
		Level::DestroyEntity(bullet->GetEntity());
	}
}

void EnemyTraveler::ShootBullet()
{
	Entity* bullet = new BulletEntity();
	TunnelTraveler* trav = bullet->GetAttachment<TunnelTraveler>();
	trav->radius = radius - GetEntity()->GetAttachment<Transform>()->scale.x * 0.3f;
	trav->track = track;
	trav->velocity *= 1;

	Level::FindAttachment<Tunnel>()->AddTraveler(trav);
	Level::SpawnEntity(bullet);
}