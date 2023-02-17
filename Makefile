read_write: main.cpp
	g++ -o read_write main.cpp file.cpp message.cpp user.cpp
	
clean: 
	rm *.txt read_write

