#include "Calculator.h"
#include <iostream>
#include <iomanip>
#include <memory>

// ─────────────────────────────────────────────
//  Constructor
// ─────────────────────────────────────────────
Calculator::Calculator() : result(0.0) {}

// ─────────────────────────────────────────────
//  Core calculation method
// ─────────────────────────────────────────────
double Calculator::calculate(double a, double b, char op) {
    std::unique_ptr<Operation> operation;

    switch (op) {
        case '+': operation = std::make_unique<Addition>();       break;
        case '-': operation = std::make_unique<Subtraction>();    break;
        case '*': operation = std::make_unique<Multiplication>(); break;
        case '/': operation = std::make_unique<Division>();       break;
        case '%': operation = std::make_unique<Modulus>();        break;
        default:
            throw std::invalid_argument("Invalid operator: " + std::string(1, op));
    }

    result = operation->execute(a, b);
    return result;
}

// ─────────────────────────────────────────────
//  Getters / Display
// ─────────────────────────────────────────────
double Calculator::getResult() const {
    return result;
}

void Calculator::displayResult(double a, double b, char op) const {
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "  " << a << " " << op << " " << b
              << " = " << result << "\n";
}

// ─────────────────────────────────────────────
//  Interactive REPL
// ─────────────────────────────────────────────
void Calculator::run() {
    std::cout << "╔══════════════════════════════════╗\n";
    std::cout << "║   OOP Calculator  (C++)          ║\n";
    std::cout << "║   Operators: + - * / %           ║\n";
    std::cout << "║   Type 'q' to quit               ║\n";
    std::cout << "╚══════════════════════════════════╝\n\n";

    while (true) {
        double a, b;
        char op;

        std::cout << "Enter expression (e.g. 10 + 5): ";
        if (!(std::cin >> a >> op >> b)) {
            // check for quit
            std::string token;
            std::cin.clear();
            std::cin >> token;
            if (token == "q" || token == "Q") break;
            std::cout << "  [!] Invalid input. Try again.\n\n";
            std::cin.ignore(1000, '\n');
            continue;
        }
        if (op == 'q' || op == 'Q') break;

        try {
            calculate(a, b, op);
            displayResult(a, b, op);
        } catch (const std::exception& e) {
            std::cout << "  [!] Error: " << e.what() << "\n";
        }
        std::cout << "\n";
    }

    std::cout << "Goodbye!\n";
}
