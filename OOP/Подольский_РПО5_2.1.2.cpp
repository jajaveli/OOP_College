#include <iostream>
#include <vector>

class Company {

		std::string name; long dohod,oborot,clear_dohod, rashod; bool is_gos;
public:
	Company(std::string name, long dohod, long rashod, bool is_gos) {
		this->name = name;
		this->dohod = dohod;
		this->rashod = rashod;
		this->is_gos = is_gos;
		oborot = dohod + rashod;
		clear_dohod = dohod - rashod;
	}

	Company& setDohod(long _dohod) {
		dohod = _dohod;
		oborot = dohod + rashod;
		clear_dohod = dohod - rashod;
		return *this;
	}
	std::string getName()const {
		return name;
	}
	long getDohod() {
		if (!is_gos && dohod > 5000000) return dohod;
		if (!is_gos && dohod < 5000000) throw std::exception("информация недоступна\n");
		if (is_gos) throw std::exception("информация недоступна\n");
	}
	long getRashod() {
		if (!is_gos && dohod > 5000000) return rashod;
		if (!is_gos && dohod < 5000000) throw std::exception("информация недоступна\n");
		if (is_gos) throw std::exception("информация недоступна\n");
	}
	long getOborot()const {
		if (!is_gos && dohod > 5000000) return oborot;
		if (!is_gos && dohod < 5000000) throw std::exception("информация недоступна\n");
		if (is_gos)return oborot;
	};
	long getClearDohod()const {
		if (!is_gos && dohod > 5000000) return clear_dohod;
		if (!is_gos && dohod < 5000000) throw std::exception("информация недоступна\n");
		if (is_gos ) throw std::exception("информация недоступна\n");
	}
	bool getGos() {
		return is_gos;
	}
};

int main() {
	system("chcp 1251");
	std::vector<Company>database;
	database.push_back(Company("РЖД",45005423, 2089011,1));
	database.push_back(Company("Filip Pavlov",2145680, 678301,0));
	database.push_back(Company("Pavel Filipov",56709154, 8763408,0));
	database.push_back(Company("Газпром",1593587023, 91218954,1));

	std::cout << "1.Вывод";
	int input; std::cin >> input;
	switch (input)
	{
	case 1:
		for (int i = 0; i < database.size(); i++)
		{
			std::cout<< "Имя: "<<database.at(i).getName();
			try { std::cout << "\nДоход: " << database.at(i).getDohod(); }
			catch (const std::exception& ex) { std::cout << "\nДоход: " << ex.what(); }
			try { std::cout << "\nРасход: " << database.at(i).getRashod(); }
			catch (const std::exception& ex) { std::cout << "\nРасход: " << ex.what(); }
			try { std::cout << "\nГосударственная: " << database.at(i).getGos(); }
			catch (const std::exception& ex) { std::cout << "\nГосударственная: " << ex.what(); }
			try { std::cout << "\nОборот: " << database.at(i).getOborot(); }
			catch (const std::exception& ex) { std::cout << "\nОборот: " << ex.what(); }
			try { std::cout << "\nЧистая прибыль: " << database.at(i).getClearDohod() << std::endl; }
			catch (const std::exception& ex) { std::cout << "\nЧистая прибыль: " << ex.what(); }

		}
	default:
		break;
	}
}