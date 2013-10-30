#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>


//created by Adam Plánský
//mail: adamplansky@gmail.com / plansada@fit.cvut.cz


using namespace std;

static void Merge(int * A, int * B, int low, int high, int half) {

    int i, j, k;
    k = i = low;
    j = half + 1;
    while (1) {
        if (i > half) {
            while(j<=high)
                B[k++] = A[j++];
            break;
        }
        if (j > high) {
            while(i <= half){
                B[k++] = A[i++];
            }
            break;
        }
        if (A[i] <= A[j]) {
            B[k++] = A[i++];
            continue;
        }
        if (A[i] > A[j]) {
            B[k++] = A[j++];
            continue;
        }
    }
    i = low;
    for (; i <= high; i++) {
        A[i] = B[i];
    }



}

static void MergeSort(int * A, int * B, int low, int high) {

    if (low < high) {
        int half = (low + high) / 2;
        MergeSort(A, B, low, half);
        MergeSort(A, B, half + 1, high);
        Merge(A, B, low, high, half);
    }
}

static void swap(int * arr, int left, int right) {
    int tmp = arr[left];
    arr[left] = arr[right];
    arr[right] = tmp;
}

static void swap1(int * arr, int left, int right) {
    arr[left] = arr[left] + arr[right];
    arr[right] = arr[left] - arr[right];
    arr[left] = arr[left] - arr[right];
}
static void swap2(int * arr, int left, int right){
    arr[left] = arr[left] ^ arr[right];
    arr[right] = arr[left] ^ arr[right];
    arr[left] = arr[left] ^ arr[right];
}

static void QuickSort(int * arr, int left, int right) {
    int i = left;
    int j = right;
    int pivot = arr[(i + j) / 2];
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            swap(arr, i++, j--);
            //            i++;
            //            j--;
        }
    }
    if (left < j)
        QuickSort(arr, left, j);
    if (i < right)
        QuickSort(arr, i, right);
}

//return position
static int binarySearch(int * arr, int key, int left, int right){
    int mid = 0;
    while(left <= right)
    {
        mid = (left+right)/2;
        if(arr[mid] < key) {
            left = arr[mid+1];
        } else if(arr[mid] > key){
            right = arr[mid-1];
        } else {
            return mid;
        }
    }
}
int main(int argc, char** argv) {


    int A[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int B[] = {1, 2, 3, 4};
    int C[] = {1, 2, 3, -1};
    int D[4];

    int key = 1;
    cout << binarySearch(A,key,0,19) << endl << endl;

    
        MergeSort(C, D, 0, 3);
    
        for (int a = 0; a < 4; a++) {
            cout << a << ": " << C[a] << endl;
        }
//    QuickSort(C, 0, 3);
//
//    for (int a = 0; a < 4; a++) {
//        cout << a << ": " << C[a] << endl;
//    }
//
//    cout << "----------------------" << endl;
//    int E[2] = {1, 2};
//    for (int a = 0; a < 2; a++) {
//        cout << a << ": " << E[a] << endl;
//    }
//    swap2(E, 0, 1);
//    for (int a = 0; a < 2; a++) {
//        cout << a << ": " << E[a] << endl;
//    }
    return 0;
}

