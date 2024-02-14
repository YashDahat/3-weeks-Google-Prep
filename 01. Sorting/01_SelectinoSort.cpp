//Selection Sort
//Putting the element in right place
void selectionSort(vector<int> &arr){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }
}