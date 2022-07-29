template<typename T>
class Node {
    private:
    T data;
    Node<T> * next = nullptr;
    public:
    Node() = default;
    Node(T data) : data(data) {}

    T get() {
        return this->data;
    }

    void set(T dt) {
        this->data = dt;
    }

    Node<T> * getNext() {
        return this->next;
    }

    void setNext(Node<T> * nxt) {
        this->next = nxt;
    }

};

template<typename T>
class NodeExt : private Node<T> {
    private: 
    Node<T> * prev = nullptr;
    public:
    using Node<T>::Node;
    using Node<T>::set;
    using Node<T>::get;
    using Node<T>::getNext;
    using Node<T>::setNext;


    Node<T> * getPrev() {
        return this->prev;
    }

    void setPrev(Node<T> * prv) {
        this->prev = prv;
    }
};