#ifndef USER_HH
#define USER_HH

/*
 *Plik zawiera deklaracje klasy User, prototypy metod i przeciazenia operatorow wczytywania/zapisywania dla strumieni plikowych
*/

#include<string>
#include<iostream>
#include<fstream>
#include<ncurses.h>

class User{
private:
  std::string name;  //imie i nazwisko
  std::string pesel; //PESEL
  std::string address; //adres zamieszkania
  std::string email; //adres mailowy
  
public:

  //Ponizsze metody zezwalaja na dostep do skladnikow prywatnych
  std::string& getName(){ return name;}
  std::string& getPesel(){ return pesel;}
  std::string& getAddress(){ return address;}
  std::string& getEmail(){ return email;}

  //ustawianie nowych wartosci dla poszczegolnych skladnikow
  void setName(std::string nName){ name = nName;}
  void setPesel(std::string nPesel){ pesel = nPesel;}
  void setAddress(std::string nAddress){ address = nAddress;}
  void setEmail(std::string nEmail){ email = nEmail;}

  void read(); //wczytywanie z klawiatury
  void write(); //wypisywanie na ekran (ncurses)

 
};

/*
 *Przeciazenie operatora przesuniecia w lewo (zapisywanie)
 *Argumenty:
 *  file - strumien plikowy
 *  user - obiekt klasy User (dane o uzytkowniku)
 *Zwraca:
 *  strumien plikowy przez referencje
 */
std::fstream& operator<<(std::fstream& file, User& user);

/*
 *Przeciazenie operatora przesuniecia w prawo (czytanie)
 *Argumenty:
 *  file - strumien plikowy
 *  user - obiekt klasy User (dane o uzytkowniku)
 *Zwraca:
 *  strumien plikowy przez referencje
 */
std::fstream& operator>>(std::fstream& file, User& user);


#endif
