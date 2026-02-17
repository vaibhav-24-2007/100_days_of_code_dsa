#include <stdio.h>

int main()
{
    int n, i;
    
    printf("enter no. of elements ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("enter elements ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    int max = arr[0];
    int min = arr[0];
    
    for(i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
        
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }
    
    printf("maximum value %d\n", max);
    printf("minimum value %d\n", min);
    
    return 0;
}
