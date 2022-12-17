#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int[], int);

void main()
{
    FILE *fptr;
    int choice = 0, n;

    do
    {
        printf("\nPress 1 for best case\nPress 2 for average case\nPress 3 for worst case\nPress 4 to exit\n");
        scanf("%d", &choice);
        if (choice == 4)
            return;

        printf("Enter a number ");
        scanf("%d", &n);
        switch (choice)
        {
        case 1:
            fptr = fopen("best", "r");
            printf("best time complexity ");
            break;
        case 2:
            fptr = fopen("average", "r");
            printf("average time complexity ");
            break;
        case 3:
            fptr = fopen("worst", "r");
            printf("worst time complexity ");
            break;
        }
        int a[n];
        for (int i = 0; i < n; i++)
        {
            fscanf(fptr, "%d", &a[i]);
        }
        selectionSort(a, n);
    } while (1);
}

void selectionSort(int a[], int n)
{
    clock_t start, end;
    double CPU_TIME_USED;
    start = clock();
    for (int i = 0; i < n - 1; i++)
    {
        int index = i;
        int min = a[i];

        for (int j = i + 1; j < n; j++)
        {
            if (min > a[j])
            {
                min = a[j];
                index = j;
            }
        }

        a[index] = a[i];
        a[i] = min;
    }
    end = clock();
    printf("%lf\n", (double)(end - start) / CLOCKS_PER_SEC);
}