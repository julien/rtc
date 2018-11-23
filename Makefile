CXXFLAGS=-Wall -pedantic
FLAGS:=-I./include
UNAME=$(shell uname -s)
ifeq ($(UNAME), Darwin)
	FLAGS+=-std=c++11 -stdlib=libc++
endif

bin?=app
src?=$(shell find *.cpp -type f)
test=t.out

all: test
.PHONY: clean test

debug: CXXFLAGS += -DDEBUG -g
debug: clean $(bin);

clean:
	@if [ -f $(bin) ];then rm $(bin);fi
	@if [ -f $(test) ];then rm $(test);fi

$(test): test.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^ $(FLAGS)

test: clean $(test)
	@if [ -f $(test) ]; then ./$(test);fi

