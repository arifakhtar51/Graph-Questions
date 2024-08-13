class Solution {
public:
int cnt=1;
void dfs(int u, unordered_map<int, vector<int>>& adj, vector<int>& vis) {
    vis[u]=1;
    for(auto v:adj[u]){
        if(vis[v]==0){
            dfs(v,adj,vis);
            cnt++;
        }
    }
}
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int> >adj;
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>vis(n+1,0);
        vector<int>v;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt=1;
                dfs(i,adj,vis);
                v.push_back(cnt);
            }
        }
        if(v.size()==1){
            return 0;
        }
        else{
            int tot=0;
            for(auto i:v)tot+=i;
            long long ans=0;
            for(int i=0;i<v.size();i++){
                tot-=v[i];
                ans+=(long long )v[i]*tot;
            }
            return ans;
        }

    }
};