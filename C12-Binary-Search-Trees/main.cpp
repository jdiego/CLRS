
/*************************************************************************
	> File Name: main.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Sun May  3 00:05:14 2015
 ************************************************************************/

/*#include "BSTree.h"*/
//#include <cstdlib>
//#include <iostream>
//using namespace std;

//int main()
//{
    //BSTree<int> intBST;
    //cout << "Constructing empty BST\n";
    //cout << "BST " << (intBST.empty()?"is":"is not") << "empty\n";

    //int number;
    //for (;;)
    //{
        //cout << "Item to insert (-999 to stop):";
        //cin >> number;
        //if (number == -999) break;
        //intBST.insert(number);
    //}
    //intBST.inorder(cout);
    //cout << endl;
    //intBST.graph(cout);

    //for (;;)
    //{
        //cout << "Item to find (-999 to stop):";
        //cin >> number;
        //if (number == -999) break;
        //bool found = intBST.find(number);
        //cout << boolalpha << found << endl;
    //}

    //for (;;)
    //{
        //cout << "Item to remove (-999 to stop):";
        //cin >> number;
        //if (number == -999) break;
        //intBST.remove(number);
        //cout << endl;
        //intBST.graph(cout);
        //cout << endl;
    //}
    //intBST.inorder(cout);
    //cout << endl;
    //return 0;
/*}*/

#include "binary_search_tree.hpp"
#include <iostream>
int main(void)
{
    BinarySearchTree<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);
    tree.inorder();
    tree.remove(50);
    tree.remove(70);
    tree.remove(20);
    std::cout<<"============================\n";
    tree.inorder();
    return 0;
}
