bool dfs(vector<int> adj[],int u,vector<int>&vis,int parent){
        vis[u]=1;
        for(auto &v:adj[u]){
            if(parent==v)continue;
            // mean jha se aae ho wha nhi jana like 1-0 so 1 
            // se 0 chle gae so 
            // 0 se one nhi ana nhi to cycle me fas jaenge
            if(vis[v]==1 && parent !=v)return 1;
            
            if(dfs(adj,v,vis,u))return 1;
        }
        return 0;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V+1,0);
        for(int i=0;i<V;i++)
        {
            if( vis[i]==0 && dfs(adj,i,vis,-1)){
                return 1;
            }
        }
        return 0;
    }