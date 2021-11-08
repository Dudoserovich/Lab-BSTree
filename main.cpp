#include <iostream>

using namespace std;

#include "src/BSTree.h"

int main() {
    BSTree bst;
    BSTree bst1;

    bst.insert(10);
    bst.insert(20);
    bst.insert(40);
    bst.insert(30);
    bst.insert(8);
    bst.insert(1);
    bst.insert(3);
    bst.insert(8);
    bst.insert(28);
    bst.insert(7);
    bst.insert(11);
    bst.insert(45);
    bst.insert(13);
    bst.print(0);

    /*bst.inorder();*/

    bst.del(30);
    cout << "=============30===================" << endl;
    bst.print(0);
    bst.del(45);
    cout << "============45================" << endl;
    bst.print(0);
    bst.del(40);
    cout << "==========40===============" << endl;
    bst.print(0);

    /*bst.inorder();*/
    /*bst.print(0);*/

    /*cout << bst.del(5) << endl;*/
    /*bst.preorder();
    bst.copy(bst1);
    bst1.preorder();*/
/*    bst1.insert(7);
    bst1.insert(4);
    bst1.inorder();
    bst1.insert(3);
    bst1.insert(8);
    bst1.insert(20);*/
    /*cout << bst1.find(20) << endl;*/

/*    bst1.preorder();
    bst1.inorder();
    bst1.postorder();*/
/*    bst1.inorder();
    bst1.postorder();*/

    cout << endl << boolalpha << bst.compare(bst1) << endl;
    return 0;
}