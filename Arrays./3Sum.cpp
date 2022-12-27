//Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {


        /*brute force - T.C = O(n3 log m)     
         m- insertion of nums into set   n- traversing three loop  

         Approach-
         will traverse each number and find out unique pair and add that in set
         */     


         /*Two pointer approach -T.C=O(N*N)
         a+b+c=0
         b+c=-a (keeping the pointer a constant will change the position of b and c)
         */
         vector<vector<int>> res; 
        sort(nums.begin(), nums.end()); 
        
        // moves for a
        //from 0->last 3rd element(from last 3rd we get our three pair)
        for (int i = 0; i < (int)(nums.size())-2; i++) {     
            
            //to avoid repeatation of duplicate numbers
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                
                //a+b+c=0
                //b+c=-a
                int lo = i+1, hi = (int)(nums.size())-1, sum = 0 - nums[i];
                
                while (lo < hi) {
                    if (nums[lo] + nums[hi] == sum) {
                        
                        vector<int> temp; 
                        temp.push_back(nums[i]); 
                        temp.push_back(nums[lo]); 
                        temp.push_back(nums[hi]); 
                        res.push_back(temp);
                        

                        //to avoid duplicates will increase the pointer until we get new number
                        while (lo < hi && nums[lo] == nums[lo+1]) lo++;
                        while (lo < hi && nums[hi] == nums[hi-1]) hi--;
                        
                        lo++; hi--;
                    } 
                    else if (nums[lo] + nums[hi] < sum) lo++;  //sum is less increase lo to right
                    else hi--;             //sum is more decrease ho to left
               }
            }
        }
        return res;
    }
};
