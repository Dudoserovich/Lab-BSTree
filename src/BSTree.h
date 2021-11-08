#pragma once
#include "types.h"
#include <iostream>
#include <vector>

// Конструктор(+)
// Деструктор(+)
// Добавление(+)
// Удаление(+)
// Поиск(+)
// Печать(+)

// Сравнение деревьев(+)

// сделать правильный нейминг всего

class BSTree {
    node_ptr_t root; // корень(+)

    // повороты и максимум среди узлов вынести сюда (+)
    node_ptr_t srl(node_ptr_t &);
    node_ptr_t drl(node_ptr_t &);
    node_ptr_t srr(node_ptr_t &);
    node_ptr_t drr(node_ptr_t &);

    type max(type, type);

    // скрытое от пользователя добавление в узел
    int insert(type, node_ptr_t &);

    // скрытое удаление из узла
    int del(type, node_ptr_t &p);

    // скрытое удаление минимального
    type deleteMin(node_ptr_t &p);

    // скрытый поиск
    int find(type, node_ptr_t &);

    // скрытая очистка
    void makeEmpty(node_ptr_t &p);

    // высота отдельного узла
    int bsHeight(node_ptr_t p);

    // вывод по узлам
    void preorder(node_ptr_t);

    void inorder(node_ptr_t);

    void postorder(node_ptr_t);

    void helpCompare(node_ptr_t &p, std::vector<type> &comp);
public:
    BSTree(); // конструктор по умолчанию (+)
    ~BSTree(); // деструктор (+)
    // чё делать с печатью?? (3 вида обхода = 3 вывода)
    // nonodes - непонятная хуебень, лучше удалить (+)
    // сравнение деревьев (одинаковые эл-ты) (+)
    // добавление/удаление/поиск должно возвращать успешность (+)
    // убрать ненужный вывод текста из методов (+)
    // копирование либо убрать, либо изменить, чтобы парметром было другое дерево + добавить getter корня (+)

    node_ptr_t getRoot();

    int insert(type);

    // удаление из узла
    int del(type);

    // удаление минимального
    type deleteMinEl();

    // поиск по значению
    int find(type);

    node_ptr_t findMin(node_ptr_t p);

    node_ptr_t findMax(node_ptr_t p);

    void makeEmpty();

    void copy(BSTree &);

    node_ptr_t nodeCopy(node_ptr_t &p);

    // вывод дерева
    void preorder();

    void inorder();

    void postorder();

    // высота дерева
    int bsHeight();

    // сравнение деревьев
    bool compare(BSTree &bst);

    void print(int level) {
        std::cout << "ROOT:" << getRoot()->element << std::endl;
        printTree(root, 0);
    }

    // печать
    void printTree(node_ptr_t p, int level) {
        if(p!= nullptr)
        {
            printTree(p->right, level+5);
            for (int i=0; i < level ; i++)
                printf(" ");
            printf("%d\n",p->element);
            printTree(p->left, level+5);
        }
    }
};
