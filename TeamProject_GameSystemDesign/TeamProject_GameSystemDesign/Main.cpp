#include"ProgramBase.h"
#include"PrintScreen.h"

int main(void)
{
	string tileStr;
	for (int y = 0; y < 7; y++)
	{
		for (int x = 0; x < 7; x++)
		{
			tileStr = to_string(x) + "," + to_string(y);
			PrintScreen::PrintTile(0 + TILESIZE_X * x, 0 + TILESIZE_Y * y, tileStr , COLOR_BLUE);
		}
	}

	

	return 0;
}