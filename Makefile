all : fadd.o fmul.o FLOPanalyzer.o tester.o

winall : fadd.o fmul.o FLOPanalyzer.o tester.exe

fadd.o : fadd.c
	gcc -c fadd.c
fmul.o : fmul.c
	gcc -c fmul.c
FLOPanalyzer.o : FLOPanalyzer.c
	gcc -c FLOPanalyzer.c -lpthread
texter.o : main.c FLOPanalyzer.c
	gcc fmul.o fadd.o FLOPanalyzer.o main.c -o tester.o -pthread
tester.exe :  main.c FLOPanalyzer.c
	gcc fmul.o fadd.o FLOPanalyzer.o main.c -o tester.exe -pthread
clean:
	rm -r FLOPanalyzer.o;\
	rm -r tester.o;\
	rm -r fadd.o;\
	rm -r tester.exe;\
	tm -r fmul.o
winclean:
	del /f FLOPanalyzer.o;
	del /f tester.o;
	del /f tester.exe;
	del /f fadd.o;
	del /f fmul.o
floptest:
	gcc FLOPanalyzer.c -o floptest.o -pthread
	echo "ouput file : floptest.o"