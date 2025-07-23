#include <stdio.h>
#include <stdlib.h>

struct Node {
  char data;
  struct Node *left;
  struct Node *right;
};

struct Node *newNode(char data) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void visit(struct Node *node) { printf("%c", node->data); }

void preorderNonRecursive(struct Node *root) {
  if (root == NULL) {
    return;
  }

  struct Node *stack[100];
  int top = -1;
  stack[++top] = root;
  while (top != -1) {

    struct Node *currentNode = stack[top--];
    visit(currentNode);

    if (currentNode->right != NULL) {
      stack[++top] = currentNode->right;
    }

    if (currentNode->left != NULL) {
      stack[++top] = currentNode->left;
    }
  }
}

int main() {

      /*
               A
              / \
             B   C
            / \
           D   E
     */

  struct Node *root = newNode('A');
  root->left = newNode('B');
  root->right = newNode('C');
  root->left->left = newNode('D');
  root->left->right = newNode('E');
  printf("Preorder traversal (non-recursive):\n ");
  preorderNonRecursive(root);
  printf("\n ");

  return 0;
}