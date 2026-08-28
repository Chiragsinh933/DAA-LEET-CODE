class Solution {
public:
    string largestNumber(vector<int>& nums) {

        vector<string> arr;

        for (int i = 0; i < nums.size(); i++) {
            arr.push_back(to_string(nums[i]));
        }

        for (int i = 0; i < arr.size(); i++) {

            for (int j = i + 1; j < arr.size(); j++) {

                string first = arr[i] + arr[j];
                string second = arr[j] + arr[i];

                if (second > first) {
                    swap(arr[i], arr[j]);
                }
            }
        }

        string answer = "";

        for (int i = 0; i < arr.size(); i++) {
            answer += arr[i];
        }

        if (answer[0] == '0') {
            return "0";
        }

        return answer;
    }
};