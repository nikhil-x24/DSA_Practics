// //LC -> 78 subset
// i/p  -> {1,2,3}
// o/p  -> return powerset (set of all subset)   2^3 = 8
//         [{}, {1}, {2}, {1,2}, {3}, {1,3}, {2,3}, {1,2,3}]

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
                 //error hai
void solve(vector<int> nums, vector<int> output, int index,
           vector<int>& ans){
        
    //base case
    if(index >= nums.size()){
        ans.push_back(output);
        return;
    }
    //exclude
    solve(nums, output, index+1, ans);
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index+1, ans);
        
}
    
vector<int> subsets(vector<int>& nums){
        
    vector<int> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans; 
        
}
int main(){
    vector<int> nums = {1,2,3};
    subsets(nums);

    vector<int> ans  = subsets(nums);
    
    for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << endl;
    }
}