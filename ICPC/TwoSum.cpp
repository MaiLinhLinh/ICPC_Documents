#include <bits/stdc++.h>
using namespace std;
#ifdef MaiLinh
#include <debug.h>
#else
#define debug(...) 12
#endif
#define ll long long
#define mod int(1e9 + 7)
#define nmax int(1e6 + 7)

vector<int> twoSum(vector<int>& nums, int target)
{
    map<int, int> idx;

    for (int i = 0; i < nums.size(); i++) {
        if (idx.count(target - nums[i])) {
            return { idx[target - nums[i]], i };
        }
        idx[nums[i]] = i;
    }
    return {};
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<int> ans = twoSum(nums, target);
    cout << ans[0] << " " << ans[1] << "\n";

    return 0;
}
