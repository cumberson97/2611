#ifndef _SORTMETHODS_H
#define _SORTMETHODS_H
struct Astruct{
     int key;
    int  data[100];
};

void displayArray (int A[], int lengthA);
void selectionSort (int A[], int lengthA);
void bubbleSort (int A[], int lengthA);
void insertionSort (int A[], int lengthA);
void mergeSort (int A[], int start, int end);
void quickSort (int A[], int p, int r);
void radixsort(int arr[], int n);
void countSort(int arr[], int n, int exp);
int getMax(int arr[], int n);
void Sradixsort(Astruct arr[], int n);
void ScountSort(Astruct arr[], int n, int exp);
int SgetMax(Astruct arr[], int n);
void SquickSort (Astruct A[], int p, int r);
int Spartition (Astruct A[], int p, int r);
void SmergeSort (Astruct A[], int start, int end);
void Smerge (Astruct A[], int p, int q, int r);
#endif
