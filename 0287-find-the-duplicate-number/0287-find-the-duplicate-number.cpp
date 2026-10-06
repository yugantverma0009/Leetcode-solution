class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      int slow=nums[0];
      int fast=nums[0];
      // due to this dont break at starting 
      slow=nums[slow];
      fast=nums[nums[fast]];
      int p=nums[0];
      while(slow!=fast){
        slow=nums[slow];
        fast=nums[nums[fast]];
     }
       while(p!=slow){
            p=nums[p];
            slow=nums[slow];
        }
              return slow;
      }
    };