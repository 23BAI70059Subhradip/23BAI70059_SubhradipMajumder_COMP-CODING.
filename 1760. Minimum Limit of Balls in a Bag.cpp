class Solution {
public:
    int max_(vector<int>& nums){
        int m = nums[0]; 
        for(auto i: nums) m =max(m, i); 
        return m; 
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, h = max_(nums); 

        while (l < h) {
            int mid = l + (h - l) / 2;
            int ops = 0;    
            for (int n : nums) 
                if ((ops += (n - 1) / mid) > maxOperations) 
                    break;
            if (ops <= maxOperations) {h = mid;} 
            else l = mid + 1;
        }

        return l;

    }
};
