all : FLOPanalyzer.o main.o
FLOPanalyzer.o : FLOPanalyzer.c
	gcc -c fmul.c;\
	gcc -c fadd.c;\
	gcc -c FLOPanalyzer.c -lpthread
main.o : main.c FLOPanalyzer.c
	gcc fmul.o fadd.o FLOPanalyzer.o main.c -o tester.o -lpthread;\
	gcc fmul.o fadd.o FLOPanalyzer.o main.c -o tester.exe -lpthread;\
	echo "output file : tester.o";\
	echo "output file : tester.exe";
clean:
	rm -r FLOPanalyzer.o;\
	rm -r tester.o;\
	rm -r fadd.o;\
	rm -r tester.exe;
floptest:
	gcc FLOPanalyzer.c -o floptest.o -pthread
	echo "ouput file : floptest.o"