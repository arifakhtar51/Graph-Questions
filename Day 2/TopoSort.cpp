void dfs(vector<int>adj[],int u,stack<int>& ans,vector<int>&vis){
	    vis[u]=1;
	    for(auto v:adj[u]){
	        if(vis[v]==0){
	            dfs(adj,v,ans,vis);
	        }
	    }
	    ans.push(u);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>vis(V+1,0);
	    stack<int>ans;
	    for(int i=0;i<V;i++){
	        if(vis[i]==0){
	            dfs(adj,i,ans,vis);
	        }
	    }
	    vector<int>res;
	    while(!ans.empty()){
	        res.push_back(ans.top());ans.pop();
	    }
	    return res;
	}