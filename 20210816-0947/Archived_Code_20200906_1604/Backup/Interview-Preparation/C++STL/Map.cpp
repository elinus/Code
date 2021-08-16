#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <algorithm>

struct PlanetComaprator {
    bool operator()(const std::string & left, const std::string & right) {
        return left > right;
    }
};

int main (int argc, char *argv[]) {
    std::map<std::string, int> planets;
    
    planets.insert(std::make_pair("mercury", 1));
    planets.insert(std::make_pair("venus", 2));
    planets["earth"] = 3;
    planets.insert(std::make_pair("mars", 4));
    planets["jupiter"] = 5;
    planets.insert(std::make_pair("saturn", 6));
    planets.insert(std::make_pair("uranus", 7));
    planets.insert(std::make_pair("neptune", 8));
    planets["pluto"] = 9;

    for (auto it = planets.begin(); it != planets.end(); ++it) {
        std::cout << it->first << " " << it->second << "\n";
    }
    std::cout << "\n\n";

    planets["earth"] = 0;
    for (auto it = planets.begin(); it != planets.end(); ++it) {
        std::cout << it->first << " " << it->second << "\n";
    }
    std::cout << "\n\n";

    if(planets.insert(std::make_pair("saturn", 0)).second == false) {
        std::cout << "Not able to insert\n";
    }


    std::map<std::string, int, PlanetComaprator> planets_dup;
    planets_dup.insert(std::make_pair("mercury", 1));
    planets_dup.insert(std::make_pair("venus", 2));
    planets_dup["earth"] = 3;
    planets_dup.insert(std::make_pair("mars", 4));
    planets_dup["jupiter"] = 5;
    planets_dup.insert(std::make_pair("saturn", 6));
    planets_dup.insert(std::make_pair("uranus", 7));
    planets_dup.insert(std::make_pair("neptune", 8));
    planets_dup["pluto"] = 9;
    for (auto it = planets_dup.begin(); it != planets_dup.end(); ++it) {
        std::cout << it->first << " " << it->second << "\n";
    }
    std::cout << "\n\n";


    return 0;
}

