  //from the source vertex S.
    #define ll  pair<int,int>
    // #define lll long long 
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>ans(V,INT_MAX);
        priority_queue<ll , vector<ll>,greater<ll>>pq;
        ans[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            auto p=pq.top();pq.pop();
            int dis=p.first;
            int node=p.second;
            
            for(auto v:adj[node]){
                int sm=v[1]+dis;
                int newNode=v[0];
                if(ans[newNode]>sm){
                    ans[newNode]=sm;
                    pq.push({sm,newNode});
                }
            }
        }
        

        return ans;
    }