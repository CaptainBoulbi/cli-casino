# gcc for c g++ foc c++
compiler = g++
#obj = build/main.o build/monster.o
# -g for debug mode (for gbd) -O3 for release mod
mode = -g
flag = -Wall -Weffc++ -Wextra -Wsign-conversion $(state)

build/course : build/course.o
	$(compiler) $(flag) -o build/course build/course.o

build/course.o : src/course.cpp
	$(compiler) $(flag) -c src/course.cpp -o build/course.o

.PHONY : clean
clean :
	rm -r build/*

.PHONY : run
run : build/course
	./build/course

.PHONY : analyse
analyse :
	cppcheck --enable=all --suppress=missingIncludeSystem -I include/ .
	flawfinder .
