#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
int check(vector<int>&arr,int l){
        int a=0;
        int n=arr.size();
        n--;
        // finding a digit to be replaced for largest and smallest seperately.

        if (l==1) { 
            while(n>=0 && (arr[n]==1 || arr[n]==0)) n--;
        }
        else while(n>=0 && arr[n]==l) n--;

        int x = -1;
        if(n>=0) x = arr[n];
        int i=arr.size();
        
        while(i--){
            if(x==arr[i]){
                // replacing the digit with 9 and (1 or 0) for largest and smallest respectively.
                if(l==1) { 
                    if(n==arr.size()-1) a = a*10 + l;
                    else a=a*10;
                } 
                else a = a*10 + l;
            }
            else a = a*10 + arr[i];
        }
        return a;
}
    int maxDiff(int num) {
        vector<int>arr;
        while(num>0){
            arr.push_back(num%10);
            num/=10;
        }
        int a1 = check(arr,9);
        int a2 = check(arr,1);
    
        return a1-a2;
    }
};