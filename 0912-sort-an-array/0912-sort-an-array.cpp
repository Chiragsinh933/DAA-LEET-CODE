class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high) {
        int l = mid - low + 1;
        int r = high - mid;

        vector<int> left(l), right(r);

        for (int i = 0; i < l; i++)
            left[i] = nums[low + i];

        for (int i = 0; i < r; i++)
            right[i] = nums[mid + 1 + i];

        int i = 0, j = 0, k = low;

        while (i < l && j < r) {
            if (left[i] <= right[j]) {
                nums[k++] = left[i++];
            } else {
                nums[k++] = right[j++];
            }
        }

        while (i < l)
            nums[k++] = left[i++];

        while (j < r)
            nums[k++] = right[j++];
    }

    void mergeSort(vector<int>& nums, int low, int high) {
        if (low < high) {
            int mid = low + (high - low) / 2;

            mergeSort(nums, low, mid);
            mergeSort(nums, mid + 1, high);

            merge(nums, low, mid, high);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};