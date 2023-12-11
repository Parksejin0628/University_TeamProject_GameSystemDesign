#pragma once
#include "Tile.h"

class TileManager
{
private:
	int x, y;
	
	vector<vector<string>> stage;
	vector<string> stageData;

public:
  Tile tile[9][9];
  TileManager();
  void InitTile(int stageIndex); // 스테이지
  void SetTile(int y, int x, bool cure);
  void ReadFile();             // stages벡터에 스테이지 정보 가져오기
  vector<string> GetStage(int stageIndex); //
};