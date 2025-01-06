class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        
    int cnt = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                if(isIn(nums,i,j))
                cnt++;
            }
        }
        return cnt;
    }
    bool isIn(vector<int> & nums,int s,int e){
        int prev = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(i<=e && i>=s)
            continue;
            if(prev>=nums[i]) return false;
            prev = nums[i];
        }
    return true;
    }
    
};
