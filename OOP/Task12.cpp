#include <iostream>

class Dice {
	int num_faces = 6;
public:
	Dice() {}
	~Dice() {}
	int Throw() {
		int face = rand() % num_faces + 1;
		return face;
	}

};
class Player {
	std::shared_ptr<Dice>dice;
public:
	Player() {}
	
	void getDice(std::shared_ptr<Dice>_dice) {
		dice = _dice;
		_dice.reset();
	}
	void throwDice() {
		//std::make_shared<Dice>();
		//dice->Throw();
		std::cout << "Выпало число " << dice->Throw() << std::endl;
	}
	Player& putDice(std::shared_ptr<Dice>&_dice) {
		if (!dice) std::cout << "У тебя нет кубика\n";
		else if (_dice)std::cout << "Здесь уже лежит кубик\n";
		else { _dice = dice; dice.reset(); }
		return *this;
	}
	~Player() {}
};

int main() {
	system("chcp 1251");
	srand(int(time(0)));
	Player p1;
	std::shared_ptr<Dice> d1 = std::make_shared<Dice>(6);
	std::shared_ptr<Dice> d2 = std::make_shared<Dice>(6);
	//firsdt
	p1.getDice(d1);
	p1.throwDice();
	p1.putDice(d1);
	//second
	p1.getDice(d2);
	p1.throwDice();
	p1.putDice(d2);

}