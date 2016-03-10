#ifndef Token_hpp
#define Token_hpp

#include <stdio.h>
#include "Tree.h"

template<class Type>
class Token {
public:
    Token(Type d);
    ~Token();
    Type getData();
private:
    Type data; // Must be a NodeType, int, or string.
};


#endif /* Token_hpp */
