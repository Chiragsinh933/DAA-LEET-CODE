class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums,
                                       vector<vector<int>>& queries) {

        vector<int> ans;

        for(auto q : queries) {

            int k = q[0];
            int trim = q[1];

            vector<pair<string, int>> temp;

            for(int i = 0; i < nums.size(); i++) {

                string s = nums[i];

                string trimmed = s.substr(s.size() - trim);

                temp.push_back({trimmed, i});
            }

            sort(temp.begin(), temp.end());

            ans.push_back(temp[k - 1].second);
        }

        return ans;
    }
};