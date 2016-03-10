#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "Token.h"

typedef enum {
    TIME = 0, CLASS, EVENT, PID, PNAME, NodeTypeSize
} NodeType;

class TreeNode {
public:
    TreeNode();
    TreeNode(std::string s);
    ~TreeNode();

    void insert(std::vector<std::string> s);
    void print();

private:
    NodeType type;
//    std::vector<std::string> data;
    std::string data;
    std::vector<TreeNode *> children;
    void insert(std::vector<std::string> s, int left, int right); // Insert between indices
};

#endif /* Tree_hpp */
