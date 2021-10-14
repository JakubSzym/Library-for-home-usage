#ifndef BOOK_HH
#define BOOK_HH

/*
 *Plik zawiera deklaracje klasy Book, prototypy metod, prototypy przeciazen operatorow czytania do / pisania z pliku
 */

#include<string.h>
#include<stdio.h>
#include<cstdlib>
#include<curses.h>
#include<ncurses.h>
#include<vector>
#include<iostream>
#include<fstream>
#include "user.hh"

class Book{
private:
  std::string title; //tytul ksiazki
  std::string author; //autor
  int year; //rok wydania
  User currentUser; //obecny uzytkownik
  std::vector<std::string> genres; //lista gatunkow, pod ktore ksiazka podpada
public:
  //metody do dostawania sie do skladnikow prywatnych
  std::string& getTitle(){ return title;}
  std::string& getAuthor(){return author;}
  User& getCurrentUser(){return currentUser;}
  int& getYear(){return year;}
  std::vector<std::string>& getGenres(){return genres;}

  //metody do ustawiania nowych wartosci skladnikow
  void setTitle(std::string nTitle){ title = nTitle;}
  void setAuthor(std::string nAuthor){ author = nAuthor;}
  void setCurrentUser(User user);
  void setYear(int nYear){ year = nYear;}
  void addGenre(std::string nGenre){ genres.push_back(nGenre);}

  void read(); //wczytywanie z klawiatury
  void write(); //wypisywanie na ekran (ncurses)
  
};

/*
 *Przeciazenie operatora przesuniecia w lewo (pisanie)
 *Argumenty:
 *  file - strumien plikowy
 *  book - obiekt klasy Book (dane o ksiazce)
 *Zwraca:
 * strumien plikowy przez referencje
 */
std::fstream& operator<<(std::fstream& file, Book& book);
/*
 *Przeciazenie operatora przesuniecia w prawo (czytanie)
 * file - strumien plikowy
 * book - obiekt klasy Book(dane o ksiazce)
 *Zwraca:
 * strumien plikowy przez referencje
 */
std::fstream& operator>>(std::fstream& file, Book& book);

#endif
