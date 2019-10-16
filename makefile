main:
	g++ -o program *.cpp
combine:
	g++ -o combine TextFileHelper.cpp TestMenu.cpp main.cpp
test:
	g++ -o test TextFileHelper.cpp TestMenu.cpp main.cpp AddMul.cpp NumberListGenerator.cpp TestHelper.cpp
clean:
	del *.o