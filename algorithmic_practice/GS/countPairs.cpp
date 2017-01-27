#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int getPairsCount(vector<int> arr, int n, int sum)
{
  unordered_map<int,int> frequencies;
  int count = 0;
  for(int i = 0; i < n; i++)
  {
      if(frequencies[sum - arr[i]] != 0)
          count += frequencies[sum - arr[i]];
      frequencies[arr[i]]++;
  }
  return count;
}


int main()
{
    vector<int> arr;
    int sz, ip, tc, sum, res;
    cin>>tc;
    while (tc--) {
        cin>>sz>>sum;
        while(sz--) {
            cin>>ip;
            arr.push_back(ip);
        }
        res = getPairsCount(arr, arr.size(), sum);
        cout<<res<<endl;
        arr.resize(0);
    }
    return 0;
}