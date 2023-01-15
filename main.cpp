#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <list>
#include <vector>

#include "Eveniment.hpp"
#include "Locatie.hpp"
#include "Meniu.hpp"
#include "Tichet.hpp"

int main() {
  std::list<Locatie> locatii;
  std::list<Eveniment> evenimente;
  std::list<Tichet> tichete;
}

/* asa scriu si citesc binar tot
   // Locatie locatie1("Locatie 1", 5, 5);
  // Locatie locatie2("Locatie 2", 2, 2);
  // Locatie locatie3("Locatie 3", 3, 3);

  // Eveniment eveniment1("Eveniment 1", "Detalii 1", 10.f, locatie1);
  // Eveniment eveniment2("Eveniment 2", "Detalii 2", 20.f, locatie2);
  // Eveniment eveniment3("Eveniment 3", "Detalii 3", 30.f, locatie3);

  // Tichet tichet1("VIP", eveniment1);
  // Tichet tichet2("VIP", eveniment2);
  // Tichet tichet3("VIP", eveniment3);

  // tichete.push_back(tichet1);
  // tichete.push_back(tichet2);
  // tichete.push_back(tichet3);

  // std::ofstream fout("tichete.txt", std::ios::binary);
  // for (auto tichet : tichete) {
  //   tichet.SaveToFile(fout);
  // }
  // fout.close();

  // std::ifstream fin("tichete.txt", std::ios::binary);
  // while (fin.peek() != EOF) {
  //   Tichet tichet;
  //   tichet.LoadFromFile(fin);
  //   tichete.push_back(tichet);
  // }
  // fin.close();

  // for (auto tichet : tichete) {
  //   locatii.push_back(tichet.getEveniment()->getLocatie());
  //   evenimente.push_back(*tichet.getEveniment());
  // }

  // for (auto locatie : locatii) {
  //   std::cout << "LOCATIE: " << locatie.getId() << std::endl;
  // }

  // for (auto eveniment : evenimente) {
  //   std::cout << "EVENIMENT: " << eveniment.getIDEveniment() << std::endl;
  // }
*/