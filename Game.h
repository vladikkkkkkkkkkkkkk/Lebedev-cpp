#pragma once
#include <iostream>    
#include <vector>      
#include <algorithm>   
#include <string>      
#include <ctime>       
#include <cmath>       


using namespace std;
class Game {
public:
    // Функция для вычисления выражения с учетом приоритетов операций и скобок
    double evaluate(const string& expr);

    // Проверка, корректно ли выражение и равно ли оно 24
    bool isValidExpression(const string& expr, const vector<int>& hand);

};