#include "Tree.h"
#include <iostream>

TreeNode::TreeNode() {}

TreeNode::TreeNode(size_t s) {
    this->data = s;
}

TreeNode::~TreeNode() {
    for (std::vector<TreeNode *>::iterator i = this->children.begin(); i != this->children.end(); i++) {
        delete *i;
    }
    this->children.clear();
}

void TreeNode::insert(std::deque<size_t> s) {
    // Insert all suffixes:
    if (s.size()) {
        for (int i = (int)(s.size() - 1); i >= 0; i--) {
            this->insert(s, i, (int)s.size());
        }
    }
}

void TreeNode::insert(std::deque<size_t> s, int first, int last) {
    // If already in the tree, ignore it, and don't insert again.
    if (first >= last) {
        return;
    }
    size_t curr = s[first];
    for (std::vector<TreeNode *>::const_iterator ci = this->children.begin(); ci != this->children.end(); ci++) {
        if ((*ci)->data == curr) {
            // Insert into this child
            (*ci)->insert(s, first+1, last);
            return;
        }
    }
    // Else, we didn't find it in the children; insert as a child here
    TreeNode * newChild = new TreeNode();
    newChild->data = s[first];
//    newChild->type = (NodeType)first;
    this->children.push_back(newChild);
    newChild->insert(s, first+1, last);
}

void TreeNode::print(int indent) {
    std::cout << "\"" << this->data << "\"" /* << this->type */ << "\n";
    if (this->children.size()) {
        for (int i = 0; i < indent; i++) {
            std::cout << "\t";
        }
        std::cout << "{\n";
        for (std::vector<TreeNode *>::const_iterator ci = this->children.begin(); ci != this->children.end(); ci++) {
            for (int i = 0; i < indent; i++) {
                std::cout << "\t";
            }
            (*ci)->print(indent+1);
        }
        for (int i = 0; i < indent; i++) {
            std::cout << "\t";
        }
        std::cout << "}\n";
    }
}
