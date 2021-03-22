int SequentialSearch(int *a,const int n, const int x)
{
    int i;
    for(i = 0;i<n;i++) //循环n次查找num
    {
        if(a[i]==x)
            return i;
    }
    if(i==n) return -1;

}
int find(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
  }