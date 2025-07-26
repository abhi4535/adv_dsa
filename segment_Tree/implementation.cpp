#include<bits/stdc++.h>
using namespace std;
vector<int> st;
int buildTree(vector<int> &nums, int i, int lo,int hi){
    if(lo==hi){
        return st[i]= nums[lo];
    }
    int mid=(lo+hi)/2;
    return st[i]=max(buildTree(nums,2*i+1,lo,mid),buildTree(nums,2*i+2,mid+1,hi));
}

int getMax(int idx,int lo,int hi,int l,int r){

    if(lo>r || hi<l)return INT_MIN;
    else if(lo>=l && hi<=r)return st[idx];
    else {
        int mid=lo+(hi-lo)/2;
        return max(getMax(2*idx+1,lo,mid,l,r),getMax(2*idx+2,mid+1,hi,l,r));
    }
}

int main(){
    vector<int> nums={1,2,3,9,5,7,3,5,6,3,4,5};
    st.resize(nums.size()*4);
    buildTree(nums,0,0,nums.size()-1);
    for(int i=0; i<nums.size(); i++)cout<<st[i]<<" ";
    cout<<endl;
    cout<<getMax(0,0,nums.size()-1,0,2)<<endl;
    return 0;

}