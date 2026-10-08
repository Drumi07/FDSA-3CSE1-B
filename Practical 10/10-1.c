#include <stdio.h>
#define SIZE 10

int main()
{
    int table[SIZE];
    int n, i, reg, index, count;

    for (i = 0; i < SIZE; i++)
        table[i] = -1;

    printf("Enter number of vehicles: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter registration number: ");
        scanf("%d", &reg);

        index = reg % 10;
        count = 0;

        while (table[index] != -1 && count < SIZE)
        {
            index = (index + 1) % SIZE;
            count++;
        }

        if (count == SIZE)
        {
            printf("Parking lot is full\n");
        }
        else
        {
            table[index] = reg;
        }
    }

    printf("\nFinal Parking Lot:\n");

    for (i = 0; i < SIZE; i++)
    {
        if (table[i] == -1)
            printf("Slot %d: Empty\n", i);
        else
            printf("Slot %d: %d\n", i, table[i]);
    }

    return 0;
}