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
        std::cout << "\n������� ������ �������: \n";
        std::cin >> size;
    } while (size <= 0 || size > MAX_SIZE);


    // ������������� ������
    AVLTree tableTree;
    TSortTable tableArrSorted(size);
    TScanTable tableArr(size);
    TListHash tableListHash(size);
    TListTable tableList;
    


    // �������� ����
    do {
        std::cout
            << (!tableList.IsEmpty() ? "1.\n �������� �������\n" : "")
            << "\n2. ����� ������\n" << "3. �������� ������\n"
            << (!tableList.IsEmpty() ? "4. ������� ������\n5. ����� ������ \n" : "")
            << "0. �����\n"
            << "������� ��������: ";
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
                std::cout << "������� �� �������:\n";
                tableArr.Print();
                std::cout << "������� �� ��������������� �������:\n";   
                tableArrSorted.Print();
                std::cout << "������� �� ������:\n";
                tableList.Print();
                std::cout << "������� �� ������:\n";
                tableTree.Print();
                std::cout <<"������ ������: " << tableTree.GetRooint() << "\n";
                std::cout << "��� �������:\n";
                tableListHash.Print();
            }
            break;
        case 3:
            std::cout << "������� ����: ";
            std::cin >> data.key;
            std::cout << "������� ��������: ";
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
                std::cout << "������� �� �������� ���������\n";
            }
            break;

        case 4:
            if (!tableList.IsEmpty()) {
                std::cout << "������� ����: ";
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
                std::cout << "������� ����: ";
                std::cin >> key;
                std::cout << (tableList.Find(key) ? "������ � ListTable\n" : "�� ������ � ListTable\n");
                std::cout << (tableTree.Find(key) ? "������ � Tree\n" : "�� ������ � Tree\n");
                std::cout << (tableArr.Find(key) ? "������ � Array\n" : "�� ������ � Array\n");
                std::cout << (tableListHash.Find(key) ? "������ � ListHash\n" : "�� ������ � ListHash\n");
                std::cout << (tableArrSorted.Find(key) ? "������ � ArraySorted\n" : "�� ������ � ArraySorted\n");
            }
            break;

        case 0:
            break;

        default:
            std::cout << "��� ������� ������" << std::endl;
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