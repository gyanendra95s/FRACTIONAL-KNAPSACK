#include<bits/stdc++.h>
using namespace std;

bool compare(pair<double,int>p1,pair<double,int>p2){
    return p1.first>p2.first;
}
double fractionalKnapsack(vector<int>&val,vector<int>&weight,int W){
    int n=val.size();

    // As,ratio=value[i]/weight[i]
    vector<pair<double,int>> ratio(n,make_pair(0.0,0)); //pair(ratio,idx)->(double,int)

    // Ratio of value/weight
    for(int i=0;i<n;i++){
        double r=val[i]/(double)weight[i];
        ratio[i]=make_pair(r,i);
    }

    sort(ratio.begin(),ratio.end(),compare);
    double ans=0;
    for(int i=0;i<n;i++){
        int idx=ratio[i].second;
        if(weight[idx]<=W){
            ans+=val[idx];
            W-=weight[idx];
        }
        else{
            ans+=(ratio[i].first*W);
            break;
        }
    }
    return ans;
}
int main(){
    vector<int>val={60,100,120};
    vector<int>weight={10,20,30};
    int W=50;

    cout<<fractionalKnapsack(val,weight,W)<<endl;
    return 0;
}