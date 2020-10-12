#include "stdafx.h"
#include "GameController.h"
#include "../GlowEngine.h"

void GameController::StartGame()
{
	gameBegun = true;
	score = 0;
	tunnel->SetActive(true);
	spawner->SetActive(true);
	tunnel->ClearTunnel();
	tunnel->spinSpeed = 0.2f;
	gameoverText->SetActive(false);
	restartText->SetActive(false);

	SpawnPlayer();
}

void GameController::EndGame()
{
	gameBegun = false;
	tunnel->ClearTunnel();
	spawner->SetActive(false);
	player->SetActive(false);
	gameoverText->SetActive(true);
	restartText->SetActive(true);
}

void GameController::IncrementScore()
{
	currentController->score++;
	currentController->tunnel->spinSpeed += 0.05f;
}

void GameController::EndCurrentGame()
{
	currentController->EndGame();
}

void GameController::SpawnPlayer()
{
	PlayerEntity* newPlayer = new PlayerEntity();
	tunnel->AddTraveler(newPlayer->GetAttachment<TunnelTraveler>());
	
	player = newPlayer->GetAttachment<PlayerTraveler>();
	player->MakeImmune(1000);

	Level::SpawnEntity(newPlayer);
}

void GameController::Init()
{
	tunnel = GetEntity()->GetAttachment<Tunnel>();
	spawner = GetEntity()->GetAttachment<EnemySpawner>();
	spawner->SetActive(false);

	LinkedList<TextRenderer>* texts = GetEntity()->GetAttachments<TextRenderer>();

	gameoverText = texts->Get(0);
	gameoverText->position = Vector2(440, 620);
	sprintf(gameoverText->text, "G A M E  O V E R");

	restartText = texts->Get(1);
	restartText->position = Vector2(439, 580);
	sprintf(restartText->text, "Press 'R' to restart");

	scoreText = texts->Get(2);
	scoreText->position = Vector2(20, 730);

	delete texts;

	StartGame();
}

void GameController::Update(float deltaTime)
{
	sprintf(scoreText->text, "SCORE: %d", score);

	if (!gameBegun && App::IsKeyPressed('R')) {
		StartGame();
	}
}

GameController* GameController::currentController = NULL;