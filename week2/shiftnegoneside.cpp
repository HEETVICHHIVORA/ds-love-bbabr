int j =0 ;
for(int i=0;i<n;i++){
        if (arr[i]<0){
            swap (arr[i],arr[j]);
            j++;
        }

}
for(int i=0;i<n;i++){
    cout<<arr[i]<<" "<<endl;
}