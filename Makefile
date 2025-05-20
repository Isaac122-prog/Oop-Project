all:
	g++ -std=c++11 -Wall Barista.cpp Cafe.cpp Chef.cpp Cleaner.cpp Customer.cpp Employee.cpp Game.cpp KitchenStaff.cpp main.cpp Player.cpp Table.cpp Waiter.cpp -lsfml-graphics -lsfml-window -lsfml-system -o cafe_game

run:
	./cafe_game

clean:
	rm -f cafe_game
