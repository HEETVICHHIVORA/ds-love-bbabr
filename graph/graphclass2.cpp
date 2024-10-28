#include <bits/stdc++.h>
using namespace std ;
template<typename T>
class Graph {
    public :
    unordered_map<int,list<int>> adlist ;
    void addedge(int u ,int v,bool dir){
        //undir=0; 
        //dir=1;
        if(dir==1){
            adlist[u].push_back(v);
        }
        else{
            adlist[v].push_back(u);
            adlist[u].push_back(v);
        }
    }
    void plist() {
        for(auto i:adlist){
            cout<<i.first<<"->{";
             for(auto neighbours : i.second){
                cout<<neighbours<<", ";
             }
             
             cout<<endl;
        }
    }
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
    bool checkcycle(T src){
        queue<int> q;
        q.push(src);
        unordered_map<int,int> parent;
        unordered_map<int,int> visited;
        visited[src]++;
        parent[src]=-1;
        while(!q.empty()){
            T frontnode = q.front();
            q.pop();
            for(auto  neighbour:adlist[frontnode]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour]++;
                    parent[neighbour]=frontnode;
                }
                else if(visited[neighbour]&& neighbour!=parent[frontnode]){
                    return true;

                }
            }
        }
        return false;
    }
};
int main (){
     Graph<int> g ;
     g.addedge(0,1,0); 
     g.addedge(1,2,0);
     g.addedge(1,3,0);
     g.addedge(2,4,0);
     g.addedge(3,4,0);
     g.addedge(2,5,0);  
     unordered_map<char,bool> visited;
    
      bool answer = g.checkcycle(0);
      if(answer){
        cout<<"yes"<<endl;
      }
      else{
        cout<<"no"<<endl;
      }

    // g.plist();
    // homework time and sapce complexity of adj list creation ;
     
    return 0 ;
}