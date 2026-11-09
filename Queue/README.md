QUEUE

A Queue is a linear data structure that follows the FIFO (First In First Out) principle.

The element inserted first will be deleted first.

A queue has two main pointers:

1. FRONT – Points to the first element.
2. REAR – Points to the last element.

---

FEATURES

- Follows FIFO principle.
- Insertion takes place at REAR.
- Deletion takes place at FRONT.
- Can be implemented using arrays and linked lists.

---

1. SIMPLE QUEUE

A Simple Queue is a linear data structure in which insertion takes place from the REAR and deletion takes place from the FRONT.

FRONT| 10| 20| 30| REAR

Operations

1. Enqueue (Insertion)
2. Dequeue (Deletion)
3. Display

---

2. CIRCULAR QUEUE

A Circular Queue is a linear data structure in which the last position is connected to the first position.

It follows the FIFO principle and uses memory efficiently.

Operations

1. Enqueue (Insertion)
2. Dequeue (Deletion)
3. Display

Formula

- REAR = (REAR + 1) % SIZE
- FRONT = (FRONT + 1) % SIZE

---

3. DEQUE (DOUBLE ENDED QUEUE)

A Deque is a special type of queue in which insertion and deletion can take place from both ends.

Operations

1. Insert at Front
2. Insert at Rear
3. Delete from Front
4. Delete from Rear
5. Display

---

NOTES

- Queue follows FIFO (First In First Out).
- Insertion is called Enqueue.
- Deletion is called Dequeue.
- FRONT indicates the first element.
- REAR indicates the last element.
- Queue can be implemented using arrays and linked lists.

---
