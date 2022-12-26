#Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
    set<int> num;
    set<int> num2;
    vector<int> ans; 

    for(auto it:nums1)                      
        num.insert(it);                  //inserting only unique values from nums1
        
    for(auto it:nums2)
        num2.insert(it);                 //inserting only unique values from nums2
    
    for(auto it:num2)
    {
        if(num.find(it)!=num.end())      //if element is not found push back in vector
            ans.push_back(it);
    }
    
    return ans;
    }

    
};
