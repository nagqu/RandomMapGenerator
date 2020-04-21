#include <iostream>
#include <ctime>
#include <cstdlib>

const char chars[4] = { ' ', '~', '|', '^' };
const int Y = 29;
const int X = 120;

int mapBase[Y][X] = { 0 }; //yx
char map[Y][X] = {};

void genLakes(int radius, int n)
{
	int modFacX = X - 1 - (2 * radius);
	int modFacY = Y - 1 - (2 * radius);
	while (n != 0) {
		int x = rand() % modFacX + radius;
		int y = rand() % modFacY + radius;
		if (mapBase[y][x] == 0) {
			for (int i = y - radius; i <= y + radius; i++)
			{
				for (int j = x - radius; j <= x + radius; j++)
				{
					mapBase[i][j] = 1;
				}
			}
			n--;
		}
	}
}

void genMountains(int n)
{
	int x, y;
	while(n != 0)
	{
		
		x = rand() % X;
		y = rand() % Y;
		if (mapBase[y][x] == 0 || mapBase[y][x] == 2) {
			mapBase[y][x] = 3;
			n--;
		}
	}
}

void convertBaseToMap()
{
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			map[i][j] = chars[mapBase[i][j]];
		}
	}
}

int main()
{
	srand(time(NULL));
	genLakes(2, 3);
	genMountains(5);
	convertBaseToMap();
	int randNum;
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			std::cout << map[i][j];

		}
		std::cout << '\n';
	}
}

