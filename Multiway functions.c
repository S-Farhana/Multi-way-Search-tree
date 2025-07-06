#include "multiway tree.h"
#include <stdio.h>
// Helper function to find the index of a key in a node

// Function to create a new node
struct node* createNode(int x)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }
    newNode->num_keys = 1;
    newNode->keys[0] = x;
    for (int i = 0; i < M; i++)
    {
        newNode->children[i] = NULL;
    }
    return newNode;
}
// Helper function to delete a key from a leaf node
void deleteKeyFromLeaf(struct node *leaf, int index)
{
    for (int i = index; i < leaf->num_keys - 1; i++)
    {
        leaf->keys[i] = leaf->keys[i+1];
    }
    leaf->num_keys--;
}


//this function to find the index of a key in a node
int findKeyIndex(struct node *root, int x)
{
    int i;
    for (i = 0; i < root->num_keys; i++)
    {
        if (root->keys[i] == x)
        {
            return i;
        }
        else if (root->keys[i] > x)
        {
            break; // Value cannot be in keys after this position
        }
    }
    return -1; // Key not found
}
// Helper function to delete a key from a leaf node


// Function to recursively delete a key from the m-way tree
struct node* deleteValue(struct node *root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }

    // Find the index of the key in the current node
    int keyIndex = findKeyIndex(root, x);

    // If the key is found in the current node
    if (keyIndex != -1)
    {
        // Case: Key is in a leaf node
        if (root->children[0] == NULL)
        {
    // Delete the key from the leaf node
            deleteKeyFromLeaf(root, keyIndex);

    // Adjust the num_keys count
            root->num_keys--;

    return root;
}

        // Case: Key is in an internal node
        else
        {
            // Find the predecessor key in the left subtree
            struct node *predNode = root->children[keyIndex];
            while (predNode->children[predNode->num_keys] != NULL)
            {
                predNode = predNode->children[predNode->num_keys];
            }
            int predKey = predNode->keys[predNode->num_keys - 1];

            // Replace the key with its predecessor
            root->keys[keyIndex] = predKey;

            // Recursively delete the predecessor key from the left subtree
            root->children[keyIndex] = deleteValue(root->children[keyIndex], predKey);

            return root;
        }
    }

    // If the key is not found in the current node, recursively search in the appropriate child
    int childIndex;
    for (childIndex = 0; childIndex < root->num_keys; childIndex++)
    {
        if (x < root->keys[childIndex])
        {
            break;
        }
    }
    root->children[childIndex] = deleteValue(root->children[childIndex], x);
    return root;
}

// Function to insert a key into the m-way tree
struct node* insert(struct node *root, int x)
{
    if (root == NULL)
    {
        return createNode(x);
    }
    // Find the child index to insert the key
    int childIndex = 0;
    while (childIndex < root->num_keys && x > root->keys[childIndex])
    {
        childIndex++;
    }
    // Recursively insert into the appropriate child
    root->children[childIndex] = insert(root->children[childIndex], x);
    return root;
}

// Function to print the m-way tree in in-order traversal
void inorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        int i;
        for (i = 0; i < root->num_keys; i++)
        {
            inorderTraversal(root->children[i]);
            printf("%d ", root->keys[i]);
        }
        inorderTraversal(root->children[i]);
    }
}
// Function to search for a key in the m-way tree
int search(struct node *root, int x) {
    if (root == NULL) {
        return 0; // Key not found
    }

    // Find the index where the key could be located
    int i;
    for (i = 0; i < root->num_keys; i++) {
        if (root->keys[i] == x) {
            return 1; // Key found
        } else if (root->keys[i] > x) {
            break; // Value cannot be in keys after this position
        }
    }

    // Recursively search in the appropriate child
    if (i < root->num_keys && root->children[i] != NULL) {
        return search(root->children[i], x);
    } else {
        return 0; // Key not found
    }
}
