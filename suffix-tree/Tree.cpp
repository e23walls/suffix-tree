#include "Tree.h"
#include <iostream>

TreeNode::TreeNode() {}

TreeNode::TreeNode(std::string s) {
    this->data = s;
}

TreeNode::~TreeNode() {
    for (std::vector<TreeNode *>::iterator i = this->children.begin(); i != this->children.end(); i++) {
        delete *i;
    }
    this->children.clear();
}

void TreeNode::insert(std::deque<std::string> s) {
    // Insert all suffixes:
    if (s.size()) {
        for (int i = (int)(s.size() - 1); i >= 0; i--) {
            this->insert(s, i, (int)s.size());
        }
    }
}

void TreeNode::insert(std::deque<std::string> s, int first, int last) {
    // If already in the tree, ignore it, and don't insert again.
    if (first >= last) {
        return;
    }
    std::string curr = s[first];
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
    newChild->type = (NodeType)first;
    this->children.push_back(newChild);
    newChild->insert(s, first+1, last);
}

void TreeNode::print() {
    std::cout << "\"" << this->data << "\" : " << this->type << "\n";
    for (std::vector<TreeNode *>::const_iterator ci = this->children.begin(); ci != this->children.end(); ci++) {
        std::cout << "\t";
        (*ci)->print();
    }
}
