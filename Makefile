all : FLOPanalyzer.o main.o
FLOPanalyzer.o : FLOPanalyzer.c
	gcc -c FLOPanalyzer.c -lpthread
main.o : main.c FLOPanalyzer.o
	gcc FLOPanalyzer.o main.c -o tester.o -lpthread;\
	gcc FLOPanalyzer.o main.c -o tester.exe -lpthread;
	echo "output file : tester.o";\
	echo "output file : tester.exe";
clean:
	rm -r FLOPanalyzer.o;\
	rm -r tester.o;\
	rm -r tester.exe;
floptest:
	gcc FLOPanalyzer.c -o floptest.o -pthread
	echo "ouput file : floptest.o"