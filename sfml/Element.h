#pragma once
#include <stdio.h>

template <class TE> class Element {
private:
    Element<TE>* pProx;
    //Element<TE>* prev;
    TE* item;
public:
    Element();
    ~Element();

    void setProx(Element<TE>* pProx) { this->pProx = pProx; }
    void setItem(TE* item) { this->item = item; }
    Element<TE>* getProx() { return pProx; }
    TE* getItem() { return item; }
};

template<class TE>
inline Element<TE>::Element()
{
    pProx = nullptr;
    item = nullptr;
}

template<class TE>
inline Element<TE>::~Element()
{

}