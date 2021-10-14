/*
 *Plik zawiera metody klasy Library
 */

#include "library.hh"

using namespace std;

void Library::readBooks(string database){
  fstream file;
  file.open(database, ios::in);
  file>>howManyBooks;
  for(unsigned int i=0;i<howManyBooks; i++){
    Book tmp;
    file>>tmp;
    books.push_back(tmp);
  }
  file.close();
}

void Library::saveBooks(string database){
  fstream file;
  file.open(database, ios::out);
  file<<books.size()<<endl;
  for(unsigned int i=0; i<books.size();i++){
    file<<books[i]<<endl;
  }
  file.close();
}

void Library::readUsers(string database){
  fstream file;
  User tmp;
  file.open(database, ios::in);
  file>>howManyUsers;
  for(unsigned int i=0; i<howManyUsers; i++){
    file>>tmp;
    users.push_back(tmp);
  }
  file.close();
}

void Library::saveUsers(string database){
  fstream file;
  file.open(database, ios::out);
  file<<users.size()<<endl;
  for(unsigned int i=0; i<users.size(); i++){
    file<<users[i];
  }
  file.close();
}

void Library::searchTitle(char* title){
  string demand(title);
  for(unsigned int i=0; i<books.size();i++){
    if(books[i].getTitle() == demand){
      books[i].write();
      printw("------------------------------------\n");
    }
  }
}
void Library::searchAuthor(char* author){
  string demand(author);
  for(unsigned int i=0; i<books.size();i++){
    if(books[i].getAuthor() == demand){
      books[i].write();
      printw("-----------------------------------\n");
    }
  }
}

void Library::searchGenre(char* genre){
  string demand(genre);
  for(unsigned int i=0; i<books.size();i++){
    for(unsigned int j=0; j<books[i].getGenres().size(); j++){
      if(books[i].getGenres()[j] == demand){
        books[i].write();
	printw("--------------------------------\n");
      }
    }
  }
}

void Library::searchUser(char* name){
  string demand(name);
  for(unsigned int i=0; i<users.size(); i++){
    if(users[i].getName() == demand){
      users[i].write();
      printw("---------------------------------\n");
    }
  }
  for(unsigned int i=0; i<books.size(); i++){
    if(books[i].getCurrentUser().getName() == demand){
      books[i].write();
      printw("---------------------------------\n");
    }
  }
}

void Library::changeUser(Book book){
  char* help = new char;
  string newPesel;
  for(unsigned int i=0; i<books.size(); i++){
    if(books[i].getTitle() == book.getTitle() && books[i].getAuthor() == book.getAuthor() &&
       books[i].getYear() == book.getYear()){
      printw("Wprowadz PESEL nowego uzytkownika: ");
      scanw("%s", help);
      newPesel = help;
      for(unsigned int j=0; j<users.size(); j++){
	if(users[j].getPesel() == newPesel){
	  books[i].setCurrentUser(users[j]);
	  break;
	}
      }
      break;
    }
  }
}

void Library::addBook(){
  Book newBook;
  string tmp, pesel;
  char* help = new char;
  char sign='t';
  bool userFound = false;
  printw("Wprowadz tytul: ");
  scanw("%s", help);
  newBook.getTitle() = help;
  printw("Wprowadz autora: ");
  scanw("%s", help);
  newBook.getAuthor() = help;
  printw("Wprowadz rok wydania: ");
  scanw("%d", &(newBook.getYear()));
  printw("Wprowadz PESEL obecnego uzytkownika:\n");
  scanw("%s", help);
  pesel = help;

  for(unsigned int i=0; i<users.size();i++){
    if(users[i].getPesel() == pesel){
      newBook.setCurrentUser(users[i]);
      userFound = true;
      break;
    }
  }
  if(!userFound)
    printw("Nie znaleziono uzytkownika\n");

  printw("Wprowadz gatunek literacki: \n");

  while(sign=='t' || sign=='T'){
    printw("Czy dodac gatunek?(t - tak)\n");
    noecho();
    sign=getch();
    echo();
    if(sign=='t' || sign=='T'){
      printw("Wprowadz gatunek: ");
      scanw("%s", help);
      tmp = help;
      newBook.addGenre(tmp);
    }
  }

  books.push_back(newBook);
}
