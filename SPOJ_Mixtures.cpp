// https://www.spoj.com/problems/MIXTURES/

#include <bits/stdc++.h>
#define mod 1e9+7
#define ll long long
using namespace std;

pair<int,int> rec(int l,int r,vector<int>&v,vector<vector<pair<int,int>>>&dp){
    if(dp[l][r].second!=-1){
        return dp[l][r];
    }
    if(l == r){
        return dp[l][r] = {v[l],0};
    }
    if(r - l == 1){
        return dp[l][r] = {(v[l]+v[r])%100,v[l]*v[r]};
    }
    int color = 0;
    int smoke = INT_MAX;
    for(int i=l;i+1<=r;i++){//partitioning
        auto res1 = rec(l,i,v,dp);
        auto res2 = rec(i+1,r,v,dp);
        int totalSmoke = res1.second + res2.second + (res1.first * res2.first);
        if(totalSmoke < smoke){
            smoke = totalSmoke;
            color = (res1.first + res2.first)%100;
        }
    }
    return dp[l][r] = {color,smoke};
}
int main(){
    int n;
    while(cin>>n){
        vector<int>v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        vector<vector<pair<int,int>>>dp(n+1,vector<pair<int,int>>(n+1,{-1,-1}));
        //dp[i][j] stores pair of {color,smoke}
        auto ans = rec(0,n-1,v,dp);
        cout<<ans.second<<"\n";   
    }
}
