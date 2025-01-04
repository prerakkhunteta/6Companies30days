class Solution {
public:
 int helpMe(vector<int>& nums, int goal) {
        int l = 0;
        int r = 0;
        int sum = 0;
        int cnt = 0;
        
        if (goal < 0) {
            return 0;
        }
        for(int i = 0;i<nums.size();i++){
            if(nums[i]%2==0){
                nums[i] = 0;
            }
            else{
                nums[i] = 1;
            }
        }
        while (r < nums.size()) {
            sum += nums[r];
            while (sum > goal) {
                if (nums[l] == 1) {
                    sum--;
                }
                l++;
            }
            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int goal) {
         return helpMe(nums, goal) - helpMe(nums, goal - 1);
    }
};
