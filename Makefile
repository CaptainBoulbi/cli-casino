PROJECTNAME=cli-casino
BIN=build/$(PROJECTNAME)
CC=g++

EXT=cpp
INCDIRS=include lib

# make mode=release
ifeq ($(mode), release)
	OPT=-O3
else
	OPT=-Og -g
endif
DEPFLAGS=-MP -MD
FLAGS=-Wall -Wextra $(foreach F,$(INCDIRS),-I$(F)) $(OPT) $(DEPFLAGS)

SRC=$(shell find . -name "*.$(EXT)" -path "./src/*")
OBJ=$(subst ./src/,./build/,$(SRC:.$(EXT)=.o))
DEP=$(OBJ:.o=.d)
TEST=$(shell find . -name "*.$(EXT)" -path "./test/*")

$(shell mkdir -p build)

all : $(BIN)

$(BIN) : $(OBJ)
	$(CC) $(FLAGS) -o $@ $^

-include $(DEP)

build/%.o : src/%.$(EXT)
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -o $@ -c $<

run : all
	./$(BIN)

clean :
	rm -rf build/*

# make test file=testGenID.cpp
test : $(OBJ)
	$(CC) $(FLAGS) -o build/$(file) test/$(file).$(EXT)
	./build/$(file)

alltest :
	@for f in $(subst ./test/,,$(TEST)); do make -s test file=$$f; done

# unzip : mkdir exemple && tar -xvf exemple.tgz -C exemple
dist : clean
	$(info /!\ project folder has to be named $(PROJECTNAME) /!\ )
	cd .. && tar zcvf $(PROJECTNAME)/build/$(PROJECTNAME).tgz $(PROJECTNAME) >/dev/null

install : dist $(BIN)
	cp build/$(PROJECTNAME).tgz $$HOME/dev/opt/archive
	cp $(BIN) $$HOME/dev/opt/built

check :
	cppcheck --enable=all --suppress=missingIncludeSystem $(foreach I,$(INCDIRS),-I$(I)) .
	flawfinder .

info :
	$(info put what ever)
	@echo you want

push :
	git push gh
	git push bbsrv

# alias

r : run

c : check

p : push

.PHONY : all run clean test alltest dist install check info push
