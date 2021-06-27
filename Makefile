all : fsub.o fmul.o FLOPanalyzer.o tester.o

winall : fsub.o fmul.o FLOPanalyzer.o tester.exe

fsub.o : ./src/floatfuncs/fsub.c
	gcc -c ./src/floatfuncs/fsub.c -o ./build/fsub.o -O0
fmul.o : ./src/floatfuncs/fmul.c
	gcc -c ./src/floatfuncs/fmul.c -o ./build/fmul.o -O0
FLOPanalyzer.o : ./src/FLOPanalyzer.c
	gcc -c ./src/FLOPanalyzer.c -o ./build/FLOPanalyzer.o -lpthread -O0
tester.o : ./src/main.c ./src/FLOPanalyzer.c
	gcc ./build/fmul.o ./build/fsub.o ./build/FLOPanalyzer.o ./src/main.c -o ./build/executables/tester.o -pthread -O0
tester.exe :  ./src/main.c ./src/FLOPanalyzer.c
	gcc ./build/fmul.o ./build/fsub.o ./build/FLOPanalyzer.o ./src/main.c -o ./build/executables/tester.exe -pthread -O0
clean:
	rm -r ./build/FLOPanalyzer.o;\
	rm -r ./build/executables/tester.o;\
	rm -r ./build/fsub.o;\
	rm -r ./build/executables/tester.exe;\
	tm -r ./build/fmul.o
winclean :
	del /f ./build/FLOPanalyzer.o;
	del /f ./build/executables/tester.o;
	del /f ./build/executables/tester.exe;
	del /f ./build/fsub.o;
	del /f ./build/fmul.o
floptest :
	gcc FLOPanalyzer.c -o floptest.o -pthread
	echo "ouput file : floptest.o"