class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        int i = s.length()-1;
        //skip spaces at the end
        while(i>=0 && s[i] == ' '){
            i--;
        }
        //count characters of the last word
        while (i>=0 && s[i] != ' ' ){
            count++;
            i--;
        }
        return count;
    }
};