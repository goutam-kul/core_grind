#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;          // Data: Integer value stored in the node 
    struct Node *next;  // Pointer to the next node 
} Node;

// Function to create a new node
Node *create_node(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory allocation failed\n");
    }
    node->value = value;
    node->next = NULL;
    return node;
}

// Function to print the linked list 
void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("Node %d-> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the linked list 
void free_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *tmp = current;
        current = current->next;
        free(tmp);
    }
}

int main() {
    // Create a linked list 10 -> 20 -> 30 -> NULL
    Node *head = create_node(10);
    head->next = create_node(20);
    head->next->next = create_node(30);
    
    // print list 
    printf("Linked List: ");
    print_list(head);

    free_list(head);
    return 0;
}