class Solution {
public:
    int maximumSwap(int num) {
        
        string s = to_string(num);

        for (int i = 0; i < s.length(); i++) {
            
            int maxIndex = i;

            // Find the largest digit after i
            for (int j = i + 1; j < s.length(); j++) {
                if (s[j] >= s[maxIndex]) {
                    maxIndex = j;
                }
            }

            // If a bigger digit is found, swap
            if (s[maxIndex] > s[i]) {
                swap(s[i], s[maxIndex]);
                break;
            }
        }

        return stoi(s);
    }
};