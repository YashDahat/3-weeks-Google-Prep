void bubbleSort(vector<int> &arr){
    int n = arr.size(), i = n;
    while(i!=0){
        for(int j=1; j<i; j++){
            if(arr[j-1] > arr[j]){
                swap(arr[j-1], arr[j]);
            }
        }
        i--;
    }
}