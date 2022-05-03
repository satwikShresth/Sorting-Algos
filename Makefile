build: bin/runTests bin/runTime 

#Run Everything
all: testAll timeAll

#Compile the Sort Code
obj/sorts.o: src/sorts.c src/sorts.h
	gcc -c -o obj/sorts.o src/sorts.c

#Compile the Test Code
obj/testLib.o: src/testLib.c src/testLib.h
	gcc -c -o obj/testLib.o src/testLib.c

#Build Executable to run test
bin/runTests: src/runTests.c obj/sorts.o obj/testLib.o
	gcc -o bin/runTests src/runTests.c obj/sorts.o obj/testLib.o

#Comple Timer Code
obj/timeLib.o: src/timeLib.c src/timeLib.h
	gcc -c -o obj/timeLib.o src/timeLib.c

#Build Executable to run timings
bin/runTime: src/runTime.c obj/sorts.o obj/testLib.o obj/timeLib.o
	gcc -o bin/runTime src/runTime.c obj/sorts.o obj/testLib.o obj/timeLib.o
	

#Test All 4 Sorts
testAll: bTest iTest mTest qTest

#Time All 4 Sorts
timeAll: bin/runTime
	./bin/runTime 17

#Test A Specific Sort
bTest: bin/runTests
	./bin/runTests b
iTest: bin/runTests
	./bin/runTests i
mTest: bin/runTests
	./bin/runTests m
qTest: bin/runTests
	./bin/runTests q

#Clean Up all Files
clean:
	rm -f obj/sorts.o
	rm -f obj/testLib.o
	rm -f obj/timeLib.o
	rm -f bin/runTests
	rm -f bin/runTime