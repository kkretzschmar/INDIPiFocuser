all: focuser
	

PiFocuser.o: PiFocuser.cpp
	g++ -I../wiringPi/wiringPi  -c  PiFocuser.cpp -o PiFocuser.o

focusMain.o: focusMain.cpp
	g++ -I../wiringPi/wiringPi  -c  focusMain.cpp -o focusMain.o

focuser: focusMain.o PiFocuser.o
	g++ -o focuser focusMain.o PiFocuser.o  -pthread -lwiringPi 