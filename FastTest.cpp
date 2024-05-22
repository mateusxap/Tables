#include<iostream>
#include<string>
#include<iomanip>

#include "TListHash.h"
#include "AVLTree.h"
#include "TArrayTable.h"
#include "TSortTable.h"




int main()
{
    int size = 5;
    TRecord value1(1, "hey");
    TRecord value2(2, "world");
    //CTableList tableList;
    AVLTree tableTree;
    TSortTable tableArrSorted(size);
    TScanTable tableArr(size);
    TListHash tableListHash(size);

    tableArr.Insert(value2);
    tableTree.Insert(value2);
    tableArrSorted.Insert(value2);
    tableListHash.Insert(value2);
    tableArr.Insert(value1);
    tableTree.Insert(value1);
    tableArrSorted.Insert(value1);
    tableListHash.Insert(value1);

    tableArr.Print();
    tableTree.Print();
    tableArrSorted.Print();
    tableListHash.Print();

    tableArr.Delete(2);
    tableTree.Delete(2);
    tableArrSorted.Delete(2);
    tableListHash.Delete(2);

    std::cout << tableArr.Find(2);
    std::cout << tableTree.Find(2);
    std::cout << tableArrSorted.Find(2);
    std::cout << tableListHash.Find(2);

    

}