#pragma once

template <typename data>

struct node {
    data element;
    node *left;
    node *right;
    int height;
};

typedef int type;

typedef struct node<type> *node_ptr_t;
