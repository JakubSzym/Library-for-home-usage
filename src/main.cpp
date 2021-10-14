/*
 *Plik zawiera funkcje glowna programu zarzadzajacego biblioteka
 *Autor: Jakub Szymkowiak
*/

#include "library.hh"

//deklaracja stalych
#define SEARCH_TITLE 0
#define SEARCH_AUTHOR 1
#define SEARCH_GENRE 2
#define SEARCH_USER 3
#define ADD_BOOK 4
#define ADD_USER 5
#define CHANGE_USER 6
#define END 7

#define OPTIONS 8
#define ENTER 10

using namespace std;

//incjalizacja zmiennych statycznych
unsigned int Library::howManyBooks;
unsigned int Library::howManyUsers;

int main(){
  //utworzenie biblioteki i wczytanie danych
  Library library;
  library.readBooks("baza_ksiazek.txt");
  library.readUsers("baza_uzytkownikow.txt");

  initscr(); //odtad dziala ncurses
  cbreak();  //mozna zakonczyc program poprzez kombinacje Ctrl+C

  //inicjalizacja okna
  WINDOW* win = newwin(10,30,0,0);
  box(win,0,0);
  refresh();
  wrefresh(win);

  keypad(win,true); //bedzie mozna czytac strzalki

  //tablica przechowuje opcje z menu
  string menu[OPTIONS] = {"1.Szukaj po tytule\n",  "2.Szukaj po autorze\n","3.Szukaj po gatunku\n" ,"4.Szukaj uzytkownikow\n","5.Dodaj ksiazke\n","6.Dodaj uzytkownika\n", "7.Zmien ksiazce uzytkownika\n", "8.Koniec dzialania programu\n"};

  //choice - ktory klawisz jest wcisniety
  //focus - ktory napis jest podswietlony (ktora opcja jest wybrana)
  int focus=0, choice;

  //petla glowna programu 
 while(true){
   //ponizsza petla obsluguje podswietlanie i wybieranie odpowiednich opcji z menu
  while(true){
    for(int i=0;i<OPTIONS; i++){
      if(i==focus)
	wattron(win, A_REVERSE);
      mvwprintw(win, i+1,1,menu[i].c_str());
      wattroff(win, A_REVERSE);
    }
    choice = wgetch(win);
    switch(choice){
    case KEY_UP:
      focus--;
      if(focus==-1)
	focus=0;
      break;
    case KEY_DOWN:
      focus++;
      if(focus==OPTIONS)
	focus=OPTIONS-1;
      break;
    default:
      break;
    }
    if(choice == ENTER) break;
  }
  
  clear(); //czyszczenie ekranu
  char* help = new char; //zmienna pomocnicza - scanw nie dziala dla typu std::string
  //switch obsluguje opcje dostepne w menu
    switch(focus){
    case SEARCH_TITLE:
      printw("Wyszukaj tytul: ");
      scanw("%s", help);
      library.searchTitle(help);
      printw("Nacisnij dowolny przycisk by powrocic do menu");
      break;
    case SEARCH_AUTHOR:
      printw("Wyszukaj autora: ");
      scanw("%s", help);
      library.searchAuthor(help);
      printw("Nacisnij dowolny przycisk by powrocic do menu");
      break;
    case SEARCH_GENRE:
      printw("Wyszukaj gatunek: ");
      scanw("%s", help);
      library.searchGenre(help);
      printw("Nacisnij dowolny przycisk by powrocic do menu");
      break;
    case SEARCH_USER:
      printw("Wyszukaj uzytkownika: ");
      scanw("%s", help);
      library.searchUser(help);
      printw("Nacisnij dowolny przycisk by powrocic do menu");
      break;
    case ADD_BOOK:
      library.addBook();
      printw("Nacisnij dowolny przycisk by powrocic do menu");
      break;
    case ADD_USER:
      {
      User newUser;
      newUser.read();
      library.getUsers().push_back(newUser);
      printw("Nacisnij dowolny przycisk by powrocic do menu");
      break;
      }
    case CHANGE_USER:
      {
      Book tmp;
      printw("Wyszukaj ksiazke: \n");
      tmp.read();
      library.changeUser(tmp);
      printw("Nacisnij dowolny przycisk by powrocic do menu");
      break;
      }
    default:
      break;
    }
    if(focus == END) break; //wyjscie z petli glownej, zakonczenie programu od strony uzytkownika
    getch();//oczekiwanie na wcisniecie dowolnego przycisku, nastepnie powrot do menu
    clear();//czyszczenie ekranu
    //powrot do okna
    box(win, 0, 0);
    refresh();
    wrefresh(win);
}
 endwin(); //koniec pracy z ncurses

 //zapisanie danych do plikow
  library.saveBooks("baza_ksiazek.txt");
  library.saveUsers("baza_uzytkownikow.txt");
}
