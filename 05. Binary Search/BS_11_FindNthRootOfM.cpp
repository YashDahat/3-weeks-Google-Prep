//Problem Link: https://www.codingninjas.com/studio/problems/nth-root-of-m_1062679

//Finding whether mid is the nth root of M
// 2 -> mid^N is greater than M
// 1 -> mid^N is equal to M
// 0 -> mid^N is less than M
int func(int mid, int n, int m){
  long long ans = 1;
  for(int i=1; i<=n; i++){
    ans = ans*mid;
    if(ans > m) return 2;
  }
  if(ans == m) return 1;
  return 0;
}

//We will apply the binary search operation to find the Nth root of M
int NthRoot(int n, int m) {
  // Write your code here.
  int low = 1, high = m;
  while(low <= high){
    int mid = (low+high)/2;
    int flag = func(mid, n, m);

    if(flag == 1) return mid;
    else if(flag == 0) low = mid+1;
    else high = mid-1;
  }
  return -1;
}