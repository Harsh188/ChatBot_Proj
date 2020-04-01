#include <stdio.h>
#include <string.h>
#include "header.h"

int main(int argc, char const *argv[]){
	/*
		This is the main method which is responsible for controling the program.
	*/
	char q[100];
	char movieTitle[100];
	intro();
	favMovie();
	movieQuiz();
	exitP();
	return 0;
}