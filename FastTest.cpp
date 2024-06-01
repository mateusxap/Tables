#include <iostream>
#include <fstream>
#include <string>
#include "TListTable.h"
#include "AVLTree.h"
#include "TArrayTable.h"
#include "TSortTable.h"
#include "TListHash.h"
#include "TTreeTable.h"

int main() {
    setlocale(0, "");
    int work, size;
    int key;
    TRecord data;

    do {
        std::cout << "\nВведите размер таблицы: \n";
        std::cin >> size;
    } while (size <= 0 || size > MAX_SIZE);


    // Инициализация таблиц
    AVLTree tableTree;
    TSortTable tableArrSorted(size);
    TScanTable tableArr(size);
    TListHash tableListHash(size);
    TListTable tableList;
    


    // Основное меню
    do {
        std::cout
            << (!tableList.IsEmpty() ? "1.\n Сбросить таблицы\n" : "")
            << "\n2. Вывод таблиц\n" << "3. Добавить данные\n"
            << (!tableList.IsEmpty() ? "4. Удалить данные\n5. Найти данные \n" : "")
            << "0. Выход\n"
            << "Введите действие: ";
        std::cin >> work;

        switch (work) {
        case 1:
           /* if (!tableList.IsEmpty()) {*/
            tableArr.Reset();
            tableArrSorted.Reset();
            tableList.Reset();
            tableTree.Reset();
            tableListHash.Reset();
            /*}
            break;*/

        case 2:
            if (!tableList.IsEmpty()) {
                std::cout << "Таблица на массиве:\n";
                tableArr.Print();
                std::cout << "Таблица на отсортированном массиве:\n";   
                tableArrSorted.Print();
                std::cout << "Таблица на списке:\n";
                tableList.Print();
                std::cout << "Таблица на дереве:\n";
                tableTree.Print();
                std::cout <<"Корень дерева: " << tableTree.GetRooint() << "\n";
                std::cout << "Хэш таблица:\n";
                tableListHash.Print();
            }
            break;
        case 3:
            std::cout << "Введите ключ: ";
            std::cin >> data.key;
            std::cout << "Введите значение: ";
            std::cin >> data.value;
            tableList.Insert(data);
            tableTree.Insert(data);
            tableListHash.Insert(data);

            if (!tableArrSorted.IsFull()) {
                tableArr.Insert(data);
                tableArrSorted.Insert(data);
            }
            else
            {
                std::cout << "Таблицы на массивах заполнены\n";
            }
            break;

        case 4:
            if (!tableList.IsEmpty()) {
                std::cout << "Введите ключ: ";
                std::cin >> key;
                tableList.Delete(key);
                tableTree.Delete(key);
                tableArr.Delete(key);
                tableArrSorted.Delete(key);
                tableListHash.Delete(key);
            }
            break;

        case 5:
            if (!tableList.IsEmpty()) {
                std::cout << "Введите ключ: ";
                std::cin >> key;
                std::cout << (tableList.Find(key) ? "Найден в ListTable\n" : "Не найден в ListTable\n");
                std::cout << (tableTree.Find(key) ? "Найден в Tree\n" : "Не найден в Tree\n");
                std::cout << (tableArr.Find(key) ? "Найден в Array\n" : "Не найден в Array\n");
                std::cout << (tableListHash.Find(key) ? "Найден в ListHash\n" : "Не найден в ListHash\n");
                std::cout << (tableArrSorted.Find(key) ? "Найден в ArraySorted\n" : "Не найден в ArraySorted\n");
            }
            break;

        case 0:
            break;

        default:
            std::cout << "Нет данного пункта" << std::endl;
            break;
        }
        std::cout << std::endl << std::endl;
    } while (work != 0);

    return 0;
}

//10 3 6 l 3 2 a 3 1 z 3 3 t 3 4 q 3 5 b 

  //  6
  //  /
  //  2
  // / \
  //1   3
  //      \
  //       4
  //        \
  //         5