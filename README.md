# 🧠 Custom Data Structures in C (Main), with example code in C++ and C# 

This project contains custom implementations of common data structures in C/C++, designed for learning and demonstration purposes. All data structures are built using fixed-size arrays without dynamic resizing (except where `malloc` is explicitly used). The code is well-commented and organized into sections for clarity.

## 🧰 Features

The following data structures are implemented from scratch:

### ✅ Stack (LIFO)
- Static size array
- Operations: `push`, `pop`, `peek`

### ✅ Queue (FIFO with Circular Buffer)
- Circular queue using array
- Operations: `enqueue`, `dequeue`
- Handles overflow and underflow gracefully

### ✅ Dictionary / Hash Map
- Hashing via DJB2
- Collision handling: None (static slots)
- Key-value pairs using strings as keys

### ✅ Binary Tree
- Node creation
- Tree traversal: `preorder`, `inorder`, `postorder`
- Utility: `treeHeight`, memory management
- Supports basic Binary Search Tree (BST) operations like `insert` and `search`

### ✅ Min Heap (Priority Queue)
- Min-heap based on array
- Operations: `insertItem`, `extract_min`, `bubbleUp`, `bubbleDown`
- Uses a 1-based index for easier parent/child calculations
