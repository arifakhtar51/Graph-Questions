 bool dfs(vector<int>adj[],int u,int parent,vector<int>&vis,vector<int>&rec){
        vis[u]=1;
        rec[u]=1;
        for(auto v:adj[u]){
            // cuurent recursion me visited hai ki nhi 
            // baki sab same parent wala concept
            if( vis[v]==0 && dfs(adj,v,u,vis,rec) )
                    return 1;
            else if(rec[v]==1)return 1;
        }
        rec[u]=0;
        return 0;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V+1,0);
        vector<int>inrecu(V+1,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0 && dfs(adj,i,-1,vis,inrecu)){
                return 1;
            }
        }
        return 0;
        // return 1;
    }