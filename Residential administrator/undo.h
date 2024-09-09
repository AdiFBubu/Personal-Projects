#pragma once
#include "repo.h"
#include "domain.h"

class ActiuneUndo{
public:
    ActiuneUndo() = default;
    virtual void doUndo() = 0;
    virtual ~ActiuneUndo() = default;
};

class UndoAdauga: public ActiuneUndo{
private:
    LocatarAbstractRepo& repo;
    int ap;
public:
    UndoAdauga(LocatarAbstractRepo&, int);
    void doUndo() override;
};

class UndoSterge: public ActiuneUndo{
private:
    LocatarAbstractRepo& repo;
    Locatar l;
public:
    UndoSterge(LocatarAbstractRepo&, Locatar);
    void doUndo() override;
};

class UndoModifica: public ActiuneUndo{
private:
    LocatarAbstractRepo& repo;
    Locatar l;
public:
    UndoModifica(LocatarAbstractRepo&, Locatar);
    void doUndo() override;
};