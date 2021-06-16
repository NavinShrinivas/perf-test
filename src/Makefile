all : fadd.o fmul.o FLOPanalyzer.o tester.o

winall : fadd.o fmul.o FLOPanalyzer.o tester.exe

fadd.o : ./floatfuncs/fadd.c
	gcc -c ./floatfuncs/fadd.c -o ../build/fadd.o
fmul.o : ./floatfuncs/fmul.c
	gcc -c ./floatfuncs/fmul.c -o ../build/fmul.o
FLOPanalyzer.o : FLOPanalyzer.c
	gcc -c FLOPanalyzer.c -o ../build/FLOPanalyzer.o -lpthread
tester.o : main.c FLOPanalyzer.c
	gcc ../build/fmul.o ../build/fadd.o ../build/FLOPanalyzer.o main.c -o ../build/executables/tester.o -pthread
tester.exe :  main.c FLOPanalyzer.c
	gcc ../build/fmul.o ../build/fadd.o ../build/FLOPanalyzer.o main.c -o ../build/executables/tester.exe -pthread
clean:
	rm -r ../build/FLOPanalyzer.o;\
	rm -r ../build/executables/tester.o;\
	rm -r ../build/fadd.o;\
	rm -r ../build/executables/tester.exe;\
	tm -r ../build/fmul.o
winclean :
	del /f ../build/FLOPanalyzer.o;
	del /f ../build/executables/tester.o;
	del /f ../build/executables/tester.exe;
	del /f ../build/fadd.o;
	del /f ../build/fmul.o
floptest :
	gcc FLOPanalyzer.c -o floptest.o -pthread
	echo "ouput file : floptest.o"