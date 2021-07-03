all : simpledb.o fsub.o fdiv.o research.o FLOPanalyzer.o tester.o

winall : simpledbwin fsub.o fdiv.o research.o FLOPanalyzer.o tester.exe

simpledb.o : ./src/SimpleDB/simpledb.c
	gcc -c ./src/SimpleDB/simpledb.c -o ./build/simpledb.o -lcurl
simpledbwin : ./src/SimpleDB/simpledb.c
	gcc -c ./src/SimpleDB/simpledb.c -o ./build/simpledb.o -lcurl -I "C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\include"
fsub.o : ./src/floatfuncs/fsub.c
	gcc -c ./src/floatfuncs/fsub.c -o ./build/fsub.o -O0
fdiv.o : ./src/floatfuncs/fdiv.c
	gcc -c ./src/floatfuncs/fdiv.c -o ./build/fdiv.o -O0
research.o : ./src/floatfuncs/research.c
	gcc -c ./src/floatfuncs/research.c -o ./build/research.o -O0
FLOPanalyzer.o : ./src/FLOPanalyzer.c
	gcc -c ./src/FLOPanalyzer.c -o ./build/FLOPanalyzer.o -lpthread -O0
tester.o : ./src/main.c ./src/FLOPanalyzer.c
	gcc ./build/simpledb.o ./build/fdiv.o ./build/fsub.o ./build/research.o ./build/FLOPanalyzer.o ./src/main.c -o ./build/executables/tester.o -pthread -lcurl -O0
tester.exe :  ./src/main.c ./src/FLOPanalyzer.c
	gcc ./build/simpledb.o ./build/fdiv.o ./build/fsub.o ./build/research.o ./build/FLOPanalyzer.o ./src/main.c -o ./build/executables/tester.exe -pthread -lcurl -O0 -I "C:\ProgramData\chocolatey\lib\mingw\tools\install\mingw64\include"
clean:
	rm -r ./build/FLOPanalyzer.o;\
	rm -r ./build/executables/tester.o;\
	rm -r ./build/fsub.o;\
	rm -r ./build/executables/tester.exe;\
	tm -r ./build/fdiv.o
winclean :
	del /f ./build/FLOPanalyzer.o;
	del /f ./build/executables/tester.o;
	del /f ./build/executables/tester.exe;
	del /f ./build/fsub.o;
	del /f ./build/fdiv.o
floptest :
	gcc FLOPanalyzer.c -o floptest.o -pthread
	echo "ouput file : floptest.o"