//Problem Link: https://www.codingninjas.com/studio/problems/capacity-to-ship-packages-within-d-days_1229379

int daysRequired(vector<int> wts, int cap){
    int days = 1, load = 0;
    for(int i=0; i<wts.size(); i++){
        if(wts[i] + load > cap){
            days += 1;
            load = wts[i];
        }else{
            load += wts[i];
        }
    }
    return days;
}
int leastWeightCapacity(vector<int> &weights, int d)
{
    // Write your code here.
    int t_wt = 0, maxi = 0, n = weights.size();
    for(int i=0; i<n; i++){
        maxi = max(maxi, weights[i]);
        t_wt += weights[i];
    }

    int low = maxi, high = t_wt, ans = INT_MAX;
    while(low <= high){
        int mid = (low+high)/2;
        int x = daysRequired(weights, mid);
        if(x <= d){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return low;
}