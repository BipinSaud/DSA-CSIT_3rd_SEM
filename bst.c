#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct Node
{
    int data;           // Data stored in the node
    struct Node *left;  // Pointer to the left child node
    struct Node *right; // Pointer to the right child node
};

typedef struct Node TreeNode;

// Function to create a new node with the given data
TreeNode *create(int item)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode)); // Allocate memory for a new node
    node->data = item;                                     // Set the data of the new node to the given item
    node->left = node->right = NULL;                       // Initialize left and right pointers to NULL
    return node;                                           // Return the newly created node
}

// Function to perform preorder traversal of the tree
void preorder(TreeNode *root)
{
    if (root == NULL)
        return; // If the current node is NULL, return (base case)

    // Print the data of the current node
    printf("%d   ", root->data);

    // Recursively call preorder on the left subtree
    preorder(root->left);

    // Recursively call preorder on the right subtree
    preorder(root->right);
}

// Function to perform inorder traversal of the tree
void inorder(TreeNode *root)
{
    if (root == NULL)
        return; // If the current node is NULL, return (base case)

    // Recursively call inorder on the left subtree
    inorder(root->left);

    // Print the data of the current node
    printf("%d   ", root->data);

    // Recursively call inorder on the right subtree
    inorder(root->right);
}

// Function to perform postorder traversal of the tree
void postorder(TreeNode *root)
{
    if (root == NULL)
        return; // If the current node is NULL, return (base case)

    // Recursively call postorder on the left subtree
    postorder(root->left);

    // Recursively call postorder on the right subtree
    postorder(root->right);

    // Print the data of the current node
    printf("%d   ", root->data);
}

// Function to insert a new node into the binary search tree
TreeNode *insertion(TreeNode *root, int item)
{
    if (root == NULL)
        return create(item); // If the tree is empty, create a new node with the given item

    if (item < root->data)
        root->left = insertion(root->left, item); // Recursively insert into the left subtree
    else
        root->right = insertion(root->right, item); // Recursively insert into the right subtree

    return root; // Return the modified tree
}

// Function to find the minimum value node in a binary search tree
TreeNode *findMinimum(TreeNode *cur)
{
    while (cur->left != NULL)
    {
        cur = cur->left; // Traverse the tree to the left until the leftmost node is reached
    }
    return cur; // Return the leftmost node (minimum value node)
}

// Function to delete a node with the given data from the binary search tree
TreeNode *deletion(TreeNode *root, int item)
{
    if (root == NULL)
        return root; // If the tree is empty or the node is not found, return the root as is

    if (item < root->data)
        root->left = deletion(root->left, item); // Recursively delete from the left subtree
    else if (item > root->data)
        root->right = deletion(root->right, item); // Recursively delete from the right subtree
    else
    {
        // Case 1: Node with only one child or no child
        if (root->left == NULL)
        {
            TreeNode *temp = root->right; // Store the right child in a temporary variable
            free(root);                   // Free the memory of the current node
            return temp;                  // Return the right child as the new root
        }
        else if (root->right == NULL)
        {
            TreeNode *temp = root->left; // Store the left child in a temporary variable
            free(root);                  // Free the memory of the current node
            return temp;                 // Return the left child as the new root
        }
        // Case 2: Node with two children
        TreeNode *temp = findMinimum(root->right);       // Find the minimum value node in the right subtree
        root->data = temp->data;                         // Copy the data from the minimum node to the current node
        root->right = deletion(root->right, temp->data); // Recursively delete the minimum node
    }
    return root; // Return the modified tree
}

// Function to search for a node with the given data in the binary search tree
TreeNode *search(TreeNode *root, int item)
{
    if (root == NULL || root->data == item)
        return root; // If the current node is NULL or contains the target data, return the current node

    if (root->data < item)
        return search(root->right, item); // Recursively search in the right subtree
    return search(root->left, item);      // Recursively search in the left subtree
}

// Function to print the binary tree in a 2D format
// this is a simple version of the function that does not print the missing children

// void print2D(TreeNode *root, int level)
// {
//     if (root == NULL) // Base case
//         return;
//     for (int i = 0; i < level; i++)             // Process right child first
//         printf(i == level - 1 ? "|-- " : "  "); // Print vertical bars for root and right subtree

//     printf("%d \n", root->data);     // Print data of current node
//     print2D(root->right, level + 2); // Process right child
//     print2D(root->left, level + 2);  // Process left child
// }

// Function to print the binary tree in a 2D format with missing children
void print2D(TreeNode *root, int level)
{
    if (root == NULL) // Base case
    {
        // Print an empty edge to indicate a missing child
        for (int i = 0; i < level; i++)
            printf(i == level - 1 ? "|-- " : "  ");
        printf("<Missing>\n");
        return;
    }

    // Print the current node's data
    for (int i = 0; i < level; i++)
        printf(i == level - 1 ? "|-- " : "  ");
    printf("%d \n", root->data);

    // Recursively process right and left children
    if (root->right == NULL && root->left == NULL)
        return;
    print2D(root->right, level + 2);
    print2D(root->left, level + 2);
}

int main()
{
    TreeNode *root = NULL;
    int choice, item;

    while (1)
    {
        printf("\n1. Insertion\n2. Deletion\n3. Search\n4. Preorder Traversal\n5. Inorder Traversal\n6. Postorder Traversal\n7. Print Tree\n8. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the item to be inserted: ");
            scanf("%d", &item);
            root = insertion(root, item); // Insert the item into the tree
            break;
        case 2:
            printf("\nEnter the item to be deleted: ");
            scanf("%d", &item);
            root = deletion(root, item); // Delete the node with the specified item
            break;
        case 3:
            printf("\nEnter the item to be searched: ");
            scanf("%d", &item);
            if (search(root, item) != NULL)
                printf("\n%d is present in the tree\n", item); // Search for and report the presence of the item
            else
                printf("\n%d is not present in the tree\n", item);
            break;
        case 4:
            printf("\nPreorder Traversal: ");
            preorder(root); // Print the tree in preorder
            break;
        case 5:
            printf("\nInorder Traversal: ");
            inorder(root); // Print the tree in inorder
            break;
        case 6:
            printf("\nPostorder Traversal: ");
            postorder(root); // Print the tree in postorder
            break;
        case 7:
            printf("\nTree in 2D format:\n");
            print2D(root, 0); // Print the tree in 2D format
            break;
        case 8:
            exit(0); // Exit the program
        default:
            printf("\nInvalid choice\n");
        }

        if (choice != 7)
            print2D(root, 0); // Print the tree in 2D format after every operation
    }
    return 0;
}
