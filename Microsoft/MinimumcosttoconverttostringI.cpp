class Solution {
public:

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        vector<vector<long long>> grid(26,vector<long long> (26,LLONG_MAX));
        for(int i = 0;i<original.size();i++){
            grid[original[i]-'a'][changed[i]-'a'] = min(grid[original[i] - 'a'][changed[i] - 'a'], (long long)cost[i]);
        }
        int n = 26;
        for(int via = 0;via<n;via++){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    if(grid[i][via] == LLONG_MAX || grid[via][j] == LLONG_MAX) continue;
                    grid[i][j] = min(grid[i][j],grid[i][via]+grid[via][j]);
                }
            }
        }
        long long ans = 0;
        for(int i = 0;i<source.size();i++){
            if(source[i] - 'a' == target[i]-'a') continue;
            if(grid[source[i]-'a'][target[i]-'a'] >= LLONG_MAX) return -1;
            
            ans+=grid[source[i]-'a'][target[i]-'a'];
        }
        return ans;

        
        

    }
};
