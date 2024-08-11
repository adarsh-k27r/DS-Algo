#include <bits/stdc++.h>
using namespace std;

// Using Two Pointers approach.
// TC: O(N/2); SC: O(1);

void reverseString(string &str){
    int i=0, j=str.length()-1;

    while(i<=j){
        swap(str[i],str[j]);
        i++;
        j--;
    }
}

int main(){

    string st;
    cout<<"Enter the string: ";
    cin>>st;
    reverseString(st);

    cout<<"Reversed string is: "<<st<<endl;

    return 0;
}