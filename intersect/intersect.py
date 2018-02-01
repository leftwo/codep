class Solution:
    def intersect(self, nums1, nums2):
        """ Given two arrays, find the elements both have in common.
        Each element in result should appear as many times as in both arrays.
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        res = []
        nums1.sort()
        nums2.sort()
        l1 = len(nums1)
        l2 = len(nums2)
        i = 0
        j = 0
        while i < l1 and j < l2:
            if nums1[i] == nums2[j]:
                res.append(nums1[i])
                i = i + 1
                j = j + 1
            elif nums1[i] < nums2[j]:
                i = i + 1
            else:
                j = j + 1
                
        return res

if __name__ == '__main__':
    n1 = [1, 2, 2, 5, 9, 12]
    n2 = [2, 2, 3, 4, 5, 6, 7]
    sol = Solution()
    res = sol.intersect(n1, n2)

    print(res)

