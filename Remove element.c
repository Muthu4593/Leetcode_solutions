int removeElement(int* nums, int numsSize, int val) {
    int k = 0; // Pointer to track the position of valid elements

    for (int i = 0; i < numsSize; i++) {
        // If the current element is NOT equal to val
        if (nums[i] != val) {
            nums[k] = nums[i]; // Move it to the front of the array
            k++;               // Increment the count of valid elements
        }
    }

    return k; // Return the count of elements not equal to val
}
