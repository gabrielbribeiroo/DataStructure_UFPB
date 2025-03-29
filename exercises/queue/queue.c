#include <stdio.h>
#include <stdlib.h>

#define SIZE 3 // Define the size of the queues

// Definition of the queue structure
typedef struct queue {
    int n;      // Number of elements in the queue
    int start;  // Index of the first element in the queue
    int size;   // Total capacity of the queue
    float *data; // Dynamic array to store the data
} Queue;

// Function to create a queue
Queue *create_queue(void) {
    Queue *q = (Queue *)malloc(sizeof(Queue)); // Allocate memory for the queue
    q->n = 0;  // Initialize the number of elements in the queue
    q->start = 0;  // Initialize the index of the first element
    q->size = SIZE;  // Set the queue size
    q->data = (float *)malloc(q->size * sizeof(float)); // Allocate memory for the data array
    return q;
}

// Function to check if the queue is empty
int queue_empty(Queue *q) {
    return q->n == 0;  // Return 1 if the queue is empty, 0 otherwise
}

// Function to insert an element into the queue
void insert_queue(Queue *q, float x) {
    if (q->n == q->size) {  // If the queue is full
        printf("Queue overflow! Cannot insert element.\n");
        exit(1);  // Exit the program on overflow
    }
    q->data[(q->start + q->n) % q->size] = x;  // Insert the element at the end of the queue
    q->n++;  // Increment the number of elements
}

// Function to remove an element from the queue
float remove_queue(Queue *q) {
    if (queue_empty(q)) {  // If the queue is empty
        printf("Queue underflow! Cannot remove element.\n");
        exit(1);  // Exit the program on underflow
    }
    float value = q->data[q->start];  // Store the value to return
    q->start = (q->start + 1) % q->size;  // Move the start index forward
    q->n--;  // Decrease the number of elements
    return value;
}

// Function to clear the queue and free the allocated memory
void clear_queue(Queue *q) {
    free(q->data);  // Free the memory allocated for the data array
    free(q);  // Free the queue structure
}

// Function to copy the elements of one queue into another
Queue *copy_queue(Queue *q) {
    Queue *new_q = create_queue();  // Create a new queue
    for (int i = 0; i < q->n; i++) {  // Iterate over the elements in the original queue
        insert_queue(new_q, q->data[(q->start + i) % q->size]); // Copy each element
    }
    return new_q; // Return the new queue
}

// Function to combine two queues (q1 and q2) alternately into q_res
void combines_queues(Queue *q_res, Queue *q1, Queue *q2) {
    while (!queue_empty(q1) || !queue_empty(q2)) {  // While either queue is not empty
        if (!queue_empty(q1)) {  // If q1 is not empty
            insert_queue(q_res, remove_queue(q1));  // Remove from q1 and insert into q_res
        }
        if (!queue_empty(q2)) {  // If q2 is not empty
            insert_queue(q_res, remove_queue(q2));  // Remove from q2 and insert into q_res
        }
    }
}

// Function to print the elements of a queue without modifying it
void print_queue(Queue *q) {
    printf("Queue elements: ");
    for (int i = 0; i < q->n; i++) {
        printf("%.1f ", q->data[(q->start + i) % q->size]);
    }
    printf("\n");
}

// Main function
int main() {
    // Create the original queue
    Queue* q1 = create_queue();
    
    // Insert elements into q1
    insert_queue(q1, 5.2);
    insert_queue(q1, 3.6);
    insert_queue(q1, 8.9);

    // Print original queue
    printf("Original queue (q1): ");
    print_queue(q1);

    // Copy q1 into q2
    Queue* q2 = copy_queue(q1);
    printf("Copied queue (q2): ");
    print_queue(q2);

    // Free memory of the queues
    clear_queue(q1);
    clear_queue(q2);

    return 0;
}