# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//void _sumRootToLeaf(struct TreeNode* root, int val, int* pSum)
//{
//    if (root == NULL)
//    {
//        return;
//    }
//    val = (val << 1) + root->val;
//
//    if (root->left == NULL && root->right == NULL)
//    {
//        *pSum += val;
//    }
//
//    _sumRootToLeaf(root->left, val, pSum);
//    _sumRootToLeaf(root->right, val, pSum);
//}
//
//int sumRootToLeaf(struct TreeNode* root) {
//    int sum = 0;
//    _sumRootToLeaf(root, 0, &sum);
//    return sum;
//}
//
//
//class Solution {
//public:
//    int sumRootToLeaf(TreeNode* root, int val = 0) {
//        if (root == nullptr)
//            return 0;
//
//        val = (val << 1) + root->val;
//
//        return root->left == root->right ? val
//            : sumRootToLeaf(root->left, val) + sumRootToLeaf(root->right, val);
//    }
//};

 /*struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    
};


 int findTilt(struct TreeNode* root) {
     if (root == NULL)
     {
         return 0;
     }

     int left = findTilt(root->left);
     int right = findTilt(root->right);

     if (root->left)
     {
         left += root->left->val;
     }
     if (root->right)
     {
         right += root->right->val;
     }

     return fabs(left - right);
 }*/

int _findTilt(struct TreeNode* root, int* ret, int sum)
{
    if (!root)
        return 0;

    int leftsum = _findTilt(root->left, ret, sum);
    int rightsum = _findTilt(root->right, ret, sum);
    int fab = fabs(leftsum - rightsum);
    *ret += fab;
    sum = root->val + leftsum + rightsum;
    return sum;
}

int findTilt(struct TreeNode* root) {
    int sum = 0;
    _findTilt(root, &sum, 0);
    return sum;
}

int getSum(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    return getSum(root->left) + getSum(root->right) + root->val;
}
int findTilt(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    return findTilt(root->left) + findTilt(root->right) + abs(getSum(root->left) -
        getSum(root->right));
}