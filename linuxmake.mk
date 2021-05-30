all : FLOPanalyzer.o main.o
FLOPanalyzer.o : FLOPanalyzer.c
	gcc -c FLOPanalyzer.c
main.o : main.c FLOPanalyzer.o
	gcc FLOPanalyzer.o main.c -o main.o
clean:
	rm -r FLOPanalyzer.o;\
	rm -r main.o	