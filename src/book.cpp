/*
 *Plik zawiera metody klasy Book oraz przeciazenia operatorow wczytywania/zapisywania dla klasy Book
 */

#include "book.hh"
using namespace std;

void Book::setCurrentUser(User user){
  currentUser.setName(user.getName());
  currentUser.setPesel(user.getPesel());
  currentUser.setAddress(user.getAddress());
  currentUser.setEmail(user.getEmail());
}

void Book::write(){
  printw("%s, %s, %d \n", title.c_str(), author.c_str(), year);
  for(unsigned int i=0; i<genres.size();i++){
    printw("%s ", genres[i].c_str());
  }
  printw("\n");
  printw("Obecny uzytkownik: %s %s\n", currentUser.getName().c_str(), currentUser.getPesel().c_str());
}

void Book::read(){
  string tmp;
  char* help = new char;
  printw("Wprowadz tytul: ");
  scanw("%s", help);
  title = help;
  printw("Wprowadz autora: ");
  scanw("%s", help);
  author = help;
  printw("Wprowadz rok wydania: ");
  scanw("%d", &(year));
 }

fstream& operator<<(fstream& file, Book& book){
  file<<book.getTitle()<<" "<<book.getAuthor()<<" "<<book.getYear()<<" ";
    for(unsigned int i=0;i<book.getGenres().size();i++){
      file<<book.getGenres()[i]<<" ";
    }
    file<<" | ";
    file<<book.getCurrentUser();
    return file;
  }
fstream& operator>>(fstream& file, Book& book){
  file>>book.getTitle()>>book.getAuthor()>>book.getYear();
  string tmp=" ";
  while(tmp != "|"){
    file>>tmp;
    if(tmp != "|")
      book.addGenre(tmp);
  }
  file>>book.getCurrentUser();

  return file;
}
