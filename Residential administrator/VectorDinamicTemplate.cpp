//
// Created by Adi on 4/5/2024.
//

/*
#include "VectorDinamicTemplate.h"
#include "IteratorVectorT.h"

VectorDinamic:: VectorDinamic(): cp{10}, lg{0}, elems{new Locatar[cp]}
{
}

VectorDinamic:: VectorDinamic(const VectorDinamic& ot): cp{ot.cp}, lg{ot.lg}, elems{new Locatar[lg]}
{
    for (int i = 0; i < lg; i ++)
        elems[i] = ot.elems[i];
}

VectorDinamic VectorDinamic:: operator=(const VectorDinamic& ot)
{
    if (this == &ot)
        return *this;
    Locatar* aux = new Locatar[ot.cp];
    for (int i = 0; i < ot.lg; i ++)
        aux[i] = ot.elems[i];
    delete[] elems;
    elems = aux;
    lg = ot.lg;
    cp = ot.cp;
    return *this;
}

void VectorDinamic:: ensureCapacity()
{
    if (lg < cp)
    {
        return;
    }
    Locatar* aux = new Locatar[cp * 2];
    for (int i = 0; i < lg; i ++)
        aux[i] = elems[i];
    delete[] elems;
    elems = aux;
    cp = cp * 2;
}

void VectorDinamic:: push_back(const Locatar& el)
{
    ensureCapacity();
    elems[lg] = el;
    lg ++;
}

IteratorVectorT VectorDinamic:: erase(IteratorVectorT it)
{
    for (int i = it.poz; i < lg - 1; i ++)
        elems[i] = elems[i + 1];
    lg --;
    it.poz --;
    return it;
}

Locatar& VectorDinamic:: get(IteratorVectorT it) const
{
    return elems[it.poz];
}

void VectorDinamic:: set(IteratorVectorT it, const Locatar& el)
{
    elems[it.poz] = el;
}

int VectorDinamic:: size() const noexcept
{
    return lg;
}

IteratorVectorT VectorDinamic:: begin() const
{
    return IteratorVectorT(*this);
}

IteratorVectorT VectorDinamic:: end() const {
    return IteratorVectorT(*this, lg);
}

VectorDinamic:: ~VectorDinamic()
{
    delete[] elems;
}

VectorDinamic:: VectorDinamic(const std::vector<Locatar>& v)
{
    cp = v.size();
    elems = new Locatar[cp];
    for (int i = 0; i < lg; i ++)
        push_back(v[i]);
}

std::vector<Locatar> VectorDinamic:: toSTLvector()
{
    std::vector<Locatar> v;
    for (int i = 0; i < lg; i ++)
        v.push_back(elems[i]);
    return v;
}

bool VectorDinamic:: empty() const
{
    return lg == 0;
}

Locatar& VectorDinamic:: operator[](int poz) const
{
    return elems[poz];
}
*/