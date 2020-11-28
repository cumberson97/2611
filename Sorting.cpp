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

    for(data_Set_Size=10000; elapsed<180;data_Set_Size+=100000) {
        start = clock();
        data_set(array, data_Set_Size);
        quickSort(array,0,data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<data_Set_Size<<endl;
        i++;
    }

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

}
void Sorted_Data_Test(int arr[],int Data_Set_Size,double elapsed,clock_t start,clock_t end){

}