/*
 *Plik zawiera metody klasy User
 */

#include "user.hh"

using namespace std;

void User::write(){
  printw("Imie i nazwisko: %s\n", name.c_str());
  printw("PESEL: %s\n", pesel.c_str());
  printw("Adres: %s\n", address.c_str());
  printw("Email: %s\n", email.c_str());
}

void User::read(){
  char* help = new char;
  printw("Wprowadz imie i nazwisko: ");
  scanw("%s", help);
  name = help;
  printw("Wprowadz PESEL: ");
  scanw("%s", help);
  pesel = help;
  printw("Wprowadz adres: ");
  scanw("%s", help);
  address = help;
  printw("Wprowadz email: ");
  scanw("%s", help);
  email = help;
}

fstream& operator<<(fstream& file, User& user){
  file<<user.getName()<<" "<<user.getPesel()<<" ";
  file<<user.getAddress()<<" "<<user.getEmail()<<endl;

  return file;
}

fstream& operator>>(fstream& file, User& user){
  file>>user.getName()>>user.getPesel()>>user.getAddress()>>user.getEmail();
  return file;
}
