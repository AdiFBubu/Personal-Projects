#include "undo.h"

UndoAdauga::UndoAdauga(LocatarAbstractRepo& repo, int ap): repo{repo}, ap{ap} {}

void UndoAdauga:: doUndo()
{
    repo.sterge(ap);
}

UndoSterge::UndoSterge(LocatarAbstractRepo& repo, Locatar l): repo{repo}, l{l} {}

void UndoSterge::doUndo() {
    repo.store(l);
}

UndoModifica::UndoModifica(LocatarAbstractRepo& repo, Locatar l) : repo{repo}, l{l} {}

void UndoModifica::doUndo() {
    repo.modifica(l);
}