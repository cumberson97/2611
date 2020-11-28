#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

#include "MaxHeap.h"
#include "SortAlgorithms.h"

using namespace std;
void data_set (int a[],int data_set_size){
    long long int numbers;
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<long long unsigned>distribution(0,100000000);
    for (int i=1; i < data_set_size; i++){
        a[i]= distribution(generator);
    }
}


int main () {
    static int * array = new int [100000000];
    int data_Set_Size;
    double elapsed;
    int i=1;
    clock_t start, end;

    for(data_Set_Size=10000;elapsed<180;data_Set_Size+=20000) {
        data_set(array, data_Set_Size);bubbleSort(array, data_Set_Size);
        end = clock();
        elapsed = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken: "<< elapsed <<"   Current run: "<<i<<"  Size of Data Set: "<<data_Set_Size<<endl;
        i++;
    }
	displayArray(array,data_Set_Size);


	cout<<start<<" "<<end<<" "<<elapsed<<endl;
	// write code here to perform experiments with the sort algorithms
	
	return 0;
}
