#include<iostream>
using namespace std;
void getithbit(int n , int i){
       int  mask = (1<<i);
       int ans =  mask & n;
       if(ans ==0 ){
        cout<<"bit is 0"<<endl;
       }
       else{
        cout<<"bit is 1"<<endl;
       }
}
void setithbit(int n ,int i){
      int mask = 1<<i;
       n = n | mask;
      cout<<n;
}
void clearithbit(int &n ,int i){
      int mask = 1<<i;
      int mask2 = ~(1<<i);

      // n = n  ^ mask;
      n = n  & mask2; 
    //  cout<<n;
}
void updateithtbit(int n ,int i,int target){
    clearithbit(n,i);
    int mask = target<<i;
    n=n|mask;
    cout<<"updated->"<<n;
}
void clearlastibits(int n ,int i){
    int mask = (-1 <<i);
    n = n & mask;
    cout<<"updated->"<<n<<endl;
}
int main (){
    int n = 15 ;
    int i=2;
    //getithbit(n,i);
    int target = 0;
    //updateithtbit(n,i,target);
    clearlastibits(n,i);
    
    //136 -> single number 
    // power of 2 


    return 0 ;
}