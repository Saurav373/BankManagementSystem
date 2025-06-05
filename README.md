# BankManagementSystem

_A comprehensive software solution for managing banking operations, built with C++._

---

## 🌟 Overview

**BankManagementSystem** is a user-friendly and efficient banking application designed to streamline core banking tasks. With robust features for account management, transactions, and reporting, it serves as a practical project for learning and demonstrating C++ programming concepts.

---

## ✨ Features

- **Account Management:**  
  Create, update and view customer accounts seamlessly.

- **Transactions:**  
  Deposit and withdraw funds, view transaction history, and manage balances securely.

- **Data Persistence:**  
  All information is stored inside the data/ folder for reliability and data integrity.
---

## 🚀 Getting Started

### Prerequisites

- C++ compiler (e.g., GCC, MinGW, Visual Studio)
- Basic knowledge of compiling and running C++ programs

### Build & Run

1. **Clone the repository:**
    ```bash
    git clone https://github.com/Saurav373/BankManagementSystem.git
    cd BankManagementSystem
    ```

2. **Compile the source code:**
    ```bash
    # Compile manually using g++
    g++ -std=c++17 -Wall -I libs/Bcrypt.cpp/include main.cpp userAuth.cpp bankSystem.cpp helper.cpp libs/Bcrypt.cpp/src/bcrypt_cpp.cpp libs/Bcrypt.cpp/src/blowfish.cpp -o BankManagementSystem

    # OR compile using Makefile
    make
    ```

3. **Run the program:**
    ```bash
    ./BankManagementSystem
    ```

---

---

## 🤝 Contributing

Contributions are welcome!  
Feel free to fork this repo, submit pull requests, or open issues for suggestions and improvements.

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).

---

## 🙋‍♂️ Author

- **Saurav373**  
  [GitHub](https://github.com/Saurav373)

---

> _Empowering digital banking with C++!_
