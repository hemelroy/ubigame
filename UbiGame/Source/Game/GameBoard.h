#pragma once
#include "GameEngine\EntitySystem\Entity.h"

#include <SFML/System/Vector2.hpp>
#include <vector>

namespace Game
{
	//Used for storing and controling all game related entities, as well as providing an entry point for the "game" side of application	
	class PlayerEntity;	

	class GameBoard
	{
	public:
		GameBoard();
		virtual ~GameBoard();


		void Update();		
		bool IsGameOver() { return false; }

	private:
		void CreatePlayer();
		void CreateObstacle();
		void CreateObstacle2();
		void CreateObstacle3();
		void CreateBackground();
		void CreateBorderTop();
		void CreateBorderBot();
		void CreateBorderLeft();
		void CreateBorderRight();
		GameEngine::Entity* m_player;
		GameEngine::Entity* obstacle;
		GameEngine::Entity* obstacle2;
		GameEngine::Entity* obstacle3;
		GameEngine::Entity* BorderTop;
		GameEngine::Entity* BorderBot;
		GameEngine::Entity* BorderLeft;
		GameEngine::Entity* BorderRight;
	};
}

