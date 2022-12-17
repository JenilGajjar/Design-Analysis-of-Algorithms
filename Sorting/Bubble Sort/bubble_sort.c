#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int[], int);

void main()
{
    FILE *fptr;
    int choice = 0, n;
    printf("Enter a number ");
    scanf("%d", &n);
    int a[n];

    do
    {
        printf("\nPress 1 for best case\nPress 2 for average case\nPress 3 for worst case\nPress 4 to exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            fptr = fopen("best", "r");
            printf("best case Time Complexity ");
            break;
        case 2:
            fptr = fopen("average", "r");
            printf("average case Time Complexity ");
            break;
        case 3:
            fptr = fopen("worst", "r");
            printf("worst case Time Complexity ");
            break;
        }
        for (int i = 0; i < n; i++)
        {
            fscanf(fptr, "%d", &a[i]);
        }
        bubbleSort(a, n);
    } while (choice != 4);
}

void bubbleSort(int a[], int n)
{
    clock_t start, end;
    double CPU_TIME_USED;
    start = clock();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    end = clock();
    printf("%lf\n", (double)(end - start) / CLOCKS_PER_SEC);
}