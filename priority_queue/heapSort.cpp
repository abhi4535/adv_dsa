#include<bits/stdc++.h>
using namespace std;
class heapy{
    vector<int> nums;
    public:
    heapy(vector<int> nums){
        this->nums=nums;

        for(int i=nums.size()/2; i>=0; i--){
            downHeapify(nums.size(),i);
        }
    }
    void downHeapify(int n,int idx){
        while(true){
            int lar=idx;
            int lc=2*idx+1;
            int rc=2*idx+2;
            if(lc<n && nums[lar]<nums[lc])lar=lc;
            if(rc<n && nums[lar]<nums[rc])lar=rc;
            if(lar==idx)break;
            swap(nums[idx],nums[lar]);
            idx=lar;
        }
    } 

    void sorting(){
        int i=nums.size()-1;
        while(i>0){
            swap(nums[0],nums[i]);
            downHeapify(i,0);
            i--;
        }
    }
    
    void display(){
        for(int n: nums)cout<<n<<" ";
        cout<<endl;
    }
};
    


int main(){
    vector<int> nums;
    for(int i=0; i<10; i++){
        int ran=rand();
        nums.push_back(ran);
    }
    heapy hp(nums);
    hp.display();
    hp.sorting();
    hp.display();
    return 0;
}