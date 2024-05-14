#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void heapify(int arr[], int N, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    
    if (l < N && arr[l] > arr[largest])
        largest = l;

    
    if (r < N && arr[r] > arr[largest])
        largest = r;

   
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
    cmp++;
}

void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for (int i = N - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


int main()
{
    int size;
    int *arr;
    ofstream file;
    file.open("HeapSortData.csv", ios::out);

    for (int i = 0; i < 100; i++)
    {
        size = (rand() % 1000) + 30;
        arr = new int[size];
        for (int j = 0; j < size; j++)
        {
            arr[j] = (rand() % 100);
        }
        int N = sizeof(arr) / sizeof(arr[0]);;
        cmp =heapSort(arr, N);
        cout << "Size = " << size << " | Comparisons = " << cmp << endl;
        file << size << "," << cmp << "\n";
        
    }
    file.close();
    return 0;
}

