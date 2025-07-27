#include<bits/stdc++.h>
using namespace std;

vector<int>st,lazy;

void buildSt(vector<int> &nums, int lo,int hi,int i){
    if(lo==hi){
        st[i]=nums[lo];
        return;
    }
    int mid=lo+(hi-lo)/2;
    buildSt(nums,lo,mid,2*i+1);
    buildSt(nums,mid+1,hi,2*i+2);
    st[i]=st[2*i+1]+st[2*i+2];
}

int getSum(int i,int lo,int hi,int l,int r){
    if(lazy[i]!=0){
        int range=hi-lo+1;
        st[i]+=range*lazy[i];
        if(lo!=hi){
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }
    if(l<=lo && r>=hi)return st[i];
    else if(l>hi || r<lo)return 0;
    int mid=lo+(hi-lo)/2;
    return getSum(2*i+1,lo,mid,l,r)+getSum(2*i+2,mid+1,hi,l,r);
}

void update(int i,int lo, int hi, int l,int r,int val){
    if(lazy[i]!=0){
        int range=hi-lo+1;
        st[i]+=range*lazy[i];
        if(lo!=hi){
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }
    if(l>hi || r<lo)return;
    else if(lo>=l && hi<=r){
        int ran=hi-lo+1;
        st[i]+=ran*val;
        if(lo!=hi){
            lazy[2*i+1]+=val;
            lazy[2*i+2]+=val;
        }
        return;
    }
    int mid=lo+(hi-lo)/2;
    update(2*i+1,lo,mid,l,r,val);
    update(2*i+2,mid+1,hi,l,r,val);
    st[i]=st[2*i+1]+st[2*i+2];
}

int main(){
    vector<int>nums={2,1,2,3,4,6,45,6,4,5,6,4};
    int n=nums.size();
    st.resize(4*n);
    lazy.resize(4*n,0);
    buildSt(nums,0,n-1,0);
    cout<<getSum(0,0,n-1,1,3)<<" ";
    update(0,0,n-1,2,5,10);
    cout<<endl;
    cout<<getSum(0,0,n-1,1,3)<<" ";
    return 0;

}