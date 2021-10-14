#ifndef LIBRARY_HH
#define LIBRARY_HH

/*
 *Plik zawiera deklaracje klasy Library
 */

#include "book.hh"
#include<iostream>
#include<fstream>
#include<vector>


class Library{
private:
  std::vector<User> users; //przechowuje dane o uzytkownikach
  std::vector<Book> books; //przechowuje dane o ksiazkach

public:

  static unsigned int howManyBooks; //zmienna statyczna - ile jest obecnie ksiazek w bibliotece
  static unsigned int howManyUsers; //zmienna statyczna - ilu jest uzytkownikow

  //metody pozwalajace dostac sie do skladnikow prywatnych
  std::vector<User> & getUsers(){ return users;}
  std::vector<Book> & getBooks(){ return books;}

  /*
   *Wczytuje informacje o ksiazkach z pliku
   *Argumenty:
   *  database - nazwa pliku z danymi
   */
  void readBooks(std::string database);

  /*
   *Wczytuje informacje o uzytkownikach
   *Argumenty:
   * database - nazwa pliku z danymi
   */
  void readUsers(std::string database);

  /*
   *Pod koniec dzialania programu zapisuje dane o ksiazkach do pliku
   *Argumenty:
   *  database - nazwa pliku
   */
  void saveBooks(std::string database);

  /*
   *Pod koniec dzialania programu zapisuje dane o uzytkownikach do pliku
   *Argumenty:
   *  database - nazwa pliku
   */
  void saveUsers(std::string database);


  /*
   *Szuka ksiazki o danym tytule
   */
  void searchTitle(char* title);

  /*
   *Szuka ksiazek danego autora
   */
  void searchAuthor(char* author);

  /*
   *Szuka ksiazek z danego gatunku
   */
  void searchGenre(char* genre);

  /*
   *Szuka uzytkownikow o danym imieniu i nazwisku
   *
   */
  void searchUser(char* name);

  /*
   *Dodaje opisana przez uzytkownika ksiazke do bazy
   */
  void addBook();

  /*
   *Zmienia uzytkownika ksiazce o danych parametrach
   */
  void changeUser(Book book);
  
};

#endif
