vector<int>ans;
  void dfs(vector<int> adj[],int u,map<int,int>&vis){
      if(vis[u]==1)return ;
      vis[u]=1;
      ans.push_back(u);
      for(auto & v:adj[u]){
          if(vis[v]==0){
              dfs(adj,v,vis);
          }
      }
      
  }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        ans.clear();
        map<int,int>visited;
        dfs(adj,0,visited);
        return ans;
        
    }