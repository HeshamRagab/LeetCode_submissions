class Solution {
public:
    int firstBadVersion(int n) {
    	long long l = 1, r = n;
    	int ans = 1;
    	while(l <= r)
    	{
    		long long mid = (l + r) / 2;
    		//cerr << mid << "\t" << nums[mid] << endl;
    		if(isBadVersion((int)mid))
    		{
    			ans = (int)mid;
    			r = mid - 1;
    		}
    		else
    		{
    			l = mid + 1;
    		}
    	} 
    	return ans;
    }
};