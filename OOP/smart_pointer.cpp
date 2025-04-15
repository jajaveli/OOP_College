#include <iostream>

class Old {
public:
	virtual void info() {
		std::cout << "ÿ מכה\n";
	}
};

class Nouveau : public Old {
public: 
	void info() {
		std::cout << "ÿ םו מכה\n";
	}
};

int main() {
	system("chcp 1251");
	std::unique_ptr<Old>old = std::make_unique<Nouveau>();
	old->info();
}