#include <stdio.h>
#include <math.h>
void makeAChange(int arr[], int coin, int change)
{
    int table[coin][change + 1];

    for (int i = 0; i < coin; i++)
    {
        for (int j = 0; j <= change; j++)
        {
            if (j == 0)
            {
                table[i][j] = 0;
            }
            else if (i == 0)
            {
                table[i][j] = 1 + table[0][j - arr[0]];
            }
            else if (j < arr[i])
            {
                table[i][j] = table[i - 1][j];
            }
            else
            {
                table[i][j] = fminf(table[i - 1][j], 1 + table[i][j - arr[i]]);
            }
        }
    }
    for (int i = 0; i < coin; i++)
    {
        for (int j = 0; j <= change; j++)
        {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
    traceMakeAChange(table, coin, change);
}

void traceMakeAChange(int table[][], int i, int j)
{
}

int main(int argc, char const *argv[])
{
    int change, coin;
    printf("Enter change ");
    scanf("%d", &change);
    printf("Enter number of coins ");
    scanf("%d", &coin);
    int arr[coin];
    for (int i = 0; i < coin; i++)
    {
        printf("Enter coin nunber %d ", i + 1);
        scanf("%d", &arr[i]);
    }
    makeAChange(arr, coin, change);
    return 0;
}
