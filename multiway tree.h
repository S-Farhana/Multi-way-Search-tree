#ifndef MULTIWAY_TREE_H_INCLUDED
#define MULTIWAY_TREE_H_INCLUDED
#define M 4
#define MIN_KEYS (M / 2) // Assuming 'm' is the order of the m-way tree


struct node
{
    int num_keys;
    int keys[M-1];
    struct node *children[M];
};
#endif // MULTIWAY_TREE_H_INCLUDED
