double findMedianSortedArrays(int* nums1, int nums1Size,
                              int* nums2, int nums2Size) {

    // Always binary search the smaller array
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(
            nums2, nums2Size, nums1, nums1Size
        );
    }

    int left = 0;
    int right = nums1Size;

    while (left <= right) {
        int cut1 = (left + right) / 2;
        int cut2 = (nums1Size + nums2Size + 1) / 2 - cut1;

        int l1 = (cut1 == 0) ? -2147483648 : nums1[cut1 - 1];
        int r1 = (cut1 == nums1Size) ? 2147483647 : nums1[cut1];

        int l2 = (cut2 == 0) ? -2147483648 : nums2[cut2 - 1];
        int r2 = (cut2 == nums2Size) ? 2147483647 : nums2[cut2];

        if (l1 <= r2 && l2 <= r1) {

            // Even number of elements
            if ((nums1Size + nums2Size) % 2 == 0) {
                int leftMax = (l1 > l2) ? l1 : l2;
                int rightMin = (r1 < r2) ? r1 : r2;

                return (leftMax + rightMin) / 2.0;
            }

            // Odd number of elements
            return (l1 > l2) ? l1 : l2;
        }

        if (l1 > r2)
            right = cut1 - 1;
        else
            left = cut1 + 1;
    }

    return 0.0;
}
