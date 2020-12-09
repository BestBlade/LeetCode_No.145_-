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

/*	迭代法2
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：8.5 MB, 在所有 C++ 提交中击败了44.40%的用户
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

vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    vector<int> res;
    if (!root) {
        return res;
    }
    s.emplace(root);

    while (!s.empty()) {
        TreeNode* node = s.top();
        s.pop();
        res.emplace_back(node->val);
        if (node->left) {
            s.emplace(node->left);
        }
        if (node->right) {
            s.emplace(node->right);
        }
    }
    //由于前序遍历为根左右，后序遍历为左右根
    //因此前序遍历先判断右节点再判断左节点依次入栈，保证出栈顺序为先左后右
    //因此后序遍历可以看作是反向的根右左遍历
    //先判断左节点再判断右节点，使得出栈顺序先右后左
    //最后再将结果翻转即可
    reverse(res.begin(), res.end());
    return res;
}