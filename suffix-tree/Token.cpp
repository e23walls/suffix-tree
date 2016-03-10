#include "Token.h"
#include <cassert>

template <class Type> Token<Type>::Token(Type d) {
    this->data = d;
}


template <class Type> Type Token<Type>::getData() {
    return this->data;
}

