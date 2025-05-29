#include <iostream>
#include <vector>
//111111111111111111111111111111111111111111111111
//class Point {
//	std::string name; int cord_x, cord_y, cord_z;
//public:
//	Point() { name = "kto"; cord_x = cord_y = cord_z = 1; }
//	Point(std::string name, int cord_x, int cord_y, int cord_z) { this->name = name; this->cord_x = cord_x; this->cord_y = cord_y; this->cord_z = cord_z;}
//	void Cin() {std::cin >> name >> cord_x >> cord_y >> cord_z;}
//	void Cout() {std::cout << name << " " << cord_x << " " << cord_y << " " << cord_z;}
//};
//int main() {
//	Point p1, p2 ,p3;
//	p1 = Point();
//	p2 = Point("buba", 1, 2, 3);
//	p3.Cin();
//	p1.Cout(); p2.Cout();p3.Cout();
//}
// 22222222222222222222222222222222222222222222222222222222
//class Planet {
//	std::string name, color; int num;
//public:
//	Planet() : name{ "govno" }, color{ " blue " }, num{ 1 } {};
//	Planet( std::string name, std::string color, int num) : name{ name }, color{ color }, num{ num } {};
//	void Input() { std::cin >> name >> color >> num; }
//	void Output() { std::cout << " "<< name << " " << color << " " << num; }
//};
//int main() {
//	std::vector<Planet>planets;
//	Planet p1;
//	planets.push_back(Planet("edgar", "orange", 124124));
//	planets.push_back(Planet("easdar", "ogse", 16331213));
//	planets.push_back(Planet());
//	for (int i = 0; i < planets.size(); i++) { planets.at(i).Output(); }
//}
//33333333333333333333333333333333333333333333333
class Worker {
	int id, age; std::string name, floor;
public:
	Worker() {};
	Worker(int id) :Worker() { this->id = id;};
	Worker(int id,std::string name) :Worker() { this->id = id; this->name = name; };
	Worker(int id, std::string name, std::string floor) :Worker() { this->id = id; this->name = name; this->floor = floor; };
	Worker(int id, std::string name, std::string floor, int age) :Worker() { this->id = id; this->name = name; this->floor = floor; this->age = age; };
	void info() {
		std::cout << id << " " << name << " " << floor << " " << age << " ";
	}
};
int main() {
	std::vector<Worker>vect;
	vect.push_back(Worker(1, "Ivan", "laminat", 800));
	vect.push_back(Worker(2, "Pasha", "plitka", 4));
	vect.push_back(Worker(3, "Gocno", "kafel", 500));
	for (int i = 0; i < vect.size(); i++)
	{
		vect.at(i).info();
	}
}