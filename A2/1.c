/*
Write a C program to multiply two matrices using dynamic memory allocation. Each 
two-dimensional array should be processed as array of pointers to a set of 1-
dimensional integer arrays. Read, access and display the matrix elements using pointers 
instead of subscript notation. Use three functions i) To read input matrix ii) To compute
the product and iii) To display the resultant matrix.
*/

#include<stdio.h>
#include<stdlib.h> 

// Function Declarations
void inputmatrix(int **arr,int r,int c);
void product(int **arr1,int **arr2,int **arr3,int r1,int c1,int r2,int c2);
void displaymatrix(int **arr,int r,int c);


int main()
{
    // Enter rows and coloumns of matrix 1 and 2
    int r1,c1,r2,c2;
    printf("Enter number of rows of Matrix 1 : ");
    scanf("%d",&r1);
    printf("Enter number of coloumns of Matrix 1 : ");
    scanf("%d",&c1);
    printf("Enter number of rows of Matrix 2 : ");
    scanf("%d",&r2);
    printf("Enter number of coloumns of Matrix 2 : ");
    scanf("%d",&c2);

    // Checking if multiplication is possile
    if(c1 != r2)
    {
        printf("Product not possible!");
        return 1;
    }

    // Dynamically allocate memory for Matrix 1
    int **m1 = (int**) malloc(r1 * sizeof(int*));
    for(int i=0;i<r1;i++)
    {
        m1[i] = (int*) malloc(c1 * sizeof(int));
    }

    // Dynamically allocate memory for Matrix 2
    int **m2 = (int**) malloc(r2 * sizeof(int));
    for(int i=0;i<r2;i++)
    {
        m2[i] = (int*) malloc(c2 * sizeof(int));
    }

    // Dynamically allocate memory for Matrix 3 (Product Matrix)
    int **m3 = (int**) malloc(r1 * sizeof(int));
    for(int i=0;i<r1;i++)
    {
        m3[i] = (int*) malloc(c2 * sizeof(int));
    }

    // Entering elements of Matrix 1
    printf("\nEnter elements of matrix 1 : \n");
    inputmatrix(m1,r1,c1);

    // Entering elements of Matrix 1
    printf("\nEnter elements of matrix 2 : \n");
    inputmatrix(m2,r2,c2);

    // Displaying elements of Matrix 1
    printf("\nElements of matrix 1 : \n");
    displaymatrix(m1,r1,c1);

    // Displaying elements of Matrix 1
    printf("\nElements of matrix 2 : \n");
    displaymatrix(m2,r2,c2);

    // Computing the product of two matrices
    printf("\nElements of Product matrix : \n");
    product(m1,m2,m3,r1,c1,r2,c2);

    // Displaying elements of Matrix 3 (Product Matrix)
    displaymatrix(m3,r1,c2);
    
    // Free the allocated memory
    for (int i = 0; i < r1; i++) free(m1[i]);
    free(m1);

    for (int i = 0; i < r2; i++) free(m2[i]);
    free(m2);

    for (int i = 0; i < r1; i++) free(m3[i]);
    free(m3);

    return 0;
}

// Function to input elements of matrix
void inputmatrix(int **matrix,int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("Enter element (%d,%d) : ",i+1,j+1);
            scanf("%d",&matrix[i][j]);
        }
    }
}

// Function to calculate product matrix
void product(int **arr1,int **arr2,int **arr3,int r1,int c1,int r2,int c2)
{

    // Declaring all elements of product matrix as 0 initially
    for(int i=0;i<r1;i++)
        {
            for(int j=0;j<c2;j++)
            {
                arr3[i][j] = 0;   
            }
        }

    // Computing the product
    for(int i=0;i<c1;i++)
    {
        for(int j=0;j<r1;j++)
        {
            for(int k=0;k<c2;k++)
                {
                    arr3[i][j] += arr1[i][k] * arr2[k][j]; // Product logic
                }
        }
    }
}

// Function to display elements of matrix
void displaymatrix(int **matrix,int r,int c)
{
    for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                printf("%d ",matrix[i][j]);
            }
            printf("\n");
        }
}