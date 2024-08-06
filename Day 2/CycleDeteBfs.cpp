	bool IsCycle(int V, vector<int> adj[]) 
	{
	    // code here
		// This algo is called khan's algo
	    vector<int>Indegree(V+1,0);
	    queue<int>q;
	    for (int i = 0; i < V; i++) {
            for (int j : adj[i]) {
                Indegree[j]++;
            }
        }
	    for(int i=0;i<V;i++){
	        if(Indegree[i]==0){
	            q.push(i);
	        }
	    }
	    vector<int>ans;
	    while(!q.empty()){
	        auto u=q.front();q.pop();
	        ans.push_back(u);
	        for(auto v:adj[u]){
	            Indegree[v]--;
	            if(Indegree[v]==0){
	                q.push(v);
	            }
	        }
	    }
	    return ans.size()==V;
	}