#include <bits/stdc++.h>
using namespace std;

// Merge Sort
// TC: O(NlogN); SC: O(N) + RSS;

void merge(vector<int> &arr, int low, int mid, int high){
    int n = arr.size();
    int i = low;
    int j = mid+1;

    vector<int> temp;

    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=high){
        temp.push_back(arr[j]);
        j++;
    }

    for(int k=low;k<=high;k++){
        arr[k] = temp[k-low];
    }

}

void merge_sort(vector<int> &arr, int low, int high){
    if(low>=high) return;
    int mid = low + (high-low)/2;

    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    merge(arr, low, mid, high);

}

void print(vector<int> &arr){
    int n = arr.size();
    for(auto &it : arr){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {1, 3, 7, 9, 0, 15, 13};
    int n = arr.size();

    merge_sort(arr, 0, n-1);
    cout<<"The result of merge sort: ";
    print(arr);

    return 0;
}