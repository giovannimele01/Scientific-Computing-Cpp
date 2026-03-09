# C++ OOP & Computational Efficiency Projects

This repository demonstrates the advantages of **Object-Oriented Programming (OOP)** and the high **computational efficiency** of the C++ language through three specialized projects.

---

## Projects Overview

### 1. Adam Optimization Method
A custom implementation of the widely-used **Adam** (Adaptive Moment Estimation) optimizer.
* **Target:** Tested on functions in $\mathbb{R}^n$ composed of sums of monomials.
* **Key Features:** Efficient gradient management and adaptive learning rate logic implemented from scratch.

### 2. Feedforward Neural Network
A modular construction of a Feedforward Neural Network (FNN).
* **Customization:** Offers a variety of selectable activation functions (e.g., ReLU, Sigmoid, Tanh).
* **Design:** Leverages OOP principles to handle layers, weights, and biases as distinct, reusable objects.

### 3. Parallel Matrix Computing with MPI
A demonstration of the performance gains achieved through parallel programming for matrix calculations.
* **Workflow:** Follows the standard parallel computing pattern: **Split** $\to$ **Operations** $\to$ **Gather**.
* **Technology:** Developed using the **MPI** (Message Passing Interface) standard to distribute workloads across multiple processes.

---

## Technical Requirements

To compile and run these projects, you will need:
* A **C++ compiler** (supporting C++17 or later).
* An **MPI implementation** (such as OpenMPI or MPICH) for the parallel computing project.
* **CMake** (recommended for build management).

## Why C++?
The choice of C++ for these implementations is driven by:
1.  **Performance:** Minimal overhead for intensive mathematical operations.
2.  **Abstraction:** The ability to model complex mathematical structures through classes without sacrificing speed.
3.  **Scalability:** Native support for high-performance computing (HPC) workflows.

---

> **Note:** This repository is intended for educational and demonstrative purposes, showcasing the synergy between software design and raw processing power.
