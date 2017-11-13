CC=g++ -std=c++14
libs=RNBase.o RNInterpreter.o

run: main.cpp ${libs}
	${CC} $^ -o $@

%.o: %.cpp %.hpp
	${CC} -c $<

clean:
	rm -f *.o run
