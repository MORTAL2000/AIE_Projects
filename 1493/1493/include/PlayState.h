///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			PlayState.h
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			play state, inherits GameState base class
// References:		http://gamedevgeek.com/tutorials/managing-game-states-in-c/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _PLAYSTATE_H_
#define _PLAYSTATE_H_

#include "GameEngine.h"
#include "GameState.h"
#include "MenuState.h"
#include "Sprite.h"
#include "EnvironmentObj.h"
#include "Player.h"
#include <list>

class PlayState : public GameState
{
	public:
		// to be executed first upon entering the state
		void Init();
		// to be executed when state is popped from end of stack
		void Cleanup();

		void Pause();
		void Resume();

		// handles responses to inputs
		void HandleEvents(GameEngine* a_opGame);
		// occurs each frame
		void Update(GameEngine* a_opGame);
		// renders things to the screen
		void Draw(GameEngine* a_opGame);
	

		static PlayState* Instance(); //**verify that this is implemented correctly in cpp**

	protected:
		PlayState();

	private:
		static PlayState m_PlayState;

		list<EnvironmentObj> m_EnvironList;
		list<Player> m_PlayerList;
		list<Enemy> m_EnemyList;

		// initializes enemy objects
		void InitEnemies();
		// triggers enemy spawns based on player's distance from level start
		void EnemyTrigger(EnvironmentObj& a_bg, Player& a_player);
};

#endif