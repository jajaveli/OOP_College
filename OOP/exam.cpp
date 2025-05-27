#include <iostream>
#include <vector>
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


class Planet {
	std::string name, color; int num;
public:
	Planet() : name{ "govno" }, color{ " blue " }, num{ 1 } {};
	Planet( std::string name, std::string color, int num) : name{ name }, color{ color }, num{ num } {};
	void Input() { std::cin >> name >> color >> num; }
	void Output() { std::cout << " "<< name << " " << color << " " << num; }
};
int main() {
	std::vector<Planet>planets;
	Planet p1;
	planets.push_back(Planet("edgar", "orange", 124124));
	planets.push_back(Planet("easdar", "ogse", 16331213));
	planets.push_back(Planet());
	for (int i = 0; i < planets.size(); i++) { planets.at(i).Output(); }
}