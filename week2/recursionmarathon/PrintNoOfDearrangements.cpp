#include<iostream>

using namespace std; 
int solve(int n){
    if(n==1) return 0;
    if(n==2) return 1;
    return (n-1)*(solve(n-2)+solve(n-1));
}
int main (){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n ; 
    cin>>n ;
    cout<<solve(n)<<endl;
    return 0 ;
}