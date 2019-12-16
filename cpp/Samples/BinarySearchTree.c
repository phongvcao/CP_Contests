#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;

struct Node {
    Node* left;
    Node* right;
    int data;
};

Node* createNode(int data);
void insertIntoBST(Node* root, int data);
void constructBST(Node* root, int arr[10]);
void printBSTInOrder(Node* root);
void printBSTPostOrder(Node* root);
void printBSTPreOrder(Node* root);
void printBSTDepthFirst(Node* root);
void printBSTBreadthFirst(Node* root);
Node* getMaxNode(Node* root, Node** preMaxNode);
Node* getMinNode(Node* root);
Node* getNode(Node* root, int data);
void deleteData(Node** root, int data, Node** current);
void rebuildBST(Node* root, int data);
int getSubTreeSize(Node* root, int size);
void balanceBST(Node* root);
void deleteSubTree(Node* root);
void deleteBST(Node* root);


int main(int argc, char** argv) {
    int arr[10];

    scanf(("%d %d %d %d %d %d %d %d %d %d"), &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6], &arr[7], &arr[8], &arr[9]);

    int i;
    for (i = 0; i != sizeof(arr)/sizeof(arr[0]); ++i) {
        printf("%d\n", arr[i]);
    }
    printf("sizeof(arr) (in main()): %d\n", sizeof(arr)/sizeof(arr[0]));

    Node* root = createNode(arr[0]);
    int* ptrArr = arr;
    constructBST(root, ptrArr);
    printf("Current root is at %d\n", root->data);

    printf("Print BST InOrder:\n");
    printBSTInOrder(root);
    printf("\n");

    printf("Print BST PreOrder:\n");
    printBSTPreOrder(root);
    printf("\n");

    printf("Print BST PostOrder:\n");
    printBSTPostOrder(root);
    printf("\n");

    printf("Print BST Depth-First:\n");
    printBSTDepthFirst(root);
    printf("\n");

    printf("Print BST Breadth-First:\n");
    printBSTBreadthFirst(root);
    printf("\n");

    printf("Print Max Node:\n");
    Node* preMaxNode = NULL;
    printf("%d\n", getMaxNode(root, &preMaxNode)->data);

    printf("Print Min Node:\n");
    printf("%d\n", getMinNode(root)->data);

    int data = 1;
    deleteData(&root, data, &root);

    printf("Tree After Deleting %d:\n", data);
    printBSTBreadthFirst(root);
    printf("\n");

    Node* dataNode = getNode(root, 3);
    printf("Print SubTree Size:\n");
    printf("sizeof(int): %d\n", sizeof(int));
    printf("sizeof(Node*): %d\n", sizeof(Node*));
    printf("sizeof(Node): %d\n", sizeof(Node));
    printf("sizeof(dataNode): %d\n", sizeof(*dataNode));
    printf("sizeof(dataNode->left): %d\n", sizeof(*(dataNode->left)));
    printf("sizeof(dataNode->right): %d\n", sizeof(*(dataNode->right)));
    printf("%d\n", getSubTreeSize(dataNode, 0));

    return 0;
}

Node* createNode(int data) {
    Node* node;

    node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void insertIntoBST(Node* root, int data) {
    Node* ptr = root;

    printf("Currently at node %d\n", ptr->data);
    printf("Currently inserting %d\n", data);

    if (data >= ptr->data) {
        if (ptr->right != NULL) {
            printf("Traversing to right of %d\n", ptr->data);
            insertIntoBST(ptr->right, data);
        }

        else {
            ptr->right = createNode(data);
            printf("Inserting %d to right of %d\n", data, ptr->data);
        }
    }

    else if (data < ptr->data) {
        if (ptr->left != NULL) {
            printf("Traversing to left of %d\n", ptr->data);
            insertIntoBST(ptr->left, data);
        }

        else {
            ptr->left = createNode(data);
            printf("Inserting %d to left of %d\n", data, ptr->data);
        }
    }
}

void constructBST(Node* root, int arr[10]) {
    Node* ptr = root;
    ptr->data = arr[0];

    if (sizeof(arr)/sizeof(arr[0]) == 1) return;

    printf("sizeof(arr): %d\n", sizeof(arr)/sizeof(arr[0]));

    int i;
    for (i = 1; i != 10; ++i) {
        insertIntoBST(ptr, arr[i]);
    }
}

void printBSTInOrder(Node* root) {
    Node* ptr = root;

    if (ptr->left != NULL) {
        printBSTInOrder(ptr->left);
    }

    printf("%d ", ptr->data);

    if (ptr->right != NULL) {
        printBSTInOrder(ptr->right);
    }
}

void printBSTPostOrder(Node* root) {
    Node* ptr = root;

    if (ptr->left != NULL) {
        printBSTPostOrder(ptr->left);
    }

    if (ptr->right != NULL) {
        printBSTPostOrder(ptr->right);
    }

    printf("%d ", ptr->data);
}

void printBSTPreOrder(Node* root) {
    Node* ptr = root;

    printf("%d ", ptr->data);

    if (ptr->left != NULL) {
        printBSTPreOrder(ptr->left);
    }

    if (ptr->right != NULL) {
        printBSTPreOrder(ptr->right);
    }
}

void printBSTDepthFirst(Node* root) {
    Node* ptr = root;

    printf("%d ", ptr->data);

    if (ptr->left != NULL) {
        printBSTPreOrder(ptr->left);
    }

    if (ptr->right != NULL) {
        printBSTPreOrder(ptr->right);
    }
}

void printBSTBreadthFirst(Node* root) {
    Node* ptr = root;

    Node* nodeArr[100];
    int headIdx = 0;
    int tailIdx = 1;
    nodeArr[0] = ptr;

    while (tailIdx - headIdx > 0) {
        // Get the current Node in nodeArr
        Node* current = nodeArr[headIdx];
        printf("%d ", current->data);

        Node* left = current->left;
        Node* right = current->right;

        // Pop current Node
        if (left != NULL) {
            nodeArr[tailIdx++] = left;
        }

        if (right != NULL) {
            nodeArr[tailIdx++] = right;
        }

        ++headIdx;
    }
}

Node* getMaxNode(Node* root, Node** preMaxNode) {
    Node* ptr = root;

    if (ptr->right != NULL) {
        *preMaxNode = ptr;
        return getMaxNode(ptr->right, preMaxNode);
    }

    return ptr;
}

Node* getMinNode(Node* root) {
    Node* ptr = root;

    if (ptr->left != NULL) {
        return getMinNode(ptr->left);
    }

    return ptr;
}

Node* getNode(Node* root, int data) {
    if (data == root->data) {
        printf("Node data %d found!\n", data);
        return root;
    }

    if (data < root->data) {
        if (root->left != NULL) {
            return getNode(root->left, data);
        }

        else {
            return NULL;
        }
    }

    if (data > root->data) {
        if (root->right != NULL) {
            return getNode(root->right, data);
        }

        else {
            return NULL;
        }
    }

    return NULL;
}

// There are several cases for deleting a Node:
// - If a Node has at least one right child
//   - That means that the current Node can be swapped with its right-most child
// - If a Node has no right child but one left child
//   - That means that the current Node should now be the left child of the current
//     Node
// - If a Node has no child
//   - No need to rebuild since
//
// Since we always swap root with the right-most Node,
//

void deleteData(Node** root, int data, Node** current) {
    Node** ptr = current;

    if (data > (*ptr)->data) {
        if ((*ptr)->right != NULL) {
            deleteData(root, data, &((*ptr)->right));
        }
    }

    else if (data < (*ptr)->data) {
        if ((*ptr)->left != NULL) {
            deleteData(root, data, &((*ptr)->left));
        }
    }

    else {
        if ((*current)->right != NULL) {
            // This root is not really the original root but rather
            // the current root
            Node* preMaxNode = NULL;
            Node* maxNode = getMaxNode(*root, &preMaxNode);
            printf("maxNode->data: %d\n", maxNode->data);
            (*current)->data = maxNode->data;
            free(maxNode);
            preMaxNode->right = NULL;
            rebuildBST(*current, (*ptr)->data);
        }

        else {
            if ((*current)->left != NULL) {
                Node* temp = (*current)->left;
                free((*current));
                (*current) = temp;
            }

            else {
                free((*current));
                (*current) = NULL;
            }
        }

        /* printf("current->data: %d\n", current->data); */
    }
}

void rebuildBST(Node* root, int data) {
    Node* ptr = root;

    if (ptr->right != NULL) {
        if (ptr->right->data < ptr->data) {
            int temp = ptr->right->data;
            ptr->right->data = ptr->data;
            ptr->data = temp;
            rebuildBST(ptr->right, data);
        }
    }
}

int getSubTreeSize(Node* root, int size) {
    if (root->left != NULL) {
        size += getSubTreeSize(root->left, size);
    }

    if (root->right != NULL) {
        size += getSubTreeSize(root->right, size);
    }

    size += sizeof(*root);

    return size;
}

void balanceBST(Node* root) {

}

void deleteSubTree(Node* root) {

}

void deleteBST(Node* root) {

}
