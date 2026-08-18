#include<iostream>
#include"20260818_Task.h"

using namespace std;

int main(void)
{
	//変数宣言
	int hp = STATE_HP;

	Damage(&hp);

	cout << "ダメージ！20くらった！\n" << endl;
	cout << "現在のHP：" << hp << endl;

	Heal(&hp);

	cout << "回復した！\n" << endl;
	cout << "現在のHP" << hp << endl;

	cout << "最終的なHP" << hp << endl;
}

void Damage(int* hp)
{
	*hp -= ATTCK;
}

void  Heal(int* hp)
{
	*hp += HEAL;
}