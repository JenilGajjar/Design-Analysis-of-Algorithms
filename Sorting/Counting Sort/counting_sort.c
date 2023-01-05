#include <stdio.h>
#include <time.h>
void counting_sort(int[], int, int);

void main()
{
    FILE *fptr;
    int choice = 0, n;
    while (1)
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
            fscanf(fptr, "%d", &a[i]);
        counting_sort(a, n, 99999);
    };
}

void counting_sort(int a[], int n, int max)
{
    int c[max];
    int b[n];

    clock_t start, end;
    start = clock();
    for (int i = 0; i < max; i++)
        c[i] = 0;

    // updating array C with occurrences of each value of A
    for (int j = 0; j < n; j++)
        c[a[j] - 1]++;

    // In array C, from index 1 to add the value with the previous element
    for (int i = 1; i < max; i++)
        c[i] += c[i - 1];

    for (size_t i = 0; i < n; i++)
        b[i] = 0;

    // Updating output array B
    for (int j = n - 1; j >= 0; j--)
    {
        b[c[a[j] - 1] - 1] = a[j];
        c[a[j] - 1]--;
    }
    end = clock();
    printf("%lf", (double)(end - start) / CLOCKS_PER_SEC);
}