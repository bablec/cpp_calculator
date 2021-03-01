#include <iostream>
#include <string>
#include <exception>
#include "stack.h"
#include "fraction.h"
#include "dictionary.h"

using namespace std;

// determines order of operations
// if multiplication or divion is on the stack it gets preformed
//    before adding another operator
bool order(char first, char second) {
    if (first == '*' || first == '/') {
        return true;
    }
    return false;
}

void doOperation(Stack<Fraction> &numStack, Stack<char> &opStack) {
    char op = opStack.pop();
    Fraction right = numStack.pop();
    Fraction left = numStack.pop();
    switch (op) {
        case '+':
            numStack.push(left + right);
            break;
        case '-':
            numStack.push(left - right);
            break;
        case '*':
            numStack.push(left * right);
            break;
        case '/':
            numStack.push(left / right);
            break;
    }
}

void processSymbol(string s, int &first, Stack<Fraction> &numStack, Stack<char> &opStack, Dictionary &vars) {
    if (isdigit(s[first])) {
        string digit_seq = string();
        int i = 0;
        while (isdigit(s[first+i])) {
            digit_seq.push_back(s[first+i]);
            i++;
        }
        numStack.push(Fraction(stoi(digit_seq)));
        first += i;
    } else if (isalpha(s[first])) {
        string name = string();
        int i = 0;
        while (isalpha(s[first+i])) {
            name.push_back(s[first+i]);
            i++;
        }
        numStack.push(vars.search(name));
        first += i;
    } else if (s[first] == '(') {
        opStack.push('(');
        first++;
    } else if (s[first] == ')') {
        while (opStack.peek() != '(') {
            doOperation(numStack,opStack);
        }
        opStack.pop();
        first++;
    } else if (s[first] == '+' || s[first] == '-' || s[first] == '*' || s[first] == '/') {
        while (order(opStack.peek(),s[first])) {
            doOperation(numStack,opStack);
        }
        opStack.push(s[first]);
        first++;
    } else {
        first++;
    }
}

Fraction evaluate(string s, Dictionary &vars) {
    Stack<Fraction> numStack;
    Stack<char> opStack;
    opStack.push('$');
    int first = 0;
    string dest = string();

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '=') {
            first = i+1;
            dest = s.substr(0,i);
            break;
        }
    }

    while (first < s.length()) {
        processSymbol(s,first,numStack,opStack,vars);
    }

    while (opStack.peek() != '$') {
        doOperation(numStack,opStack);
    }

    // if there is more than 1 number on numStack
    // there was a syntax error. ex: 3(2) or (2)3
    if (numStack.size() > 1) {
        throw logic_error("Leftovers in numStack");
    }

    if (dest != string()) {
        vars.forceUpdate(dest,numStack.peek());
    }

    return numStack.pop();
}

int main() {
    Dictionary vars;
    string expression;
    
    while (1) {
        getline(cin,expression);
        try {
            cout << evaluate(expression,vars) << "\n\n";
        } catch (domain_error) {
            cout << "Error: Variable not found" << "\n\n";
        } catch (...) {
            cout << "Syntax Error" << "\n\n";
        }
    }

    return 0;
}