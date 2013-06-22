#ProblemTwelve.mak
CC = gcc
WARNINGS = -Wall

all: ProblemTwelve.exe

ProblemTwelve.exe: ProblemTwelve.o inputs.o
	$(CC) $(WARNINGS) ProblemTwelve.o inputs.o -o ProblemTwelve.exe
	
ProblemTwelve.o: ProblemTwelve.c ProblemTwelve.h
	$(CC) -c ProblemTwelve.c
	
inputs.o: inputs.c inputs.h
	$(CC) -c inputs.c
	
clean:
	rm -rf *o ProblemTwelve.exe