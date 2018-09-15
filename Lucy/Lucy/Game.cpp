#include "Game.h"
#include "pch.h"
#include <stdlib.h>
#include "GameConst.h"

Game::Game()
{
	myGState = GameState::MENU;
	myIsRunning = true;
}

Game::~Game()
{
}

void Game::Run()
{
	while (myIsRunning)
	{
		Update();
	}
}

void Game::Update()
{
	Empty();
	switch (myGState)
	{
	case GameState::MENU:
		MainMenu();
		break;

	case GameState::GAME:
		myPlayer.Update();
		ThreadSleep(25);
		myWorld.Update();
		break;
	}
}

void Game::MainMenu()
{
	Print("GAME: " NAME);
	Print("Author: " AUTHOR "\n");
	Print("[1] Start");
	Print("[2] Exit");

	std::string tempCho;
	std::getline(std::cin, tempCho);
	try
	{
		myCho = std::stoi(tempCho);
	}
	catch (...) {}
	switch (myCho)
	{
	case 1:
		myGState = GameState::GAME;
		break;
	case 2:
		myIsRunning = false;
		break;
	}
}