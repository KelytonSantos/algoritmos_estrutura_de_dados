#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char val;
    struct Node *left, *right;
} Node;

Node *new_node(char v)
{
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n)
        return NULL;
    n->val = v;
    n->left = n->right = NULL;
    return n;
}

int find_index(char arr[], int start, int end, char value)
{
    for (int i = start; i <= end; i++)
        if (arr[i] == value)
            return i;
    return -1;
}

Node *build_from_pre_in(char pre[], char in[], int inStart, int inEnd, int *preIndex)
{
    if (inStart > inEnd)
        return NULL;

    char rootVal = pre[*preIndex];
    Node *root = new_node(rootVal);
    (*preIndex)++;

    if (inStart == inEnd)
        return root;

    int inIndex = find_index(in, inStart, inEnd, rootVal);
    if (inIndex == -1)
        return root; // defensive

    root->left = build_from_pre_in(pre, in, inStart, inIndex - 1, preIndex);
    root->right = build_from_pre_in(pre, in, inIndex + 1, inEnd, preIndex);

    return root;
}

void print_pre(Node *r)
{
    if (!r)
        return;
    printf("%c", r->val);
    print_pre(r->left);
    print_pre(r->right);
}

void print_in(Node *r)
{
    if (!r)
        return;
    print_in(r->left);
    printf("%c", r->val);
    print_in(r->right);
}

void print_post(Node *r)
{
    if (!r)
        return;
    print_post(r->left);
    print_post(r->right);
    printf("%c", r->val);
}

void free_tree(Node *r)
{
    if (!r)
        return;
    free_tree(r->left);
    free_tree(r->right);
    free(r);
}

int main(void)
{
    // exemplo que você deu
    char preorder[] = "xYz"; // pré: raiz primeiro
    char inorder[] = "Yxz";  // em: esquerda raiz direita

    int n = (int)strlen(preorder);
    if ((int)strlen(inorder) != n)
    {
        fprintf(stderr, "tamanhos diferentes\n");
        return 1;
    }

    int preIndex = 0;
    Node *root = build_from_pre_in(preorder, inorder, 0, n - 1, &preIndex);

    printf("Reconstructed traversals:\n");
    printf("pre:  ");
    print_pre(root);
    printf("\n");
    printf("in:   ");
    print_in(root);
    printf("\n");
    printf("post: ");
    print_post(root);
    printf("\n");

    free_tree(root);
    return 0;
}
