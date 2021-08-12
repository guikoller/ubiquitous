// The Element class for our linked List

//http://www2.lawrence.edu/fast/GREGGJ/CMSC270/linked/iterators.html
template <typename T>
class Element {
public:
    T data;
    Element<T>* next;

    Element() : next(nullptr) {}
    Element(const T& item, Element<T>* ptr = nullptr) :
        data(item), next(ptr) {}
    const T getData() const{
        return data;
    }

};

// Linked List class
template <typename T>
class List {
public:
    List() {
        // Create the dummy head Element
        head = tail = new Element<T>();
    }
    List(const List<T>& other) = delete;
    List(List<T>&& other) = delete;
    ~List() {
        while (head->next != nullptr) {
            Element<T>* temp = head;
            head = head->next;
            delete temp;
        }
        delete head;
    }

    List<T>& operator=(const List<T>& other) = delete;
    List<T>& operator=(List<T>&& other) = delete;

    // Inner class iterator
    class iterator {
        friend class List;
    private:
        Element<T>* elementPtr;
        // The constructor is private, so only our friends
        // can create instances of iterators.
        iterator(Element<T>* newPtr) : elementPtr(newPtr) {}
    public:
        iterator() : elementPtr(nullptr) {}

        // Overload for the comparison operator !=
        bool operator!=(const iterator& itr) const {
            return elementPtr != itr.elementPtr;
        }

        // Overload for the dereference operator *
        T& operator*() const {
            return elementPtr->next->data;
        }

        // Overload for the postincrement operator ++
        iterator operator++(int) {
            iterator temp = *this;
            elementPtr = elementPtr->next;
            return temp;
        }
    }; // End of inner class iterator

    iterator begin() const {
        return iterator(head);
    }

    iterator end() const {
        return iterator(tail);
    }

    iterator insert(iterator position, const T& value) {
        Element<T>* newNode = new Element<T>(value, position.elementPtr->next);
        if (position.elementPtr == tail) tail = newNode;
        position.elementPtr->next = newNode;
        return position;
    }

    iterator erase(iterator position) {
        Element<T>* toDelete = position.elementPtr->next;
        position.elementPtr->next = position.elementPtr->next->next;
        if (toDelete == tail) tail = position.elementPtr;
        delete toDelete;
        return position;
    }
    /*
    iterator removeElement(const T& value) {
        if (head == nullptr) {
            return;
        }
        else {
            Element<T>* aux = first;
            while (aux != nullptr && aux->getData() != value) {
                aux = aux->getNext();
            }
            
            if (aux == nullptr) 
                return;
            
            if (aux* != nullptr) 
                aux*.setPrev(aux->getPrev());
            
            else 
                tail = aux->getPrev();
            
            if (aux->getPrev() != nullptr) aux->getPrev()->setNext(aux->getNext());
            
            else head = aux->getNext();

            delete aux;
        }
    }
    */
private:
    Element<T>* head;
    Element<T>* tail;
};