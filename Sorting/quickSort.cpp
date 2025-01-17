#include <bits/stdc++.h>
using namespace std;

// Quick Sort
// TC: O(NlogN); SC: O(1) + RSS;

int partition(vector<int> &arr, int low, int high){
    // arr[low] is pivot.
    int pivot = arr[low];
    int i = low+1;
    int j = high;

    while(i<=j){
        while(i<=high && arr[i]<=pivot) i++;
        while(j>=low && arr[j]>pivot) j--;

        if(i<j){
            swap(arr[i], arr[j]);
        }
    }


    swap(arr[j], arr[low]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high){
    if(low>=high) return;

    int p = partition(arr, low, high);
    quickSort(arr, low, p-1);
    quickSort(arr, p+1, high);

}



void print(vector<int> &arr){
    for(auto &it : arr){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {1, 3, 7, 9, 0, 15, 13};
    int n = arr.size();
    quickSort(arr, 0, n-1);
    cout<<"Sorted list is: ";
    print(arr);
    return 0;
}