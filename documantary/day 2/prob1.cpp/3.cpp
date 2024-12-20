/*Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once.
The relative order of the elements should be kept the same.Then return the number of unique elements in nums*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; // Handle empty array case

        int j = 0; // Pointer for the last unique element
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[j]) { // Found a new unique element
                j++; // Move the unique pointer forward
                nums[j] = nums[i]; // Update the position with the new unique element
            }
        }
        return j + 1; // Return the count of unique elements
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};

    int uniqueCount = solution.removeDuplicates(nums);
    
    cout << "Number of unique elements: " << uniqueCount << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < uniqueCount; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}