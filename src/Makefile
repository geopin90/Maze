CXX=g++
FLAGS=-Wall -Wextra -Werror
STD=-std=c++17
F_TEST=-lgtest
REP=--coverage
BD=../build/
MAZE=./Maze/Model/Matrix.cpp ./Maze/Model/InitMaze.cpp ./Maze/Model/FindPath.cpp
TESTS=./Tests.cpp
APP=$(BD)Maze.app
APP_INSTALL=$(HOME)/Applications/Maze/

all: install

build:
	mkdir $(BD)
	cp Maze.pro $(BD)
	cd $(BD) && qmake Maze.pro
	make -C $(BD)

install: build
	mkdir $(APP_INSTALL) 2>/dev/null
	cp -rf $(APP) $(APP_INSTALL)
	open $(APP_INSTALL)

uninstall: clean
	rm -rf $(APP_INSTALL)

tests:
	$(CXX) $(FLAGS) $(STD) $(REP) $(TESTS) $(MAZE) -o ./tests $(F_TEST)
	./tests

gcov_report: tests
	lcov -t "tests" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

dvi:
	open ./Documentation/info.html

dist:
	tar -cvf $(APP_INSTALL)Maze.tar $(APP_INSTALL)
	open $(APP_INSTALL)

clean:
	rm -rf $(BD)
	rm -rf tests *.gcda *.gcno *.info
	rm -rf ./report/

cpplint:
	cp -f ../materials/linters/CPPLINT.cfg ./
	python3 ../materials/linters/cpplint.py --extensions=cpp ./Maze/Controller/*.cpp ./Maze/Controller/*.h ./Maze/Model/*.cpp ./Maze/Model/*.h ./Maze/View/*.cpp ./Maze/View/*.h
	rm -rf CPPLINT.cfg

cppcheck:
	cppcheck --enable=all --suppress=unusedFunction --suppress=missingInclude Maze/*/*.cpp *.h

leaks:
	CK_FORK=no leaks --atExit -- ./tests
