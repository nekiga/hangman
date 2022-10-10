#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int letterCheck(char c, char *word)
{
    int i;
    i = 0;
    while (word[i])
    {
        if (word[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int main(void)
{
    int randomNumber;
    char word[20];
    int i;
    char guess;
    int len;
    int j;
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
    i = 0;
    // removing new line character
    len = strlen(word);
    while (i++ < len)
    {
       if (word[i] == '\n')
        word[i] = '\0';
    }
   fclose(wordFile);
    //printf("%s\n", word);
    i = 1;
    j = 0;
    // looping through max numbers of trials 
    while (i <= 7)
    {
        if (i == 6) // checking if tries are at max
        {
            printf("Woops! You lost\n");
            break;
        }
        printf("Guess a letter:\n");
        scanf(" %c", &guess); // getting guess form user 
        if (letterCheck(guess, word) == 1) // checking if letter exists in word
        {
            if (j == len)
            {
                printf("GG!");
                break;
            }
            printf("You're right!\nGo again:)\n");
            j++;
            i++;
        }
        else // giving another try
         {
            printf("This letter is not in the word :C\n");
            printf("This is your %d try, you have 6 in total\n", i);
            i++;
         }
    }
    return(0);
}