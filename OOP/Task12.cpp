#include <iostream>

class Dice {
	int num_faces;
public:
	Dice() {};
	~Dice() {};
	int Throw() {
		int face = rand() % 6;
		std::cout << "Выпало число " + face << std::endl;
	}
};
class Player {
	std::shared_ptr<Dice>dice;
public:
	Player();
	~Player();
	void getDice() {

	}
	void throwDice() {
		std::make_shared<Dice>();
		
	}
	void putDice() {

	}
};

int main() {
	system("chcp 1251");
	srand(int(time(0)));
}