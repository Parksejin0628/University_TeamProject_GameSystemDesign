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
	vector<string> stages;
public:
	GameManager();
	void InitGame();
	void InitStage(int stageIndex);
	void ReadFromFile();
};