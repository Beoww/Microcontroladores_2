output: ./bin ./obj ./obj/main.o ./obj/calculator_functions.o ./obj/buttons.o ./obj/globals.o ./obj/gui.o ./obj/gui_buttons.o
	g++ -I ./lib ./obj/*.o -o ./bin/output `pkg-config --libs gtk+-3.0` `pkg-config --cflags gtk+-3.0`

./bin:
	mkdir ./bin

./obj:
	mkdir ./obj

./obj/main.o: ./obj main.cpp
	g++ -g -c -I ./lib main.cpp -o ./obj/main.o `pkg-config --libs gtk+-3.0` `pkg-config --cflags gtk+-3.0`

./obj/calculator_functions.o: ./obj ./src/calculator_functions.cpp ./lib/calculator_functions.h
	g++ -g -c -I ./lib ./src/calculator_functions.cpp -o ./obj/calculator_functions.o `pkg-config --libs gtk+-3.0` `pkg-config --cflags gtk+-3.0`

./obj/buttons.o: ./obj ./src/buttons.cpp ./lib/buttons.h
	g++ -g -c -I ./lib ./src/buttons.cpp -o ./obj/buttons.o `pkg-config --libs gtk+-3.0` `pkg-config --cflags gtk+-3.0`

./obj/globals.o: ./obj ./src/gui/globals.cpp ./lib/gui/globals.h
	g++ -g -c -I ./lib ./src/gui/globals.cpp -o ./obj/globals.o `pkg-config --libs gtk+-3.0` `pkg-config --cflags gtk+-3.0`

./obj/gui.o: ./obj ./src/gui/gui.cpp ./lib/gui/gui.h
	g++ -g -c -I ./lib ./src/gui/gui.cpp -o ./obj/gui.o `pkg-config --libs gtk+-3.0` `pkg-config --cflags gtk+-3.0`

./obj/gui_buttons.o: ./obj ./src/gui/gui_buttons.cpp ./lib/gui/gui_buttons.h
	g++ -g -c -I ./lib ./src/gui/gui_buttons.cpp -o ./obj/gui_buttons.o `pkg-config --libs gtk+-3.0` `pkg-config --cflags gtk+-3.0`

run:
	./bin/output

debug:
	gdb ./bin/output

clean:
	rm ./obj/*.o
	rm ./bin/output
	rm -r ./obj
	rm -r ./bin
