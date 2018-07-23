class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int length = nums.size();
        vector<vector<int>> quadruplets;
        if(length<4) return quadruplets;
        sort(nums.begin(),nums.end());
        for(int i=0;i<length-3;i++){
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[length-3]+nums[length-2]+nums[length-1] < target) continue;
            for(int j =i+1;j<length-2;j++){
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2] > target) break;
                int left_h = j+1,right_h =length-1;
                while(left_h<right_h){
                    int add = nums[left_h]+nums[right_h]+nums[j]+nums[i];
                    if(add==target)
                        quadruplets.push_back({nums[left_h],nums[right_h],nums[j],nums[i]});
                    if(add>target){
                        right_h--;
                        while(nums[right_h]==nums[right_h+1]&&left_h<right_h)
                            right_h--;
                    }
                    if(add<=target){
                        left_h++;
                        while(nums[left_h]==nums[left_h-1]&&left_h<right_h)
                            left_h++;
                    }
                }
                while(nums[j]==nums[j+1]&&j<length)
                    j++;
            }
            while(nums[i]==nums[i+1]&&i<length)
                i++;
        }
        return quadruplets;
    }
};
