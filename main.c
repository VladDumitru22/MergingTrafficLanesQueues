#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char *licencePlate;
    struct Node* next;
} Node;

Node* createNode() {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation ERROR\n");
        return NULL;
    }
    newNode->licencePlate = malloc(sizeof(char) * 20); // Allocating more space to avoid issues
    printf("Enter the vehicle's license plate number: ");
    scanf("%s", newNode->licencePlate);
    newNode->next = NULL;
    return newNode;
}

Node* enqueue(Node* head) {
    Node* ptr = head;
    Node* newNode = createNode();

    if (ptr == NULL) {
        return newNode;
    }

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = newNode;
    return head;
}

void display(Node* head) {
    Node* ptr = head;
    printf("\nVehicle order in the lane:\n");
    while (ptr != NULL) {
        printf("- %s\n", ptr->licencePlate);
        ptr = ptr->next;
    }
}

Node* combineQueue(Node* head1, Node* head2) {
    Node* ptr1 = head1;
    Node* ptr2 = head2;

    printf("\nFinal vehicle order after merging both lanes:\n");
    while (ptr1 != NULL && ptr2 != NULL) {
        printf("- %s (Lane 2)\n", ptr2->licencePlate);
        printf("- %s (Lane 1)\n", ptr1->licencePlate);
        ptr2 = ptr2->next;
        ptr1 = ptr1->next;
    }

    while (ptr1 != NULL) {
        printf("- %s (Lane 1)\n", ptr1->licencePlate);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL) {
        printf("- %s (Lane 2)\n", ptr2->licencePlate);
        ptr2 = ptr2->next;
    }
}

int main() {

    int m, n;
    Node* queue1 = NULL;
    Node* queue2 = NULL;

    printf("Enter the number of vehicles in Lane 1: ");
    scanf("%d", &m);
    printf("Enter the number of vehicles in Lane 2: ");
    scanf("%d", &n);

    printf("\nEnter the license plates for the vehicles in Lane 1:\n");
    for (int i = 0; i < m; i++) {
        queue1 = enqueue(queue1);
    }

    printf("\nEnter the license plates for the vehicles in Lane 2:\n");
    for (int i = 0; i < n; i++) {
        queue2 = enqueue(queue2);
    }

    combineQueue(queue1, queue2);

    return 0;
}
