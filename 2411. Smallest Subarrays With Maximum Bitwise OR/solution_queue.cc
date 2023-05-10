#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <functional>
#include <climits>
#include <set>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

/*		
ios_base::sync_with_stdio(0); 
cin.tie(NULL);
*/

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        // Maximum OR means, each available digit has at least 1 number to contribute
        // So, for each digit, pre-calculate the numbers that can contribute to it.
    	//
        // A minimized subarray from i can be determined by the MAX of indices of the numbers
    	// 
        // Previously, we find the max index at each digit using binary search for each nums[i];
        // However, since we don't care about the index < j in digtis and we are visiting digits every time,
        // 	let's pop out the non used index every time of visits.
        // 
        // Time complexity: O(N*32)
    	vector<queue<int>> digtis(32);
        for(int j = 0; j < nums.size(); ++j) {
     	   for(int i = 0; i <= 31; ++i) {
     	   		if(nums[j] & (1 << i))
     	   			digtis[i].push(j);
     	   }
	    }

	    vector<int> ans(nums.size(), 1);
	    for(int j = 0; j < ans.size(); ++j) {
	    	// the max index
	    	int ind = j;
	    	for(int i = 0; i <= 31; ++i) {
	    		while(!digtis[i].empty() && digtis[i].front() < j)
	    			digtis[i].pop();
	    		if(!digtis[i].empty())
	    			ind = max(ind, digtis[i].front());
	    	}
	    	ans[j] = ind - j + 1;
	    }
	    return ans;
    }
};