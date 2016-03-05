#include "Tree.h"
#include <string>
#include <vector>

class TreeNode {
public:
    TreeNode();
    ~TreeNode();
private:
    NodeType type;
    std::vector<std::string> data;
    std::vector<TreeNode *> children;
};