#include "Game.h"

double Game::evaluate(const string& expr)
{
    vector<double> values;
    vector<char> ops;
    string num;

    for (char c : expr) {
        if (isdigit(c) || c == '.') {
            num += c;
        }
        else {
            if (!num.empty()) {
                values.push_back(stod(num));
                num.clear();
            }
            if (c == '(') {
                ops.push_back(c);
            }
            else if (c == ')') {
                while (ops.back() != '(') {
                    double b = values.back(); values.pop_back();
                    double a = values.back(); values.pop_back();
                    char op = ops.back(); ops.pop_back();
                    if (op == '+') values.push_back(a + b);
                    else if (op == '-') values.push_back(a - b);
                    else if (op == '*') values.push_back(a * b);
                    else if (op == '/') values.push_back(a / b);
                }
                ops.pop_back();
            }
            else if (c == '+' || c == '-' || c == '*' || c == '/') {
                while (!ops.empty() && ops.back() != '(' &&
                    ((c == '+' || c == '-') || (c == '*' || c == '/'))) {
                    double b = values.back(); values.pop_back();
                    double a = values.back(); values.pop_back();
                    char op = ops.back(); ops.pop_back();
                    if (op == '+') values.push_back(a + b);
                    else if (op == '-') values.push_back(a - b);
                    else if (op == '*') values.push_back(a * b);
                    else if (op == '/') values.push_back(a / b);
                }
                ops.push_back(c);
            }
        }
    }

    if (!num.empty()) {
        values.push_back(stod(num));
    }

    while (!ops.empty()) {
        double b = values.back(); values.pop_back();
        double a = values.back(); values.pop_back();
        char op = ops.back(); ops.pop_back();
        if (op == '+') values.push_back(a + b);
        else if (op == '-') values.push_back(a - b);
        else if (op == '*') values.push_back(a * b);
        else if (op == '/') values.push_back(a / b);
    }

    return values.back();
}

bool Game::isValidExpression(const string& expr, const vector<int>& hand)
{
    vector<int> handCopy = hand;
    string num;
    for (char c : expr) {
        if (isdigit(c) || c == '.') {
            num += c;
        }
        else {
            if (!num.empty()) {
                double val = stod(num);
                auto it = find(handCopy.begin(), handCopy.end(), static_cast<int>(val));
                if (it != handCopy.end()) {
                    handCopy.erase(it);
                }
                else {
                    return false;
                }
                num.clear();
            }
        }
    }
    if (!num.empty()) {
        double val = stod(num);
        auto it = find(handCopy.begin(), handCopy.end(), static_cast<int>(val));
        if (it != handCopy.end()) {
            handCopy.erase(it);
        }
        else {
            return false;
        }
    }

    if (!handCopy.empty()) {
        return false;
    }

    double result = evaluate(expr);
    return abs(result - 24) < 1e-6;
}
