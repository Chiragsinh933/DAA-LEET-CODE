class NumArray {
public:
    vector<int> nums;
    vector<int> prefix;

    NumArray(vector<int>& arr) {
        nums = arr;

        prefix.resize(nums.size());

        if (nums.size() == 0)
            return;

        prefix[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
    }

    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;

        for (int i = index; i < nums.size(); i++) {
            prefix[i] += diff;
        }
    }

    int sumRange(int left, int right) {
        if (left == 0)
            return prefix[right];

        return prefix[right] - prefix[left - 1];
    }
};