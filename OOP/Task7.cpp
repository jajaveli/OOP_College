#include <iostream>

class DynArr {
	int* arr; int size;
public:
	DynArr() {//по умолч
		size = 1;
		arr = new int[size];
	}
	DynArr(int size) {//параметры
		this->size = size;
		arr = new int[size];
	}
	DynArr(DynArr&& obj) noexcept {//перемещение
		arr = obj.arr;
		obj.arr = nullptr;
	}
	~DynArr(){//деструктор
	delete[] arr;
	arr = nullptr;
	}	
	int& operator[](int index) {
		return arr[index];
	}
	friend std::ostream& operator<<(std::ostream& out, DynArr obj);
	
};
DynArr createArr(int size) {
	return DynArr(size);
}
std::ostream& operator<<(std::ostream& out, DynArr obj) {
	for (int i = 0; i < obj.size; i++){
		out << obj[i] << " ";
	}
	return out;
}

int main() {
	system("pause");
	DynArr arr = createArr(8000000);
	system("pause");
	DynArr arr1(std::move(arr));
	system("pause");
}