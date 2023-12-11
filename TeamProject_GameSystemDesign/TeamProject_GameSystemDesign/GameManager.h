#pragma once
#include"ProgramBase.h"
#include"TileManager.h"
#include"CardManager.h"
#include"ScreenManager.h"

#define VK_1 0x31
#define VK_2 0x32
#define VK_R 0x52

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
	void InputPlayer();
	void UseCard(int x, int y, Card card);
};