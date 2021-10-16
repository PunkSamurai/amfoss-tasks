#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int check_key();

int main(int argc, char* argv[])
{
    if (argc == 2)
    {
        int c = check_key(argv[1]);

        if (c == 1)
        {
            printf("Key must contain 26 letters.\n");
            return 1;
        }
        else if (c == 2)
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        else
        {
            char* key = argv[1];
            char* text;
            text = get_string("plaintext: ");

            for (int i = 0, n = strlen(text); i < n; i++)
            {
                char x = text[i];
                if isalpha(x)
                {
                    if isupper(x)
                    {
                        text[i] = toupper(key[x - 'A']);
                    }
                    else if islower(x)
                    {
                        text[i] = tolower(key[x - 'a']);
                    }
                }
            }
            printf("ciphertext: %s\n", text);
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}


int check_key(char* key)
{
    int sum = 0;
    if (strlen(key) != 26)
    {
        return 1;
    }

    for(int i = 0, n = strlen(key); i < n; i++)
    {

        if(isalpha(key[i]))
        {
            sum += tolower(key[i]);
        }
        else
            return 2;
    }
    if(sum == 2847)
        return 0;
    else
        return 2;

}