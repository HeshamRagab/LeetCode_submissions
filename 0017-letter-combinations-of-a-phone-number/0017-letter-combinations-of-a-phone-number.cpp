class Solution {
public:
    vector<string> combinations;
    string combination = "";
    string t[3] = {"pqrs", "tuv", "wxyz"};
    void solve(int i, const string& digits){
        if(i >= digits.size())
        {
            if(combination.size())
                combinations.emplace_back(combination);
            return;
        }
        int d = digits[i] - '0';
        d -= 1;
        d *= 3;
        //debug(i, d);
        if(digits[i] > '6')
        {
            for(auto ch: t[digits[i] - '7'])
            {
                combination += ch;
                solve(i + 1, digits);
                combination.pop_back();
            }
        }
        else
        {
            for(char c = 3; c > 0; c--){
                combination += ('a' + (d - c));
                solve(i + 1, digits);
                combination.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        solve(0, digits);
        return combinations;
    }
};