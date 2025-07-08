#include<bits/stdc++.h>
using namespace std;

class heap{
    private:
    vector<int> v;


    void up_heapify(int idx){
        if(idx==0)return;
        int pi=(idx-1)/2;
        while(v[pi]<v[idx]){
            swap(v[pi],v[idx]);
            idx=pi;
            pi=(pi-1)/2;
        }
    }

    void down_heapify(int idx){
        
        int n=v.size();
        while(true){
            int largest=idx;
            int lc=2*idx+1;
            int rc=2*idx+2;
            if(lc<n && v[largest]<v[lc])largest=lc;
            if(rc<n && v[largest]<v[rc])largest=rc;

            if(largest==idx)break;

            swap(v[largest],v[idx]);
            idx=largest;
        }
    }
    
    
    public:
    
    // heap(vector<int> &v){
    //     this->v=v;
    // }

    
     void insertion(int n){
        v.push_back(n);
        up_heapify(v.size()-1);
     }
     
     void pop_out(){
        swap(v[0],v[v.size()-1]);
        v.pop_back();
        down_heapify(0);

     }
     void display(){
        for(int num: v){
            cout<<num<<" ";
        }
        cout<<endl;
     }

};

int main(){
    
    heap newheap;
    for(int i=0; i<10; i++){
        int ran=rand();
        newheap.insertion(ran);    
    }
    newheap.insertion(100000);
    newheap.display();
    newheap.pop_out();
    newheap.display();
    return 0;
}