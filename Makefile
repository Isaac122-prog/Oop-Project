all:
	g++ -std=c++20 -Wall -I/opt/homebrew/Cellar/sfml/3.0.1/include Barista.cpp Cafe.cpp Chef.cpp Cleaner.cpp Customer.cpp Employee.cpp Game.cpp KitchenStaff.cpp main.cpp Player.cpp Table.cpp Waiter.cpp -o cafe_game -L/opt/homebrew/Cellar/sfml/3.0.1/lib -lsfml-graphics -lsfml-window -lsfml-system

run:
	./cafe_game

clean:
	rm -f cafe_game
