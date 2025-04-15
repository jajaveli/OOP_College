#include<iostream>
class IDoDamage {
public:
	virtual void damageDo() = 0;
};
bool is_drunk = 0;

class Sword : public IDoDamage {
	int damage = 7;
public:
	void damageDo() {
		if (is_drunk == 1)
		{
		std::cout << "Вы нанесли ув.урон мечом в размере " << damage*2 << " pt.";
		is_drunk = 0;
		}
		else {	std::cout << "Вы нанесли урон мечом в размере " << damage  << " pt.";}
	}
};

class Bow : public IDoDamage
{
	int damage = 10;
public:
	void damageDo() {
		if (is_drunk == 1)
		{
			std::cout << "Вы нанесли ув.урон луком в размере " << damage * 2 << " pt.";
			is_drunk = 0;
		}
		else {std::cout << "Вы нанесли урон луком в размере " << damage  << " pt.";}
	}
};

class Potion_dmg : public IDoDamage
{
	int scale;
public:
	void damageDo(){
		std::cout << "Вы выпили пива, урон увеличен на 1 ход";
		is_drunk = 1;
	}
};

class Player {
public:
	void useItem(std::shared_ptr<IDoDamage>object) {
		object->damageDo();
	}
};
int main() {
	system("chcp 1251");
	std::shared_ptr<Sword> sword = std::make_shared<Sword>();
	std::shared_ptr<Bow> bow = std::make_shared<Bow>();
	std::shared_ptr<Potion_dmg> pdmg = std::make_shared<Potion_dmg>();
	Player player;
	int switch_on;
	do
	{
		std::cout << "\n1.Ударить мечом\n2.Стрелять из лука\n3.Выпить пива\n0.Закончить\n";
		std::cin >> switch_on;
		switch (switch_on)
		{
		case 1:
			player.useItem(sword);
			break;
		case 2:
			player.useItem(sword);
			break;
		case 3:
			player.useItem(pdmg);
			break;
		default:
			break;
		}
	} while (switch_on != 0);
	

}