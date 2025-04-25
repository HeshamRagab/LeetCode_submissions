class Solution {
public:
    unordered_map<char, string> t;
    string gen = "";
    vector<string> letterCombinations(string digits) {
    	if(digits.size() == 0)
    	{
    		return {};
    	}
    t['2'] = "abc";
    t['3'] = "def";
    t['4'] = "ghi";
    t['5'] = "jkl";
    t['6'] = "mno";
    t['7'] = "pqrs";
    t['8'] = "tuv";
    t['9'] = "wxyz";
    vector<string> ans;
    solve(0, digits, ans);
    return ans;
    }
    void solve(int i, const string& d, vector<string>& ans){
    	if(gen.size() >= d.size())
    	{
    		//cout << gen << " ";
    		ans.push_back(gen);
    		return;
    	}
    	for(auto ch: t[d[i]])
    	{
    		gen += ch;
    		solve(i+1, d, ans);
    		gen.pop_back();
    	}
    }
};