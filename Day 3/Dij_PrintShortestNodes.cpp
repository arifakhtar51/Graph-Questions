 vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        map<int,vector<pii> >adj;
        for(auto v:edges){
            adj[v[0]].push_back({v[1],v[2]});
            adj[v[1]].push_back({v[0],v[2]});
        }
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({0,1});
        vector<int>Parent(n+1,0);
        for(int i=1;i<=n;i++){
            Parent[i]=i;
        }
        vector<int>DIS(n+1,INT_MAX);
        // vis[1]=1;
        DIS[1]=0;
        while(!pq.empty()){
            auto tp=pq.top();pq.pop();
            int node=tp.second;
            int dis=tp.first;
            // ans.push_back(node);
            for(auto v:adj[node]){
                if(DIS[v.first]>v.second+dis){
                    DIS[v.first]=v.second+dis;
                    pq.push({v.second+dis,v.first});
                    Parent[v.first]=node;
                }
            }
        }
        if(DIS[n]==INT_MAX){
            return {-1};
        }
        vector<int>ans;
        int node=n;
        while(Parent[node]!=node){
            ans.push_back(node);
            node=Parent[node];
        }
        ans.push_back(1);
        ans.push_back(DIS[n]);
        
        reverse(begin(ans),end(ans));
        // for(auto i:ans)cout<<i<<" ";
        return ans;
    }