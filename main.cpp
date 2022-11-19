#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "Eveniment.hpp"
#include "Locatie.hpp"

int main() {
    Eveniment ev1("CS:GO", "2020-01-01", "12:00", "CS:GO Major", 100, 0, 100);
    Eveniment ev2("Dota 2", "2020-01-01", "12:00", "Dota 2 Major", 100, 0, 100);
    Eveniment ev3("League of Legends", "2020-01-01", "12:00", "League of Legends Major", 100, 0, 100, Locatie("WEEABO Bucuresti Romania Strada", 1, 1));

    std::cout << ev1 << std::endl;
    std::cout << ev2 << std::endl;
    std::cout << ev3 << std::endl;
}