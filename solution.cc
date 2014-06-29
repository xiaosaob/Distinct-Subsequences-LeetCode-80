// Given a string S and a string T, count the number of distinct subsequences of T in S.

// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

// Here is an example:
// S = "rabbbit", T = "rabbit"

// Return 3.
    
class Solution {
public:
    int numDistinct(string S, string T) {
        int n1 = S.size();
        int n2 = T.size();
        if(n1 == 0 || n2 == 0) return 0;
        vector<vector<int> > table(n1+1, vector<int>(n2+1, 0));
        table[0][0] = 1;
        
        for(int i = 1; i <= n1; ++i) {
            table[i][0] = 1;
            for(int j = 1; j <= min(i,n2); ++j) {
                if(T[j-1] == S[i-1]) table[i][j] = table[i-1][j-1]+table[i-1][j];
                else table[i][j] = table[i-1][j];
            }
        }
        return table[n1][n2];
    }
};
