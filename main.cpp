
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <chrono>
using namespace std;
//Choose 1024 randomly between 1 and 1024. Expect duplicates. Sort the array using merge sort. Note the time required. Use system functions to calculate time. Repeat this exercise using 32768 randomly selected integers between 1 and 32768. Again, report machine time using system functions. The time complexity of merge sort is O(nlogn). Your results should reflect the theoretical estimate. Do they?

void merge(int arrA[], int low, int mid, int high);
void mergeSort(int arrA[], int low, int high);

int main() {

    srand((unsigned int)time(NULL));
    int sizeOne = 1024, sizeTwo =32768;
    int arrayOne[sizeOne], arrayTwo[sizeTwo];
    for(int i=0;i<sizeOne;i++)
        arrayOne[i]=(rand()%sizeOne)+1;
    
    for(int i=0;i<sizeTwo;i++)
           arrayTwo[i]=(rand()%sizeTwo)+1;
    auto start = std::chrono::steady_clock::now();
    mergeSort(arrayOne, 0, sizeOne-1);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = end-start;
    cout<<"MergeSort(1024) time in seconds: "<<elapsed.count()<<endl;
    
    auto startTwo = std::chrono::steady_clock::now();
    mergeSort(arrayTwo, 0, sizeTwo-1);
    auto endTwo = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsedTwo = endTwo-startTwo;
    cout<<"MergeSort(32768) time in seconds: "<<elapsedTwo.count()<<endl;
    
    
    return 0;
 
}


void merge(int arr[], int low,int mid, int high)
{
    int leftSize = mid-low+1, rightSize=high-mid;
  
    int arrLeft[leftSize];
    int arrRight[rightSize];
    
    for(int i=0;i<leftSize;i++)
        arrLeft[i]=arr[low+i];
    for(int i=0;i<rightSize;i++)
        arrRight[i]=arr[(mid+1)+i];
    
    int i=0, j=0,k=low;
    while (i<leftSize&&j<rightSize) {
        if(arrLeft[i]<=arrRight[j]){
            arr[k]=arrLeft[i];
            i++;
        }
        else{
            arr[k]=arrRight[j];
            j++;
        }
        k++;
    }
    while(i<leftSize){
        arr[k]=arrLeft[i];
        k++;
        i++;
    }
    while(j<rightSize){
        arr[k]=arrRight[j];
        j++;
        k++;
    }
    
}
void mergeSort(int arr[], int low, int high){
    int mid;
    if(low<high){
        mid=low +(high-low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
