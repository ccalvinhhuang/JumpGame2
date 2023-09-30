#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int jump(vector<int>& nums) {
    if(nums.size() == 1) return 0;
    int mmax = -1;
    int maxes[nums.size()];
    for(int i = 0; i < nums.size(); i++){
        mmax = max(mmax, i + nums[i]);
        maxes[i] = mmax;
    }
    int jumps = 0;
    int cur_max = nums.size() - 1;
    for(int i = nums.size() - 1; i >= 0; i--){
        if(i == 0){
            jumps++;
            break;
        }
        if(maxes[i - 1] < cur_max){
            jumps++;
            cur_max = i;
        }
    }
    return jumps;
}
int main() {
    vector<int>test1 = {2,3,0,1,4};
    cout << jump(test1);
}
