#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main()
{
	char str[100] = "";
	ifstream fin;
	char input;
	int chances = 7;
	while (chances > 0)
	{
		fin.open("hangman.txt", ios::in);
		if (!fin)
		{
			cout << "the file is not found." << endl;
		}
		else
	
		for (int i = 0; !fin.eof(); i++)
		{
			fin >> input;
			str[i] = input;
		}
			int length = strlen(str);
			char str1[100] = "-";
			char guess;
			int k = 0;
			int c = chances;
			for (int i =0 ; i <= chances;)
			{
				cout << "\n enter the alphabet you guess : " << endl;
				cin >> guess;
				if (guess == str[k])
				{
					str1[k] = guess;
					k++;
					i++;
					cout << "\t\n\nyou guess a right alphabet... your word is : ";
					for (int j = i, p = 0; j > 0; j--)
					{
						cout << str1[p];
						p++;
					}
				}
				else 
				{
					c--;
					
					cout << "chances left" << c << endl;
				}
			}
			str1[k] = '\0';
			bool flag = true;
			for (int i = 0; str[i] != '\0' && str1[i]!='\0'; i++)
			{
				if (str[i] == str1[i] && c > 0)
					flag = true;
				else
					flag = false;
			}
			if (flag == true)
			{
				cout << "\ncongrats...! YOU WON." << endl;
				break;	
			}
			else
			{
				cout << "\noops....YOU LOSE.";
				break;	
			}
	}
}


