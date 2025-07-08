#include<bits/stdc++.h>
using namespace std;

void downHeapify(int idx, vector<int> &arr){
    int n=arr.size();
    while(true){
        int lar=idx;
        int lc=(idx-1)/2;
        int rc=(idx-1)/2;
        if(lc<n && arr[lc]>arr[idx])lar=lc;
        if(rc<n && arr[rc]>arr[idx])lar=rc;
        if(lar==idx)break;
        swap(arr[lar],arr[idx]);
        idx=lar;
    }
}
int main(){
    vector<int> arr;

}