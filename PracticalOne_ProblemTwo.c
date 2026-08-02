#include <stdio.h>

int main()
{
    int n, i, j, count;
    int alreadyPrinted, foundDuplicate = 0;
    int ids[100];

    printf("Enter number of borrow records: ");
    scanf("%d", &n);

    printf("Enter book IDs:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &ids[i]);
    }

    printf("Duplicate book IDs are: ");

    for(i = 0; i < n; i++)
    {
        count = 0;
        alreadyPrinted = 0;

        for(j = 0; j < i; j++)
        {
            if(ids[i] == ids[j])
            {
                alreadyPrinted = 1;
                break;
            }
        }

        if(alreadyPrinted == 1)
        {
            continue;
        }

        for(j = 0; j < n; j++)
        {
            if(ids[i] == ids[j])
            {
                count++;
            }
        }

        if(count > 1)
        {
            printf("%d ", ids[i]);
            foundDuplicate = 1;
        }
    }

    if(foundDuplicate == 0)
    {
        printf("No duplicate book IDs");
    }

    return 0;
}
