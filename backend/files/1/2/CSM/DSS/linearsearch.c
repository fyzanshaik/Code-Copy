#include <stdio.h>
int linear_search(int a[], int, int);
void main()
{
    int a[20], n, key, i;
    int res;
    printf("Enter number of elements");
    scanf("%d", &n);
    printf("Enter the Array elements");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the key to be searched");
    scanf("%d", &key);
    res = linear_search(a, n, key);
    if (res != -1)
        printf("Successful search , found at %d", res + 1);
    else
        printf("Unsuccessful search, Key not fount");
}
int linear_search(int a[], int n, int key)
{
    int i, flag = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        return i;
    else
        return -1;
}