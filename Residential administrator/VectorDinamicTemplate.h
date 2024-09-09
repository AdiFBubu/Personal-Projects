#pragma once
#include "domain.h"
#include <vector>

template<typename TElement>
class IteratorVectorT;

template<typename TElement>
class VectorDinamic{

public:

    friend class IteratorVectorT<TElement>;

    VectorDinamic();
    VectorDinamic(const VectorDinamic& ot);

    VectorDinamic(const std::vector<TElement>& v);
    std::vector<TElement> toSTLvector();

    ~VectorDinamic();
    VectorDinamic(VectorDinamic&&);

    VectorDinamic<TElement>& operator=(const VectorDinamic& ot);
    VectorDinamic<TElement>& operator=(VectorDinamic&& ot);

    void push_back(const TElement& el);
    IteratorVectorT<TElement> erase(IteratorVectorT<TElement> it);
    TElement& get(int poz) const;
    void set(int poz, const TElement& el);
    int size() const noexcept;
    bool empty() const;

    TElement& operator[](int poz) const;

    IteratorVectorT<TElement> begin() const;
    IteratorVectorT<TElement> end() const;

private:
    int cp;
    int lg;
    TElement* elems;

    void ensureCapacity();
};

template<typename TElement>
VectorDinamic<TElement>:: VectorDinamic(): cp{10}, lg{0}, elems{new TElement[cp]}
{
}

template<typename TElement>
VectorDinamic<TElement>:: VectorDinamic(const VectorDinamic<TElement>& ot): cp{ot.cp}, lg{ot.lg}, elems{new TElement[cp]}
{
    for (int i = 0; i < lg; i ++)
        elems[i] = ot.elems[i];
}

template<typename TElement>
VectorDinamic<TElement>& VectorDinamic<TElement>:: operator=(const VectorDinamic& ot)
{
    if (this == &ot)
        return *this;
    TElement* aux = new TElement[ot.cp];
    for (int i = 0; i < ot.lg; i ++)
        aux[i] = ot.elems[i];
    delete[] elems;
    elems = aux;
    lg = ot.lg;
    cp = ot.cp;
    return *this;
}

template<typename TElement>
void VectorDinamic<TElement>:: ensureCapacity()
{
    if (lg < cp)
    {
        return;
    }
    TElement* aux = new TElement[cp * 2];
    for (int i = 0; i < lg; i ++)
        aux[i] = elems[i];
    delete[] elems;
    elems = aux;
    cp = cp * 2;
}

template<typename TElement>
void VectorDinamic<TElement>:: push_back(const TElement& el)
{
    ensureCapacity();
    elems[lg] = el;
    lg ++;
}

template<typename TElement>
IteratorVectorT<TElement> VectorDinamic<TElement>:: erase(IteratorVectorT<TElement> it)
{
    for (int i = it.poz; i < lg - 1; i ++)
        elems[i] = elems[i + 1];
    lg --;
    return it;
}

template<typename TElement>
TElement& VectorDinamic<TElement>:: get(int poz) const
{
    return elems[poz];
}

template<typename TElement>
void VectorDinamic<TElement>:: set(int poz, const TElement& el)
{
    elems[poz] = el;
}

template<typename TElement>
int VectorDinamic<TElement>:: size() const noexcept
{
    return lg;
}

template<typename TElement>
IteratorVectorT<TElement> VectorDinamic<TElement>:: begin() const
{
    return IteratorVectorT(*this);
}

template<typename TElement>
IteratorVectorT<TElement> VectorDinamic<TElement>:: end() const {
    return IteratorVectorT(*this, lg);
}

template<typename TElement>
VectorDinamic<TElement>:: ~VectorDinamic()
{
    delete[] elems;
}

template<typename TElement>
VectorDinamic<TElement>:: VectorDinamic(const std::vector<TElement>& v)
{
    cp = v.size();
    elems = new TElement[cp];
    for (int i = 0; i < cp; i ++)
        push_back(v[i]);
}

template<typename TElement>
std::vector<TElement> VectorDinamic<TElement>:: toSTLvector()
{
    std::vector<TElement> v;
    for (int i = 0; i < lg; i ++)
        v.push_back(elems[i]);
    return v;
}

template<typename TElement>
bool VectorDinamic<TElement>:: empty() const
{
    return lg == 0;
}

template<typename TElement>
TElement& VectorDinamic<TElement>:: operator[](int poz) const
{
    return elems[poz];
}

template<typename TElement>
VectorDinamic<TElement>:: VectorDinamic(VectorDinamic<TElement>&& ot)
{
    elems = ot.elems;
    cp = ot.cp;
    lg = ot.lg;

    ot.elems = nullptr;
    ot.lg = 0;
    ot.cp = 0;
}

template<typename TElement>
VectorDinamic<TElement>& VectorDinamic<TElement>:: operator=(VectorDinamic<TElement>&& ot)
{
    if (this == &ot)
        return *this;
    delete[] elems;

    elems = ot.elems;
    lg = ot.lg;
    cp = ot.cp;

    ot.elems = nullptr;
    ot.lg = 0;
    ot.cp = 0;

    return *this;
}