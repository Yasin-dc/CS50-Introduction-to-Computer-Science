#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int shiftChar(char c, int k);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    // Check if the key is a valid non-negative integer
    string key = argv[1];
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isdigit(key[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    
    int k = atoi(key);

    string text = get_string("Text: ");
    printf("ciphertext: ");

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char encryptedChar = shiftChar(text[i], k);
        printf("%c", encryptedChar);
    }

    printf("\n");
    return 0;
}

int shiftChar(char c, int k)
{
    if (isalpha(c))
    {
        int base = isupper(c) ? 'A' : 'a';
        return ((c - base + k) % 26) + base;
    }
    else
    {
        return c;
    }
}
