  bool bfs(vector<int> adj[],int u,vector<int>&vis,int parent){
       queue<pair<int,int>>q;//u , parent
       q.push({u,parent});
       while(!q.empty()){
           auto ele=q.front();q.pop();
           
           int x=ele.first;
           parent=ele.second;
           vis[x]=1;
           for(auto v:adj[x]){
               if(v==parent)continue;
               if(vis[v]==1){
                   return 1;
               }
               q.push({v,x});
               
           }
           
       }
       return 0;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V+1,0);
        for(int i=0;i<V;i++)
        {
            if( vis[i]==0 && bfs(adj,i,vis,-1)){
                return 1;
            }
        }
        return 0;
    }