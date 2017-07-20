class NumArray {
    vector<int> num;
    int n;
    vector<int> _BIT;
    public:
    NumArray(vector<int> nums) {
        num = nums;
        n = nums.size();
        _BIT.resize(n + 1, 0);
        for (auto i = 0; i < n; i++) 
            init(i, nums[i]);
    }
    void init(int i, int val) {
        i++;
        while (i <= n) {
            _BIT[i] += val;
            i += (i & -i);
        }
    }
    void update(int i, int val) {
        int diff = val - num[i];
        num[i] = val;
        init(i, diff);
    }
    int getSum(int i) {
        int sum = 0;
        i++;
        while (i > 0) {
            sum += _BIT[i];
            i -= (i & -i);
        }
        return sum;
    }

    int sumRange(int i, int j) {
        return getSum(j) - getSum(i-1);
    }
};
