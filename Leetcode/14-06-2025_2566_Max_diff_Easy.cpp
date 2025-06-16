#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int check(vector<int>&arr,int l){
        int a=0;
        int n=arr.size();
        n--;
        // finding a digit to be replaced for largest and smallest seperately.

        while(n>=0 && arr[n]==l) n--;

        int x = -1;
        if(n>=0) x = arr[n];
        int i=arr.size();
        
        while(i--){
            // replacing the digit with 9 and 0) for largest and smallest respectively.
            if(x==arr[i]){
                a = a*10 + l;
            }
            else a = a*10 + arr[i];
        }
        return a;
}
    int minMaxDifference(int num) {
         vector<int>arr;
        while(num>0){
            arr.push_back(num%10);
            num/=10;
        }
        int a1 = check(arr,9);
        int a2 = check(arr,0);
    
        return a1-a2;
    }
};