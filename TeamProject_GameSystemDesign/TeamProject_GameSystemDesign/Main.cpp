#include"ProgramBase.h"
#include"ScreenManager.h"
#include"GameManager.h"
#define MAXSIZE 5

int main(void)
{
	int x = 0;
	int y = 0;

	GameManager gameManager;

	
	ScreenManager::PrintInGame(gameManager);
	while (1)
	{
		gameManager.InputPlayer();
		ScreenManager::PrintStage(gameManager.GetTIleManager());
	}
	
	



	return 0;
}