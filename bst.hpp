#ifndef BST_H
#define BST_H

#include "node.hpp"
#include <memory>
#include <iostream>
#include <optional>

namespace DataStructures {

template <typename T>
class Bst {
private:
    std::unique_ptr<Node<T>> m_root;

    void print(Node<T>* node) const {
        if (!node) return;
        print(node->m_left.get());
        std::cout << node->m_value << std::endl;
        print(node->m_right.get());
    }

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

public:
    Bst() : m_root(nullptr) {}

    void insert(T value) {
        if (!m_root) {
            m_root = std::make_unique<Node<T>>(value);
            return;
        }
        Node<T>* cur = m_root.get();
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

    void print() const { print(m_root.get()); }

    T max_value() const { return max(m_root.get()).value_or(T{}); }
    T min_value() const { return min(m_root.get()).value_or(T{}); }

    void remove(T value) { remove(m_root, value); }
};

} // namespace DataStructures

#endif // BST_H
