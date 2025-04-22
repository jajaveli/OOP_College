#include <iostream>
#include <vector>

class Apartment{
	int square, num_of_room;
public:
	Apartment() :square{ 75 }, num_of_room{ 2 } {  };
	~Apartment() { };
	void info(int apa) {
		std::cout << " Площадь: " << square << ", Количество комнат:" << num_of_room << std::endl;
	}
}; 

class Building {
	std::vector<Apartment>apartments;
public:
	Building() { std::cout << "Билдинг создан\n"; };
	~Building() { std::cout << "Билдинг удален\n"; };
	void addApartm() {
		apartments.push_back(Apartment());
		std::cout << "Квартира по адресу " << &apartments.back() << " построена\n";
	}
	void deleteApartm() {
		std::cout << "	Выберите квартиру чтобы удалить:\n";
		for (int i = 0; i < apartments.size(); i++)
		{
			std::cout << i << ". Квартира по адресу " << &apartments.at(i)<<std::endl;
		}
		int index;
		std::cin >> index;
		std::cout << "Квартира по адресу " << &apartments.at(index) << " исчезла\n";
		apartments.erase(apartments.begin()+index);
	}
	void info() {
		if (apartments.empty())
		{
			std::cout << "Билдинг снесен, владелец банкрот, квартиранты рыдают\n";
		}
		else
		{
				std::cout << "	Все квартиры:" << std::endl;
			for (int i = 0; i < apartments.size(); i++)
			{
				std::cout << i << ". Квартира по адресу " << &apartments.at(i); apartments.at(i).info(i);
			}
		}
		
	}
};

int main() {
	system("chcp 1251");
	Building b1;
	b1.addApartm();
	b1.addApartm();
	b1.info();
	b1.deleteApartm();
	b1.deleteApartm();
	b1.info();
}
