#include <iostream>
#include <fstream>
#include <string>
#include "TListTable.h"
#include "AVLTree.h"
#include "TArrayTable.h"
#include "TSortTable.h"
#include "TListHash.h"

int main() {
    setlocale(0, "");
    int work, size;
    int key;
    TRecord data;

    // Инициализация таблиц
    AVLTree tableTree;
    TSortTable tableArrSorted(MAX_SIZE);
    TScanTable tableArr(MAX_SIZE);
    TListHash tableListHash(MAX_SIZE);
    TListTable tableList;

    // Основное меню
    do {
        std::cout
            << (!tableList.IsEmpty() ? "1. Сбросить таблицы\n" : "")
            << "2. Добавить данные\n"
            << (!tableList.IsEmpty() ? "3. Удалить данные\n4. Найти данные \n5. Вывод таблиц\n" : "")
            << "0. Выход\n"
            << "Введите действие: ";
        std::cin >> work;

        switch (work) {
        case 1:
           /* if (!tableList.IsEmpty()) {*/
            tableList.Reset();
            tableTree.Reset();
            tableArr.Reset();
            tableArrSorted.Reset();
            tableListHash.Reset();
            /*}
            break;*/

        case 2:
            std::cout << "Please, enter the key: ";
            std::cin >> data.key;
            std::cout << "Please, enter the data: ";
            std::cin >> data.value;
            tableList.Insert(data);
            tableTree.Insert(data);
            tableListHash.Insert(data);

            if (!tableArrSorted.IsFull()) {
                tableArr.Insert(data);
                tableArrSorted.Insert(data);
            }
            break;

        case 3:
            if (!tableList.IsEmpty()) {
                std::cout << "Please, enter the key: ";
                std::cin >> key;
                tableList.Delete(key);
                tableTree.Delete(key);
                tableArr.Delete(key);
                tableArrSorted.Delete(key);
                tableListHash.Delete(key);
            }
            break;

        case 4:
            if (!tableList.IsEmpty()) {
                std::cout << "Please, enter the key: ";
                std::cin >> key;
                std::cout << (tableList.Find(key) ? "Found in ListTable\n" : "Not found in ListTable\n");
                std::cout << (tableTree.Find(key) ? "Found in Tree\n" : "Not found in Tree\n");
                std::cout << (tableArr.Find(key) ? "Found in Array\n" : "Not found in Array\n");
                std::cout << (tableListHash.Find(key) ? "Found in ListHash\n" : "Not found in ListHash\n");
                std::cout << (tableArrSorted.Find(key) ? "Found in ArraySorted\n" : "Not found in ArraySorted\n");
            }
            break;

        case 5:
            if (!tableList.IsEmpty()) {
                tableList.Print();
                tableTree.Print();
                tableArr.Print();
                tableArrSorted.Print();
                tableListHash.Print();
            }
            break;

        case 0:
            break;

        default:
            std::cout << "This item doesn't exist!" << std::endl;
            break;
        }
        std::cout << std::endl << std::endl;
    } while (work != 0);

    return 0;
}

//2 1 1 2 3 3 2 2 2