#pragma once

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef string str;

int run() {
    bool running = true;
    char operand;
    float num1, num2, result;

    while (running) {
        cout << "Enter an operation (+, -, *, /): ";
        cin >> operand;

        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        switch (operand) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                result = num1 / num2;
                break;
            default:
                cout << "Invalid operation!\n";
                running = false;
                break;
        }

        cout << "Result: " << result << '\n';

        cout << "Continue? [Y/N]: ";
        cin >> operand;
        switch (operand) {
            case 'Y':
            case 'y':
                running = true;
                break;
            case 'N':
            case 'n':
                running = false;
                break;
            default:
                cout << "Invalid input!\n";
                break;
        }
    }
}