#include "TTreeTable.h"
#include <algorithm>

class AVLTree : public TTreeTable {
private:
    // Вращение вправо
    TTreeNode* rightRotate(TTreeNode* y) {
        TTreeNode* x = y->pLeft;
        TTreeNode* T2 = x->pRight;
        x->pRight = y;
        y->pLeft = T2;
        y->bal = std::max(getHeight(y->pLeft), getHeight(y->pRight)) + 1;
        x->bal = std::max(getHeight(x->pLeft), getHeight(x->pRight)) + 1;
        return x;
    }

    // Вращение влево
    TTreeNode* leftRotate(TTreeNode* x) {
        TTreeNode* y = x->pRight;
        TTreeNode* T2 = y->pLeft;
        y->pLeft = x;
        x->pRight = T2;
        x->bal = std::max(getHeight(x->pLeft), getHeight(x->pRight)) + 1;
        y->bal = std::max(getHeight(y->pLeft), getHeight(y->pRight)) + 1;
        return y;
    }

    // Получение баланса узла
    int getBalanceFactor(TTreeNode* N) {
        if (N == nullptr)
            return 0;
        return getHeight(N->pLeft) - getHeight(N->pRight);
    }

    // Высота узла
    int getHeight(TTreeNode* N) {
        if (N == nullptr)
            return 0;
        return N->bal;
    }

    // Вставка узла с балансировкой
    TTreeNode* insertNode(TTreeNode* node, TRecord rec) {
        if (node == nullptr)
            return new TTreeNode(rec);

        if (rec.key < node->rec.key)
            node->pLeft = insertNode(node->pLeft, rec);
        else if (rec.key > node->rec.key)
            node->pRight = insertNode(node->pRight, rec);
        else
            return node;

        node->bal = 1 + std::max(getHeight(node->pLeft), getHeight(node->pRight));
        int balanceFactor = getBalanceFactor(node);

        if (balanceFactor > 1 && rec.key < node->pLeft->rec.key)
            return rightRotate(node);
        if (balanceFactor < -1 && rec.key > node->pRight->rec.key)
            return leftRotate(node);
        if (balanceFactor > 1 && rec.key > node->pLeft->rec.key) {
            node->pLeft = leftRotate(node->pLeft);
            return rightRotate(node);
        }
        if (balanceFactor < -1 && rec.key < node->pRight->rec.key) {
            node->pRight = rightRotate(node->pRight);
            return leftRotate(node);
        }

        return node;
    }

    // Удаление узла с балансировкой
    TTreeNode* deleteNode(TTreeNode* root, int key) {
        if (root == nullptr)
            return root;

        if (key < root->rec.key)
            root->pLeft = deleteNode(root->pLeft, key);
        else if (key > root->rec.key)
            root->pRight = deleteNode(root->pRight, key);
        else {
            if ((root->pLeft == nullptr) || (root->pRight == nullptr)) {
                TTreeNode* temp = root->pLeft ? root->pLeft : root->pRight;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                }
                else
                    *root = *temp;
                delete temp;
            }
            else {
                TTreeNode* temp = nodeWithMinimumValue(root->pRight);
                root->rec = temp->rec;
                root->pRight = deleteNode(root->pRight, temp->rec.key);
            }
        }

        if (root == nullptr)
            return root;

        root->bal = 1 + std::max(getHeight(root->pLeft), getHeight(root->pRight));
        int balanceFactor = getBalanceFactor(root);

        if (balanceFactor > 1 && getBalanceFactor(root->pLeft) >= 0)
            return rightRotate(root);
        if (balanceFactor > 1 && getBalanceFactor(root->pLeft) < 0) {
            root->pLeft = leftRotate(root->pLeft);
            return rightRotate(root);
        }
        if (balanceFactor < -1 && getBalanceFactor(root->pRight) <= 0)
            return leftRotate(root);
        if (balanceFactor < -1 && getBalanceFactor(root->pRight) > 0) {
            root->pRight = rightRotate(root->pRight);
            return leftRotate(root);
        }

        return root;
    }

    TTreeNode* nodeWithMinimumValue(TTreeNode* node) {
        TTreeNode* current = node;
        while (current->pLeft != nullptr)
            current = current->pLeft;
        return current;
    }

public:
    AVLTree() : TTreeTable() {}

    bool Insert(TRecord rec) override {
        if (Find(rec.key))
            return false;

        pRoot = insertNode(pRoot, rec);
        dataCount++;
        return true;
    }

    bool Delete(int key) override {
        if (!Find(key))
            return false;

        pRoot = deleteNode(pRoot, key);
        dataCount--;
        return true;
    }
};