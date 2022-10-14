SHELL=/bin/sh
CC=g++
CFLAGS=-Wall -Werror -Wextra
OS=$(shell uname)
ifeq ($(OS), Linux)
    CHECK_FLAGS=-lgtest -pthread -lrt -lm -lsubunit
else
    CHECK_FLAGS=-lgtest
endif
BUILD=3d_viewer
HOME=3dviewer_v2_0
TEST_COMPILE=$(CC) $(CFLAGS) test.cpp 3dviewer_v2_0/Model/data.cpp 3dviewer_v2_0/Model/af*.cpp $(CHECK_FLAGS)

all: install test

install: clean uninstall
	mkdir $(BUILD)
	cd $(HOME); qmake
	make -C ./$(HOME)
	cd $(HOME); mv moc_* ui_* 3dviewer_v2_0.app Makefile ../$(BUILD)
	cd $(HOME); mv *.o qrc_*.cpp ../$(BUILD); rm .qmake.stash

uninstall:
	rm -rf *.conf
	rm -rf $(BUILD)

start:
	./$(BUILD)/3dviewer_v2_0.app/Contents/MacOS/3dviewer_v2_0

test:
	$(TEST_COMPILE)
	./a.out
	make clean

dvi:
	makeinfo --html doc.texi
	open doc/index*

dist:
	make clean
	tar -czvf 3d_viewer.tar.gz Makefile $(HOME) test.cpp doc.texi examples screenshots

linter: 
	cp ../materials/linters/CPPLINT.cfg ./
	python3 ../materials/linters/cpplint.py --extensions=cpp $(HOME)/*/* $(HOME)/*.cpp
	rm CPPLINT.cfg

clean:
	rm -rf doc *.g* *.info *.out build*
