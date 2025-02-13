// 3.
#include<stdio.h>

void sort(int n, int array[])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(array[j]>array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }  
}


int main()
{
    int n,m;
    // Size of both Arrays
    printf("Enter size of array 1 & array 2 : ");
    scanf("%d %d",&n,&m);
    
    int array1[n],array2[m],array[n+m];
    // Elements of both arrays
    
    printf("Enter sorted array 1 : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array1[i]);
    }
    
    printf("Enter sorted array 2 : ");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&array2[i]);
    }
    
    // Seperate index for traversing
    // Merging Both arrays
    int index=0;
   
    for(int i=0;i<n;i++)
    {
        array[index] = array1[i];
        index++;
    }
    
    for(int i=0;i<m;i++)
    {
        array[index] = array2[i];
        index++;
    }
    
    // Sort the Merged Array 
    int k = m+n;
    
    sort(k,array);
    
    printf("Merged Sorted Array : \n");
    
    for(int i=0;i<k;i++)
    {
        printf("%d ",array[i]);
    }
    
    return 0; 
}