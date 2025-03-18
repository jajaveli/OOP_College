#include <iostream>
#include <vector>
class Student
{
	std::string name, class_ob, gender; int age, id;
	static int amount_of_students;
public:
	Student(std::string name,std::string class_ob, std::string gender, int age) {
		this->name = name;
		this->class_ob = class_ob;
		this-> gender = gender;
		this->age = age;
		amount_of_students++;
		id = amount_of_students;
	}
	//Сеттеры
	Student& setName(std::string name) {
		this->name = name;
		return *this;
	}
	Student& setClass(std::string class_ob) { 
		this->class_ob = class_ob;
		return *this; 
	}
	Student& setGender(std::string gender) { 
		this->gender = gender;
		return *this; 
	}
	Student& setAge(int age) { 
		this->name = name;
		return *this; 
	}
	Student& setId(int id) { 
		this->id = id;
		return *this; 
	}
	//Геттеры
	std::string getName() const{return name;}
	std::string getClass() const {return class_ob;}
	std::string getGender() const {return gender;}
	int getAge() const {return age;}
	int getId() const {return id;}

};
int Student::amount_of_students = 0;


int main() {
	system("chcp 1251");
	std::vector<Student>database;
	database.push_back(Student("Иван", "9B", "Механик", 5));
	database.push_back(Student("Тима", "85G", "Боевой вертолет", 84));
	database.push_back(Student("Александр", "5P", "this->", 16));
	do
	{
	int switch_on;
	std::cin >> switch_on;
	std::cout << "1.Вывод\n2.Редактирование\n3.Удаление\n4.Добавление\n_<";
	switch (switch_on)
	{
	case 1:
		for (int i = 0; i < database.size(); i++)
			{
			std::cout << "\nИмя: " << database.at(i).getName() << std::endl;
			std::cout << "Класс: " << database.at(i).getClass() << std::endl;
			std::cout << "Гендер: " << database.at(i).getGender() << std::endl;
			std::cout << "Возраст: " << database.at(i).getAge() << std::endl;
			std::cout << "Id: " << database.at(i).getId() << std::endl << std::endl;
			}
	break;
	case 2: 
	{
		int ent;
		std::string name;
		std::string class_ent;
		std::string gender;
		int age;
		for (int i = 0; i < database.size(); i++)
		{
			std::cout << "\nИмя: " << database.at(i).getName() << std::endl;
			std::cout << "Id: " << database.at(i).getId() << std::endl << std::endl;
		}
		std::cout << "Введите id для редактирования _<";
		std::cin >> ent;
		std::cout << "\nИмя: ";
		database.at(ent).setName(name);
		std::cout << "\nКласс: ";
		database.at(ent).setClass(class_ent);
		std::cout << "\nГендер: ";
		database.at(ent).setGender(gender);
		std::cout << "\nВозраст: ";
		//database.at(ent).setAge(age);
	}
	break;
	case 3: {
		int ent;
		for (int i = 0; i < database.size(); i++)
		{
			std::cout << "\nИмя: " << database.at(i).getName() << std::endl;
			std::cout << "Id: " << database.at(i).getId() << std::endl << std::endl;
		}
		std::cout << "Введите id для удаления _<";
		std::cin >> ent;
		database.erase(database.begin() + ent);
		break;
	}
	case 4:
		std::cout << "Hello World";
		break;
	default:
		break;
	}
} while (true);
	
}