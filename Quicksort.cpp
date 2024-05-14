#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int partition(int arr[], int low, int high, int& c)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        c++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int randomizedPartition(int arr[], int low, int high, int& c)
{
    int random = low + rand() % (high - low + 1);
    swap(arr[random], arr[high]);
    return partition(arr, low, high, c);
}

void quickSort(int arr[], int low, int high, int& c)
{
    if (low < high) {
        int pivot = randomizedPartition(arr, low, high, c);
        quickSort(arr, low, pivot - 1, c);
        quickSort(arr, pivot + 1, high, c);
    }
}

int main()
{
    int size;
    int *arr;
    int cmp;
    ofstream file;
    file.open("rQuickSortData.csv", ios::out);
    file << "Size" << "," << "Comparisons" << "\n";
    for (int i = 0; i < 100; i++)
    {
        cmp = 0;
        size = (rand() % 1000) + 30;
        arr = new int[size];
        for (int j = 0; j < size; j++)
        {
            arr[j] = (rand() % 100);
        }
        quickSort(arr, 0, size - 1, cmp);
        cout << "Size = " << size << " | Comparisons = " << cmp << endl;
        file << size << "," << cmp << "\n";
        delete[] arr;
    }
    file.close();
    return 0;
}

