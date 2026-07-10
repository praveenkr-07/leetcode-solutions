class Solution
{
public:
  vector<int> plusOne(vector<int> &digits)
  {
    if (digits.size() == 1 && digits[digits.size() - 1] == 9)
      return {1, 0};
    if (digits[digits.size() - 1] != 9)
    {
      digits[digits.size() - 1] += 1;
      return digits;
    }
    else
    {
      int count9 = 0;
      while (digits.size() > 0 && digits.back() == 9)
      {
        count9++;
        digits.pop_back();
      }
      if (digits.size() > 0)
      {
        digits.back() += 1;
        for (int i = 1; i <= count9; i++)
        {
          digits.push_back(0);
        }
      }
      if (digits.size() == 0)
      {
        digits.push_back(1);
        for (int i = 1; i <= count9; i++)
        {
          digits.push_back(0);
        }
      }
      return digits;
    }
  }
};