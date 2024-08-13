class Solution {
public:
#define pll pair<int,int>
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int,vector<pll>>adj;// node -> (v,w)
        for(auto &v:times){
            adj[v[0]].push_back({v[1],v[2]});
            
        }
        priority_queue<pll,vector<pll>,greater<pll> > pq;
        vector<int>Dis(n+1,INT_MAX);
        Dis[k]=0;
        pq.push({0,k});//dis ->node
        while(!pq.empty()){
            auto tp=pq.top();pq.pop();
            int dis=tp.first;
            int node=tp.second;
            for(auto v:adj[node]){
                if(Dis[v.first]>v.second+dis){
                    Dis[v.first]=v.second+dis;
                    pq.push({v.second+dis,v.first});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(Dis[i]==INT_MAX)return -1;
        }
        int maxi=0;
        for(int i=1;i<=n;i++){
            maxi=max(Dis[i],maxi);
        }
        return maxi;
        
    }
};