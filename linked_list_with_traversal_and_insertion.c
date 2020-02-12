// A simple C program to introduce
// a linked list
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

//A linked list node
struct Node {
    int data;
    struct Node* next;
};

//traverse a linked list and print its elements
void printList(struct Node* n)
{
    while(n !=NULL)
    {
        printf(" %d ", n->data);
        n= n->next;
    }
}

/* Given a reference (pointer to pointer) to the head of a list
   and an int,  inserts a new node on the front of the list. */
void add_first(struct Node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    /* 2. put in the data of the new node  */
    new_node->data  = new_data;

    /* 3. Make next of new node is the head of the previous node */
    new_node->next = (*head_ref);

    /* 4. move the head to point to the new node */
    (*head_ref)    = new_node;
}

/* Given a node prev_node, insert a new node after the given
   prev_node */
void insertAfter(struct Node* prev_node, int new_data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }

    /* 2. allocate new node */
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));

    /* 3. put in the data in the new node */
    new_node->data  = new_data;

    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;

    /* 5. move the next of prev_node to point to new_node */
    prev_node->next = new_node;
}

// Program to create a simple linked
// list with 3 nodes
int main()
{
    //Create 3 pointer to nodes and initialize them by Null
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // allocate 3 nodes in the heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    /* Three blocks have been allocated dynamically.
    We have pointers to these three blocks as head,
    second and third
    head		 second		 third
        |			 |			 |
        |			 |			 |
    +---+-----+	 +----+----+	 +----+----+
    | # | # |	 | # | # |	 | # | # |
    +---+-----+	 +----+----+	 +----+----+

# represents any random value.
Data is random because we haven’t assigned anything yet */

    head->data = 1; // assign data in first node
    head->next = second; // Link first node with
    // the second node

    /* data has been assigned to the data part of the first
    block (block pointed by the head). And next
    pointer of first block points to second.
    So they both are linked.

    head		 second		 third
        |			 |			 |
        |			 |			 |
    +---+---+	 +----+----+	 +-----+----+
    | 1 | o----->| # | # |	 | # | # |
    +---+---+	 +----+----+	 +-----+----+
    */


    second->data = 2;// assign data to second node
    // Link second node with the third node
    second->next = third;

    /* data has been assigned to the data part of the second
    block (block pointed by second). And next
    pointer of the second block points to the third
    block. So all three blocks are linked.

    head		 second		 third
        |			 |			 |
        |			 |			 |
    +---+---+	 +---+---+	 +----+----+
    | 1 | o----->| 2 | o-----> | # | # |
    +---+---+	 +---+---+	 +----+----+	 */

    third->data = 3; // assign data to third node
    third->next = NULL; //indicate the linked list
    //is terminated

    /* data has been assigned to data part of third
    block (block pointed by third). And next pointer
    of the third block is made NULL to indicate
    that the linked list is terminated here.

    We have the linked list ready.

        head
            |
            |
        +---+---+	 +---+---+	 +----+------+
        | 1 | o----->| 2 | o-----> | 3 | NULL |
        +---+---+	 +---+---+	 +----+------+


    Note that only head is sufficient to represent
    the whole list. We can traverse the complete
    list by following next pointers. */
    //printList(head);
    add_first(&head ,5);
    insertAfter(second,7);
    printList(head);
    return 0;
}
