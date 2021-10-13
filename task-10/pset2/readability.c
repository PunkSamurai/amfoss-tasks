#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main()
{
    string text = get_string("Text: ");
    int letters = 0, words = 1, sentences = 0;

    // counting letters, words, and sentences
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters ++;
        }
        else if (text[i] == ' ')
        {
            words ++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences ++;
        }
    }

    //calculating reading level
    float L = (letters * 100) / (float) words;
    float S = (sentences * 100) / (float) words;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }

}