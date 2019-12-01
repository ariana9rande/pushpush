#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Consola.h"
#include "map.h"
#include "keycode.h"
using namespace std;

void game();
void gameLoop(int);
bool clearCheck();

int getKey()
{
	int ch = _getch();
	if (ch == ' ')
		return SUBMIT;
	return (ch != 0xe0) ? ch : (0xe000 | _getch());
}

void xyputstr(int x, int y, const char* str)
{
	gotoxy(x, y);
	cout << str;
}

void fillbox(int x1, int y1, int x2, int y2, int color)
{
	textbackground(color);

	for (int y = y1; y <= y2; ++y)
		for (int x = x1; x <= x2; ++x)
		{
			gotoxy(x, y);
			putchar(' ');
		}
}

const char* cellSymbol[] = { "  ", "▒", "●", "★", "※", "  " };

int whereAtPlayer(int tempMap[10][MAP_HEIGHT][MAP_WIDTH])
{
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
			if (tempMap[stage][i][j] == 5)
			{
				return i * 10 + j;
			}
	}
}

void drawCell(int stage, int col, int row)
{
	int cell = tempMap[stage][row][col];

	textbackground((cell == 1) ? DARKGRAY : YELLOW);
	gotoxy((MAP_X1 + col + 1) * 2, MAP_Y1 + row + 1);
	puts(cellSymbol[cell]);
}

void drawCharacter(int mx, int my)
{
	textbackground(YELLOW);
//	gotoxy((MAP_X1 + mx + 1) * 2, MAP_Y1 + my + 1);
	gotoxy((MAP_X1 + mx + 1) * 2, MAP_Y1 + my + 1);
	puts("♀");
	textbackground(BLACK);
}

void drawMap()
{
	//system("cls");
	for (int row = 0; row < MAP_HEIGHT; ++row)
		for (int col = 0; col < MAP_WIDTH; ++col)
			drawCell(stage, col, row);
	textbackground(BLACK);
//	Sleep(3000);
}

void pushpushBox(int x, int y)
{
	gotoxy(x, y);     printf("┌────────────────┐\n");
	gotoxy(x, y + 1); printf("│                │\n");
	gotoxy(x, y + 2); printf("│ P U S H P U S H│\n");
	gotoxy(x, y + 3); printf("│                │\n");
	gotoxy(x, y + 4); printf("└────────────────┘\n");
}

void titleDraw()
{
	pushpushBox(40, 3);
}

int menuDraw()
{
	int x = 44, y = 12;

	gotoxy(x - 3, y + 10); cout << "select : space bar";
	gotoxy(x - 2, y); printf("> 게 임 시 작");
	gotoxy(x, y + 2); printf("게 임 정 보");
	gotoxy(x, y + 4); printf("게 임 종 료");

	while (1)
	{
		int input = getKey();
		switch (input)
		{
		case M_UPKEY:
			if (y > 12)
			{
				gotoxy(x - 2, y); printf(" ");
				gotoxy(x - 2, y -= 2); printf(">");
			}
			break;
		case M_DOWNKEY:
			if (y < 16)
			{
				gotoxy(x - 2, y); printf(" ");
				gotoxy(x - 2, y += 2); printf(">");
			}
			break;
		case SUBMIT:
			return y - 12;
		}
	}
}

void infoDraw()
{
	system("cls");
	cout << "\n\n";
	gotoxy(43, 5); cout << "조작법";
	gotoxy(40, 7); cout << "이동 : 방향키";
	gotoxy(38, 9); cout << "2018301087 홍재호";
	gotoxy(25, 12); cout << "스페이스바를 누르면 메인화면으로 이동합니다.";

	while (1)
	{
		if (getKey() == SUBMIT)
			break;
	}
}

int main()
{
	_setcursortype(_NOCURSOR);
	while (1)
	{
		titleDraw();
		int menuCode = menuDraw();
		if (menuCode == 0)
		{
			//if (n == 0)
			system("cls");
			gameLoop(stage);
		}
		else if (menuCode == 2)
		{
			infoDraw();
		}
		else if (menuCode == 4)
		{
			exit(1);
		}
		system("cls");
	}

	
}

void gameLoop(int stage)
{
	pushpushBox(40, 3);
	//bool isPlaying = TRUE;

	//if (stage == 0)
	memcpy(tempMap[stage], map[stage], sizeof(tempMap[stage]));

	drawMap();

	while (!clearCheck())
	{
		game();
	}
}

void game()
{
	int y = whereAtPlayer(tempMap) / 10, x = whereAtPlayer(tempMap) % 10;
	int key, oldx, oldy;
	int startX = x, startY = y;
	int tempX = x, tempY = y, dx = 0, dy = 0;
	int data, data2;
	do
	{
		
		tempMap[stage][y][x] = 0;
		whereAtPlayer(tempMap);
		drawCharacter(x, y);
		
		key = getKey();

		oldx = x;
		oldy = y;

		switch (key)
		{
		case M_UPKEY:
			if (y > 0)
			{
				dx = 0, dy = -1;
				//if (tempMap[y + dy][x] == 0)
				//y--;
				//cout << "y = " << y << endl;
			}
			break;
		case M_DOWNKEY: 
			if (y < MAP_HEIGHT - 1)
			{
				dx = 0, dy = 1;
				//if (tempMap[y + dy][x] == 0)
				//y++;
				//cout << "y = " << y << endl;
			}
				break;
		case M_LEFTKEY: 
			if (x > 0)
			{
				dx = -1, dy = 0;
				//if (tempMap[y][x + dx] == 0)
				//x--;
				//cout << "x = " << x << endl;
			}
			break;
		case M_RIGHTKEY: 
			if (x < MAP_WIDTH - 1)
			{
				dx = 1, dy = 0;
				//if (tempMap[y][x + dx] == 0)
				//x++;
				//cout << "x = " << x << endl;
			}
			break;
			
		}
		data = tempMap[stage][y + dy][x + dx];
		data2 = tempMap[stage][y + dy + dy][x + dx + dx];

		if (data == 2) {
			if (data2 == 0) {
				tempMap[stage][y + dy][x + dx] = 0;
				tempMap[stage][y + dy + dy][x + dx + dx] = 2;
				y += dy; x += dx;
				drawMap();
				}
			else if (data2 == 4) {
				tempMap[stage][y + dy][x + dx] = 0;
				tempMap[stage][y + dy + dy][x + dx + dx] = 3;
				y += dy; x += dx;
				drawMap();
			}

		}
		else if (data == 3) {
			if (data2 == 0) {
				tempMap[stage][y + dy][x + dx] = 4;
				tempMap[stage][y + dy + dy][x + dx + dx] = 2;
				y += dy; x += dx;
				drawMap();
			}
			else if (data2 == 4) {
				tempMap[stage][y + dy][x + dx] = 4;
				tempMap[stage][y + dy + dy][x + dx + dx] = 3;
				y += dy; x += dx;
				drawMap();
			}
		}

		else {
			if (data != 1) {
				y += dy; x += dx;
			}
		}
		gotoxy(40, 10);
		cout << "x : " << x << ", y : " << y;
		//충돌
		if (tempMap[stage][y][x] == 1)
		{
			x = oldx;
			y = oldy;
		}
		// erase old charactor
		if (oldx != x || oldy != y)
			drawMap();
		dx = 0; dy = 0;

		if (clearCheck())
		{
			gotoxy(15, 9);
			cout << "stage clear!!";
			key = _getch();
			system("cls");
			stage++;
			drawMap();
			break;
		}

	} while (key != 'r'); // && key != 't');
	::system("cls");
	tempMap[stage][startY][startX] = 5;
	pushpushBox(40, 3);
	memcpy(tempMap[stage], map[stage], sizeof(tempMap[stage]));
	drawMap();
	/*else if (key == 'e')
	{
		if (stage > 0)
		{
			::system("cls");
			tempMap[stage - 1][startY][startX] = 5;
			pushpushBox(40, 3);
			memcpy(tempMap[stage - 1], map[stage - 1], sizeof(tempMap[stage - 1]));
			drawMap();
		}
		else
		{
			x = oldx;
			y = oldy; 
			drawMap();
			tempMap[stage][startY][startX] = 5;
		}
	}
	else if (key == 't')
	{
		if (stage < 9)
		{
			::system("cls");
			tempMap[stage + 1][startY][startX] = 5;
			pushpushBox(40, 3);
			memcpy(tempMap[stage + 1], map[stage + 1], sizeof(tempMap[stage + 1]));
			drawMap();
		}
		else
			tempMap[stage][startY][startX] = 5;
	}*/
}

bool clearCheck()
{
	for (int i = 0; i < MAP_HEIGHT; i++)
		for (int j = 0; j < MAP_WIDTH; j++)
			if (tempMap[stage][i][j] == 4)
				return false;
	return true;
}