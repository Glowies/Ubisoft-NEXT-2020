#include "stdafx.h"
#include "EnemySpawner.h"
#include "../GlowEngine.h"

void EnemySpawner::SpawnEnemy()
{
	int prev = -1;
	for (int i = 0; i < 2; i++) {
		Entity* enemy = new EnemyEntity();
		TunnelTraveler* trav = enemy->GetAttachment<TunnelTraveler>();

		trav->track = rand() % tunnel->trackCount;
		if (prev == trav->track)
			trav->track += 2;
		prev = trav->track;
		trav->radius += 200 * i;

		tunnel->AddTraveler(trav);

		Level::SpawnEntity(enemy);
	}
}

void EnemySpawner::SpawnWall()
{
	int randOffset = rand() % tunnel->trackCount;

	for (int i = 0; i < tunnel->trackCount - 2; i++) {
		Entity* enemy = new WallEntity();
		enemy->GetAttachment<TunnelTraveler>()->track = i + randOffset;
		tunnel->AddTraveler(enemy->GetAttachment<TunnelTraveler>());

		Level::SpawnEntity(enemy);
	}
}

void EnemySpawner::Init()
{
	tunnel = GetEntity()->GetAttachment<Tunnel>();
}

void EnemySpawner::Update(float deltaTime)
{
	enemyTimer += deltaTime;
	wallTimer += deltaTime;

	if (enemyTimer > enemySpawnInterval) {
		enemyTimer -= enemySpawnInterval;

		SpawnEnemy();
	}

	if (wallTimer > wallSpawnInterval) {
		wallTimer -= wallSpawnInterval;

		SpawnWall();
	}
}
