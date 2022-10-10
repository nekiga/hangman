#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

void printRules(void)
{
    printf("Welcome to the hangman!\n");
    printf("There is a secret word you have to guess\n");
    printf("You may only guess one letter at a time\n");
    printf("Good luck! don't kill our... volunteer, Mathew. He has children.\n");
}
void printStats(int tries, char *correctGuesses, int len, char *word)
{
    int i;

    i = 0;
    printf("You are on try number %d. You have 8 total  |  ", tries);
    printf("The word has %d letters  |  ", len);
    printf("Here is a tip... We don't ACTUALLY hate Mathew:\n");
    while(i++ < strlen(word))
        {
            if ( i % 2 == 0)
                printf("%c", word[i]);
        }
        printf("\n");
    i = 0;
    printf("Here are the letters you already guessed: ");
    while (i++ < strlen(correctGuesses))
    {
        if (correctGuesses[i] >= 97 && correctGuesses[i] <=  122)
        printf("%c", correctGuesses[i]);
    }
    printf("\n");
    printf("\nEnter a . at anytime to quit\n\n");
}
int inString(char *guesses, char *word)
{
    int i;
    int j;
    int len;
    int len1;

    j = 0;
    i = 0;
    len = strlen(word);
    len1 = strlen(guesses);
    while (i++ < len1)
    {
        j = 0;
        while (j++ < len )
        {
            if (guesses[i] == word[j])
                return (j);
        }
    }
    return (j);
}

void stand(void)
{
    printf("      _______\n");
    printf("     |\n");
    printf("     |\n");
    printf("     |\n");
    printf("     |\n");
    printf("     |\n");
    printf("     |\n");
    printf("     |\n");
    printf("     |\n");
    printf("     |\n");
    printf("     |\n");
    printf("  --------\n");
    printf("Death is patient, it will wait.\n");
}

void head(void)
{
    printf("      _______\n");
    printf("     |      |\n");
    printf("     |     ####\n");
    printf("     |     #  #\n");
    printf("     |     ####\n");
    printf("     |\n");
    printf("     |\n");
    printf("     |\n");
    printf("     |\n");
    printf("     |\n");
    printf("     |\n");
    printf("     |\n");
    printf("     |\n");
    printf("     |\n");
    printf("  --------\n");
    printf("Remind Yourself That Overconfidence Is A Slow And Insidious Killer\n");
}

void body(void)
{
    printf("      _______\n");
    printf("     |      |\n");
    printf("     |     ####\n");
    printf("     |     #  #\n");
    printf("     |     ####\n");
    printf("     |      ||\n");
    printf("     |    #######\n");
    printf("     |      ###\n");
    printf("     |      ###\n");
    printf("     |      ###\n");
    printf("     |\n");
    printf("     |\n");
    printf("     |\n");
    printf("     |\n");
    printf("  --------\n");
    printf("As life ebbs, terrible vistas of emptiness reveal themselves.\n");
}

void arm(void)
{
    printf("      _______\n");
    printf("     |      |\n");
    printf("     |     ####\n");
    printf("     |     #  #\n");
    printf("     |     ####\n");
    printf("     |      ||\n");
    printf("     | ---#######----\n");
    printf("     |      ###\n");
    printf("     |      ###\n");
    printf("     |      ###\n");
    printf("     |\n");
    printf("     |\n");
    printf("     |\n");
    printf("     |\n");
    printf("  --------\n");
    printf("Do not ruminate on this fleeting failure, the campaign is long, and victory will come\n");
}

void legs(void)
{
    printf("      _______\n");
    printf("     |      |\n");
    printf("     |     ####\n");
    printf("     |     #  #\n");
    printf("     |     ####\n");
    printf("     |      ||\n");
    printf("     | ---#######----\n");
    printf("     |      ###\n");
    printf("     |      ###\n");
    printf("     |      ###\n");
    printf("     |      | |\n");
    printf("     |      | |\n");
    printf("     |\n");
    printf("     |\n");
    printf("  --------\n");
    printf("Leave her corpse to rot, consumed by the spores she spawned.\n");
}

void dead(void)
{
    printf("      _______\n");
    printf("     |      |\n");
    printf("     |     ####\n");
    printf("     |     X  X\n");
    printf("     |     ####\n");
    printf("     |      ||\n");
    printf("     | ---#######----\n");
    printf("     |      ###\n");
    printf("     |      ###\n");
    printf("     |      ###\n");
    printf("     |      | |\n");
    printf("     |      | |\n");
    printf("     |\n");
    printf("     |\n");
    printf("  --------\n");
    printf("Slowly, Gently, This Is How A Life Is Taken..\n");
}

int letterCheck(char c, char *word)
{
    int i;
    int len;

    len = strlen(word);
    i = 0;
    while (i < len)
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
    int k;
    char rightGuesses[20];
    int l;

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
        fgets(word, 20, (FILE *)wordFile);
    i = 0;
    k = 2;
    // removing new line character
    len = strlen(word);
    while (i++ < len)
    {
        if (word[i] == '\n')
            word[i] = '\0';
    }
    fclose(wordFile);
    system("cls");
    // printf("%s\n", word);
    i = 1;
    j = 0;
    while (i++ != 20)
    {
        rightGuesses[i] = '\0';
    }
    i = 1;
    // looping through max numbers of trials
    while (i <= 8)
    {
        system("cls");
     printRules();
       // printf("FOR TESTING THE SECRET WORD IS %s\n", word);
        printf("\n");
    //printword(len, rightGuesses, word);
    printf("\n");
    if (i == 1 )
        stand();
    if (i == 4 || i == 2 || i == 3)
        head();
    if (i == 5)
        body();
    if (i == 6)
        arm();
    if (i == 7)
        legs();
    
    if (i == 8) // checking if tries are at max
    {
        system("cls");
        dead();
        printf("You... really killed him... Jerry call his wife.\n");
        break;
    }
    printStats(i, rightGuesses, len, word);
    if (k == 0)
        printf("That was not correct.. Ouch\n");
    if (k == 1)
        printf("That was correct! Mathew was startign to sweat...\n");
    printf("Guess a letter:\n");
    scanf(" %c", &guess); // getting guess form user
    if (guess == '.')
    {
        system("cls");
        printf("The player has quit. I wonder what happens to Mathew now.\n");
        return (0);
    }
        
    if (letterCheck(guess, word) == 1) // checking if letter exists in word
    {
        if (j == len - 2)
        {
             system("cls");
            printf("oh... Mathew lives yet another day. i hope he has a good chiro\n");
            break;
        }
        rightGuesses[j] = guess;
        printf("You're right!\nGo again:)\n");
        k = 1;
        j++;
    }
    else // giving another try
    {
        k = 0;
        printf("This letter is not in the word :C\n");
        i++;
    }
}
return (0);
}