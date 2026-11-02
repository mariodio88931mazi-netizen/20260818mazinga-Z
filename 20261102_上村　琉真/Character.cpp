#include "Character.h"
#include "Config.h"
#include "Enemy.h"
#include "Player.h"
#include <iostream>

using namespace std;



void Damage(Character teaget)
{
	HP =- ATK - DFE;
}

namespace player
{
	void Init()
	{
		HP = HP_MAX;
	}

	void Comand()
	{
		int num;
		cin >> num;

		cout << "‘I‚×ƒRƒ}ƒ“ƒh\n" << "1:UŒ‚\n2:–hŒä\n3:‰ñ•œ\n" << endl;

		if (num == 1)
		{
			Attack();
		}
		else if (num == 2)
		{
			cout << "–hŒäI" << endl;
		}
		else
		{
			Heal();
		}
	}

	void Attack()
	{
		cout << "ƒvƒŒƒCƒ„[‚ÌUŒ‚I" << endl;
		Damage();
	}

	void Heal()
	{
		cout << "‰ñ•œ‚µ‚½I" << endl;
		HP = HP + 20;;
	}
}

namespace enemy
{

	void Init()
	{
		HP = HP_MAX;
	}

	void Attack()
	{
		cout << "“G‚ÌUŒ‚I" << endl;
	}


}

int main(void)
{
	player::Attack();
	enemy::Attack();
	return 0;
}

