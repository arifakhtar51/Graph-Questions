void dfs(unordered_map<int,vector<int>>&adj, int u,vector<int>&vis){
      vis[u]=1;
      for(auto v:adj[u]){
          if(vis[v]==0){
              dfs(adj,v,vis);
          }
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int cnt=0;
        vector<int>vis(V+1,0);
        unordered_map<int,vector<int> >adjL;
        for(int i=0;i<V;i++){
            // int * lst[];
            vector<int>a;
            for(int j=0;j<V;j++){
                if(i!=j){
                    if(adj[i][j]==1){
                        a.push_back(j);
                    }
                }
            }
            adjL[i]=a;
        }
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                cnt++;
                dfs(adjL,i,vis);
            }
        }
        return cnt;