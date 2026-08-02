#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[1000], word[100], longest[100];
    int i = 0, j = 0;
    int currLen = 0, maxLen = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    for(i = 0; sentence[i] != '\0'; i++)
    {
        if(sentence[i] != ' ' && sentence[i] != '\n' && sentence[i] != '\t')
        {
            word[j] = sentence[i];
            j++;
        }
        else
        {
            if(j > 0)
            {
                word[j] = '\0';
                currLen = strlen(word);

                if(currLen > maxLen)
                {
                    maxLen = currLen;
                    strcpy(longest, word);
                }

                j = 0;
            }
        }
    }

    if(j > 0)
    {
        word[j] = '\0';
        currLen = strlen(word);

        if(currLen > maxLen)
        {
            maxLen = currLen;
            strcpy(longest, word);
        }
    }

    if(maxLen > 0)
    {
        printf("Longest word: %s\n", longest);
        printf("Length: %d\n", maxLen);
    }
    else
    {
        printf("No word found.\n");
    }

    return 0;
}
