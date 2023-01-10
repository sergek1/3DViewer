CXX = g++
STD = -std=c++17
CFLAG = -Wall -Werror -Wextra
GTEST_LIBS := -lgtest

all: compile run

install: compile
	@mkdir 3DViewer
	@cp 3d_viewer_2_0 3DViewer/3d_viewer_2_0
	@rm 3d_viewer_2_0

uninstall:
	rm -rf 3DViewer

dvi:
	texi2dvi foo.texi

dist: install
	tar --create --file 3DViewer.tar.gzip 3d_viewer_2_0

tests: clean
	$(CXX) $(STD) $(CFLAG) -o tests.out -I app/model/. test/test.cpp app/model/storage.cpp -lgcov $(GTEST_LIBS) --coverage
	@./tests.out

compile: clean build
	cd build ; qmake 3d_viewer_2_0.pro; make
	cp ./build/3d_viewer_2_0.app/Contents/MacOS/3d_viewer_2_0 .

run:
	./3d_viewer_2_0

gcov_report: tests
	@lcov --directory . -t "viewer_tests" -o gcovreport.info -c  --no-external
	@lcov -q --remove gcovreport.info "`pwd`/tests/*" -o gcovreport.info --rc lcov_function_coverage=0
	@genhtml -o $@ gcovreport.info
	@echo opening report `pwd`/gcov_report/index.html
	@open ./gcov_report/index.html

build:
	mkdir build
	cp -R app/ ./build/

clean:
	@rm -rf build 3d_viewer_2_0 *.gcda *.gcno gcov_report/ tests.out.dSYM/
	@rm -f tests.out app/.qmake.stash app/3d_viewer_2_0.pro.user
	@rm -f .clang-format
	@rm -f *.info *.gzip 3d_viewer_2_0 *.aux *.dvi *.log *.toc

style:
	cp ../materials/linters/.clang-format .
	cd app ; clang-format -n controller/*.h controller/*.cpp model/*.h model/*.cpp view/*.h view/*.cpp main.cpp

valgrind: tests
	valgrind --tool=memcheck --leak-check=full --track-origins=yes ./tests.out

leaks: tests
	leaks -atExit -- ./tests.out

cppcheck:
	cd app ; cppcheck --suppress=missingIncludeSystem --suppress=unknownMacro --std=c++17 --language=c++ controller/*.h controller/*.cpp model/*.h model/*.cpp view/*.h view/*.cpp main.cpp
