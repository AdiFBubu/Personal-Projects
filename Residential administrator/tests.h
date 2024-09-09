#pragma once

class Tests
{
public:
    void allTests();
private:
    void domainTest();
    void storeTest();
    void addTest();
    void validatorTest();
    void stergeTest();
    void modificaTest();
    void modificaRepoTest();
    void cautareLocatarTest();
    void filtrareTest();
    void sortareTest();
    void undoTest();

    void clearListTest();
    void addNotifTest();
    void generateTest();
    void exportTest();

    void clearListServTest();
    void addNotifServTest();
    void generateServTest();
    void exportListServTest();

    void raportTest();

    void repoFileTest();

    void repoProbTest();
};