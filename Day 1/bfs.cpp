vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        map<int,bool>vis;
        queue<int>q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            auto u=q.front();q.pop();
            ans.push_back(u);
            for(auto v:adj[u]){
                if(vis[v]==0){
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
        return ans;
    }