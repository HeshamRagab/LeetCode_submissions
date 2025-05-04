class Solution {
public:
    vector<int> id[300];
    int appendCharacters(string s, string t) {
        int i = 0, j = 0;
        while(i < s.size() and j < t.size())
        {
            if(s[i] == t[j])
            {
                j++;
            }
            i++;
        }
        return (int)t.size() - j;
    }
};