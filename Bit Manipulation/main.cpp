#include <bits/stdc++.h>
using namespace std;

// Convert Decimal to Binary
// TC: O(logn) ; SC: O(logn)
string convertToBinary(int x){
    string ans="";
    while(x){
        if(x%2==1){
            ans+='1';
        }
        else{
            ans+='0';
        }

        x=x/2;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

// Convert Binary to Decimal
// TC: O(n) ; SC: O(1)
int convertToDecimal(string s){
    int n= s.length();
    int p2=1, num=0;

    for(int i=n-1;i>=0;i--){
        if(s[i]=='1'){
            num+=p2;
        }
        p2=p2*2;

    }

    return num;
}

int main(){

    string bits= convertToBinary(727);
    int no= convertToDecimal("1011010111");
    
    cout<<"The Binary representation is: "<<bits<<endl;
    cout<<"The Decimal representation is: "<<no<<endl;


    return 0;
}