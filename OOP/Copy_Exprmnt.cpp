#include <iostream>

class Expr {
public:
	int* arr = new int[2] {3,123};
	Expr() {
		std::cout << "конструктор сработал";
	}
	~Expr() {
		std::cout << "деструктор сработал"; delete[] arr; arr = nullptr;
	}
};

	
	
int main() {

}