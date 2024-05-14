#include <iostream>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    int weight;
};

bool compare(Interval a, Interval b) {
    return a.end < b.end;
}

void merge(Interval arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    Interval L[n1], R[n2];
    for(int i=0; i<n1; i++)
        L[i] = arr[l + i];
    for(int j=0; j<n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2) {
        if(L[i].end <= R[j].end) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Interval arr[], int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int maxWeight(Interval intervals[], int n) {
    mergeSort(intervals, 0, n-1);
    int dp[n];
    dp[0] = intervals[0].weight;
    for(int i=1; i<n; i++) {
        int prevNonConflict = -1;
        for(int j=i-1; j>=0; j--) {
            if(intervals[j].end <= intervals[i].start) {
                prevNonConflict = j;
                break;
            }
        }
        if(prevNonConflict != -1)
            dp[i] = max(dp[i-1], dp[prevNonConflict] + intervals[i].weight);
        else
            dp[i] = max(dp[i-1], intervals[i].weight);
    }
    return dp[n-1];
}

int main() {
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;
    Interval intervals[n];
    cout << "Enter the start time, end time, and weight of each interval: " << endl;
    for(int i=0; i<n; i++) {
        cin >> intervals[i].start >> intervals[i].end >> intervals[i].weight;
    }
    cout << "The maximum total weight that can be obtained is: " << maxWeight(intervals, n) << endl;
    return 0;
}

