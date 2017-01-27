#include<bits stdc++.h="">

using namespace std;

int lis(int a[],int n)

{

int dp[n];int i,j;

for (i = 0; i < n; i++ )

dp[i] = 1;

for(i=1;i<n;i++) {="" for(j="0;j&lt;i;j++)" {="" if(a[i]="">a[j])

dp[i]=max(dp[i],dp[j]+1);

}

}return dp[n-1];

}

int main()

{

int arr[] = { 10, 22, 9, 33, 21, 50, 55, 60 };

int n = sizeof(arr)/sizeof(arr[0]);

printf("Length of lis is %d\n", lis( arr, n ) );

return 0;

}