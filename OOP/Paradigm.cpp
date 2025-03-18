/*Парадигма ООП направлена на упрощение архитектурной разработки и проектирования.Также позволяет облегчить дальнейшую поддержку
проекта*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Planet {
    string p_name;
    int diam, density;


public:
    Planet() {
        string name = " "; int diameter = 0, dens = 0;
    }

    Planet(string name, int diameter, int dens) {
        p_name = name;
        diam = diameter;
        density = dens;
    }


    void print() {
        cout << "планета: " << p_name << endl;
        cout << "диаметр: " << diam << " км" << endl;
        cout << "плотность: " << density << " kг/м^3" << endl;

    }
    Planet& setName(std::string _name) { p_name = _name; return *this; }
    Planet& setDiam(int _diam) { diam = _diam; return *this; }
    Planet& setDensity(int _density) { density = _density; return *this; }
    
    string getName() const { return p_name; }
    int getDiam() const { return diam; }
    int getDensity() const { return density; }
};

int main() {
    system("chcp 1251");
    vector<Planet> planet_vector;


    planet_vector.push_back(Planet("меркурий", 4879, 5427));
    planet_vector.push_back(Planet("марс", 6779, 3933));
    planet_vector.push_back(Planet("юпитер", 139820, 1326));

    planet_vector.push_back(Planet().setName("земля"));
    planet_vector.push_back(Planet().setDiam(1241));
    planet_vector.push_back(Planet().setDensity(2718));

    for (size_t i = 0; i < planet_vector.size(); i++)
    {
        for (size_t j = 0; j < planet_vector.size()-1; j++)
        {
            if (planet_vector.at(j).getDiam() > planet_vector.at(j+1).getDiam())
            {
                std::swap(planet_vector.at(j), planet_vector.at(j+1));
            }
        }
    }
    for (int i = 0; i < planet_vector.size(); i++)
    {
        planet_vector.at(i).print();
    }
    return 0;
}