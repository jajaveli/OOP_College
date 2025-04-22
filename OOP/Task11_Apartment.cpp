#include <iostream>
#include <vector>

class Apartment{
	int square, num_of_room;
public:
	Apartment() :square{ 75 }, num_of_room{ 2 } {  };
	~Apartment() { };
	void info(int apa) {
		std::cout << " �������: " << square << ", ���������� ������:" << num_of_room << std::endl;
	}
}; 

class Building {
	std::vector<Apartment>apartments;
public:
	Building() { std::cout << "������� ������\n"; };
	~Building() { std::cout << "������� ������\n"; };
	void addApartm() {
		apartments.push_back(Apartment());
		std::cout << "�������� �� ������ " << &apartments.back() << " ���������\n";
	}
	void deleteApartm() {
		std::cout << "	�������� �������� ����� �������:\n";
		for (int i = 0; i < apartments.size(); i++)
		{
			std::cout << i << ". �������� �� ������ " << &apartments.at(i)<<std::endl;
		}
		int index;
		std::cin >> index;
		std::cout << "�������� �� ������ " << &apartments.at(index) << " �������\n";
		apartments.erase(apartments.begin()+index);
	}
	void info() {
		if (apartments.empty())
		{
			std::cout << "������� ������, �������� �������, ����������� ������\n";
		}
		else
		{
				std::cout << "	��� ��������:" << std::endl;
			for (int i = 0; i < apartments.size(); i++)
			{
				std::cout << i << ". �������� �� ������ " << &apartments.at(i); apartments.at(i).info(i);
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
