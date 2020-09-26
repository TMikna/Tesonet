//Tomas Mikna 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <limits.h>
#include <dirent.h> 


char* getFirstWord(char* str);
int main(int argc, char *argv[]) {
	
	char *dir = getcwd(NULL, 0);
	printf(dir);
	char command[100];
	
	int x = 1;
	while(x){
		gets(command);
		
		if(strcmp ("list", command) == 0 ){
			  DIR *d;
			  struct dirent *dir;
			  d = opendir(".");
			  if (d) {
			    while ((dir = readdir(d)) != NULL) {
			      printf("%s\n", dir->d_name);
			    }
			    closedir(d);
			  }
		}
		else if (strcmp ("enter", getFirstWord(command)) == 0 ){
			printf("enter");
		}
		
		
		else if (strcmp ("stop", command) == 0 )
			x = 0;		


	}

	return 0;
}

char* getFirstWord(char* str){
	int len = sizeof(str)/sizeof(str[0]);
	char subStr[len];
	int i = 0;
	for (i = 0; i<len; i++)
		if (str[i] != '\0'){
			subStr[i] = str[i];
		}
		else{
			subStr[i] = '\0';
			break;
		}
	return subStr;
}

char** split(char* str){
	int len = sizeof(str)/sizeof(str[0]);
	char words[5][len];
	int i = 0; // original string
	int k = 0; // substr
	int j = 0; // will be j-th word
	while (str[i] != '\0')
	{
		while (str[i] != ' ')
			{
				words[j][k] = str[i];
				k++;
			}
		k = 0;
		j += 1;
	}
	return words;
}


