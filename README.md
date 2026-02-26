MyQueueArr Project - C++ Dynamic Array Queue

Overview

An efficient C++ implementation of a Queue data structure built on a custom dynamic array. This project demonstrates how to implement queue operations using array-based memory management with automatic resizing capabilities.

Features

Dynamic Array Foundation: Self-resizing array that grows and shrinks as needed

Complete Queue Interface: Full FIFO (First-In-First-Out) implementation

Generic Type Support: Template-based design works with any data type

Memory Efficient: Manual memory management with proper allocation/deallocation

Architecture
clsDynamicArray<T>: Core dynamic array with automatic resizing and comprehensive array operations

clsMyQueueArr<T>: Queue wrapper providing intuitive queue interface


Core Operations

push: Add element to the back of queue

pop: Remove element from the front of queue

Technical Highlights
Dynamic Resizing: Array automatically adjusts to accommodate elements

Zero-Based Indexing: Standard array access patterns

Boundary Checking: Safe operations with index validation

Memory Safety: Proper destructor prevents memory leaks

O(1) Access: Constant-time element access by index

Learning Outcomes

This implementation showcases:

Dynamic array data structure internals

Queue implementation using arrays

Manual memory management in C++

Template-based generic programming

Resizing algorithms and strategies

Time-space tradeoffs in data structures

Use Cases

When fixed-size arrays are insufficient

Applications requiring frequent insertions/deletions

Teaching array-based data structures

Building blocks for more complex containers

Requirements

C++ compiler with template support

No external dependencies

front/back: Access elements at both ends

InsertAt/DeleteAt: Flexible insertion and deletion at any position

Reverse: Invert the entire queue order

Find: Locate elements by value

Extended Functionality

Insert at beginning, end, or any position

Delete first, last, or specific items

Update items by index

Clear entire queue

Check empty status
