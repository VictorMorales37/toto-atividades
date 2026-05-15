int mySqrt(int x) {

    int left = 0;
    int right = x;
    int ans = 0;
    long long squared;
    
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        squared = (long long) mid * mid;
        if (squared == x) return mid;
        if (squared < x) 
        {
            ans = mid;
            left = mid + 1;
        }
        if (squared > x) 
        {
            right = mid - 1;
        }
    }

    return ans;
}