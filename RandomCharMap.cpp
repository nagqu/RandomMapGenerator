#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

const char chars[4] = { ' ', '~', '|', '^' };
const int Y = 30;
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
					if (rand() % 5 == 0 && (j == x + radius || i == y + radius || i == y - radius))
					{
						break;
					}
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
	while (n != 0)
	{
		x = abs(rand() % X - 1);
		y = abs(rand() % Y - 1);
		if (mapBase[y - 1][x] != 1 && mapBase[y + 1][x] != 1 && mapBase[y][x - 1] != 1 && mapBase[y][x + 1] != 1 && (mapBase[y][x] == 0 || mapBase[y][x] == 2))
		{
				mapBase[y][x] = 3;
				n--;
		}

	}
}

void genTreeClusters(int n)
{
	int x, y;
	while (n != 0)
	{
		x = abs(rand() % X - 1);
		y = abs(rand() % Y - 1);
		if (mapBase[y - 1][x] != 1 && mapBase[y + 1][x] != 1 && mapBase[y][x - 1] != 1 && mapBase[y][x + 1] != 1 && mapBase[y][x] == 0)
		{
			mapBase[y][x] = 2;
			for (int i = 0; i < 2; i++)
			{
				mapBase[abs((y + (rand() % 2)) % Y)][(abs(x + (rand() % 2)) % X)] = 2;
				mapBase[abs((y - (rand() % 2)) % Y)][(abs(x + (rand() % 2)) % X)] = 2;
				mapBase[abs((y + (rand() % 2)) % Y)][(abs(x - (rand() % 2)) % X)] = 2;
				mapBase[abs((y - (rand() % 2)) % Y)][(abs(x - (rand() % 2)) % X)] = 2;
			}
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
	genLakes(2, 6);
	genMountains(30);
	genTreeClusters(40);
	convertBaseToMap();
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			std::cout << map[i][j];

		}
		std::cout << '\n';
	}
}

