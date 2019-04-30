#include <stdio.h>

int *getMembersN3(int sum, int n, int *arr, int size)
{
    int s = 0;
    for (int i = 0; i < size - 2; i++)
        for (int j = 1; j < size - 1; j++)
            for (int k = 2; k < size; k++)
                if (j != k && i != j && k != i)
                {
                    s = arr[i] + arr[j] + arr[k];
                    if (sum == s)
                        printf("%d %d %d\n", arr[i], arr[j], arr[k]);
                }
}
int *getMembersN(int sum, int n, int *arr, int size)
{
    int s = 0, i = 0, j = 1, k = 2;
    while (i < size - 2)
    {

        s = arr[i] + arr[j] + arr[k];
        if (sum == s && i != j && j != k && i != k)
            printf("%d %d %d\n", arr[i], arr[j], arr[k]);

        if (j == size - 2)
        {
            j = 1;
            k = 2;
            i++;
        }
        j++;
        k++;
    }
}

void main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4};
    int size = 4;
    getMembersN3(9, 3, arr, size);
    getMembersN(9, 3, arr, size);
}
