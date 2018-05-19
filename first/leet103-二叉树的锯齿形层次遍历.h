/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //主要是使用了2个栈来回倒换
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        stack<TreeNode *> left;
        stack<TreeNode *> right;
        left.push(root);
        
        while(!left.empty() || !right.empty())
        {
            vector<int> tmp;
            while(!left.empty())
            {
                TreeNode *pNode = left.top();
                left.pop();
                if (NULL == pNode)
                {
                    continue;
                }
                tmp.push_back(pNode->val);
                right.push(pNode->left);
                right.push(pNode->right);
            }
            if (!tmp.empty())
            {
                result.push_back(tmp);
                continue;
            }
            
            while(!right.empty())
            {
                TreeNode *pNode = right.top();
                right.pop();
                if (NULL == pNode)
                {
                    continue;
                }
                tmp.push_back(pNode->val);
                left.push(pNode->right);
                left.push(pNode->left);
            }
            if (!tmp.empty())
            {
                result.push_back(tmp);
                continue;
            }
        }
        
            
        return result;
    }
};
