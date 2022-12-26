#Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.


#include<iostream>
#include<map>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
       /* set<int> s;
        for(int i=0;i<nums.size();i++){
            auto it=s.find(nums[i]);
            cout<<*it<<endl;
            if(it !=s.end()){
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }*/
        
        
        map<int,int>countMap;
        for(int i=0;i<nums.size();i++){
            int x=countMap.count(nums[i]);
            cout<<x;
            
            if(countMap[nums[i]]==1){
                return true;
            }
            countMap[nums[i]]++;
        }
        return false;
    }
        
        
};
