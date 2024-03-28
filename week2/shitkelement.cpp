
#include<bits/stdc++.h>

using namespace std ;
int main (){
    int arr[]={5,4,6,2,1};
    int k = 2 ;
    vector<int> temp ;
    for(int i=5-k;i<5;i++){
        temp.push_back(arr[i]);
    }
    for(int i=0;i<k;i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
    for(int i=5-1;i>1;i--){
        arr[i]=arr[i-2];
    }
    int it = 0 ;
    for(int i=k-1;i>=0;i--){
         arr[i]=temp[it];
         it++;
    }
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0 ;
}