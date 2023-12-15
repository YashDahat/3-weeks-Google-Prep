//Rearranging the Order of the elements
//arranging the order of the elements based on the -ve and +ve value
//without hindering the actual order of the elements, arrange them in alternative fassion
//Problem Link: https://www.codingninjas.com/studio/problems/alternate-numbers_6783445
vector<int> alternateNumbers(vector<int>&a) {
    int n = a.size();
    vector<int> ans(n, 0);
    int neg = 0, pos = 0;
    for(int i=0; i<n; i++){
        if(a[i] > 0){
            ans[2*pos] = a[i];
            pos++;
        }else{
            ans[2*neg+1] = a[i];
            neg++;
        }
    }
    return ans;
}