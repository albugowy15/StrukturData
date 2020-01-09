/*
-- Created by Bayu Laksana on 9 January 2019
-- Implemented for C++ (Data Structure 2020)
----------------------------------------------
*/

#include <stdlib.h>

/* Structure of Queue using List */

template <typename T=int>
struct Queue
{
    // Node Structure
    struct QueueNode {
        T data;
        QueueNode *next;
    } *_front, *_rear;
    unsigned _size;

    Queue()
    {
        _size  = 0;
        _front = NULL;
        _rear  = NULL;
    }

    bool isEmpty() {
        return (_front == NULL && _rear == NULL);
    }

    void push(T value)
    {
        QueueNode *newNode =\
            (QueueNode*) malloc(sizeof(QueueNode));
        if (newNode) {
            _size++;
            newNode->data = value;
            newNode->next = NULL;
            
            if (isEmpty())                 
                _front = _rear = newNode;
            else {
                _rear->next = newNode;
                _rear = newNode;
            }
        }
    }

    void pop()
    {
        if (!isEmpty()) {
            QueueNode *temp = _front;
            _front = _front->next;
            free(temp);
            
            if (_front == NULL)
                _rear = NULL;
            _size--;
        }
    }

    T front()
    {
        if (!isEmpty())
            return _front->data;
        exit(-1);
    }

    unsigned size() {
        return _size;
    }
};