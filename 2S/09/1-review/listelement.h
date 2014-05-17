#ifndef LISTELEMENT_H
#define LISTELEMENT_H

#pragma once

class ListElement
{
public:
    ListElement(int value);
    ListElement();
    int getValue();
    void takeValue(int value);
    void printElement();
private:
    int value;
};

#endif // LISTELEMENT_H
