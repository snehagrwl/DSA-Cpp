class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Make sure nums1 is the smaller array for binary search efficiency
        if (nums1.size() > nums2.size()) 
            return findMedianSortedArrays(nums2, nums1);

        int x = nums1.size();
        int y = nums2.size();

        int low = 0, high = x;

        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;

            // If partitionX is 0 it means nothing on left side, use -infinity for maxLeftX
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            // If partitionX is length of nums1, use +infinity for minRightX
            int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

            // Check if we have found the correct partition
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // If total length is even
                if ((x + y) % 2 == 0) {
                    return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
                } else { // Odd length
                    return (double)max(maxLeftX, maxLeftY);
                }
            }
            else if (maxLeftX > minRightY) {
                // Move towards left in nums1
                high = partitionX - 1;
            } else {
                // Move towards right in nums1
                low = partitionX + 1;
            }
        }

        // If input arrays are not sorted or something unexpected happens
        return -1;
    }
};
