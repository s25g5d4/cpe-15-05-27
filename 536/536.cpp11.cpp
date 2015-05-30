#include <iostream>
#include <string>
#include <algorithm>

typedef std::string::iterator str_it;

struct node
{
    char c;
    node *l;
    node *r;

    node(char ch, node *le = NULL, node *ri = NULL) : c(ch), l(le), r(ri)
    {

    }
};

// pre_b: preorder traversal string begin iterator
// pre_e: preorder traversal string end iterator
// in_b: inorder traversal string begin iterator
// in_e: inorder traversal string end iterator
node *make_tree(str_it pre_b, str_it pre_e, str_it in_b, str_it in_e)
{
    if (in_b == in_e)
        return NULL;

    if (pre_e - pre_b == 1)
        return new node(*pre_b);

    auto found = find(in_b, in_e, *pre_b);
    auto l_sub = (found - in_b);

    node *root = new node(*pre_b);
    ++pre_b;
    root->l = make_tree(pre_b, pre_b + l_sub, in_b, found);
    root->r = make_tree(pre_b + l_sub, pre_e, found + 1, in_e);

    return root;
}

void print_n_del_tree(node *root)
{
    if (root == NULL)
        return;

    if (root->l != NULL)
        print_n_del_tree(root->l);

    if (root->r != NULL)
        print_n_del_tree(root->r);

    std::cout << root->c;

    delete root;
}

int main()
{
    using namespace std;

    while (true) {
        string preorder, inorder;
        cin >> preorder >> inorder;
        if (cin.eof())
            break;

        node *root = make_tree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());

        print_n_del_tree(root);

        cout << endl;
    }

    return 0;
}