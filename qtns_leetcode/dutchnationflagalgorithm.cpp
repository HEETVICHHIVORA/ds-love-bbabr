#include<iostream> 
using namespace std ;
int main(){
       int arr[]={1,2,-3,4,8,9,-10,-34,98,-100};
       int i =0 ;
       int j =  10-1;
       while(i<j){
           if(arr[i]<0){
            i++;
           }
           else if(arr[j]>0){
            j--;
           }
           else{
            swap(arr[i],arr[j]);
           }

       }
       for(auto it:arr){
        cout<<it<<" ";
       }
       return 0 ;
}