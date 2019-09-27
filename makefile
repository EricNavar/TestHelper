main:
	g++ -o program TestHelper.cpp TextFileHelper.cpp main.cpp
combine:
	g++ -o combine TextFileHelper.cpp main.cpp
clean:
	del Combine.o TestHelper.o