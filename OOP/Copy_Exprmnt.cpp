#include <iostream>

class Expr {
public:
	int* arr = new int[2] {3,123};
	Expr() {
		std::cout << "����������� ��������";
	}
	~Expr() {
		std::cout << "���������� ��������"; delete[] arr; arr = nullptr;
	}
};

	
	
int main() {

}