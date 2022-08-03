class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int n = nums.size();
      
      vector<int> prefixSum(n);
      prefixSum[0] = nums[0];
      vector<int> p(1,-1);
      
      int rs = 0;
      
      for (int i = 1; i < n; i++) {
        prefixSum[i] = (prefixSum[i - 1] + nums[i]);
      }
      
      for (int pivot = n - 1; pivot >= 0; pivot--) {
        if(pivot == 0 && rs == 0) p.push_back(pivot);
        if(pivot == 0) break;
        if (prefixSum[pivot - 1] == rs) {
          p.push_back(pivot);
        }
        rs += nums[pivot];
      }
      return p.back();
    }
};
  
