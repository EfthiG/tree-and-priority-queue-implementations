# Data Structures in C

A university programming project exploring the implementation, composition, and testing of abstract data types (ADTs) in C. The project includes alternative representations of recursive trees, complete binary trees, and priority queues, with a focus on the trade-offs between underlying data structures.

## Overview

The implementations demonstrate how the same abstract interface can be supported by different internal representations. The project also includes tree utility operations and unit tests that exercise several combinations of implementations.

This work was completed as part of a 2023 university data structures assignment, using a course-provided starter repository and ADT interfaces.

## Implementations

| Component | Source location | Approach |
| --- | --- | --- |
| Recursive tree | `modules/UsingLinkedTree/ADTRecTree.c` | Linked-tree representation |
| Recursive tree | `modules/UsingADTMap/ADTRecTree.c` | Map-backed representation |
| Tree utilities | `modules/ADTRecTree_utils.c` | Operations on recursive trees |
| Complete binary tree | `modules/UsingADTRecTree/ADTCompTree.c` | Built on the recursive-tree interface |
| Priority queue | `modules/UsingADTCompTree/ADTPriorityQueue.c` | Built on a complete binary tree |
| Priority queue | `modules/UsingHeap/ADTPriorityQueue.c` | Heap-based alternative |

Supporting ADT implementations and interfaces for maps, sets, and vectors are included under `modules/` and `include/`.

## Project layout

```text
include/       Public ADT interfaces and test dependencies
modules/       Data structure implementations and utility functions
tests/         Unit tests and test build rules
Makefile       Top-level build commands
common.mk      Shared Makefile configuration
.github/       Course-provided GitHub Actions configuration
.vscode/       Editor configuration supplied with the project
```

## Building and testing

Requirements: a C compiler, `make`, and a Unix-like development environment.

From the repository root:

```bash
make tests
```

To build and run the configured test suite:

```bash
make run-tests
```

To remove generated build files:

```bash
make clean
```

**Known limitation:** The supplied archive does not contain `tests/ADTSet_test.c`, although the test Makefile refers to it. As a result, a complete clean build of every configured test target may fail. Other test targets can be built individually using the Makefile in `tests/`.

## What this project demonstrates

- Implementing abstract data types behind consistent C interfaces
- Working with recursive and complete binary tree representations
- Building higher-level structures from reusable ADTs
- Comparing linked and map-backed implementations
- Testing multiple implementations against shared interfaces
- Reasoning about time complexity and representation trade-offs

## Coursework and attribution

The repository originated from a university assignment starter project. It retains the original public headers, build setup, and supporting framework. The implementation work extends that starter with data structure modules, tree utilities, and tests. Not every file in this repository was authored from scratch.

The original assignment reference included in the starter project was: https://k08.chatzi.org/projects/project2/ . This link is included for context and may have changed since the 2023 assignment.
