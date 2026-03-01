#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdexcept>
#include <string>

// ─────────────────────────────────────────────
//  Base class: Operation
// ─────────────────────────────────────────────
class Operation {
public:
    virtual double execute(double a, double b) const = 0;
    virtual std::string symbol() const = 0;
    virtual ~Operation() = default;
};

// ─────────────────────────────────────────────
//  Derived operation classes
// ─────────────────────────────────────────────
class Addition : public Operation {
public:
    double execute(double a, double b) const override { return a + b; }
    std::string symbol() const override { return "+"; }
};

class Subtraction : public Operation {
public:
    double execute(double a, double b) const override { return a - b; }
    std::string symbol() const override { return "-"; }
};

class Multiplication : public Operation {
public:
    double execute(double a, double b) const override { return a * b; }
    std::string symbol() const override { return "*"; }
};

class Division : public Operation {
public:
    double execute(double a, double b) const override {
        if (b == 0)
            throw std::runtime_error("Division by zero is not allowed.");
        return a / b;
    }
    std::string symbol() const override { return "/"; }
};

class Modulus : public Operation {
public:
    double execute(double a, double b) const override {
        if (b == 0)
            throw std::runtime_error("Modulus by zero is not allowed.");
        return static_cast<int>(a) % static_cast<int>(b);
    }
    std::string symbol() const override { return "%"; }
};

// ─────────────────────────────────────────────
//  Calculator class
// ─────────────────────────────────────────────
class Calculator {
private:
    double result;

public:
    Calculator();
    double calculate(double a, double b, char op);
    double getResult() const;
    void displayResult(double a, double b, char op) const;
    void run();                          // interactive loop
};

#endif // CALCULATOR_H
