#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "Eveniment.hpp"
#include "Locatie.hpp"
#include "eSportTickets.hpp"

int main() {
    Eveniment ev2("LOL Championship", "Finala LOL", 250, Locatie("Arena Nationala", 10, 10));

    eSportsTickets es2("VIP", ev2);
    eSportsTickets es3("VIP", ev2);
    eSportsTickets es4("VIP", ev2);
    eSportsTickets es5("VIP", ev2);
    eSportsTickets es6("VIP", ev2);
    eSportsTickets es7("VIP", ev2);
    eSportsTickets es8("VIP", ev2);
    eSportsTickets es9("VIP", ev2);
    eSportsTickets es10("VIP", ev2);
    eSportsTickets es11("VIP", ev2);
    eSportsTickets es12("VIP", ev2);    
    eSportsTickets es13("VIP", ev2);
    eSportsTickets es14("VIP", ev2);

//    std::cout << es2.getNrLoc() << ' ' << es2.getNrRand() << std::endl;
    std::cout << *es14.getEveniment() << std::endl;
}