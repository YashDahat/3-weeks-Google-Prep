//heavy elements will sink into the bottom
void insertionSort(vector<int> &arr){
    int n = arr.size();
    for(int i=1; i<n; i++){
        if(arr[i-1] > arr[i]){
            int j=i;
            while(j>0 && arr[j-1] > arr[j]){
                swap(arr[j-1], arr[j]);
                j--;
            }
        }
    }
}