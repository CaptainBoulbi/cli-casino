
build/course : build/course.o
	g++ -o build/course build/course.o

build/course.o : src/course.cpp
	g++ -c src/course.cpp -o build/course.o

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
