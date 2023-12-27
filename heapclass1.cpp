#include<iostream> 
using namespace std ;
class heap {
    public :
    int *arr ;
    int capacity;
    int size;
    heap(int capacity){
        this -> arr = new int [capacity];
        this ->size= 0;
    }
    int remove(){
        int answer = arr[1]; 
        arr[1]= arr[size];
        size--;
        int index =1;
        while(index<size){
        int leftindex = 2*index;
        int rightindex = 2*index+1;
        int lindex = index;
        if(arr[leftindex]>arr[lindex]){
            lindex = leftindex;
        }
        if(arr[rightindex]>arr[lindex]){
            lindex = rightindex;
        }
        if(index==lindex){
            break;
        }
        else{
            swap(arr[lindex],arr[index]);
            index = lindex;
        }
        }
        return answer;
    }  
    void insert(int val){
        if(size==capacity){
            cout<<"overflow"<<endl;
            return ;
        }
        size++;
        int index= size;
        arr[index]=val;
        while(index>1){
            int parentindex = index /2;
            if(arr[index]>arr[parentindex]){
                swap(arr[index],arr[parentindex]);
                index = parentindex ;
            }
            else{
                break;
            }
        }
    }
    void printheap(){
    for(int i =1;i<=size;i++){
       cout<<arr[i]<<" ";
        }
    }
   
};
void heapify( int *arr,int n, int index ){
    int leftindex= index *2;
    int rightindex  =(index *2) +1 ;
    int largestindex = index ;
    if( leftindex<=n && arr[leftindex]>arr[largestindex]){
        largestindex = leftindex ;
    }
    if( rightindex<=n && arr[rightindex]>arr[largestindex]){
        largestindex = rightindex ;
    }
    if(largestindex!=index){
        swap ( arr[largestindex],arr[index]);
        index = largestindex;
        heapify(arr,n,index);
    }

}
void buildheap(int arr[],int n ){
     for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
     }
}
void heapsort(int arr[],int size){
     while(size!=1){
        swap(arr[1],arr[size]);
        size--;
        heapify(arr,size,1);

     }
} 
int main (){
    heap h (20);
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(11);
    h.insert(6);
    // h.printheap();
    // int k = h.remove();
    // cout<<k;
    // cout<<endl;
    // h.printheap();
    int arr[]={0,20,24,2,1,0,43};
    int size = 6;
    buildheap(arr,size);
    for(int i =1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapsort(arr,size);
     for(int i =1;i<=size;i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}