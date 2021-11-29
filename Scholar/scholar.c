// Jonathan Prawiromaruto
// 10/31/2021
// Solution to p4 Problem: Scholarly Reader

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(long long table[], long long tempTable[], int low, int high);
void manyReads(long long *table, long long n, long long L);
void allocBooks(long long* table, long long n);

int main(void)
{
    int c, cases = 0;

    //scanning number of cases
    scanf("%d", &c);

    while (cases != c)
    {
        long long n, L;
        //scanning total numbers of book available and 
        //how many total pages user wants to read
        scanf("%lld %lld", &n, &L);
        //printf("%lld %lld\n", n, L);

        long long* table = malloc(sizeof(long long) * n);
        long long* tempTable = malloc(sizeof(long long) * n);
        // calling function to input variables inside an array
        allocBooks(table, n);
        
        //calling function sort to sort the array table
        sort(table, tempTable, 0, n-1);

        //calling function manyReads to count how many articles read
        manyReads(table, n, L);

        cases++;
    }
}

//allocating books into the array table
void allocBooks(long long* table, long long n)
{
    for(int i = 0; i < n; i++)
    {
        scanf("%lld", &table[i]);
    }
}

//merging function to transfer variable from array to temporary array
void merging(long long table[], long long tempTable[],int low, int mid, int high) 
{
    //initializing low1 and low2 variables to merge and sort the integers
    int low1, low2, i;

    //finding the lower integer with low1 and low2 then transferring it
    //to the temporary array
    for(low1 = low, low2 = mid + 1, i = low; low1 <= mid && low2 <= high; i++) 
    {
        if(table[low1] <= table[low2])
        {
            tempTable[i] = table[low1++];
        }
        else
        {
            tempTable[i] = table[low2++];
        }
    }
    //filling temporary array with lowest numbers from integers
    //smaller than mid number
    while(low1 <= mid)
    {
        tempTable[i++] = table[low1++];
    }
    //filling temporary array with integers lower than the highest number
    //starting from mid number    
    while(low2 <= high)
    {
        tempTable[i++] = table[low2++];
    }   

    //returning all numbers from the temporary array to the real array
    for(i = low; i <= high; i++)
    {
        table[i] = tempTable[i];
    }
}

//sorting function from small to big
void sort(long long table[], long long tempTable[], int low, int high) 
{
    int mid;
    //sorting every integer by calling the function sort and merging  
    if(low < high) 
    {
        mid = (low + high) / 2;
        sort(table,tempTable,low, mid);
        sort(table, tempTable,mid+1, high);
        merging(table,tempTable,low, mid, high);
    } 
    //return to main
    else 
    { 
        return;
    }   
}

//function to count how many articles can user read/want to read in total
void manyReads(long long *table, long long n, long long L)
{
    //initializing temporary counter to compare with total pages read
    //and how many articles read
    long long pages = 0 ;
    int i, read = 0;
    while(i != n)
    {
        //comparing total pages read with total pages user willing to read
        if((pages + table[i]) > L)
        {
            break;
        }
        //adding score to read if still below user's reading capacity
        //and adding score to total pages read
        else
        {
            pages += table[i];
            read++;
        }
        i++;
    }
    printf("\n%d", read);
    return;
}