#ifndef BIN_TREE_HPP
#define BIN_TREE_HPP
#include "node.hpp"
#include "utils.h"
#include <iostream>

namespace DataStructures {
template<typename T>
class BinTree{

protected:
    std::unique_ptr<Node<T>> m_root;
public:
    BinTree():m_root(nullptr){}
    void print() const { print(m_root.get()); }
    virtual void insert(T value, directions type){
        insert(value,m_root,type);
    }
    virtual void remove(std::unique_ptr<Node<T>>& node){
        if (!node) return;
        if (!node->m_left && !node->m_right) node.reset();
    }
protected:
    virtual void print(Node<T>* node) const {
        if (!node) return;

        print(node->m_left.get());
        std::cout << node->m_value << std::endl;
        print(node->m_right.get());
    }
    virtual void insert(T value, std::unique_ptr<Node<T>>& node, directions type){
        if (!node) {
            node = std::make_unique<Node<T>>(value);
            return;
        }

        // For simplicity, just insert as left if empty, else right
        if (!node->m_left) {
            node->m_left = std::make_unique<Node<T>>(value);
        } else if (!node->m_right) {
            node->m_right = std::make_unique<Node<T>>(value);
        } else {
            // If both children exist, insert recursively to left subtree
            insert(value, node->m_left, type);
        }
    }
};
}
#endif // BIN_TREE_HPP
