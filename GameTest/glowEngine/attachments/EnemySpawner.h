#pragma once
#include "Attachment.h"
#include "Tunnel.h"

/**
 Attachment that is used to spawn enemies and walls.
 Requires the Tunnel attachment.
*/
class EnemySpawner :
	public Attachment
{
public:
	/**
	 Constructor for EnemySpawner.
	 Constructs an new EnemySpawner.

	 @param ent The Entity to which this EnemySpawner is attached.
	*/
	EnemySpawner(Entity* ent) : Attachment(ent) {
		enemySpawnInterval = 6000;
		wallSpawnInterval = 2000;
		enemyTimer = 0;
		wallTimer = 0;
		tunnel = NULL;
	};

	/**
	 Spawn an enemy in a random track on the tunnel.
	*/
	void SpawnEnemy();

	/**
	 Spawn a randomized array of walls.
	*/
	void SpawnWall();

	/**
	 The time between two enemy spawns in miliseconds.
	*/
	float enemySpawnInterval;

	/**
	 The time between two wall spawns in miliseconds.
	*/
	float wallSpawnInterval;

	virtual void Init() override;

	virtual void Update(float deltaTime) override;

private:
	Tunnel* tunnel;
	float enemyTimer;
	float wallTimer;
};

