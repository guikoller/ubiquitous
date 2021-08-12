#pragma once

template <typename TF>
class List {
private:
    unsigned int size;

    template <typename TE>
    class ListElement {
    private:
        ListElement<TE>* next;
        ListElement<TE>* prev;
        TE data;
    public:
        ListElement<TE>* getNext() {
            return next;
        }
        void setNext(ListElement<TE>* elem) {
            next = elem;
        }
        ListElement<TE>* getPrev() {
            return prev;
        }
        void setPrev(ListElement<TE>* elem) {
            prev = elem;
        }
        TE& getData() {
            return data;
        }
        void setData(const TE& elem) {
            data = elem;
        }

        ListElement() {
            next = nullptr;
            prev = nullptr;
        }
        ~ListElement() {
            next = nullptr;
            prev = nullptr;
        }
    };

    ListElement<TF>* first;
    ListElement<TF>* last;

public:
    List() {
        first = nullptr;
        last = nullptr;
        size = 0;
    }
    ~List() {
        clear();
    }
    void addElementBack(const TF& newElement) {
        ++size;
        if (first == nullptr) {
            ListElement<TF>* elem = new ListElement<TF>();
            elem->setData(newElement);
            first = elem;
            last = elem;
        }
        else {
            ListElement<TF>* elem = new ListElement<TF>();
            elem->setData(newElement);
            last->setNext(elem);
            elem->setPrev(last);
            last = elem;
        }
    }
    void addElementFront(const TF& newElement) {
        ++size;
        if (first == nullptr) {
            ListElement<TF>* elem = new ListElement<TF>();
            elem->setData(newElement);
            first = elem;
            last = elem;
        }
        else {
            ListElement<TF>* elem = new ListElement<TF>();
            elem->setData(newElement);
            first->setPrev(elem);
            elem->setNext(first);
            first = elem;
        }
    }
    void removeFirstMatchingElement(const TF& element) {
        if (first == nullptr) {
            return;
        }
        else {
            ListElement<TF>* aux = first;
            while (aux != nullptr && aux->getData() != element) {
                aux = aux->getNext();
            }
            if (aux == nullptr) return;
            if (aux->getNext() != nullptr) aux->getNext()->setPrev(aux->getPrev());
            else last = aux->getPrev();
            if (aux->getPrev() != nullptr) aux->getPrev()->setNext(aux->getNext());
            else first = aux->getNext();

            delete aux;
            --size;
        }
    }
    const unsigned int getSize() const {
        return size;
    }

    class iterator {
    private:
        ListElement<TF>* element;
        iterator(ListElement<TF>* el) {
            element = el;
        }
    public:
        iterator(const iterator& other) {
            element = other.element;
        }
        ~iterator() {
            element = nullptr;
        }
        TF& operator*() {
            return element->getData();
        }
        bool operator==(const iterator& other) {
            return element == other.element;
        }
        bool operator!=(const iterator& other) {
            return !(*this == other);
        }
        iterator& operator++() {
            if (element != nullptr) {
                element = element->getNext();
            }
            return *this;
        }
        iterator operator++(int) {
            ListElement<TF>* ret = element;
            if (element != nullptr) {
                element = element->getNext();
            }
            return iterator(ret);
        }
        friend class List;
    };

    iterator begin() {
        return iterator(first);
    }
    iterator end() {
        return iterator(nullptr);
    }

    void clear() {
        while (first != nullptr) {
            ListElement<TF>* aux = first->getNext();
            delete first;
            first = aux;
        }
        first = nullptr;
        last = nullptr;
    }

};