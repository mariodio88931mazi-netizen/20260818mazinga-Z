#pragma once
#include "Config.h"

class Character
{
private:
	void Init
	(
		int HP
	);
	
public:
	void Attack();
	void Damage(Character* target);
	void Comand();
	void Heal();
};

