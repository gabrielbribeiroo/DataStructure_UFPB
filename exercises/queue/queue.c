/*
Consider the existence of an abstract type Queue of real numbers, whose interface is defined in the file queue.h as follows:

typedef struct queue Queue;
Queue* create_queue(void);
void insert_queue(Queue* q, float v);
float remove_queue(Queue* q);
int queue_empty(Queue* q);
void clear_empty(Queue* q);

Without knowing the internal representation of this abstract type and using only the functions declared in the interface file, implement a function that receives three queues, fores, f1 and f2, and alternately transfers the elements of f1 and f2 to fores.
Note that, at the end of this function, queues f1 and f2 will be empty, and queue f_res will contain all the values ​​originally in f1 and f2 (initially f_res may or may not be empty). 
This function must obey the prototype:
void combines_queues(Queue* q_res, Queue* q1, Queue* q2);
*/

#include "queue.h" // include the queue header file

typedef struct queue {
    int n; // number of elements in the queue
    int start; // index of the first element in the queue
    float data[SIZE]; // data stored in the queue
} Queue;

Queue *create_queue() {
    Queue *q = (Queue *)malloc(sizeof(Queue)); // allocates memory for the queue
    q->n = 0; // initializes the number of elements in the queue
    q->start = 0; // initializes the index of the first element in the queue
    return q; // returns a pointer to the queue
}

int queue_empty(Queue *q) {
    return q->n == 0; // returns 1 if the queue is empty, 0 otherwise
}

void insert_queue(Queue *q, float x) {
    q->data[(q->start + q->n) % SIZE] = x; // inserts the element x at the end of the queue
    q->n++; // increments the number of elements in the queue
}

float remove_queue(Queue *q) {
    if (queue_empty(q)) {
        printf("Queue underflow! Cannot remove element.\n");
        exit(1); 
    }
 
    float value = q->data[q->start]; // store the value to return
    q->start++; // move the start index forward
    q->n--; // decrease the number of elements

    // Reset the queue if it becomes empty
    if (q->n == 0) {
        q->start = 0;
    }

    return value;
}

void clear_queue(Queue *q) {
    // clear the entire queue
    while (!queue_empty(q)) {
        remove_queue(q);
    }
    free(q);
}

void combines_queues(Queue *q_res, Queue *q1, Queue *q2) {
    while (!queue_empty(q1) || !queue_empty(q2)) {
        if (!queue_empty(q1)) {
            insert_queue(q_res, remove_queue(q1));
        }
        if (!queue_empty(q2)) {
            insert_queue(q_res, remove_queue(q2));
        }
    }
}

int main() {
    Queue* q1 = create_queue();
    Queue* q2 = create_queue();
    Queue* q_res = create_queue();

    insert_queue(q1, 2.1);
    insert_queue(q1, 4.5);
    insert_queue(q1, 1.0);

    insert_queue(q2, 7.2);
    insert_queue(q2, 3.1);
    insert_queue(q2, 9.8);

    printf("Combining queues...\n");
    combines_queues(q_res, q1, q2);

    // print the combined queue
    while (!queue_empty(q_res)) {
        printf("%.1f ", remove_queue(q_res));
    }
    printf("\n");

    // clean up memory
    clear_queue(q_res);
    clear_queue(q1);
    clear_queue(q2);

    return 0;
}