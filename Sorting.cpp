#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

#include "MaxHeap.h"
#include "SortAlgorithms.h"

using namespace std;
void data_set (int a[],int data_set_size);
void Unsorted_Data_Test(int arr[],int Data_Set_Size,double elapsed,clock_t start,clock_t end);
void Sorted_Data_Test(int arr[],int Data_Set_Size,double elapsed,clock_t start,clock_t end);

int main () {
    static int * array = new int [1000000000];
    int data_Set_Size=10000;
    double elapsed;
    int i=1;
    clock_t start, end;
    elapsed=0;

    Unsorted_Data_Test(array,data_Set_Size,elapsed,start,end);
    Sorted_Data_Test(array,data_Set_Size,elapsed,start,end);


	// write code here to perform experiments with the sort algorithms
	
	return 0;
}


void data_set (int a[],int data_set_size){
    long long int numbers;
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<long long unsigned>distribution(0,100000000);
    for (int i=1; i < data_set_size; i++){
        a[i]= distribution(generator);
    }
}
void Unsorted_Data_Test(int arr[],int Data_Set_Size,double elapsed,clock_t start,clock_t end){
    int i=1;
    elapsed=0;
    cout<<"***Selection Sort***"<<endl;
    for(Data_Set_Size=10000; elapsed<=180;Data_Set_Size*=2) {
        if(Data_Set_Size>1000000000){
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        selectionSort(arr,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        i++;
    }
    elapsed =0;
    Data_Set_Size/=2;
    for(Data_Set_Size+=(Data_Set_Size/2);elapsed<=180;Data_Set_Size=(Data_Set_Size/2)+Data_Set_Size){
        if(Data_Set_Size>1000000000){
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        selectionSort(arr,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        i++;
    }
    i=1;
    elapsed=0;
    cout<<endl<<"***Bubble Sort***"<<endl;
    for(Data_Set_Size=10000; elapsed<180;Data_Set_Size*=2) {
        if(Data_Set_Size>1000000000){
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        bubbleSort(arr,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        i++;
    }
    elapsed =0;
    Data_Set_Size/=2;
    for(Data_Set_Size+=(Data_Set_Size/2);elapsed<=180;Data_Set_Size=(Data_Set_Size/2)+Data_Set_Size){
        if(Data_Set_Size>1000000000){
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        bubbleSort(arr,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        i++;
    }
    i=1;
    elapsed=0;
    cout<<endl<<"***Insertion In Plcae***"<<endl;
    for(Data_Set_Size=10000; elapsed<180;Data_Set_Size*=2) {
        if(Data_Set_Size>1000000000){
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        insertionSort(arr,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        i++;
    }
    elapsed =0;
    Data_Set_Size/=2;
    for(Data_Set_Size+=(Data_Set_Size/2);elapsed<=180;Data_Set_Size=(Data_Set_Size/2)+Data_Set_Size){
        if(Data_Set_Size>1000000000){
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        insertionSort(arr,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        i++;
    }
    i=1;
    elapsed=0;
    cout<<endl<<"***MergeSort***"<<endl;
    for(Data_Set_Size=10000; elapsed<180;Data_Set_Size*=2) {
        if(Data_Set_Size>1000000000){
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        mergeSort(arr,0,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        i++;
    }
    elapsed =0;
    Data_Set_Size/=2;
    for(Data_Set_Size+=(Data_Set_Size/2);elapsed<=180;Data_Set_Size=(Data_Set_Size/2)+Data_Set_Size){
        if(Data_Set_Size>1000000000){
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        mergeSort(arr,0,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        i++;
    }
    i=1;
    elapsed=0;
    cout<<endl<<"***QuickSort***"<<endl;
    for(Data_Set_Size=10000; elapsed<180;Data_Set_Size*=2) {
        if(Data_Set_Size>1000000000){
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        quickSort(arr,0,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        i++;
    }
    elapsed =0;
    Data_Set_Size/=2;
    for(Data_Set_Size+=(Data_Set_Size/2);elapsed<=180;Data_Set_Size=(Data_Set_Size/2)+Data_Set_Size){
        if(Data_Set_Size>1000000000){
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        quickSort(arr,0,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        i++;
    }
    i=1;
    elapsed=0;
    cout<<endl<<"***Maxheap***"<<endl;
    for(Data_Set_Size=10000; elapsed<180;Data_Set_Size*=2) {
        if(Data_Set_Size>1000000000){
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        heapSort(arr,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        i++;
    }
    elapsed =0;
    Data_Set_Size/=2;
    for(Data_Set_Size+=(Data_Set_Size/2);elapsed<=180;Data_Set_Size=(Data_Set_Size/2)+Data_Set_Size){
        if(Data_Set_Size>1000000000){
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        heapSort(arr,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        i++;
    }
}
//Carson
void Sorted_Data_Test(int arr[],int Data_Set_Size,double elapsed,clock_t start,clock_t end){
    int i=1,full=1000000000;
    elapsed=0;
    data_set(arr, full);
    cout<<"***Selection Sort***"<<endl;
    for(Data_Set_Size=10000; elapsed<=180;Data_Set_Size*=2) {
        if(Data_Set_Size>1000000000){
            break;
        }

        start = clock();
        selectionSort(arr,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        i++;
    }
    i=1;
    elapsed=0;
    data_set(arr, full);
    cout<<endl<<"***Bubble Sort***"<<endl;
    for(Data_Set_Size=10000; elapsed<180;Data_Set_Size*=2) {
        if(Data_Set_Size>1000000000){
            break;
        }
        start = clock();
        bubbleSort(arr,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        i++;
    }
    i=1;
    elapsed=0;
    data_set(arr, full);
    cout<<endl<<"***Insertion In Plcae***"<<endl;
    for(Data_Set_Size=10000; elapsed<180;Data_Set_Size*=2) {
        if(Data_Set_Size>1000000000){
            break;
        }

        start = clock();
        insertionSort(arr,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        i++;
    }
    i=1;
    data_set(arr, full);
    elapsed=0;
    cout<<endl<<"***MergeSort***"<<endl;
    for(Data_Set_Size=10000; elapsed<180;Data_Set_Size*=2) {
        if(Data_Set_Size>1000000000){
            break;
        }
        start = clock();
        mergeSort(arr,0,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        i++;
    }
    i=1;
    data_set(arr, full);
    elapsed=0;
    cout<<endl<<"***QuickSort***"<<endl;
    for(Data_Set_Size=10000; elapsed<180;Data_Set_Size*=2) {
        if(Data_Set_Size>1000000000){
            break;
        }
        start = clock();
        quickSort(arr,0,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        i++;
    }
    i=1;
    data_set(arr, full);
    elapsed=0;
    cout<<endl<<"***Maxheap***"<<endl;
    for(Data_Set_Size=10000; elapsed<180;Data_Set_Size*=2) {
        if(Data_Set_Size>1000000000){
            break;
        }
        start = clock();
        heapSort(arr,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        i++;
    }

}