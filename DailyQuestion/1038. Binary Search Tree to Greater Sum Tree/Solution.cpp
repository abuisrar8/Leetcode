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

To handle the case where you need to go one level deeper inside each folder (i.e., extract `.zip` files that are inside subfolders of the main folders), you can slightly modify the script to account for this additional depth.

The updated script will:
- Start from the root directory.
- Go one level deeper into subdirectories.
- Search for `.zip` files within those subdirectories and extract them.

### Python Script to Extract `.zip` Files One Level Inside Each Folder:

```python
import os
import zipfile

def extract_zip_files_in_subfolders(root_dir):
    for dirpath, dirnames, filenames in os.walk(root_dir):
        # Check if we are exactly one level deeper inside each main folder
        current_depth = dirpath[len(root_dir):].count(os.sep)
        
        if current_depth == 1:
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
    extract_zip_files_in_subfolders(root_dir)
    print("All zip files extracted successfully.")
```

### Key Changes:
1. **`current_depth == 1`**: This ensures that we only extract `.zip` files that are one level deep inside each main folder. We calculate the depth by comparing the current folder's path to the root directory's path.

2. **Search only in subfolders**: The script will ignore `.zip` files at the root level and instead focus on subfolders that are exactly one level deep.

### Example Directory Structure (Before Extraction):
```
C:/example/folders/
    folder1/
        subfolder1/
            file1.zip
    folder2/
        subfolder2/
            file2.zip
        subfolder3/
            another_file.zip
```

### Example Directory Structure (After Extraction):
```
C:/

