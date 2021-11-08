#pragma once
#include "BSTree.h"
#include <iostream>
#include <vector>

using namespace std;

BSTree::BSTree() {
    root = nullptr;
}

BSTree::~BSTree() {
    root = nullptr;
}

// добавление узла в дерево
int BSTree::insert(type x) {
    return BSTree::insert(x, root);
}

node_ptr_t BSTree::getRoot() {
    node_ptr_t p = this->root;
    return p;
}

// Добавление узла
int BSTree::insert(type x, node_ptr_t &p) {
    if (p == nullptr) {
        p = root;
        p = new node<type>;
        p->element = x;
        p->left = nullptr;
        p->right = nullptr;
        p->height = 0;
        if (p == nullptr) {
            return 0; // некуда добавлять(закончилось место в памяти)
        }
    } else {
        if (x < p->element) {
            insert(x, p->left);
            if ((bsHeight(p->left) - bsHeight(p->right)) == 2) {
                if (x < p->left->element) {
                    p = srl(p);
                } else {
                    p = drl(p);
                }
            }
        } else if (x > p->element) {
            insert(x, p->right);
            if ((bsHeight(p->right) - bsHeight(p->left)) == 2) {
                if (x > p->right->element) {
                    p = srr(p);
                } else {
                    p = drr(p);
                }
            }
        } else {
            return 0;
        }
    }
    int m, n, d;
    m = bsHeight(p->left);
    n = bsHeight(p->right);
    d = max(m, n);
    p->height = d + 1;
    return 1;
}

// вытаскивание минимального узла
node_ptr_t BSTree::findMin(node_ptr_t p) {
    if (p == nullptr) {// в дереае нет эл-ов
        return p;
    } else {
        while (p->left != nullptr) {
            p = p->left;
        }
        return p;
    }
}

// вытаскивание максимального узла
node_ptr_t BSTree::findMax(node_ptr_t p) {
    if (p == nullptr) {// в дереве нет эл-ов
        return p;
    } else {
        while (p->right != nullptr) {
            p = p->right;
        }
        return p;
    }
}

// скрытый поиск
int BSTree::find(type x, node_ptr_t &p) {
    if (p == nullptr) {
        return 0; // эл-та нет
    } else {
        if (x < p->element) {
            find(x, p->left);
        } else {
            if (x > p->element) {
                find(x, p->right);
            } else {
                return 1; // эл-т найден
            }
        }
    }
}

// удаление из узла
int BSTree::del(type x) {
    return del(x, root);
};

// удаление минимального
type BSTree::deleteMinEl() {
    return deleteMin(root);
};

// поиск
int BSTree::find(type x) {
    return find(x, root);
};

void BSTree::makeEmpty() {
    makeEmpty(root);
};

// копирование дерева
void BSTree::copy(BSTree &bst) {
    makeEmpty(bst.root);
    bst.root = nodeCopy(root);
}

// очистка дерева
void BSTree::makeEmpty(node_ptr_t &p) {
    node_ptr_t d;
    if (p != nullptr) {
        makeEmpty(p->left);
        makeEmpty(p->right);
        d = p;
        free(d);
        p = nullptr;
    }
}

// копирование узла
node_ptr_t BSTree::nodeCopy(node_ptr_t &p) {
    node_ptr_t temp;
    if (p == nullptr) {
        return p;
    } else {
        temp = new node<type>;
        temp->element = p->element;
        temp->left = nodeCopy(p->left);
        temp->right = nodeCopy(p->right);
        return temp;
    }
}

// скрытое удаление узла
int BSTree::del(type x, node_ptr_t &p) {
    node_ptr_t d;
    if (p == nullptr) {
        return 0; // эл-та нет
    } else if (x < p->element) {
        del(x, p->left);
    } else if (x > p->element) {
        del(x, p->right);
    } else if ((p->left == nullptr) && (p->right == nullptr)) {
        d = p;
        free(d);
        p = nullptr;
        // добавить проверку на сбалансировать и возвращая узловой эл-т балансировки и уже здесь балансировать при необходимости
        return 1; // эл-т удалён
    } else if (p->left == nullptr) {
        d = p;
        free(d);
        p = p->right;
        // добавить проверку на сбалансировать и возвращая узловой эл-т балансировки и уже здесь балансировать при необходимости
        return 1; // эл-т удалён
    } else if (p->right == nullptr) {
        d = p;
        p = p->left;
        free(d);
        // cout << "HEIGHT:" << root->right->height << root->left->height << endl;
        root = srl(root); // временный костыль
        //cout << "HEIGHT:" << root->right->height << root->left->height << endl;
        // добавить проверку на сбалансировать и возвращая узловой эл-т балансировки и уже здесь балансировать при необходимости
        return 1; // эл-т удалён
    } else {
        p->element = deleteMin(p->right);
    }
}

// удаление минимального с вытаскиванием
type BSTree::deleteMin(node_ptr_t &p) {
    type c;
    if (p->left == nullptr) {
        c = p->element;
        p = p->right;
        return c;
    } else {
        c = deleteMin(p->left);
        return c;
    }
}

void BSTree::preorder(node_ptr_t p) {
    if (p != nullptr) {
        cout << p->element << ' ';
        preorder(p->left);
        preorder(p->right);
    }
}

// Inorder Printing
void BSTree::inorder(node_ptr_t p) {
    if (p != nullptr) {
        inorder(p->left);
        cout << p->element << ' ';
        inorder(p->right);
    }
}

// PostOrder Printing
void BSTree::postorder(node_ptr_t p) {
    if (p != nullptr) {
        postorder(p->left);
        postorder(p->right);
        cout << p->element << ' ';
    }
}

// вывод дерева
// префиксный
void BSTree::preorder() {
    cout << "Префиксный обход дерева:" << endl;
    if (root == nullptr)
        cout << "Пустое дерево!";
    else {
        preorder(root);
    }
    cout << endl;
};

// инфиксный
void BSTree::inorder() {
    cout << "Инфиксный обход дерева:" << endl;
    if (root == nullptr)
        cout << "Пустое дерево!";
    else {
        inorder(root);
    }
    cout << endl;
};

// постфиксный
void BSTree::postorder() {
    cout << "Постфиксный обход дерева:" << endl;
    if (root == nullptr)
        cout << "Пустое дерево!";
    else {
        postorder(root);
    }
    cout << endl;
};

// максимальный элемент
type BSTree::max(type value1, type value2) {
    return ((value1 > value2) ? value1 : value2);
}

// высота узла
int BSTree::bsHeight(node_ptr_t p) {
    int t;
    if (p == nullptr) {
        return -1;
    } else {
        t = p->height;
        return t;
    }
}

// высота дерева
int BSTree::bsHeight() {
    return bsHeight(root);
};

// обход с записью
void BSTree::helpCompare(node_ptr_t &p, vector<type> &comp) {
    if (p != nullptr) {
        comp.push_back(p->element);
        helpCompare(p->left, comp);
        helpCompare(p->right, comp);
    }
}

// сравнение деревьев
bool BSTree::compare(BSTree &bst) {
    vector<type> comp1;
    vector<type> comp2;
    helpCompare(root, comp1);
    helpCompare(bst.root, comp2);
    sort (comp1.begin(), comp1.end());
    sort (comp2.begin(), comp2.end());

    return comp1 == comp2;
}

// малый поворот влево
node_ptr_t BSTree::srl(node_ptr_t &p1) {
    if (bsHeight(p1->left) - bsHeight(p1->right) == 2) {
        node_ptr_t p2;
        p2 = p1->left;
        p1->left = p2->right;
        p2->right = p1;
        p1->height = max(bsHeight(p1->left), bsHeight(p1->right)) + 1;
        p2->height = max(bsHeight(p2->left), p1->height) + 1;
        return p2;
    } else return p1;
}

// малый поворот вправо
node_ptr_t BSTree::srr(node_ptr_t &p1) {
    if (bsHeight(p1->right) - bsHeight(p1->left) == 2) {
        node_ptr_t p2;
        p2 = p1->right;
        p1->right = p2->left;
        p2->left = p1;
        p1->height = max(bsHeight(p1->left), bsHeight(p1->right)) + 1;
        p2->height = max(p1->height, bsHeight(p2->right)) + 1;
        return p2;
    } else return p1;
}

// большой поворот влево
node_ptr_t BSTree::drl(node_ptr_t &p1) {
    p1->left = srr(p1->left);
    return srl(p1);
}

// большой поворот вправо
node_ptr_t BSTree::drr(node_ptr_t &p1) {
    p1->right = srl(p1->right);
    return srr(p1);
}