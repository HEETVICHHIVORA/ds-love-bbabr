#include<iostream> 
#include<algorithm>

using namespace std;

int main() {
    int arr[] = {1, 3, 5, 3, 4};
    int n = 5;
// the negative marking method 
    for (int i = 0; i < n; i++) {
        int index = abs(arr[i]) - 1;
        if (arr[index] > 0) {
            arr[index] *= -1; 
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
    for (int i = 0; i < n; i++) {
        if(arr[i]>0){
            cout<<i+1<<" ";
        }
    }
     //
     for(int i=0;i<n;i++){
        if(arr[i]!=i+1){
            swap(arr[i],arr[])
        }
     }
    
    
    return 0;
}
