#include <stdio.h>

int main()
{
    int n, h, k, i;

    char items[100][50];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter item names:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%s", items[i]);
    }

    printf("Enter number of hours: ");
    scanf("%d", &h);

    k = h % n;

    printf("Final display order:\n");

    for(i = k; i < n; i++)
    {
        printf("%s ", items[i]);
    }

    for(i = 0; i < k; i++)
    {
        printf("%s ", items[i]);
    }

    printf("\n");

    return 0;
}
