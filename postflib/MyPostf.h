//#pragma once
//#include "MyPostf.h"
//#include "MyStack.h"
//#include <map>
//#include <vector>
//#include <string>
//#include <cctype>
//#include <sstream>
//using namespace std;
//class MyPostf {
//private:
//    string infix;
//    string postfix;
//    vector<string> lexems;
//    map<char, int> priority;
//
//public:
//    MyPostf(string infix);
//    string GetInfix();
//    string GetPostfix();
//    void Parse();
//    void ToPostfix();
//    vector<string> GetOperands();
//    double Calculate(const map<string, double>& values);
//};
//
//MyPostf::MyPostf(string infix) : infix(infix), priority({ {'(', 1}, {')', 1}, {'+', 2}, {'-', 2}, {'*', 3}, {'/', 3} }) {
//    Parse();
//    ToPostfix();
//}
//
//string MyPostf::GetInfix() {
//    return infix;
//}
//
//string MyPostf::GetPostfix() {
//    return postfix;
//}
//
//void MyPostf::Parse() {
//    istringstream iss(infix);
//    string token;
//    while (iss >> token) {
//        lexems.push_back(token);
//    }
//}
//
//void MyPostf::ToPostfix() {
//    TStack<string> st(200);
//    for (const auto& token : lexems) {
//        if (isdigit(token[0])) {
//            postfix += token + ' ';
//        }
//        else if (token == "(") {
//            st.Push(token);
//        }
//        else if (token == ")") {
//            while (!st.IsEmpty() && st.Top() != "(") {
//                postfix += st.Pop() + ' ';
//            }
//            st.Pop();
//        }
//        else {
//            while (!st.IsEmpty() && priority[st.Top()[0]] >= priority[token[0]]) {
//                postfix += st.Pop() + ' ';
//            }
//            st.Push(token);
//        }
//    }
//    while (!st.IsEmpty()) {
//        postfix += st.Pop() + ' ';
//    }
//}
//
//vector<string> MyPostf::GetOperands() {
//    vector<string> operands;
//    for (const auto& lexem : lexems) {
//        if (isalpha(lexem[0])) {
//            operands.push_back(lexem);
//        }
//    }
//    return operands;
//}
//
//double MyPostf::Calculate(const map<string, double>& values) {
//    TStack<double> st(100);
//    istringstream iss(postfix);
//    string token;
//    while (iss >> token) {
//        if (isdigit(token[0])) {
//            st.Push(stod(token));
//        }
//        else if (token.size() == 1 && priority.find(token[0]) != priority.end()) {
//            double rightOperand = st.Pop();
//            double leftOperand = st.Pop();
//            switch (token[0]) {
//            case '+': st.Push(leftOperand + rightOperand); break;
//            case '-': st.Push(leftOperand - rightOperand); break;
//            case '*': st.Push(leftOperand * rightOperand); break;
//            case '/': st.Push(leftOperand / rightOperand); break;
//            }
//        }
//        else {
//            st.Push(values.at(token));
//        }
//    }
//    return st.IsEmpty() ? 0 : st.Pop();
//}

