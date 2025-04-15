#include <iostream>
#include <vector>
#include <string>
class Body {
	int id;
	static int amount;
protected:
	int mass, coord_x, coord_y, jump;
public:
	Body() : mass(0), coord_x(0), coord_y(0), jump(0) { ++amount; id = amount; }
	int getId() {
		return id;
	}
	virtual int dropIt(double& force) = 0;
	virtual int getDiceNumber() { return 0; }
};
 
class Dice : public Body {
	int num, dice_number;
	int dropIt(double& force) override {
		force = force * force / (2 * force);
		dice_number = rand() % 6+1;
		return force;
	}
	int getDiceNumber() {
		return dice_number;
	}
};

class Ball : public Body {
	int high_of_jump;
	int dropIt(double& force) override {
		force = force * force / (2 * force);
		return force;
	}
};

int Body::amount = 0;

int main() {
	srand(int(time(0)));
	double force;
	double mass;
	Body* b1 = new Ball;
	Body* b2 = new Dice;
	std::cout << "Enter power for ball: "; std::cin >> force;
	
	Ball ball1;
	std::cout << "ID: " << b1->getId() << "\n";
	while (force > 1) {
		b1->dropIt(force); std::cout << "Force of rebound: " << force << "\n";
	}
	std::cout << "Enter power for dice: "; std::cin >> force; 
	std::cout << "ID: " << b2->getId() << "\n";
	while (force > 1) {
		b2->dropIt(force); std::cout << "\nForce of rebound: " << force << "\n" << "The number came up: " << b2->getDiceNumber();
	}
}