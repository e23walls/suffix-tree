#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include <string>
#include <deque>
#include "Token.h"
#include <vector>

typedef enum {
    TIME  = 0,
    CLASS = 1,
    EVENT = 2,
    PID   = 3,
    PNAME = 4,
    NodeTypeSize
} NodeType;

class TreeNode {
public:
    TreeNode();
    TreeNode(size_t);
    ~TreeNode();

    void insert(std::deque<size_t> s);
    void print(int indent);

private:
//    NodeType type;
//    std::vector<std::string> data;
    size_t data;
    std::vector<TreeNode *> children;
    void insert(std::deque<size_t> s, int left, int right); // Insert between indices
};

#endif /* Tree_hpp */
