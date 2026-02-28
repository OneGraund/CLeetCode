// relative order the same

int removeDuplicates(int* nums, int numsSize) {

	int last_val = nums[0];
	int count = 1; // since we've set the first number
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] > last_val) {
			nums[count] = nums[i];
			last_val = nums[i];
			count++;
		}
	}

	return count;
}
