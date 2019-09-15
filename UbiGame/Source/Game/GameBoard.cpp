
#include <cstdlib>
#include "GameBoard.h"
#include "GameEngine\GameEngineMain.h"
#include "Game\Components\PlayerMovementComponent.h"
#include "GameEngine\EntitySystem\Components\SpriteRenderComponent.h"
#include <GameEngine\EntitySystem\Components\CollidableComponent.h>
#include <GameEngine\EntitySystem\Components\CollidablePhysicsComponent.h>

bool is_end = true;
bool is_end2 = true;
bool is_end3 = true;
bool is_end4 = true;
bool is_end5 = true;
float ObsVel, ObsVel2, ObsVel3, ObsVel4, ObsVel5;


using namespace Game;

GameBoard::GameBoard() : m_player(nullptr)
{
	CreatePlayer();
	CreateObstacle();
	CreateObstacle2();
	CreateObstacle3();
	CreateObstacle4();
	CreateObstacle5();
	CreateBackground();
	CreateBorderTop();
	CreateBorderBot();
	CreateBorderLeft();
	CreateBorderRight();
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	int y1 = rand() % 700 + 150;
	int y2 = rand() % 700 + 150;
	int y3 = rand() % 700 + 150;
	int y4 = rand() % 700 + 150;
	int y5 = rand() % 700 + 150;

	float dt2 = GameEngine::GameEngineMain::GetTimeDelta();
	sf::Vector2f wantObsVel = sf::Vector2f(0.f, 0.f);
	
	

	if (is_end == true)
	{
		ObsVel = rand() % 400 + 200.f;
		is_end = false;
	}
	if (is_end2 == true)
	{
		ObsVel2 = rand() % 400 + 200.f;
		is_end2 = false;
	}
	if (is_end3 == true)
	{
		ObsVel3 = rand() % 400 + 200.f;
		is_end3 = false;
	}
	if (is_end4 == true)
	{
		ObsVel4 = rand() % 400 + 200.f;
		is_end4 = false;
	}
	if (is_end5 == true)
	{
		ObsVel5 = rand() % 400 + 200.f;
		is_end5 = false;
	}

	wantObsVel.x -= ObsVel * dt2;
	obstacle->SetPos(obstacle->GetPos() + wantObsVel);
	wantObsVel.x -= ObsVel2 * dt2;
	obstacle2->SetPos(obstacle2->GetPos() + wantObsVel);
	wantObsVel.x -= ObsVel3 * dt2;
	obstacle3->SetPos(obstacle3->GetPos() + wantObsVel);
	wantObsVel.x -= ObsVel4 * dt2;
	obstacle4->SetPos(obstacle4->GetPos() + wantObsVel);
	wantObsVel.x -= ObsVel5 * dt2;
	obstacle5->SetPos(obstacle5->GetPos() + wantObsVel);

	sf::Vector2f posi = obstacle->GetPos();
	sf::Vector2f posi2 = obstacle2->GetPos();
	sf::Vector2f posi3 = obstacle3->GetPos();
	sf::Vector2f posi4 = obstacle3->GetPos();
	sf::Vector2f posi5 = obstacle3->GetPos();

	if (posi.x < -200)
	{
		obstacle->SetPos(sf::Vector2f(2000.f, y1));
		is_end = true; 
	}
	if (posi2.x < -200)
	{
		obstacle2->SetPos(sf::Vector2f(2200.f, y2));
		is_end2 = true;
	}
	if (posi3.x < -200)
	{
		obstacle3->SetPos(sf::Vector2f(2400.f, y3));
		is_end3 = true;
	}
	if (posi4.x < -200)
	{
		obstacle4->SetPos(sf::Vector2f(2600.f, y4));
		is_end4 = true;
	}
	if (posi5.x < -200)
	{
		obstacle5->SetPos(sf::Vector2f(2800.f, y5));
		is_end5 = true;
	}
	
	sf::Vector2f playerPosi = m_player->GetPos();
	if (playerPosi.x <= 0)
	{
		exit(0);
	}
		
		
}

void GameBoard::CreatePlayer()
{
	m_player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);

	m_player->SetPos(sf::Vector2f(300.f, 500.f));
	m_player->SetSize(sf::Vector2f(78.f, 93.f));

	GameEngine::SpriteRenderComponent* spriterender = static_cast<GameEngine::SpriteRenderComponent*>(m_player->AddComponent<GameEngine::SpriteRenderComponent>());

	spriterender->SetFillColor(sf::Color::Transparent);
	spriterender->SetTexture(GameEngine::eTexture::Player);
	//Movement
	m_player->AddComponent<PlayerMovementComponent>();

	m_player->AddComponent<GameEngine::CollidablePhysicsComponent>();
}

void GameBoard::CreateObstacle()
{
	obstacle = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(obstacle);

	obstacle->SetPos(sf::Vector2f(1800.f, 100.f));
	obstacle->SetSize(sf::Vector2f(104.f, 124.f));

	//Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
		(obstacle->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::Obstacle);

	obstacle->AddComponent<GameEngine::CollidableComponent>();
}

void GameBoard::CreateObstacle2()
{
	obstacle2 = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(obstacle2);

	obstacle2->SetPos(sf::Vector2f(2000.f, 600.f));
	obstacle2->SetSize(sf::Vector2f(104.f, 124.f));

	//Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
		(obstacle2->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::Obstacle);

	obstacle2->AddComponent<GameEngine::CollidableComponent>();
}

void GameBoard::CreateObstacle3()
{
	obstacle3 = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(obstacle3);

	obstacle3->SetPos(sf::Vector2f(2200.f, 350.f));
	obstacle3->SetSize(sf::Vector2f(104.f, 124.f));

	//Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
		(obstacle3->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::Obstacle);

	obstacle3->AddComponent<GameEngine::CollidableComponent>();
}


void GameBoard::CreateObstacle4()
{
	obstacle4 = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(obstacle4);

	obstacle4->SetPos(sf::Vector2f(2200.f, 675.f));
	obstacle4->SetSize(sf::Vector2f(104.f, 124.f));

	//Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
		(obstacle4->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::Obstacle);

	obstacle4->AddComponent<GameEngine::CollidableComponent>();
}


void GameBoard::CreateObstacle5()
{
	obstacle5 = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(obstacle5);

	obstacle5->SetPos(sf::Vector2f(2200.f, 125.f));
	obstacle5->SetSize(sf::Vector2f(104.f, 124.f));

	//Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
		(obstacle5->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::Obstacle);

	obstacle5->AddComponent<GameEngine::CollidableComponent>();
}


void GameBoard::CreateBackground()
{
	GameEngine::Entity* background = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(background);

	background->SetPos(sf::Vector2f(900.f, 500.f));
	background->SetSize(sf::Vector2f(1800.f, 1000.f));

	//Render
	GameEngine::SpriteRenderComponent* backrender = static_cast<GameEngine::SpriteRenderComponent*>
		(background->AddComponent<GameEngine::SpriteRenderComponent>());

	backrender->SetTexture(GameEngine::eTexture::Background);
	backrender->SetFillColor(sf::Color::Transparent);
	backrender->SetZLevel(-1);
}


void GameBoard::CreateBorderTop()
{
	BorderTop = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(BorderTop);

	BorderTop->SetPos(sf::Vector2f(900.f, 0.f));
	BorderTop->SetSize(sf::Vector2f(2000.f, 10.f));

	//Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
		(BorderTop->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::Transparent);

	BorderTop->AddComponent<GameEngine::CollidableComponent>();
}

void GameBoard::CreateBorderBot()
{
	BorderBot = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(BorderBot);

	BorderBot->SetPos(sf::Vector2f(900.f, 1000.f));
	BorderBot->SetSize(sf::Vector2f(2000.f, 10.f));

	//Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
		(BorderBot->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::Transparent);

	BorderBot->AddComponent<GameEngine::CollidableComponent>();
}


void GameBoard::CreateBorderLeft()
{
	BorderLeft = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(BorderLeft);

	BorderLeft->SetPos(sf::Vector2f(0.f, 500.f));
	BorderLeft->SetSize(sf::Vector2f(10.f, 1200.f));

	//Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
		(BorderLeft->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::Transparent);

	BorderLeft->AddComponent<GameEngine::CollidableComponent>();
}


void GameBoard::CreateBorderRight()
{
	BorderRight = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(BorderRight);

	BorderRight->SetPos(sf::Vector2f(1800.f, 500.f));
	BorderRight->SetSize(sf::Vector2f(10.f, 1200.f));

	//Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
		(BorderRight->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::Transparent);

	BorderRight->AddComponent<GameEngine::CollidableComponent>();
}
