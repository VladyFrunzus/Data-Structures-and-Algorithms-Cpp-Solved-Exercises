#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node* newNode (int data)
{
    struct node* temp =
        (struct node *) malloc(sizeof(struct node));

    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

struct node* constructTreeUtil(int post[], int* postIndex,
                               int key, int min, int max,
                               int size)
{
    if (*postIndex < 0)
        return NULL;

    struct node* root = NULL;

    if (key > min && key < max)
    {

        root = newNode(key);
        *postIndex = *postIndex - 1;

        if (*postIndex >= 0)
        {

            root->right = constructTreeUtil(post, postIndex,
                                            post[*postIndex],
                                            key, max, size );


            root->left = constructTreeUtil(post, postIndex,
                                           post[*postIndex],
                                           min, key, size );
        }
    }
    return root;
}

struct node *constructTree (int post[],
                            int size)
{
    int postIndex = size-1;
    return constructTreeUtil(post, &postIndex,
                             post[postIndex],
                             INT_MIN, INT_MAX, size);
}


//asta a fost postordinea


class node
{
public:
    int data;
    node* left;
    node* right;
};

node* newNode(int data)
{
    node* temp = new node();

    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

node* constructTreeUtil(int pre[], int* preIndex, int low,
                        int high, int size)
{
    if (*preIndex >= size || low > high)
        return NULL;

    node* root = newNode(pre[*preIndex]);
    *preIndex = *preIndex + 1;

    if (low == high)
        return root;

    int i;
    for (i = low; i <= high; ++i)
        if (pre[i] > root->data)
            break;

    root->left = constructTreeUtil(pre, preIndex, *preIndex,
                                   i - 1, size);
    root->right
        = constructTreeUtil(pre, preIndex, i, high, size);

    return root;
}

node* constructTree(int pre[], int size)
{
    int preIndex = 0;
    return constructTreeUtil(pre, &preIndex, 0, size - 1,
                             size);
}

void printInorder(node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}


//asta e preordinea
