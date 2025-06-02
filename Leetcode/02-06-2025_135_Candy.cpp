// 135 candy
// Greedy approach :
// take smallest rating child give him 1.
// before that check whether neigbours have candies.
// if there, based on (rating > neibours rating) then  give 1 + max(neibours) candies;

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            pq.push({ratings[i],i});
        }
        vector<int>dp(n,0);
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int val = it.first;
            int pos = it.second;
            int x=0,y=0;
            if(pos-1>=0){
                x=dp[pos-1];
                if(val==ratings[pos-1]) x=0;
            }
            if(pos+1<n) {
                y=dp[pos+1];
                if(val==ratings[pos+1]) y=0;
            }
            dp[pos]=max(x,y)+1;
        }
        int total=0;
        for(auto x:dp) total+=x;
        return total;
    }
};

void solve(){
    Solution obj = Solution();
    
    vector<int> ratings{2,4,1,3,4,4,5};

    cout << obj.candy(ratings);
}

int main(){
clock_t time_req;
time_req=clock();

solve();

time_req=clock()-time_req;
cout <<'\n';
cout << "Execution time : " << (float)time_req/CLOCKS_PER_SEC << " seconds" <<'\n';
return 0;
}