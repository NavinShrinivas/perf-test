all : FLOPanalyzer.o main.o
FLOPanalyzer.o : FLOPanalyzer.c
	gcc -c FLOPanalyzer.c
main.o : main.c FLOPanalyzer.o
	gcc FLOPanalyzer.o main.c -o main.o;\
	echo "output file : main.o"
clean:
	rm -r FLOPanalyzer.o;\
	rm -r main.o
floptest:
	gcc FLOPanalyzer.c -o floptest.o -pthread
	echo "ouput file : floptest.o"