main:
	g++ -o program TestHelper.cpp TextFileHelper.cpp TestMenu.cpp NumberListGenerator.cpp Timer.cpp main.cpp
combine:
	g++ -o combine TextFileHelper.cpp TestMenu.cpp main.cpp
clean:
	del Combine.o TestHelper.o TestMenu.o NumberListGenerator.o Timer.o