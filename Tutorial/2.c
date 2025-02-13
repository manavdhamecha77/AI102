// 2.
#include<stdio.h>

void billing(int cus_code,int calls)
{
    double bill = 250; // Bill is 250 from start
    if(calls>100)
    { 
    // For each call after 100 additional 1.25 charged
        bill += (calls-100)*1.25; 
    }
    printf("Total billing for customer with code : %d is : %.2f ",cus_code,bill);
}

int main()
{
    int cus_code;
    printf("Enter customer code : ");
    scanf("%d",&cus_code);
    
    int calls;
    printf("Enter calls made by the customer : ");
    scanf("%d",&calls);
    
    billing(cus_code,calls);
    return 0;
}