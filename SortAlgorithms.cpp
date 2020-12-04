#include <iostream>
#include "SortAlgorithms.h"
   using namespace std;
static int * b = new int [1000000000];
static int * c = new int [1000000000];
void displayArray (int A[], int lengthA) {

	int i;
	
	for (i=0; i<lengthA; i++)
		cout << A[i] << " ";
		
	cout << endl;
}


void selectionSort (int A[], int lengthA) {

    int i, j, min, temp;  
   
    for (i=0; i<lengthA-1; i++) {  
        min = i;  
        for (j = i+1; j<lengthA; j++) { 
        	if (A[j] < A[min])  
            	min = j;  
        }

		temp = A[i];
		A[i] = A[min];
		A[min] = temp;
    }  
}  


void bubbleSort (int A[], int lengthA) {

    int i, j, temp; 
    bool swapped;
    
	for (i=0; i<lengthA-1; i++) {
	   swapped = false;
	   for (j=0; j<lengthA-i-1; j++) {
	      if (A[j] > A[j+1]) {
	         temp = A[j];
	         A[j] = A[j+1];
	         A[j+1] = temp;
	         swapped = true;
	      }
	   }
	   if (!swapped)
	   		break;
	}
}



void insertInPlace (int A[], int n, int newElement) {

	int k = n-1;

	while (k >= 0 && newElement < A[k]) {
		A[k+1] = A[k];
		k--;
	}

	A[k+1] = newElement;
}



void insertionSort (int A[], int lengthA) {
	
	int i;
	
	for (i=1; i<lengthA; i++)
		insertInPlace (A, i, A[i]);
		
}



void merge (int A[], int p, int q, int r) {
    int n1, n2;

    n1 = q - p + 1;
    n2 = r - q;

    for (int k=0; k<n1; k++)
        b[k] = A[k+p];

    b[n1] = INT_MAX;

    for (int k=0; k<n2; k++)
        c[k] = A[q+k+1];

    c[n2] = INT_MAX;

    int i, j;

    i = 0;
    j = 0;

    for (int k=p; k<=r; k++) {
        if (b[i] < c[j]) {
            A[k] = b[i];
            i++;
        }
        else {
            A[k] = c[j];
            j++;
        }
    }

}



void mergeSort (int A[], int start, int end) {
    int mid;

    if (start < end) {
        mid = (start + end) / 2;
        mergeSort (A, start, mid);
        mergeSort (A, mid+1, end);
        merge (A, start, mid, end);
    }

}


int partition (int A[], int p, int r) {
	
	int x, i, j;
	int temp;
	
	x = A[r];	
	i = p - 1;
	
	for (j=p; j<=r-1; j=j+1) {
		if (A[j] <= x) {
			i = i + 1;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	
	temp = A[i+1];
	A[i+1] = A[r];
	A[r] = temp;

	return (i+1);
}

	

void quickSort (int A[], int p, int r) {
	int q;
	
	if (p < r) {
		q = partition (A, p, r);
		quickSort (A, p, q-1);
		quickSort (A, q+1, r);
	}
}

int getMax(int arr[], int n) {
    int mx = arr[0];
    int i;
    for (i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp) {
    static int * output = new int[1000000000];
    int i, count[10] = { 0 };


    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];


    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}


void radixsort(int arr[], int n) {
    int m = getMax(arr, n);

    int exp;
    for (exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int SgetMax(Astruct arr[], int n) {
    int mx = arr[0].key;
    int i;
    for (i = 1; i < n; i++)
        if (arr[i].key > mx)
            mx = arr[i].key;
    return mx;
}
void ScountSort(Astruct arr[], int n, int exp) {
    static int * output = new int[1000000000];
    int i, count[10] = { 0 };


    for (i = 0; i < n; i++)
        count[(arr[i].key / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];


    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i].key / exp) % 10] - 1] = arr[i].key;
        count[(arr[i].key / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i].key = output[i];
}
void Sradixsort(Astruct arr[], int n) {
    int m = SgetMax(arr, n);

    int exp;
    for (exp = 1; m / exp > 0; exp *= 10)
        ScountSort(arr, n, exp);
}

int Spartition (Astruct A[], int p, int r) {

    int x, i, j;
    int temp;

    x = A[r].key;
    i = p - 1;

    for (j=p; j<=r-1; j=j+1) {
        if (A[j].key <= x) {
            i = i + 1;
            temp = A[i].key;
            A[i].key = A[j].key;
            A[j].key = temp;
        }
    }

    temp = A[i+1].key;
    A[i+1].key = A[r].key;
    A[r].key = temp;

    return (i+1);
}

void SquickSort (Astruct A[], int p, int r) {
    int q;

    if (p < r) {
        q = Spartition (A, p, r);
        SquickSort (A, p, q-1);
        SquickSort (A, q+1, r);
    }
}

void Smerge (Astruct A[], int p, int q, int r) {
    int n1, n2;
    static int * b = new int [1000000000];
    static int * c = new int [1000000000];
    n1 = q - p + 1;
    n2 = r - q;

    for (int k=0; k<n1; k++)
        b[k] = A[k+p].key;

    b[n1] = INT_MAX;

    for (int k=0; k<n2; k++)
        c[k] = A[q+k+1].key;

    c[n2] = INT_MAX;

    int i, j;

    i = 0;
    j = 0;

    for (int k=p; k<=r; k++) {
        if (b[i] < c[j]) {
            A[k].key = b[i];
            i++;
        }
        else {
            A[k].key = c[j];
            j++;
        }
    }

}

void SmergeSort (Astruct A[], int start, int end) {
    int mid;

    if (start < end) {
        mid = (start + end) / 2;
        SmergeSort (A, start, mid);
        SmergeSort (A, mid+1, end);
        Smerge (A, start, mid, end);
    }

}
