FLAGS=-Wall -pedantic -std=c++1z -iquote inc -lncurses
__start__:.//biblioteka

.//biblioteka: ./obj/main.o ./obj/library.o ./obj/book.o ./obj/user.o
	g++ -o .//biblioteka ./obj/main.o ./obj/library.o ./obj/book.o ./obj/user.o -lncurses
./obj:
	mkdir ./obj;
./obj/main.o: src/main.cpp inc/library.hh inc/book.hh
	g++ -c ${FLAGS} -o ./obj/main.o src/main.cpp
./obj/library.o: src/library.cpp inc/library.hh
	g++ -c ${FLAGS} -o ./obj/library.o src/library.cpp
./obj/book.o: src/book.cpp inc/book.hh
	g++ -c ${FLAGS} -o ./obj/book.o src/book.cpp
./obj/user.o: src/user.cpp inc/user.hh
	g++ -c ${FLAGS} -o ./obj/user.o src/user.cpp
clean:
	rm -f .//biblioteka ./obj/*
