#pragma once
#include "domain.h"

//#include "VectorDinamicTemplate.h"

template <typename TElement>
class VectorDinamic;

template <typename TElement>
class IteratorVectorT{
private:

    const VectorDinamic<TElement>& v;
    int poz;

public:

    friend class VectorDinamic<TElement>;

    IteratorVectorT(const VectorDinamic<TElement>& v) noexcept;
    IteratorVectorT(const VectorDinamic<TElement>& v, int poz) noexcept;

    bool valid() const;
    TElement& operator*();
    IteratorVectorT& operator++();
    bool operator==(const IteratorVectorT& ot) noexcept;
    bool operator!=(const IteratorVectorT& ot) noexcept;
    IteratorVectorT& operator +(int val);
};

template<typename TElement>
bool IteratorVectorT<TElement>:: valid() const
{
    return poz < v.lg;
}

template<typename TElement>
IteratorVectorT<TElement>:: IteratorVectorT(const VectorDinamic<TElement>& v) noexcept: v{v}, poz{0}
{
}

template<typename TElement>
IteratorVectorT<TElement>:: IteratorVectorT(const VectorDinamic<TElement>& v, int poz) noexcept: v{v}, poz{poz}
{
}

template<typename TElement>
TElement& IteratorVectorT<TElement>:: operator*()
{
    return v.elems[poz];
}

template<typename TElement>
IteratorVectorT<TElement>& IteratorVectorT<TElement>:: operator++()
{
    poz ++;
    return *this;
}

template<typename TElement>
bool IteratorVectorT<TElement>:: operator==(const IteratorVectorT<TElement>& ot) noexcept
{
    return (poz == ot.poz);
}

template<typename TElement>
bool IteratorVectorT<TElement>:: operator!=(const IteratorVectorT<TElement>& ot) noexcept
{
    return !(*this == ot);
}

template<typename TElement>
IteratorVectorT<TElement>& IteratorVectorT<TElement>:: operator +(int val)
{
    poz += val;
    return *this;
}