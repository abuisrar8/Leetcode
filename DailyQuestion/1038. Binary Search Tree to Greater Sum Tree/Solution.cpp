/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   
    TreeNode* bstToGst(TreeNode* root) {
        int sum =0;
        btog(root,sum);
        return root;   
    }
    void btog(TreeNode* root,int &sum)
    {
        if(root == nullptr)     return;
        btog(root->right,sum);
        sum+=root->val;
        root->val = sum;
        btog(root->left,sum);
    }

};
import os
import zipfile

def extract_zip_files_in_folders(root_dir):
    for dirpath, dirnames, filenames in os.walk(root_dir):
        for filename in filenames:
            if filename.endswith(".zip"):
                zip_file_path = os.path.join(dirpath, filename)
                extract_dir = os.path.splitext(zip_file_path)[0]

                # Create a directory where the zip file will be extracted
                if not os.path.exists(extract_dir):
                    os.makedirs(extract_dir)

                # Extract the zip file
                with zipfile.ZipFile(zip_file_path, 'r') as zip_ref:
                    zip_ref.extractall(extract_dir)
                
                print(f"Extracted: {filename} to {extract_dir}")

if __name__ == "__main__":
    root_dir = input("Enter the root directory where the folders are located: ")
    extract_zip_files_in_folders(root_dir)
    print("All zip files extracted successfully.")
