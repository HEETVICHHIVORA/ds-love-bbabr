#include<bits/stdc++.h>
using namespace std; 
void merge(vector<int>&a,s,e){
   // int mid = (s+e)/2;
    vector<int>left;
    vector<int>right;
    for(int i=s;i<mid;i++) left.push_back(a[i]);
    for(int i=mid;i<=e;i++) right.push_back(a[i]);
    

}
void mergesort(vector<int>a,int s,int e){
    int n = sizeof(a)/sizeof(a[0]);
    int mid = (s+e)/2;
    mergesort(a,s,mid);
    mergesort(a,mid+1,e);
    merge(a,s,e);
}

int main (){
    vector<int>a= {5,4,3,2,1};
    mergesort(a,0,4);
    for(auto it:a) cout<<it<<" ";
    return 0 ;
}