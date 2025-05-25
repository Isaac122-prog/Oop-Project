#// complie the game (cafe_game)
cafe_game: Barista.cpp Cafe.cpp Chef.cpp Cleaner.cpp Consumable.cpp Customer.cpp Employee.cpp Game.cpp KitchenStaff.cpp main.cpp Player.cpp Table.cpp Waiter.cpp
	g++ -std=c++20 -Wall -I/opt/homebrew/Cellar/sfml/3.0.1/include Barista.cpp Cafe.cpp Chef.cpp Cleaner.cpp Consumable.cpp Customer.cpp Employee.cpp Game.cpp KitchenStaff.cpp main.cpp Player.cpp Table.cpp Waiter.cpp -o cafe_game -L/opt/homebrew/Cellar/sfml/3.0.1/lib -lsfml-graphics -lsfml-window -lsfml-system

# to run the complied game
run: all
	g++ -std=c++20 -Wall -I/opt/homebrew/Cellar/sfml/3.0.1/include Barista.cpp Cafe.cpp Chef.cpp Cleaner.cpp Customer.cpp Employee.cpp Game.cpp KitchenStaff.cpp main.cpp Player.cpp Table.cpp Waiter.cpp -o cafe_game -L/opt/homebrew/Cellar/sfml/3.0.1/lib -lsfml-graphics -lsfml-window -lsfml-system
	./cafe_game

# remove the game from explorer
clean:
	rm -f *.o cafe_game
	
check_git:
	git status

git_upload:
	git add .
	git commit -m "Auto commit from Makefile"
	git push