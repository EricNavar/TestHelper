main:
	g++ -o TestHelper Combine.cpp main.cpp
combine:
	g++ -o combine Combine.cpp main.cpp
clean:
	del Combine.o