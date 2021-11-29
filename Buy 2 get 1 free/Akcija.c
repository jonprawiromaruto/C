// Jonathan Prawiromaruto
// 10/27/2021
// Solution to Kattis Problem: Akcija

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int table[], int tempTable[], int low, int high);
int findPrice(int *table, int i, int N, int temp);
void printArray(int A[], int size);

int main(void)
{
  //initializing some variables for later use
  int N, i = 0;
  
  //scanning first input to determine the amount of total integers user
  //wants to input into the program
  scanf("%d", &N);
  //DMA both real and temporary array for the merge sort function later
  int* tempTable = malloc(sizeof(int)* N);
  int* table = malloc(sizeof(int)* N);
  //scanning all integers into the array
  while (i < N)
  {
    scanf("%d", &table[i]);
    i++;
  }
  //calling function sort
  sort(table, tempTable, 0, N-1);
  //calling function findPrice to find the minimum price for the books
  findPrice(table, 0 , N, 0);
  return 0;
}

//merging function to transfer variable from array to temporary array
void merging(int table[], int tempTable[],int low, int mid, int high) 
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
void sort(int table[], int tempTable[], int low, int high) 
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
  else 
  { 
    return;
  }   
}

int findPrice(int *table, int i, int N, int temp)
{
  //checking if there are integers that are outside the groups of 3
  //if there are, add them.
  for(i = 0; i < N%3; i++)
  {
    temp += table[i];
  }
  //jumping through the end of the array and adding the 2 bigger numbers
  //from the group of 3 for the price.
  for(i = N%3+1; i < N; i+=3)
  {
    temp += table[i] + table[i+1];
  }
  //printing the total price.
  printf("%d", temp);
  return 0;
}
