#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void checkExit(char input[]);
void intro();
void favMovie();
void lower_string(char s[]);
void movieQuiz();
void exitP();

void checkExit(char input[]){
	/*
		This method checks if the user has entered "exit"
			TRUE:
				It says goodbye and ends the program
			FALSE:
				It returns nothing
	*/
	if (strcmp(input,"exit")==0){
		printf("\nWell seems like you have to go! Talk to you later!\n\n");
		exit(0);
	}
}

void lower_string(char s[]) {
	int c = 0;
	while (s[c] != '\0') {
		if (s[c] >= 'A' && s[c] <= 'Z'){
			s[c] = s[c] + 32;
		}
		c++;
	}
}

void intro(){
	/*
		This method introduces the program to the user. It gets the user's name and then returns
	*/
	printf("Welcome user! You will be connected to a chatbot soon. Enter 'exit' to end the program\n\n");
	printf("You have been connected to Jin Cook. He loves to talk about movies.\n\n");
	printf("Hi, I'm Jin! What's your name?\n");
	char name[100];
	scanf("%[^\n]s",name);
	checkExit(name);
	printf("\nNice to meet you %s!\n",name);
	printf("Name one of your hobbies if you have any\n",name);
	scanf("\n");
	scanf("%[^\n]s",name);
	checkExit(name);
	printf("\nWow %s huh... that sounds really fun\n",name);
	printf("Well one of mine is to watch movies during my free time!\n");
	printf("I love to watching movies! ");
	printf("Hey why dont we play a couple games regarding different movies?\n");
}

void favMovie(){
	/*
		This method asks the user for their favorite movie. Then it stores it in an array and returns
	*/
	FILE *fptr1;
	fptr1 = fopen("movieTitle.txt","r");
	if(fptr1 == NULL){
		printf("Error!");
		exit(1);
	}
	char title[200];
	printf("\nAlright tell me any movie title, I will give you differnt information about that movie\n");
	scanf("\n");
	scanf("%[^\n]s",title);
	checkExit(title);
	lower_string(title);
	// printf("%s\n", title);
	int ctr=0;
	char mTitle[100];
	while(fscanf(fptr1,"%[^\n]s",&mTitle)!=EOF){
		if (strcmp(mTitle,title)==0){
			break;
		}
		fscanf(fptr1,"\n");
		ctr++;
	}
	// printf("Line: %d\n",ctr);
	//Geting info of fav movie:
	FILE *fptr2;
	fptr2 = fopen("movieTag.txt","r");
	if(fptr2 == NULL){
		printf("Error!");
		exit(1);
	}
	FILE *fptr3;
	fptr3 = fopen("movieDate.txt","r");
	if(fptr1 == NULL){
		printf("Error!");
		exit(1);
	}
	FILE *fptr4;
	fptr4 = fopen("movieVote.txt","r");
	if(fptr4 == NULL){
		printf("Error!");
		exit(1);
	}
	char temp[10000];
	if (ctr!=20389)
	{
		printf("\nOh wow! I know a lot about that movie!\n");
		for (int i = 0; i < ctr; ++i){
			fscanf(fptr2,"%[^\n]s",&temp);
			fscanf(fptr3,"%[^\n]s",&temp);
			fscanf(fptr4,"%[^\n]s",&temp);
			fscanf(fptr2,"\n");
			fscanf(fptr3,"\n");
			fscanf(fptr4,"\n");
		}
		fscanf(fptr2,"%[^\n]s",temp);
		printf("The movie is about: %s\n", temp);
		fscanf(fptr3,"%[^\n]s",temp);
		printf("The movie was made in: %s\n",temp);
		fscanf(fptr4,"%[^\n]s",temp);
		printf("The movie is voted %s on a scale of 1-10.\n", temp);
		printf("This is fun!! Do you want to try another movie?\n");
		char ans[20];
		scanf("%s",&ans);
		checkExit(ans);
		if (strcmp(ans,"yes")==0){
			favMovie();
		}
	}
	else{
		printf("\nWhoops! seems like I am unable to recall this movie.\n");
		printf("Well there must be a mistake in your spelling or maybe I need to add this one to my watch list!\n");
	}
}
void movieQuiz(){
	printf("\nWell lets play another game shall we! This time I will give you the tagline of a movie and you will have 3 chances to guess the movie.\n");
	printf("Lets start!\n");
	int n = rand() %20390;
	FILE *fptr1;
	fptr1 = fopen("movieTitle.txt","r");
	if(fptr1 == NULL){
		printf("Error!");
		exit(1);
	}
	FILE *fptr2;
	fptr2 = fopen("movieTag.txt","r");
	if(fptr2 == NULL){
		printf("Error!");
		exit(1);
	}
	char title[100];
	char tag[500];
	printf("rand num: %d\n",n);
	for (int i = 0; i < n; ++i){
		fscanf(fptr1,"%[^\n]s",&title);
		fscanf(fptr2,"%[^\n]s",&tag);
		fscanf(fptr1,"\n");
		fscanf(fptr2,"\n");
	}
	fscanf(fptr1,"%[^\n]s",&title);
	fscanf(fptr2,"%[^\n]s",&tag);
	char ans[100];
	int guess=0;
	printf("\nHere is the tagline:\n%s",tag);
	for (int i = 1; i <=3; ++i){
		printf("\nAlright this is you guess number %d\n",i);
		printf("What movie do you think it is?\n");
		scanf("\n");
		scanf("%[^\n]s",&ans);
		if (strcmp(ans,title)==0){
			printf("YAY! you guessed it right\n");
			guess=1;
			break;
		}
		else{
			guess=0;
			printf("Not quite!\n");
		}
	}
	if (guess==0){
		printf("\nThe movie was %s\n",title);
	}
	printf("\nThis is fun!! Do you want to try another movie?\n");
	char in[20];
	scanf("%s",&in);
	checkExit(in);
	if (strcmp(in,"yes")==0){
		movieQuiz();
	}
}
void exitP(){
	printf("I had a blast talking with you but I have to run now!\n");
	printf("Talk to you later!!\n");
}

