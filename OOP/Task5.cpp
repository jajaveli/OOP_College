#include <iostream>
#include <vector>

class Worker {
	int id,age,otdel;
	std::string name, rank, gender;
public:
	Worker() {
		id = age = otdel = 0;
		name = rank = gender = "";
	}
	Worker(int id) : Worker() { this->id = id; }//id
	Worker(int id, int age) : Worker() { this->id = id; this->age = age; }//id age
	Worker(int id, int age,std::string name) : Worker() { this->id = id; this->age = age; this->name = name; }//id age name
	Worker(int id, int age,std::string name, std::string rank) : Worker() //id age name rank
	{ this->id = id; this->age = age; this->name = name; this->rank = rank;  }
	Worker(int id, int age,std::string name, std::string rank, int otdel) : Worker() //id age name rank otdel
	{ this->id = id; this->age = age; this->name = name; this->rank = rank; this->otdel = otdel;  }
	Worker(int id, int age,std::string name, std::string rank, int otdel,std::string gender) : Worker()//id age name rank otdel gender
	{ this->id = id; this->age = age; this->name = name; this->rank = rank; this->otdel = otdel; this->gender = gender; }

	void info() {
		std::cout << id << "\n" << age << "\n" << name << "\n" << rank << "\n" << otdel << "\n" << gender;
	}
	void redact() {
		std::cin >> age >> name >> rank >> otdel >> gender;
	}void add() {
		std::cin >> id >> age >> name >> rank >> otdel >> gender;
	}
};

int main() {
	std::vector<Worker>info;
	int choise;
	info.push_back(Worker(1, 23, "Ogr", "genius", 1, "mechanic"));
	do
	{
		std::cout << "1.print\n2.edit\n3.add\n4.delete\n0.exit";
		std::cin >> choise;
		switch (choise)
		{
		case 1:
			for (int i = 0; i < info.size(); i++)
			{
				info.at(i).info();
			}
			break;
		case 2:
			for (int i = 0; i < info.size(); i++)
			{
				info.at(i).info();
				info.at(i).redact();
			}
			break;
		case 3:
			for (int i = 0; i < info.size(); i++)
			{
				info.at(i).add();
			}
		default:
			break;
		}

	} while (choise != 0);
}