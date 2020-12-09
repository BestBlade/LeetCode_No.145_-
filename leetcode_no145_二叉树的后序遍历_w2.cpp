/* ------------------------------------------------------------------|
给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [3,2,1]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	迭代法
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：8.6 MB, 在所有 C++ 提交中击败了22.65%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void postorderStack(TreeNode* node, stack<TreeNode*>& s) {
    while (node) {
        s.emplace(node);
        node = node->left;
    }
    return;
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode* node = root;
    //prev用于判断右分支是否探寻过
    TreeNode* prev = nullptr;

    while (!s.empty() || node != nullptr) {
        postorderStack(node, s);
        node = s.top();
        s.pop();
        
        if (node->right == nullptr || node->right == prev) {
            res.emplace_back(node->val);
            prev = node;
            node = nullptr;
        }
        else {
            s.emplace(node);
            node = node->right;
        }

    }
    return res;
}