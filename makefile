main:
	g++ -o program *.cpp
combine:
	g++ -o combine TextFileHelper.cpp TestMenu.cpp main.cpp
clean:
	del *.o