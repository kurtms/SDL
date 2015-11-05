game.out: game.o battle.o player.o map.o save.o menu.o
	g++ -lcurses -Wall -ansi -g -o game.out game.o battle.o player.o map.o save.o menu.o

game.o: game.cpp player.h map.h battle.h inventory.h save.h menu.h
	g++ -Wall -ansi -g -c game.cpp

battle.o: battle.cpp battle.h player.h inventory.h
	g++ -lcurses -Wall -ansi -g -c battle.cpp

player.o: player.cpp player.h inventory.h
	g++ -Wall -ansi -g -c player.cpp

map.o: map.cpp map.h battle.h inventory.h 
	g++ -lcurses -Wall -ansi -g -c map.cpp

save.o: save.cpp save.h game.h player.h
	g++ -Wall -ansi -g -c save.cpp

menu.o: menu.cpp menu.h
	g++ -Wall -ansi -g -c menu.cpp

encrypt: encrypt.cpp save.h save.cpp
	g++ -Wall -ansi -g -o encrypt.out encrypt.cpp save.o

clean:
	rm -f game.out battle.o player.o map.o save.o game.o menu.o
