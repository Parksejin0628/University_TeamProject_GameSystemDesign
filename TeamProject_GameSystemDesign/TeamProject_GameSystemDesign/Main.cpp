#include"ProgramBase.h"
#include"ScreenManager.h"
#include"GameManager.h"
#define MAXSIZE 5

int main(void)
{
	int x = 0;
	int y = 0;
	int stage = 1;
	srand((unsigned int)time(NULL));

	GameManager gameManager;
	gameManager.InitStage(stage);

	
	ScreenManager::PrintInGame(gameManager);
	while (1)
	{
		gameManager.InputPlayer();
		gameManager.AddTurn();
		if (gameManager.GetTIleManager().isClear() == true)
		{
			gameManager.GetCardManager().rewardCard(stage);
			gameManager.InitStage(++stage);
		}
		if (gameManager.GetNowTurn() > gameManager.GetMaxTurn())
		{
			gameManager.InitStage(stage);
		}
		ScreenManager::PrintStage(gameManager.GetTIleManager());
	}
	
	



	return 0;
}