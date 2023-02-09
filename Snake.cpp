#include <iostream>
#include <conio.h>
using namespace std;
bool gameOver;
const int width = 50;
const int height = 30;
int x, y, fruitX, fruitY, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
void setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}
void Draw()
{
	system("cls");
	for (int i = 0; i < width + 2; i++)
	{
		cout << "#";
	}
	cout << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0) {
				cout << "#";
			}
			if (i == y && j == x)
				cout << "O";
			else if (i == fruitY && j == fruitX)
				cout << "F";
			else
				cout << " ";
			if (j == width - 1) {
				cout << "#";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; i++) {
		cout << "#";
	}
}
void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'w':
			dir = UP;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}
void logic()
{
	switch (dir)
	{
	
	case LEFT:
		x--;
		break;
	case RIGHT:
		x--;
		break;
	case UP:
		y++;
		break;
	case DOWN:
		y--;
		break;
	default:
		break;
	}
}
int main() {
	setup();
	while (!gameOver) {
		Draw();
		input();
		logic();
		//sleep(10); sleep (10);
	}
	system("Pause");
	return 0;
}