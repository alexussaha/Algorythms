#include <stdio.h>
//Усов Александр
//1. Реализовать простейшую хэш-функцию. На вход функции подается строка, на выходе сумма кодов символов.
//2. Реализовать двоичное дерево поиска
//а) Добавить обход дерева различными способами;
//б) Реализовать поиск в двоичном дереве поиска;

typedef struct tree
{
    int key;
    struct tree *left;
    struct tree *right;
    struct tree *parent;
} node;

node *create(node *root, int key)
{

    node *tmp = malloc(sizeof(node));

    tmp -> key = key;

    tmp -> parent = NULL;

    tmp -> left = tmp -> right = NULL;
    root = tmp;
    return root;
}

node *add(node *root, int key)
{
    node *root2 = root, *root3 = NULL;

    node *tmp = malloc(sizeof(node));

    tmp -> key = key;

    while (root2 != NULL)
    {
        root3 = root2;
        if (key < root2 -> key)
            root2 = root2 -> left;
        else
            root2 = root2 -> right;
    }

    tmp -> parent = root3;

    tmp -> left = NULL;
    tmp -> right = NULL;

    if (key < root3 -> key) root3 -> left = tmp;
    else root3 -> right = tmp;
    return root;
}

node *search(node * root, int key)
{

    if ((root == NULL) || (root -> key = key))
        return root;

    if (key < root -> key)
        return search(root -> left, key);
    else return search(root -> right, key);
}

void preorder(node *root)
{
    if (root == NULL)
        return;
    if (root -> key)
        printf("%d ", root -> key);
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root -> left);
    postorder(root -> right);
    if (root -> key)
        printf("%d ", root -> key);
}

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root -> left);
    if (root -> key)
        printf("%d ", root -> key);
    inorder(root -> right);
}
void printTree(node *root) {
    if (root)
    {
        printf("%d", root->key);
        if (root->left || root->right)
        {
            printf("(");
            if (root->left)
                printTree(root->left);
            else
                printf("NULL");
            printf(",");
            if (root->right)
                printTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}

int hash(char* str){
	int s = 0;
	while (*str != '\0') {
        s += *str;
        str++;
    }
    return s;
} 

int main(){
	printf("%d",hash("abcdef"));
	printf("\n");
	node *t = create(NULL, 10);
	t = add(t, 11);
	t = add(t, 8);
	t = add(t,7);
	printTree(t);
	return 0;
}