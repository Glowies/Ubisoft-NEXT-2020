#pragma once
#include "Attachment.h"
#include "Tunnel.h"
#include "EnemySpawner.h"
#include "renderers/TextRenderer.h"

/**
 Main Attachment that controls the game.
 Starts and ends the game, keeps track of score, controls the Tunnel and Spawner.
*/
class GameController :
	public Attachment
{
public:
    /**
     Constructor for GameController.
     Constructs an new GameController.

     @param ent The Entity to which this GameController is attached.
    */
    GameController(Entity* ent) : Attachment(ent) {
        currentController = this;
        gameBegun = false;
        score = 0;
        tunnel = NULL;
        spawner = NULL;
        player = NULL;
        gameoverText = NULL;
        scoreText = NULL;
    };

    /**
     Start the game.
     Starting the game resets the score and activates Attachments that drive the game.
    */
    void StartGame();

    /**
     End the game.
     Ending the game displays a gameover text and prompts the user to replay by pressing SPACE.
    */
    void EndGame();

    /**
     Spawns a new player controlled Entity.
    */
    void SpawnPlayer();

    /**
     Increment the score.
    */
    static void IncrementScore();

    /**
     End the game being controlled by the currentController.
    */
    static void EndCurrentGame();

    /**
     The current GameController that is controlling the game.
     This is the last GameController object to be instantiated.
    */
    static GameController* currentController;

    virtual void Init() override;

    virtual void Update(float deltaTime) override;
private:
    Tunnel* tunnel;
    EnemySpawner* spawner;
    PlayerTraveler* player;
    int score;
    bool gameBegun;
    TextRenderer *scoreText, *gameoverText, *restartText;
};

