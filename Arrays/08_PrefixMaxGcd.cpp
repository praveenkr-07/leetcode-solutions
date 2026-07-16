class Solution
{
  vector<int> prefixMax(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> arr(n);
    arr[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
      arr[i] = max(arr[i - 1], nums[i]);
    }
    return arr;
  }

public:
  long long gcdSum(vector<int> &nums)
  {
    vector<int> prefixMx = prefixMax(nums);
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      prefixMx[i] = __gcd(prefixMx[i], nums[i]);
    }
    sort(prefixMx.begin(), prefixMx.end());
    long long sum = 0;
    int i = 0;
    int j = nums.size() - 1;
    while (i < j)
    {
      sum += 0LL + __gcd(prefixMx[i], prefixMx[j]);
      i++;
      j--;
    }
    return sum;
  }
};