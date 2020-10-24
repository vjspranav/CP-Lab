/ C program to merge a linked list into another at 
// alternate positions 
// merge two sorted lists to make a thrid sorted list
// delete a given node from the linked list 
// link list sorted through bubble sort
// reversing a linked list without recursion 
#include <stdio.h> 
#include <stdlib.h> 
#include<assert.h>
  

struct Node 
{ 
    int data; 
    struct Node *next; 
}; 
  
/* Function to insert a node at the beginning */
void push(struct Node ** head_ref, int new_data) 
{ 
    struct Node* new_node =  
           (struct Node*) malloc(sizeof(struct Node)); 
    new_node->data  = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref)  = new_node; 
} 
  
// helper function to print a singly linked list 
void printList(struct Node *head) 
{ 
    struct Node *temp = head; 
    while (temp != NULL) 
    { 
        printf("%d ", temp->data); 
        temp = temp->next; 
    } 
    printf("\n"); 
} 
  
// Main function that inserts nodes of linked list q into p at  
// alternate positions. Since head of first list never changes  
// and head of second list  may change, we need single pointer 
// for first list and double pointer for second list. 
void merge(struct Node *p, struct Node **q) 
{ 
     struct Node *p_curr = p, *q_curr = *q; 
     struct Node *p_next, *q_next; 
  
     // While therre are avialable positions in p 
     while (p_curr != NULL && q_curr != NULL) 
     { 
         // Save next pointers 
         p_next = p_curr->next; 
         q_next = q_curr->next; 
  
         // Make q_curr as next of p_curr 
         q_curr->next = p_next;  // Change next pointer of q_curr 
         p_curr->next = q_curr;  // Change next pointer of p_curr 
  
         // Update current pointers for next iteration 
         p_curr = p_next; 
         q_curr = q_next; 
    } 
  
    *q = q_curr; // Update head pointer of second list 
} 
  
// Driver program to test above functions 
void MoveNode(struct Node** destRef, struct Node** sourceRef); 
  
/* Takes two lists sorted in increasing order, and splices 
   their nodes together to make one big sorted list which 
   is returned.  */
struct Node* SortedMerge(struct Node* a, struct Node* b) 
{ 
    /* a dummy first node to hang the result on */
    struct Node dummy; 
  
    /* tail points to the last result node  */
    struct Node* tail = &dummy; 
  
    /* so tail->next is the place to add new nodes 
      to the result. */
    dummy.next = NULL; 
    while (1) 
    { 
        if (a == NULL) 
        { 
            /* if either list runs out, use the 
               other list */
            tail->next = b; 
            break; 
        } 
        else if (b == NULL) 
        { 
            tail->next = a; 
            break; 
        } 
        if (a->data <= b->data) 
            MoveNode(&(tail->next), &a); 
        else
            MoveNode(&(tail->next), &b); 
  
        tail = tail->next; 
    } 
    return(dummy.next); 
} 
  
/* MoveNode() function takes the node from the front of the 
   source, and move it to the front of the dest. 
   It is an error to call this with the source list empty. 
   */
void MoveNode(struct Node** destRef, struct Node** sourceRef) 
{ 
  
    struct Node* newNode = *sourceRef; 
    assert(newNode != NULL); 
  
    
    *sourceRef = newNode->next; 
  
    newNode->next = *destRef; 
  
    /* Move dest to point to the new node */
    *destRef = newNode; 
} 
  
  
// function to delete a node from a given linked list
void deleteNode(struct Node **head_ref, int key) 
{ 
    // Store head node 
    struct Node* temp = *head_ref, *prev; 
  
    // If head node itself holds the key to be deleted 
    if (temp != NULL && temp->data == key) 
    { 
        *head_ref = temp->next;   // Changed head 
        free(temp);               // free old head 
        return; 
    } 
  
    // Search for the key to be deleted, keep track of the 
    // previous node as we need to change 'prev->next' 
    while (temp != NULL && temp->data != key) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
  
    // If key was not present in linked list 
    if (temp == NULL) return; 
  
    // Unlink the node from linked list 
    prev->next = temp->next; 
  
    free(temp);  // Free memory 
} 
// insertion at beginning 
void insertAtTheBegin(struct Node **start_ref, int data) 
{ 
    struct Node *ptr1 = (struct Node*)malloc(sizeof(struct Node)); 
    ptr1->data = data; 
    ptr1->next = *start_ref; 
    *start_ref = ptr1; 
} 
  
// swap the values of two nodes
void swap(struct Node *a, struct Node *b) 
{ 
    int temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
} 
  
// bubble sort for a linked list 
void bubbleSort(struct Node *start) 
{ 
    int swapped, i; 
    struct Node *ptr1; 
    struct Node *lptr = NULL; 
  
    // checking for empty list 
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->data > ptr1->next->data) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 
  




  
/* Drier program to test above functions*/
int main() 
{ 
     struct Node *p = NULL, *q = NULL; 
     push(&p, 3); 
     push(&p, 2); 
     push(&p, 1); 
     printf("First Linked List:\n"); 
     printList(p); 
  
     push(&q, 8); 
     push(&q, 70); 
     push(&q, 26); 
     push(&q, 51); 
     push(&q, 24); 
     printf("Second Linked List:\n"); 
     printList(q); 
   // bubbleSort(q);
    merge(p, &q); 
        //merged list
     printf("Modified First Linked List:\n"); 
     printList(p); 
        //extra list
     printf("Modified Second Linked List:\n"); 
     printList(q); 
  //code for testing merging of sorted linked lists  
  /*  struct Node* res = NULL; 
    struct Node* a = NULL; 
    struct Node* b = NULL;
    push(&a, 5); 
    push(&a, 3); 
    push(&a, 1); 
  
    push(&b, 27); 
    push(&b, 13); 
    push(&b, 2); 
  
   res = SortedMerge(a, b); 
  
   printf("Merged Linked List is: \n"); 
   printList(res); */
     getchar(); 
     return 0; 
}
