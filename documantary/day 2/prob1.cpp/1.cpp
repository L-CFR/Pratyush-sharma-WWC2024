/*Q1: Convert Sorted Array to Binary Search Tree

Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.*/
#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }
    
private:
    TreeNode* buildBST(const vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr; // Base case: no elements to form a tree
        }
        
        int mid = left + (right - left) / 2; // Find the middle index
        TreeNode* root = new TreeNode(nums[mid]); // Create a node with the middle element
        
        // Recursively build the left and right subtrees
        root->left = buildBST(nums, left, mid - 1); // Left subarray
        root->right = buildBST(nums, mid + 1, right); // Right subarray
        
        return root; // Return the root of the subtree
    }
};

// Helper function to print the tree (in-order traversal)
void printInOrder(TreeNode* root) {
    if (root) {
        printInOrder(root->left);
        cout << root->val << " ";
        printInOrder(root->right);
    }
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    Solution solution;
    TreeNode* root = solution.sortedArrayToBST(nums);
    
    cout << "In-order traversal of the BST: ";
    printInOrder(root); // Print the tree in-order to verify the structure
    cout << endl;

    return 0;
}