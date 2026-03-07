#ifndef NODE_HPP
#define NODE_HPP
#include <memory>

namespace DataStructures {

template <typename T>
class Node
{
public:
    T m_value;
    std::unique_ptr<Node<T>> m_left;
    std::unique_ptr<Node<T>> m_right;

public:
    Node() : m_value(T{}), m_left(nullptr), m_right(nullptr) {}          // default constructor
    Node(T value) : m_value(value), m_left(nullptr), m_right(nullptr) {} // constructor with value
};

} // namespace DataStructures

#endif // NODE_HPP
