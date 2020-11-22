CPP=g++
CFLAGS=-O2 -fPIC
INC=-I/usr/include/Inventor \
	-I/usr/include/x86_64-linux-gnu/qt5/QtCore \
	-I/usr/include/x86_64-linux-gnu/qt5

LDFLAGS=-lSoQt -lCoin -lQt5Core -L/usr/lib/x86_64-linux-gnu

EXE=hello ex02cppvsiv ex03cppvsiv example21 example22 example23 example24 example31

all: $(EXE)

example31: example31.o
	g++ -o $@ $? $(LDFLAGS)
example31.o: example31.cpp
	$(CPP) $(CFLAGS) $(INC) -c -o $@ $?

example24: example24.o
	g++ -o $@ $? $(LDFLAGS)
example24.o: example24.cpp
	$(CPP) $(CFLAGS) $(INC) -c -o $@ $?

example23: example23.o
	g++ -o $@ $? $(LDFLAGS)
example23.o: example23.cpp
	$(CPP) $(CFLAGS) $(INC) -c -o $@ $?

example22: example22.o
	g++ -o $@ $? $(LDFLAGS)
example22.o: example22.cpp
	$(CPP) $(CFLAGS) $(INC) -c -o $@ $?

example21: example21.o
	g++ -o $@ $? $(LDFLAGS)
example21.o: example21.cpp
	$(CPP) $(CFLAGS) $(INC) -c -o $@ $?

ex03cppvsiv: ex03cppvsiv.o
	g++ -o $@ $? $(LDFLAGS)
ex03cppvsiv.o: ex03cppvsiv.cpp
	$(CPP) $(CFLAGS) $(INC) -c -o $@ $?

ex02cppvsiv: ex02cppvsiv.o
	g++ -o $@ $? $(LDFLAGS)
ex02cppvsiv.o: ex02cppvsiv.cpp
	$(CPP) $(CFLAGS) $(INC) -c -o $@ $?

hello: hello.o
	g++ -o $@ $? $(LDFLAGS)
hello.o: hello.cpp
	$(CPP) $(CFLAGS) $(INC) -c -o $@ $?

clean:
	rm -f $(EXE) *.o

