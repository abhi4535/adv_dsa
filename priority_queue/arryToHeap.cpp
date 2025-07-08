//here we convert an array to heap

#include <bits/stdc++.h>
using namespace std;
void up_heapify(int idx,vector<int> &hp){
        if(idx==0)return;
        int pi=(idx-1)/2;
        while(idx>0 && hp[pi]<hp[idx]){
            swap(hp[pi],hp[idx]);
            idx=pi;
            pi=(pi-1)/2;
        }
    }

int main(){
    vector<int> v;
    for(int i=0; i<10; i++){
        int ran=rand();
        v.push_back(ran);

    }
    for(int n: v){
        cout<<n<<" ";
    }
    cout<<endl;
    for(int i=0; i<10; i++){
        up_heapify(i,v);
    }
    for(int n: v){
        cout<<n<<" ";
    }
    return 0;
}