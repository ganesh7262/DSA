#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int TotalPairs(vector<int> &nums, int x, int y)
    {
        int pairs = 0;
        int i = 0;
        int j = nums.size() - 1;
        while (i < nums.size())
        {
            if (x <= nums[i] * nums[j] && y >= nums[i] * nums[j] && i != j)
            {
                pairs++;
                if (i > j)
                    i++;
                else
                    nums[j] > nums[i] ? j-- : i++;
                continue;
            }
            if (i > j)
                i++;
            else
                nums[j] > nums[i] ? j-- : i++;
        }
        return pairs;
    }
};

int main()
{
    vector<int> a = {3, 5, 5, 2, 6};
    Solution obj;
    cout << obj.TotalPairs(a, 8, 13);

    return 0;
}