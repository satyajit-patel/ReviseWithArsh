/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) {
            return "";
        }

        string data = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* curNode = q.front();
            q.pop();
            if(!curNode) {
                data += "#,";
            } else {
                data += to_string(curNode->val) + ',';
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }

        // cout << data << endl;
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) {
            return NULL;
        }

        stringstream ss(data);
        string word;
        getline(ss, word, ','); // get word by word
        TreeNode* root = new TreeNode(stoi(word));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* curNode = q.front();
            q.pop();

            // left
            getline(ss, word, ',');
            if(word == "#") {
                curNode->left = NULL;
            } else {
                TreeNode* newNode = new TreeNode(stoi(word));
                curNode->left = newNode;
                q.push(newNode);
            }

            // right
            getline(ss, word, ',');
            if(word == "#") {
                curNode->right = NULL;
            } else {
                TreeNode* newNode = new TreeNode(stoi(word));
                curNode->right = newNode;
                q.push(newNode);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));