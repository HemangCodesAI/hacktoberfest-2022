//Selection Sort
#include <iostream>
using namespace std;

void SelectionSort(int *arr, int size){
    int i, j, temp;
    for(i=0; i<size-1; i++){
        for(j=i+1; j<size; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void Display(int *arr, int size){
    cout<<"Sorted Array: ";
    int i=0;
    while(i<size){
        cout<<arr[i++]<<" ";
    }
}

int main(){
    int i, size;
    cout<<"Enter the size: "; cin>>size;
    int *arr = new int[size];
    cout<<"Enter "<<size<<" elements: ";
    for(i=0; i<size; i++){
        cin>>arr[i];
    }
    SelectionSort(arr,size);
    Display(arr,size);
    return 0;
}
