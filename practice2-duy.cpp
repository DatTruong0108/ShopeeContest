#include<iostream>
#include<vector>
using namespace std;


int findMaxConsecutiveOnes(vector<int> nums) {
        int curr=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                curr++;
            }
            if(nums[i]==0)
                curr=0;
            ans=max(ans,curr);
        }
        return ans;

}

int main()
{
    vector<int> numOne= {1,1,1,0,0,1,1,1,1,0,1};
    cout<<findMaxConsecutiveOnes(numOne);
    return 0;
}   