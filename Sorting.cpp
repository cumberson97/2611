#include <iostream>
#include <ctime>
#include <random>
#include <fstream>

#include "MaxHeap.h"
#include "SortAlgorithms.h"

using namespace std;
void data_set (int a[],int data_set_size);
void Unsorted_Data_Test(int arr[],long int Data_Set_Size,double elapsed,clock_t start,clock_t end);
void Half_Sorted_Data_Test(int arr[],long int Data_Set_Size,double elapsed,clock_t start,clock_t end);
void Fully_Sorted_Data_Test(int arr[],long int Data_Set_Size,double elapsed,clock_t start,clock_t end);

int main () {
    static int * array = new int [1000000000];
    long int data_Set_Size=10000;
    double elapsed;
    int i=1;

    clock_t start, end;
    elapsed=0;

    Unsorted_Data_Test(array,data_Set_Size,elapsed,start,end);
    Half_Sorted_Data_Test(array,data_Set_Size,elapsed,start,end);
    Fully_Sorted_Data_Test(array,data_Set_Size,elapsed,start,end);


    // write code here to perform experiments with the sort algorithms

    return 0;
}


void data_set (int a[],int data_set_size){
    mt19937_64 generator(time(0));
    uniform_int_distribution<long long unsigned>distribution(0,1000000000);
    long long int i=0;
    for (  i=1; i < data_set_size; i++){
        a[i]= distribution(generator);
    }

}

void Unsorted_Data_Test(int arr[],long int Data_Set_Size,double elapsed,clock_t start,clock_t end) {

    ofstream out;
    out.open("Unsorted Statistics.csv");

    out << "Unsorted Data Test" << endl;

    int i = 1;
    elapsed = 0;
    cout << "***Selection Sort***" << endl;
    out << "Selection Sort" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;
    for (Data_Set_Size = 10000; elapsed <= 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        selectionSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    elapsed = 0;
    Data_Set_Size = (Data_Set_Size / 4);
    float quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;
    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        selectionSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }

    out << "" << endl;

    i = 1;
    elapsed = 0;
    cout << "***Bubble Sort***" << endl;
    out << "Bubble Sort" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;
    for (Data_Set_Size = 10000; elapsed < 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        bubbleSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    elapsed = 0;
    Data_Set_Size = Data_Set_Size / 4;
    quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;
    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        bubbleSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
        out << "" << endl;
    }
    i = 1;
    elapsed = 0;
    cout << "***Insertion Sort***" << endl;
    out << "Insertion Sort" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;
    out << i << "," << elapsed << "," << Data_Set_Size << endl;
    for (Data_Set_Size = 10000; elapsed < 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        insertionSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    elapsed = 0;
    Data_Set_Size = Data_Set_Size / 4;
    quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;
    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        insertionSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    out << "" << endl;

    i = 1;
    elapsed = 0;
    cout << "***MergeSort***" << endl;
    out << "MergeSort" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;
    for (Data_Set_Size = 10000; elapsed < 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        mergeSort(arr, 0, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    elapsed = 0;
    Data_Set_Size = Data_Set_Size / 4;
    quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;
    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        mergeSort(arr, 0, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    out << "" << endl;

    i = 1;
    elapsed = 0;
    cout << "***QuickSort***" << endl;
    out << "QuickSort" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;
    for (Data_Set_Size = 10000; elapsed < 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        quickSort(arr, 0, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    elapsed = 0;
    Data_Set_Size = Data_Set_Size / 4;
    quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;
    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        quickSort(arr, 0, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    out << "" << endl;

    i = 1;
    elapsed = 0;
    cout << "***Maxheap***" << endl;
    out << "Maxheap" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;
    for (Data_Set_Size = 10000; elapsed < 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        heapSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    elapsed = 0;
    Data_Set_Size = Data_Set_Size / 4;
    quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;
    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        heapSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    out << "" << endl;

    i = 1;
    elapsed = 0;
    cout << "***RadixSort***" << endl;
    out << "RadixSort" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;
    for (Data_Set_Size = 10000; elapsed < 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        radixsort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;

        i++;
    }
    elapsed = 0;
    Data_Set_Size = Data_Set_Size / 4;
    quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;
    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        data_set(arr, Data_Set_Size);
        start = clock();
        radixsort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
}


void Half_Sorted_Data_Test(int arr[],long int Data_Set_Size,double elapsed,clock_t start,clock_t end){

    ofstream out;
    out.open("Sorted Statistics.csv");

    out<<"Sorted Data Test"<<endl;

    int i=1,full=1000000000;
    elapsed=0;
    data_set(arr, full);
    cout<<"***Selection Sort***"<<endl;
    out<<"Selection Sort"<<endl;
    out<<"Current Run"<<","<<"Time Taken"<<","<<"Size of Data Set"<<","<<endl;
    for(Data_Set_Size=10000; elapsed<=180;Data_Set_Size*=2) {
        if(Data_Set_Size>1000000000){
            break;
        }

        start = clock();
        selectionSort(arr,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        out<<i<<","<<elapsed<<","<<Data_Set_Size<<endl;
        i++;
    }

    out<<""<<endl;

    i=1;
    elapsed=0;
    data_set(arr, full);
    cout<<"***Bubble Sort***"<<endl;
    out<<"Bubble Sort"<<endl;
    out<<"Current Run"<<","<<"Time Taken"<<","<<"Size of Data Set"<<","<<endl;
    for(Data_Set_Size=10000; elapsed<180;Data_Set_Size*=2) {
        if(Data_Set_Size>1000000000){
            break;
        }

        start = clock();
        bubbleSort(arr,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        out<<i<<","<<elapsed<<","<<Data_Set_Size<<endl;
        i++;
    }
    out<<""<<endl;

    i=1;
    elapsed=0;
    data_set(arr, full);
    cout<<endl<<"***Insertion In Place***"<<endl;
    out<<endl<<"Insertion In Place"<<endl;
    out<<"Current Run"<<","<<"Time Taken"<<","<<"Size of Data Set"<<","<<endl;
    for(Data_Set_Size=10000; elapsed<180;Data_Set_Size*=2) {
        if(Data_Set_Size>1000000000){
            break;
        }

        start = clock();
        insertionSort(arr,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        out<<i<<","<<elapsed<<","<<Data_Set_Size<<endl;
        i++;
    }
    out<<""<<endl;

    i=1;
    data_set(arr, full);
    elapsed=0;
    cout<<"***MergeSort***"<<endl;
    out<<"MergeSort"<<endl;
    out<<"Current Run"<<","<<"Time Taken"<<","<<"Size of Data Set"<<","<<endl;
    for(Data_Set_Size=10000; elapsed<180;Data_Set_Size*=2) {
        if(Data_Set_Size>1000000000){
            break;
        }
        start = clock();
        mergeSort(arr,0,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        out<<i<<","<<elapsed<<","<<Data_Set_Size<<endl;
        i++;
    }
    out<<""<<endl;

    i=1;
    data_set(arr, full);
    elapsed=0;
    cout<<"***QuickSort***"<<endl;
    out<<"QuickSort"<<endl;
    out<<"Current Run"<<","<<"Time Taken"<<","<<"Size of Data Set"<<","<<endl;
    for(Data_Set_Size=10000; elapsed<180;Data_Set_Size*=2) {
        if(Data_Set_Size>1000000000){
            break;
        }
        start = clock();
        quickSort(arr,0,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        out<<i<<","<<elapsed<<","<<Data_Set_Size<<endl;
        i++;
    }
    out<<""<<endl;

    i=1;
    data_set(arr, full);
    elapsed=0;
    cout<<"***Maxheap***"<<endl;
    out<<"Maxheap"<<endl;
    out<<"Current Run"<<","<<"Time Taken"<<","<<"Size of Data Set"<<","<<endl;
    for(Data_Set_Size=10000; elapsed<180;Data_Set_Size*=2) {
        if(Data_Set_Size>1000000000){
            break;
        }
        start = clock();
        heapSort(arr,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        out<<i<<","<<elapsed<<","<<Data_Set_Size<<endl;
        i++;
    }
    i=1;
    data_set(arr, full);
    elapsed=0;
    cout<<endl<<"RadixSort"<<endl;
    out<<endl<<"RadixSort"<<endl;
    out<<"Current Run"<<","<<"Time Taken"<<","<<"Size of Data Set"<<","<<endl;
    for(Data_Set_Size=10000; elapsed<180;Data_Set_Size*=2) {
        if(Data_Set_Size>1000000000){
            break;
        }
        start = clock();
        radixsort(arr,Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<Data_Set_Size<<endl;
        out<<i<<","<<elapsed<<","<<Data_Set_Size<<endl;
        i++;
    }
}

void Fully_Sorted_Data_Test(int arr[],long int Data_Set_Size,double elapsed,clock_t start,clock_t end){

    ofstream out;
    out.open("Fully Sorted Statistics.csv");

    out << "Fully Sorted Data Test" << endl;
    cout<<"Array is being loaded"<<endl<<endl;
    data_set(arr,1000000000);
    cout<<"Array is being sorted test will start shortly...."<<endl<<endl;
    radixsort(arr,1000000000);

    int i = 1;
    elapsed = 0;

    cout << "***Selection Sort***" << endl;
    out << "Selection Sort" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;

    for (Data_Set_Size = 10000; elapsed <= 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        start = clock();
        selectionSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    elapsed = 0;
    Data_Set_Size = (Data_Set_Size / 4);
    float quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;

    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        start = clock();
        selectionSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }

    out << "" << endl;

    i = 1;
    elapsed = 0;
    cout << "***Bubble Sort***" << endl;
    out << "Bubble Sort" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;
    for (Data_Set_Size = 10000; elapsed < 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 1000000000) {
            break;
        }
        start = clock();
        bubbleSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    elapsed = 0;
    Data_Set_Size = Data_Set_Size / 4;
    quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;
    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 1000000000) {
            break;
        }

        start = clock();
        bubbleSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
        out << "" << endl;
    }
    i = 1;
    elapsed = 0;
    cout << "***Insertion Sort***" << endl;
    out << "Insertion Sort" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;
    out << i << "," << elapsed << "," << Data_Set_Size << endl;

    for (Data_Set_Size = 10000; elapsed < 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 1000000000) {
            break;
        }

        start = clock();
        insertionSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }

    elapsed = 0;
    Data_Set_Size = Data_Set_Size / 4;
    quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;

    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 1000000000) {
            break;
        }

        start = clock();
        insertionSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    out << "" << endl;

    i = 1;
    elapsed = 0;
    cout << "***MergeSort***" << endl;
    out << "MergeSort" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;

    for (Data_Set_Size = 10000; elapsed < 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 1000000000) {
            break;
        }

        start = clock();
        mergeSort(arr, 0, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }

    elapsed = 0;
    Data_Set_Size = Data_Set_Size / 4;
    quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;

    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 1000000000) {
            break;
        }

        start = clock();
        mergeSort(arr, 0, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    out << "" << endl;


    i = 1;
    elapsed = 0;
    cout << "***QuickSort***" << endl<<endl;
    out << "QuickSort Will Crash with sorted data" << endl;
    out << "" << endl;


    cout << "***Maxheap***" << endl;
    out << "Maxheap" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;

    for (Data_Set_Size = 10000; elapsed < 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 1000000000) {
            break;
        }

        start = clock();
        heapSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }

    elapsed = 0;
    Data_Set_Size = Data_Set_Size / 4;
    quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;

    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 1000000000) {
            break;
        }

        start = clock();
        heapSort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }
    out << "" << endl;

    i = 1;
    elapsed = 0;
    cout << "***RadixSort***" << endl;
    out << "RadixSort" << endl;
    out << "Current Run" << "," << "Time Taken" << "," << "Size of Data Set" << "," << endl;

    for (Data_Set_Size = 10000; elapsed < 180; Data_Set_Size *= 2) {
        if (Data_Set_Size > 1000000000) {
            break;
        }

        start = clock();
        radixsort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;

        i++;
    }

    elapsed = 0;
    Data_Set_Size = Data_Set_Size / 4;
    quat = Data_Set_Size / 4;
    Data_Set_Size = Data_Set_Size + quat;

    for (Data_Set_Size = Data_Set_Size; elapsed <= 180; Data_Set_Size += quat) {
        if (Data_Set_Size > 1000000000) {
            break;
        }

        start = clock();
        radixsort(arr, Data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: " << elapsed << "   Current run: " << i << "  Size of Data Set: " << Data_Set_Size
             << endl;
        out << i << "," << elapsed << "," << Data_Set_Size << endl;
        i++;
    }

}
