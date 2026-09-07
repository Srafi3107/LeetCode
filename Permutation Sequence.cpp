class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        
        for (int i = 1; i <= n; i++)
            nums.push_back(i);

        // Convert k to 0-based
        k--;

        string ans = "";

        for (int i = n - 1; i >= 0; i--) {
            int fact = 1;

            for (int j = 1; j <= i; j++)
                fact *= j;

            int index = k / fact;
            k %= fact;

            ans += to_string(nums[index]);
            nums.erase(nums.begin() + index);
        }

        return ans;
    }
};
