#include <stdio.h>
#include <stdlib.h>
#include "multiway tree.h"
int main()
{
    int choice,x,searched;
    char further;
    struct node *ptr=NULL;
    printf("\n----------------------------------------------MULTIWAY - SEARCH TREE--------------------------------------------------\n");
    while(1)
    {
        printf("             Operations            \n");
        printf("1.Insertion\n2.Deletion\n3.Search\n4.Display ( In-Order Traversal )");
        printf("\nEnter your choice\t:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\n.......Insetion.......\n");
            printf("Enter the value to insert in the tree\t:");
            scanf("%d",&x);
            ptr=insert(ptr,x);
            break;
        case 2:
            printf("\n.......Deletion.......\n");
            printf("Enter the value to delete from the tree\t:");
            scanf("%d",&x);
            ptr=deleteValue(ptr,x);
            break;
        case 3:
            printf("\n.........Search.........\n");
            printf("Enter the value to search an element from the tree\t:");
            scanf("%d",&x);
            searched=search(ptr,x);
            if(searched==x)
            {
                printf("\nThe Searched element is found in the Tree\n");
            }
            else
            {
                printf("\nThe Searched is not found in the Tree\n");
            }
            break;
        case 4:
            printf("\n.......Display ( In-Order Traversal ).......\n");
            inorderTraversal(ptr);
            break;
        }
        printf("\nDo You want further operations ( If yes Enter 'y' or 'Y')\t:");
        scanf(" %c",&further);
        if(further!='y' && further!='Y')
        {
            break;
        }
    }
    printf("         ===========             *****          ==========");
    return 0;
}
