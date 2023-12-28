#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Info{
    public:
    int data ;
    int row ;
    int col;
    Info(int data,int row, int col ){
        this ->data = data ;
        this ->row = row;
        this ->col=col ;

    }
};
class compare{
    public:
bool operator()(Info* a, Info* b) {
return a->data > b->data;

}
};
void mergeksortedarrays(int arr[][4],int n,int k,vector<int>&ans){
       priority_queue<Info*,vector<Info*>,compare>q;
       for (int row = 0; row < k; row++) {
        Info* temp = new Info(arr[row][0], row, 0);
        q.push(temp);
    }
       while(!(q.empty())){
          Info * a = q.top();
          q.pop();
          ans.push_back(a->data);
          if(a->col+1<n){
            Info* newtemp =new Info(arr[a->row][a->col+1],a->row,a->col+1);
            q.push(newtemp);
          }

       }
}
int main (){
    int arr [3][4]={
        {2,3,4,5},
        {-4,-3,-2,-1},
        {10,11,12,13}
    };
    int n=4;
    int k=3;
    vector<int>ans;
   
    mergeksortedarrays(arr,n,k,ans);
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}