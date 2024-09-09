//
// Created by Adi on 5/23/2024.
//

#pragma once

class Observer{
public:
    virtual void update() = 0;
};

#include <vector>
#include <algorithm>
using std::vector;

class Observable{
private:
    vector<Observer*> observers;

public:
    void addObserver(Observer* obs){
        observers.push_back(obs);
    }

    void removeObserver(Observer* obs){
        auto it = std::find(observers.begin(), observers.end(), obs);
        observers.erase(it);
    }

    void notify(){
        for (auto obs : observers)
            obs->update();
    }
};
