#include <bits/stdc++.h>
using namespace std;

// Selection Sort : TC: O(N*N); SC: O(1);
void selection_sort(vector<int> &v){
    int n = v.size();
    // select the minimum and swap.
    for(int i=0;i<n-1;i++){
        int mini = i;
        for(int j=i+1;j<n;j++){
            if(v[j]<v[mini]){
                mini = j;
            }
        }
        // swap
        int temp = v[mini];
        v[mini] = v[i];
        v[i] = temp;
    }
}

// Bubble Sort
// TC: For avg and worst case: O(N*N); For Best case: O(N); SC: O(1);
void bubble_sort(vector<int> &v){
    // Push the maximum to the bottom using adjacent swaps.
    int n = v.size();
    for(int j=n-1;j>0;j--){
        bool didSwap = 0;
        for(int i=0;i<j;i++){
            if(v[i]>v[i+1]){
                swap(v[i], v[i+1]);
                didSwap = 1;
            }
        }
        if(!didSwap){
            break;
        }
    }  
}

// Insertion Sort
// TC: For avg and worst case: O(N*N); For Best case: O(N); SC: O(1);
void insertion_sort(vector<int> &v){
    // Insert the number at it's correct position in the sorted array using reverse swapping.
    int n = v.size();
    for(int j=1;j<n;j++){
        int i = j;
        while(i>0 && v[i]<v[i-1]){
            swap(v[i], v[i-1]);
            i--;
        }
    }
}

void print(vector<int> &v){
    for(auto &it: v){
        cout<<it<<" ";
    }
    cout<<endl;
}


int main(){
    vector<int> v = {11, 34, 3, 67, 56, 15273, 363};
    // selection_sort(v);
    // cout<<"Selection Sort results: ";
    // print(v);
    
    // bubble_sort(v);
    // cout<<"Bubble Sort results:    ";
    // print(v);

    insertion_sort(v);
    cout<<"Insertion Sort results: ";
    print(v);

    return 0;
}