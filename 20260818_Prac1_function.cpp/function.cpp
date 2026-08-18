#include"20280818.h"
#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

using namespace std;

void createCard(int cards[])
{
	int index = 0;
	int number = 0;
	int count = 0;

	for (number = 1; number <= MAX_NUMBER; number++)
	{
		for (count = 0; count < number; count++)
		{
			cards[index] = number;
			index++;
		}
	}
}

void shuffleCard(int cards[])
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < TOTAL_CARD; i++)
	{
		int randomeIndex = rand() % TOTAL_CARD;

		int temp = cards[i];
		cards[i] = cards[randomeIndex];
		cards[randomeIndex] = temp;
	}
}

void showCard(int cards[])
{
	for (int i = 0; i < GROUP_CARD; i++)
	{
		cout << "[" << cards[i] << "]";
	}

	cout << endl;
}

void showHiddenCard(int cards[])
{
	for (int i = 0; i < GROUP_CARD; i++)
	{
		cout << "[?]";
	}
	cout << endl;
}