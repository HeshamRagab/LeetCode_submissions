class Solution {
public:

    int xr[4] = {0, 1, -1, 0};
    int yc[4] = {1, 0, 0, -1};
    bool vis[15][15];
    
    bool isValid(const int& r, const int& c, const vector<vector<char>>& board, const string& word, const int& ln)
    {
        return r >= 0 and c>= 0 and (!vis[r][c]) and  r < board.size() and c < board[r].size() and board[r][c] == word[ln];
    }
    bool solve(int r, int c,const vector<vector<char>>& board, const string& word, int ln)
    {
//        debug(r, c, board[r][c], ln, word);
        if(ln == word.size())
        {
            return true;
        }
        bool ret = false;
        for(int i = 0; i < 4; i++)
        {
            int nr = r + xr[i];
            int nc = c + yc[i];
            if(isValid(nr, nc, board, word, ln))
            {
                vis[nr][nc] = 1;
                ret |= solve(nr, nc, board, word, ln + 1);
                vis[nr][nc] = 0;
            }
        }
        
        return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {
        memset(vis, 0, sizeof vis);
        for(int r = 0; r < board.size(); r++)
        {
            for(int c = 0; c < board[r].size(); c++)
            {
                if(word[0] == board[r][c])
                {
                    vis[r][c] = 1;
                    if(solve(r, c, board, word, 1))
                        return true;
                    vis[r][c] = 0;
                }
            }
        }
        return false;
    }
};