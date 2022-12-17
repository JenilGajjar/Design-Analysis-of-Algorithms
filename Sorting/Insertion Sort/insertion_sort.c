#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int[], int);

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
        insertionSort(a, n);
    } while (1);
}

void insertionSort(int a[], int n)
{
    clock_t start, end;
    double CPU_TIME_USED;
    start = clock();

    for (int i = 1; i < n; i++)
    {
        int x = a[i];
        int j = i - 1;
        while (x < a[j] && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
    end = clock();
    printf("%lf\n", (double)(end - start) / CLOCKS_PER_SEC);
}