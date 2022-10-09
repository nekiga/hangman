#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void)
{
    int randomNumber;
    char word[20];
    int i;
    // opens file
    FILE *wordFile = fopen("words.txt", "r");
    // check if file open was succesful
    if (wordFile == NULL)
    {
        printf("File could not be opened");
        return (1);
    }
    // generating a random number to pick the word
    srand(time(0));
    randomNumber = rand() % (1000 + 1 - 1) + 1; 
    // getting random word
    i = 0;
    while (i++ != randomNumber)
        fgets(word, 20, (FILE*) wordFile);
    // get letter from user


    return(0);
}