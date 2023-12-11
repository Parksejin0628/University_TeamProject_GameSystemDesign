#include"ProgramBase.h"
#include"ScreenManager.h"
#include"GameManager.h"
#define MAXSIZE 5

int main(void)
{
	int x = 0;
	int y = 0;

	GameManager gameManager;

	ScreenManager::PrintInGame(1, gameManager);
	gameManager.InputPlayer();

	

	return 0;
}