#include <stdio.h>
#include <stdlib.h>

/**
 * Node struct for linked list
 */
typedef struct
{
    int value;
    void *next;
} Node;


Node *head = NULL; /*< Global head pointer as start of linked list  item0 (head) -> item1 -> item2 -> intemN... */ 

/**
 * Insert a value at the end of linked list
 */
Node *insert(int value)
{
    // Allocate space for a new node
    Node *new = malloc(sizeof(Node));

    // If head is NULL list is empty
    if (head == NULL)
    {
        // New node becomes head
        head = new;
        head->value = value;
        head->next = NULL;
    }
    else
    {
        // Temporary pointer to iterate
        Node *node = head;

        // Find next NULL in linked list
        while (node->next != NULL)
        {
            node = node->next;
        }

        // Assign new to next
        node->next = new;

        // Update temporary pointer to new and assign value
        node = node->next;
        node->value = value;
        node->next = NULL;
    }
}

/**
 * Print all values of linked list
 */
void print_list()
{
    // If head is NULL list is empty
    if (head == NULL)
    {
        printf("Empty list\n");
        return;
    }

    // Assign head to temporary Node pointer
    Node *node = head;
    do
    {
        // Print its value
        printf("%d->", node->value);

        // Move to next
        node = node->next;

    } while (node != NULL); // Until node is NULL (end of list)

    // New line
    printf("\n");
}

/**
 * Inser a value in specifi position (base 0 index)
 * being 0 the head of linked list
 */
void insert_into(int value, unsigned int index)
{
    // If list empty and index is greater than zero
    // illegal operation
    if (head == NULL && index > 0)
    {
        printf("Can't insert further index 0 on empty list\n");
        return;
    }

    // Index variable for loop
    unsigned int i = 0;

    // Initialize current node pointer with head
    Node *current_node = head;

    // Initiliaze previous node pointer with NULL
    Node *previous_node = NULL;

    // Iterate tracking previous node
    // TODO: pointer math maybe?
    for (i = 0; i < index; i++)
    {
        previous_node = current_node;
        
        if(current_node != NULL)
        {
            current_node = current_node->next;
        }
        else {
            break;
        }
    }

    if(current_node == NULL && previous_node == NULL)
    {
        printf("Index out of bounds (%d)\n", index);
        return;
    }

    // Memory allocation for new node
    Node *new = malloc(sizeof(Node));

    // Initialize new value
    new->value = value;

    // Previous_node is NULL only for empty list
    // TODO: test this
    if (previous_node == NULL)
    {
        // Next is current node regardless
        new->next = current_node;

        // Head becomes new pointer
        head = new;
    }
    else
    {
        printf("3");

        // Next is current node
        new->next = current_node;
        
        // New takes position of current node
        previous_node->next = new;
    }
}

/**
 * Removes an item from specific position (base 0 index)
 * 
 */
void remove_from(unsigned int index)
{
    // Removing from empty linked list is illegal
    if (head == NULL && index > 0)
    {
        printf("Can't remove from empty list\n");
        return;
    }

    // Index to iterate nodes
    unsigned int i = 0;

    // Current node
    Node *current_node = head;

    // Previous node
    Node *previous_node = NULL;

    // If next node is NULL and index is greater
    // than zero then no item in such index
    if(current_node->next == NULL && index > 0)
    {
        printf("Exceeded list size\n");
        return;
    }

    for (i = 0; i < index; i++)
    {
        previous_node = current_node;
        current_node = current_node->next;
    }

    // Previous node should be NULL
    // only on single item list
    if (previous_node == NULL)
    {
        // Remove head
        head = current_node->next;
    }
    else
    {
        // Bypass current node in list
        previous_node->next = current_node->next;
    }

    // Free memory of node
    free(current_node);
}

/**
 * Entry point to handle user interaction
 */
int main(int argc, char **argv)
{
    int option = 0;
    while (option < 5)
    {
        printf("Select an action:\n");
        printf("\t1. Insert\n");
        printf("\t2. Remove\n");
        printf("\t3. Print\n");
        printf("\t4. Insert into\n");
        printf("\t5. Quit\n");

        scanf("%d", &option);
        switch (option)
        {
        case 1:
        { // Insert
            int value = 0;
            printf("Type value to insert: ");
            scanf("%d", &value);
            insert(value);
            break;
        }
        case 2:
        { // Remove
            int value = 0;
            unsigned int index = 0;

            printf("Index to remove: ");
            scanf("%d", &index);

            remove_from(index);
            break;
        }
        case 3:
        { // Print
            print_list();
            break;
        }
        case 4:
        { // Insert into
            int value = 0;
            unsigned int index = 0;
            printf("Type value to insert: ");
            scanf("%d", &value);

            printf("Index to insert: ");
            scanf("%d", &index);

            insert_into(value, index);

            break;
        }
        default:
            break;
        }
    }
}