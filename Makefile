CXXFLAGS=-Wall -pedantic

FLAGS:=-I./include

bin?=app
src?=$(shell find *.cpp -type f)
test=t.out

all: test
.PHONY: clean test

# debug: CXXFLAGS += -DDEBUG -g
# debug: clean $(bin);

clean:
	@if [ -f $(bin) ];then rm $(bin);fi
	@if [ -f $(test) ];then rm $(test);fi

$(test): test.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^ $(FLAGS)

test: clean $(test)
	@if [ -f $(test) ]; then ./$(test);fi

