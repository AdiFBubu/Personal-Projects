/*
 * #include "IteratorVectorT.h"
#include "VectorDinamicTemplate.h"



bool IteratorVectorT:: valid() const
{
    return poz < v.lg;
}

IteratorVectorT:: IteratorVectorT(const VectorDinamic& v) noexcept: v{v}, poz{0}
{
}

IteratorVectorT:: IteratorVectorT(const VectorDinamic& v, int poz) noexcept: v{v}, poz{poz}
{
}

Locatar& IteratorVectorT:: operator*()
{
    return v.elems[poz];
}

IteratorVectorT& IteratorVectorT:: operator++()
{
    poz ++;
    return *this;
}

bool IteratorVectorT:: operator==(const IteratorVectorT& ot) noexcept
{
    return (poz == ot.poz);
}

bool IteratorVectorT:: operator!=(const IteratorVectorT& ot) noexcept
{
    return !(*this == ot);
}

IteratorVectorT& IteratorVectorT:: operator +(int val)
{
    poz += val;
    return *this;
}
*/