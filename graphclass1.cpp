//adjacency list .. 
#include <bits/stdc++.h>
using namespace std ;
template<typename T>

// class Graph {
//     public :
//     unordered_map<int,list<int>> adlist ;
//     void addedge(int u ,int v,bool dir){
//         //undir=0; 
//         //dir=1;
//         if(dir==1){
//             adlist[u].push_back(v);
//         }
//         else{
//             adlist[v].push_back(u);
//             adlist[u].push_back(v);
//         }
//     }
//     void plist() {
//         for(auto i:adlist){
//             cout<<i.first<<"->{";
//              for(auto neighbours : i.second){
//                 cout<<neighbours<<", ";
//              }
             
//              cout<<endl;
//         }
//     }
// };
class Graph {
    public :
    unordered_map<int,list<pair<int,int>>>adlist ;
    void addedge(int u ,int v,int wt,bool dir){
        //undir=0; 
        //dir=1;
        if(dir==1){
            adlist[u].push_back({v,wt});
        }
        else{
            adlist[v].push_back({u,wt});
            adlist[u].push_back({v,wt}); 
        }
    }
    void plist() {
        for(auto i:adlist){
            cout<<i.first<<"{";
             for(pair<int,int>p : i.second){
                cout<<"{"<<p.first<<", "<<p.second<<"},";
             }
             
             cout<<endl;
        }
    }
    //traversal bfs 
    void bfs(T src,unordered_map<T,bool> &visit){
        //tc -> relate karegi ad list ke sath = o(v+e)-. worst case n2


         queue<T>q;
         q.push(src);
         visit[src]=true;
         while(!q.empty()){
            T frontnode = q.front();
            cout<< frontnode <<" ";
            q.pop();
            for(auto it : adlist[frontnode]){
                T neighbour = it.first ;
                if(!visit[neighbour]){
                    q.push(neighbour);
                    visit[neighbour]=true ;
                }
            }
        }
         

    }
    void dfs(T src,unordered_map<T,bool>&visit){
        visit[src]=true ;
        cout<<src<<" ";
        for(auto it:adlist[src ]){
            T ndata = it.first;
            if(!visit[ndata]){
                dfs(ndata,visit );
            }
        }

        
    }
};



int main (){
     Graph<char> g ;
     g.addedge('a','b',5 ,0); 
     g.addedge('c','d',10,0);
    // g.addedge('b','c',20,0);
    // g.addedge('c','d',50,0);
     g.addedge('e','f',50,0);
    // g.addedge('d','e',50,0); 
     unordered_map<char,bool> visited;
    //  for(char node='a';node<='f';node++){
    //     if(!visited[node]){
    //         g.bfs(node,visited);
    //         cout<<endl;
    //     }
    //  }
    /// HW : find no of disconnected nodes.
    // number of islands
    //rotten tomatoes / oranges.
      for(char node='a';node<='f';node++){
        if(!visited[node]){
            g.dfs(node,visited);
            cout<<endl;
        }
     }
    
    // g.plist();
    // homework time and sapce complexity of adj list creation ;
     
    return 0 ;
}
