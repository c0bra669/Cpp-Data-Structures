#ifndef BST_H
#define BST_H
#include "bin-tree.hpp"
#include <optional>

namespace DataStructures {

template <typename T>
class Bst : public BinTree<T>{
public:
    void print() const { print(BinTree<T>::m_root.get()); }
    void insert(T value){
        if (!this->m_root) {
            this->m_root = std::make_unique<Node<T>>(value);
            return;
        }
        Node<T>* cur = this->m_root.get();
        while (true) {
            if (value == cur->m_value) return;
            if (value < cur->m_value) {
                if (cur->m_left) cur = cur->m_left.get();
                else { cur->m_left = std::make_unique<Node<T>>(value); return; }
            } else {
                if (cur->m_right) cur = cur->m_right.get();
                else { cur->m_right = std::make_unique<Node<T>>(value); return; }
            }
        }
    }
    T max() const { return max(this->m_root.get()).value_or(T{}); }
    T min() const { return min(this->m_root.get()).value_or(T{}); }
    void remove(T value) { remove(this->m_root, value); }
private:
    std::optional<T> max(Node<T>* node) const {
        if (!node) return std::nullopt;
        while (node->m_right) node = node->m_right.get();
        return node->m_value;
    }

    std::optional<T> min(Node<T>* node) const {
        if (!node) return std::nullopt;
        while (node->m_left) node = node->m_left.get();
        return node->m_value;
    }

    void remove(std::unique_ptr<Node<T>>& node, T value) {
        if (!node) return;

        if (value < node->m_value) remove(node->m_left, value);
        else if (value > node->m_value) remove(node->m_right, value);
        else {
            // node with 0 or 1 child
            if (!node->m_left && !node->m_right) node.reset();
            else if (!node->m_left) node = std::move(node->m_right);
            else if (!node->m_right) node = std::move(node->m_left);
            else {
                // node with 2 children: find successor
                Node<T>* successor = node->m_right.get();
                while (successor->m_left) successor = successor->m_left.get();
                node->m_value = successor->m_value;
                remove(node->m_right, successor->m_value);
            }
        }
    }
    void print(Node<T>* node) const {
        if (!node) return;
        print(node->m_left.get());
        std::cout << node->m_value << std::endl;
        print(node->m_right.get());
    }

};

} // namespace DataStructures

#endif // BST_H
