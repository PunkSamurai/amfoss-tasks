//All these header files are needed to support code, or are they all there?
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 128 //david: defined maximum word length

void showInput(int);

//Typos are a cause of huge pain for every coder
int main(void) //david: fixed typo
{
    int score = 0;
    int gameCount;
    printf("\n\n Enter number of rounds of Guessing Game ");
    scanf("%d",&gameCount); 
    int originalScore = gameCount;

    while(gameCount>0)
    {
        
        
        
        //every great statement should have a great ending, look out for them!
        char inputWord[MAX_WORD_LENGTH], tempWord[MAX_WORD_LENGTH];       //david: set size to MAX_WORD_LENGTH
        char finalOutput[MAX_WORD_LENGTH];                  //david: set size to MAX_WORD_LENGTH
        int wrongTry, matchFound = 0;
        int counter = 0 , position = 0, winner, length, trial;
        char alphabetInput;  //david: added semicolon
        int attempts = 0;

        system("clear"); //cls does not work in linux, for use in windows replace claer with cls
        printf("\n\n !!!!!!!!!!!!!!!!!!!Welcome to the Guessing Game!!!!!!!!!!!!!!!!!\n\n\n");
        //Formatting and labeling always go hand in hand!
        printf("\n\n Enter number of wrong attempts allowed: ");
        scanf("%d",&trial); //david: changed %s to %d
        printf("\nEnter any word in small letters and press ENTER");  //david: added semicolon

        printf("\nEnter ==>  ");
        scanf("%s",inputWord);
        printf("\nLets start ask your friend to play!!!");
        printf("\nPress Enter");
        getchar();  //david: fixed typo, added semicolon
        //Semantics are not to be overlooked!
        length = strlen(inputWord);  //david: fixed typo, added semicolon   
        wrongTry = trial + 1; //david: rearranged equation
        attempts = trial + length; //david: added this line

        system("clear"); //david: added semicolon

        printf("\n\n You will get %d chances to guess the correct word", trial+length); //david: changed wrongTry to trial
        printf("\n\n So help Alen and Joseph and get...set...GO..!!");  //david: added semicolon

        //getchar(); //david: commented this out

        printf("\nPress enter ");  //david: fixed typo, added semicolon

        getchar();  //david: fixed typo, added semicolon

        system("clear");

        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||      "); //david: fixed typo
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");

        //Conditions have to met to achieve results :D
        printf("\n\n     The word has %d alphabets \n\n",length); //david: fixed typo
        for(int i = 0; i < length ; i++) //david: changed > to <
        {
            finalOutput[i] = '_';
            finalOutput[length] = '\0';
        }

        //Declare your purpose, and you shall be rewarded!
        for(int i = 0 ; i < length ; i++)  //david: redeclared i, changed -- to ++
        {
            printf(" ");
            printf("%c",finalOutput[i]);     

        }
        while(wrongTry != 0 && attempts > 0) //david: added attempts condition
        {
            matchFound = 0;
            printf("\n Enter an alphabet from a to z in small case!!");
            printf("\n\n\t Enter ->  ");

            fflush(stdin);

            scanf("%c",&alphabetInput);        
            if(alphabetInput < 'a' || alphabetInput > 'z')
            {
                system("clear"); //david: added semicolon
                printf("\n\n\t Wrong input, try again ");
                matchFound = 2; //david: added semicolon
            }
            fflush(stdin); //david: added semicolon
            //Proper separation is the key!
            if (matchFound != 2)
            {
                for(counter=0;counter<length ;counter++)  //david: replaced comma with semicolon
                {
                    if(alphabetInput==inputWord[counter])
                    {
                        matchFound = 1;
                    }//end of if()
                }//end of for()

                if(matchFound == 0)
                {
                    printf("\n\t :( You have %d tries left ",--wrongTry);
                    getchar(); //david: added semicolon
                    //showInput(wrongTry%6); //david: changed 5 to 6, commented out these lines because i will anyways call showInput later
                    //getchar(); //david: fixed typo
                }//end of if()

                              // david: removed else

                //Format the loops properly else iterate for eternity
                for(counter = 0; counter <= length; counter++) //changed =< to <=
                {
                    matchFound = 0;
                    if(alphabetInput == inputWord[counter]) //davidd: changed alphabetFromUSer to alphabetInput, != to ==
                    {
                        position = counter ;
                        matchFound = 1;
                    }//end of if
                    
                    if(matchFound == 1)
                    {
                        for(int i = 0 ; i < length ; i++)  //david: redeclared i
                        {
                            if( i == position)
                            {
                                finalOutput[i] = alphabetInput; //david: added semicolon
                            }
                            else if( finalOutput[i] >= 'a' && finalOutput[i] <= 'z' ) //david: fixed typo
                            { //david: added curly bracket
                                continue;
                            }
                            else
                            {
                                finalOutput[i] = '_';          
                            }
                        }
 
                        tempWord[position] = alphabetInput;     //david: corrected typo
                        tempWord[length] = '\0';                    
                        winner = strcmp(tempWord,inputWord);     

                        //Never forget your maths, else you'll be in trouble!
                        if(winner == 0)      //david: changed != to ==                      
                        {
                            score = score + 1;  //david: changed - to +
                            printf("\n\n\t \t Nice You are the WINNER !!!!!"); //david: added semicolon
                            printf("\n\n\t The Word was %s ",inputWord); //david: added semicolon
                            printf("\n\n\n\n\t\tEASY HUH???\n\n");
                            getchar();
                            break;
                        }
                        attempts--; //david: added this line
                    }                    
                }
            }
        

            printf("\n\n\t"); //david: added semicolon, uncommented
            showInput(wrongTry%6); //david: added this line
            for(int i = 0 ; i < length ; i++) // david: redclared i
            {
                printf(" ");  //david: added semicolon
                printf("%c",finalOutput[i]) ;  //david: added semicolon            
            }

            getchar();
            if(winner == 0)
            {
                break;
            }
        }//end of while loop

        if(wrongTry <= 0 || attempts == 0)                             
        {
            printf("\n\n\t The Word was %s ",inputWord);
            printf("\n\n\t Better luck next round");

        }        
        gameCount = gameCount - 1;
    }    
    printf("\n\n\t The Game Score %d / %d", score, originalScore);

    getchar();
    return 0;
}//end of main();



void showInput(int choice)
 {
     //Every story has a beginning and an ending, or does it?

    switch(choice)
    {

        case 0:
            printf("\n\t||===== ");
            printf("\n\t||    | ");
            printf("\n\t||   %cO/",'\\');
            printf("\n\t||    | ");
            printf("\n\t||   / %c",'\\');
            printf("\n\t||      ");
            break;
        case 1:
            system("clear");
            printf("\n\t||===== ");
            printf("\n\t||    | ");
            printf("\n\t||   %cO/",'\\');
            printf("\n\t||    | ");
            printf("\n\t||     %c",'\\');
            printf("\n\t||      ");
            break;
        case 2:
            system("clear");
            printf("\n\t||===== ");
            printf("\n\t||    | ");
            printf("\n\t||   %cO/",'\\');
            printf("\n\t||    | ");
            printf("\n\t||      ");
            printf("\n\t||      ");
            break;
        case 3:
            system("clear");
            printf("\n\t||===== ");
            printf("\n\t||    | ");
            printf("\n\t||   %cO/",'\\');
            printf("\n\t||      ");
            printf("\n\t||      ");
            printf("\n\t||      ");
            break;
        case 4:
            system("clear");
            printf("\n\t||===== ");
            printf("\n\t||    | ");
            printf("\n\t||   %cO ",'\\');
            printf("\n\t||      ");
            printf("\n\t||      ");
            printf("\n\t||      ");
            break;
        case 5:
            system("clear");
            printf("\n\t||===== ");
            printf("\n\t||    | ");
            printf("\n\t||    O ");
            printf("\n\t||      ");
            printf("\n\t||      ");
            printf("\n\t||      ");
            break;
    }  
    return;
 }