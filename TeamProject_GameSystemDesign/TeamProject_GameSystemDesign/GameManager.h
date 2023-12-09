#pragma once
#include"ProgramBase.h"
#include"TileManager.h"
#include"CardManager.h"

class GameManager
{
private:
	TileManager tileManager;
	CardManager cardManager;
	int stageIndex;
	int nowTurn;
	int maxTurn;
public:
	GameManager();
	InitGame();
	InitStage(int stageIndex);

};