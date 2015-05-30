#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    char c;
    struct node *l;
    struct node *r;
};

typedef struct node node;

node *make_node(int ch)
{
    node *new_node = (node *)malloc(sizeof (node));
    new_node->c = ch;
    new_node->l = NULL;
    new_node->r = NULL;
    
    return new_node;
}

node *make_tree(char *pre_b, char *pre_e, char *in_b, char *in_e)
{
    if (in_b == in_e)
        return NULL;

    if (pre_e - pre_b == 1)
        return make_node(*pre_b);

    char *found = (char *)memchr(in_b, *pre_b, (in_e - in_b));
    unsigned int l_sub = (found - in_b);

    node *root = make_node(*pre_b);
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

    printf("%c", root->c);

    free(root);
}

int main()
{
    while (1) {
        char preorder[27], inorder[27];
        scanf("%s %s", preorder, inorder);
        if (feof(stdin))
            break;

        node *root = make_tree(preorder, preorder + strlen(preorder), inorder, inorder + strlen(inorder));

        print_n_del_tree(root);

        printf("\n");
    }

    return 0;
}
