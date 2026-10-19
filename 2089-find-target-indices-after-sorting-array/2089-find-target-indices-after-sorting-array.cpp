class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> result;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(target>nums[i]){
                count++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
               result.push_back(count++);
            }
        }
        return result;
    }
};