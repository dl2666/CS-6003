//Using a random generator, compute 1000 integers between 1 and 1000. There will be duplicates in the array. Sort the array using bubble sort and insertion sort/merge sort. The two sorted arrays should agree. Then pick at random one element from your sorted array and use a binary search to find its position in the array.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

void bubbleSort(int arr[], int size);
void insertionSort(int arr[], int size);
int binarySearch(int arr[], int size, int num);

int main() {
    //fill array with random numbers btw 1 to 1000
    int size = 1000;
    int randArr[size];
    srand((unsigned int)time(0));
    for(int i=0;i<size;i++){
        randArr[i]=(rand()%1000)+1;
    }
    
    bubbleSort(randArr,size);
    insertionSort(randArr,size);
    
    int num = (rand()%1000)+1;
    cout<<"Searching array for "<<num<<endl;
    int index = binarySearch(randArr, size, num);
    
    if(index==-1)
        cout<<num<<" was not found in array"<<endl;
    else
        cout<<num<<" was located at index "<<index<<endl;
   
    return 0;
}

//will create a new array and copy numbers so as not to return an already sorted array into the insertionSort function later
void bubbleSort(int arr[], int size){
    int newArr[size];
    for(int i=0;i<size;i++){
        newArr[i]=arr[i];
       }
    for(int i=0;i<size-1;i++){
           for(int j=i+1;j<size;j++){
               int temp;
               if(newArr[i]>newArr[j]){
                   temp=newArr[i];
                   newArr[i]=newArr[j];
                   newArr[j]=temp;
               }
           }
       }
}
  //this function will return the sorted randArr array
void insertionSort(int arr[],int size){
    int num, index;
    for(int i=1;i<size;i++){
        num=arr[i];
        index=i;
        while(index>0 && arr[index-1]>num){
            arr[index]=arr[index-1];
            index-=1;
        }
        arr[index]=num;
    }
}
int binarySearch(int arr[], int size,int num){
    int start(0),end(size-1);
    
    while(start<=end){
        int mid = (start+end)/2;
        if(num==arr[mid])
            return mid;
        else if(num>arr[mid])
            start=mid+1;
        else
            end=mid-1;
    }
    return -1;
}
