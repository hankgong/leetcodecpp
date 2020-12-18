from functools import lru_cache
from itertools import combinations
import sys

class Solution(object):
    def minimumIncompatibility(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        gsize = n//k

        @lru_cache(None)
        def dp(mask):
            if mask==(1<<n) - 1:
                return 0

            ans = sys.maxsize

            remaining = [i for i in range(n) if mask & (1<<i)==0]
            print(remaining)

            comb = list(combinations(remaining, gsize))
            print(comb)

            for c in comb:
                cur_nums = set([nums[i] for i in c])
                #check if there is any duplicate number
                if len(cur_nums) < gsize:
                    continue

                new_mask = mask
                for i in c:
                    new_mask |= (1<<i)

                ans = min(ans, dp(new_mask)+max(cur_nums)-min(cur_nums))

            return ans

        ans = dp(0) 

        return ans if ans<sys.maxsize else -1


if __name__ == '__main__':
    s = Solution()
    print(s.minimumIncompatibility([1,2,1,4], 2))