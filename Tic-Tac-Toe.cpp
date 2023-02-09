#include<iostream>
#include <cstdlib>
#include<ctime>
#include<cstring>
using namespace std;
void printBoard(char board[3][3])
{
	//system("color 05");
	system("cls");
	cout << "\t\t\t\t*\t*";
	cout << "\t\t\t\t**\t**";
	cout << "\t\t\t\t***\t***";
	cout << "\t\t\t\t****\t****";
	cout << "\t\t\t\t*****\t*****";
	cout << "\t\t\t\t******\t******";
	cout << "\t\t\t\t*******\t*******";
	cout << "\t\t\t\t*******\t*******";
	cout << "\t\t\t\t******\t******";
	cout << "\t\t\t\t*****\t*****";
	cout << "\t\t\t\t****\t****";
	cout << "\t\t\t\t***\t***";
	cout << "\t\t\t\t**\t**";
	cout << "\t\t\t\t*\t*";

	cout << "\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout << "\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout << "\n\t\t\t\t TIC-TAC-TOE gman Game!";
	cout << "\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout << "\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout << endl << endl << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "\t\t\t\t\t\t\t";
		for (int j = 0; j < 3; j++)
		{
			if (j == 1 || j == 2)
			{
				cout << "||";
			}
			cout << "  " << board[i][j] << "  ";
		}
		cout << endl;
		if (i == 0 || i == 1) {
			cout << "\t\t\t\t\t\t\t-----||-----||-----" << endl;
		}
	}
}

void player1(char board[3][3]) {
	int r, c;
	cout << endl;
	cout << "PLAYER 1 ";
	cout << "Enter row : " << endl;
	cin >> r;
	cout << "Enter column : " << endl;
	cin >> c;
	while (1) {
		if (r < 0 || r>3) {
			cout << "Enter a valid row number : ";
			cin >> r;
		}
		else {
			break;
		}
	}
	while (1) {
		if (c < 0 || c>3) {
			cout << "Enter a valid column number : ";
			cin >> c;
		}
		else {
			break;
		}
	}

	while (1) {
		if (board[r - 1][c - 1] != '*') {
			cout << "Enter row : " << endl;
			cin >> r;
			cout << "Enter column : " << endl;
			cin >> c;
		}
		else {
			break;
		}
	}

	board[r - 1][c - 1] = 'X';
}

void player2(char board[3][3]) {
	int r, c;
	cout << endl;
	cout << "PLAYER 2 ";
	cout << "Enter row : " << endl;
	cin >> r;
	cout << "Enter column : " << endl;
	cin >> c;
	while (1) {
		if (r < 0 || r>3) {
			cout << "Enter a valid row number : ";
			cin >> r;
		}
		else {
			break;
		}
	}
	while (1) {
		if (c < 0 || c>3) {
			cout << "Enter a valid column number : ";
			cin >> c;
		}
		else {
			break;
		}
	}


	while (1) {
		if (board[r - 1][c - 1] != '*') {
			cout << "Enter row : " << endl;
			cin >> r;
			cout << "Enter column : " << endl;
			cin >> c;
		}
		else {
			break;
		}
	}

	board[r - 1][c - 1] = 'O';

}


void mainGame() {
	char board[3][3];
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			board[i][j] = '*';
		}
	}

	while (1) {
		system("cls");
		printBoard(board);
		player1(board);

		if (board[0][0] != '*' && board[0][1] != '*' && board[0][2] != '*' &&
			board[1][0] != '*' && board[1][1] != '*' && board[1][2] != '*' &&
			board[2][0] != '*' && board[2][1] != '*' && board[2][2] != '*' )
		{
			break;
			cout << endl << "\t\t\t\t\t\t Draw Game " << endl;
			
		}
		
		
		bool check1 = false;
		for (int i = 0; i < 3; i++) {
			int j = 0;
			if (board[i][j] == 'X' && board[i][j + 1] == 'X' && board[i][j + 2] == 'X') {
				printBoard(board);
				system("cls");
				cout << endl << "\t\t\t\t    Congrats Player 1..! You won the Game... " << endl;
				check1 = true;
				break;
			}
			if (board[j][i] == 'X' && board[j + 1][i] == 'X' && board[j + 2][i] == 'X') {
				system("cls");
				printBoard(board);
				cout << endl << "\t\t\t\t    Congrats Player 1..! You won the Game... !!! " << endl;
				check1 = true;
				break;
			}
			if ((board[i][j] == 'X' && board[i + 1][j + 1] == 'X' && board[i + 2][j + 2] == 'X')||
				(board[i][j + 2] == 'X' && board[i + 1][j + 1] == 'X' && board[i + 2][j] == 'X'))
				{
				system("cls");
				printBoard(board);
				cout << endl << "\t\t\t\t    Congrats Player 1..! You won the Game... !!! " << endl;
				check1 = true;
				break;
			}
		}
		if (check1 == true) {
			break;
		}


		system("cls");
		printBoard(board);
		player2(board);

		bool check2 = false;
		for (int i = 0; i < 3; i++) {
			int j = 0;
			if (board[i][j] == 'O' && board[i][j + 1] == 'O' && board[i][j + 2] == 'O') {
				system("cls");
				printBoard(board);
				cout << endl << "\t\t\t\t   Congrats Player 2..! You won the Game... !!! " << endl;
				check2 = true;
				break;
			}
			if (board[j][i] == 'O' && board[j + 1][i] == 'O' && board[j + 2][i] == 'O') {
				system("cls");
				printBoard(board);
				cout << endl << "\t\t\t\t    Congrats Player 2..! You won the Game... !!! " << endl;
				check2 = true;
				break;
			}
			if ((board[i][j] == 'O' && board[i + 1][j + 1] == 'O' && board[i + 2][j + 2] == 'O') || (board[i][j + 2] == 'O' && board[i + 1][j + 1] == 'O' && board[i + 2][j] == 'O')) {
				system("cls");
				printBoard(board);
				cout << endl << "\t\t\t\t    Congrats Player 2..! You won the Game... !!! " << endl;
				check2 = true;
				break;
			}
		}
		if (check2 == true) {
			break;
		}
	}
}
int main() {
	mainGame();
}
