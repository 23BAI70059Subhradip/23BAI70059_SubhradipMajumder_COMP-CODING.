class Solution {
  public:
    bool fn(vector<vector<int>> &adj, vector<bool> &vis,vector<bool> &pathVis, int i){
        if(vis[i]){
            //already vis 
            return true;
        }
        
        
        vis[i] = true; 
        pathVis[i] = true; 
        for(auto &loc: adj[i]){
            if(!vis[loc]){
               if(fn(adj, vis,pathVis, loc)) return true;
            }
            else if(pathVis[loc]) return true;  
        }
        pathVis[i] = false;
        
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V, vector<int>(0)); 
        for(auto &i : edges){
            adj[i[0]].push_back(i[1]); 
        }
        
        vector<bool> vis(V, false); 
        vector<bool> pathVis(V, false); 
        
        for(int i = 0; i< V; i++){
            if(!vis[i]){
                if(fn(adj, vis, pathVis, i)) return true; 
            }
        }
        
        // for(int i= 0; i < V; i++){
        //     cout << i << ">> "; 
        //     for(auto &j: adj){
        //         cout << j << " "; 
        //     }cout << endl;
        // }
        
        return false; 
    }
};
