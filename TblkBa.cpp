#include <iostream>    
#include <vector>      
#include <algorithm>   
#include <string>      
#include <ctime>       
#include <cmath>       
#include "Game.h"




int main() {
    Game g;
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел

    vector<int> deck;
    for (int i = 1; i <= 13; ++i) {
        for (int j = 0; j < 4; ++j) {
            deck.push_back(i);
        }
    }
    random_shuffle(deck.begin(), deck.end());

    int player1Cards = 0, player2Cards = 0;
    int currentPlayer = 1;

    while (!deck.empty()) {
        vector<int> hand;
        for (int i = 0; i < 4 && !deck.empty(); ++i) {
            hand.push_back(deck.back());
            deck.pop_back();
        }

        if (hand.size() < 4) {
            break;
        }

        cout << "Карты: ";
        for (int card : hand) {
            cout << card << " ";
        }
        cout << endl;

        bool foundSolution = false;
        for (int i = 0; i < 2; ++i) {
            cout << "Игрок " << currentPlayer << ", введите ваше решение или 'Пропустить': ";
            string input;
            getline(cin, input);

            if (input == "пропустить") {
                currentPlayer = (currentPlayer == 1) ? 2 : 1; // смена игрока
                continue;
            }

            if (g.isValidExpression(input, hand)) {
                foundSolution = true;
                if (currentPlayer == 1) {
                    player1Cards += 4;
                    cout << "Игрок 1 нашел решение: " << input << " = 24" << endl;
                }
                else {
                    player2Cards += 4;
                    cout << "Игрок 2 нашел решение: " << input << " = 24" << endl;
                }
                break;
            }
            else {
                cout << "Неверное решение. Попробуйте снова." << endl;
            }

            currentPlayer = (currentPlayer == 1) ? 2 : 1; // смена игрока
        }

        if (!foundSolution) {
            random_shuffle(deck.begin(), deck.end());
            cout << "Решение не найдено. Карты перемешаны." << endl;
        }
    }

    cout << "Игра окончена." << endl;
    cout << "Игрок 1 имеет " << player1Cards << " карт." << endl;
    cout << "Игрок 2 имеет " << player2Cards << " карт." << endl;

    if (player1Cards > player2Cards) {
        cout << "Игрок 1 победил!" << endl;
    }
    else if (player2Cards > player1Cards) {
        cout << "Игрок 2 победил!" << endl;
    }
    else {
        cout << "Ничья!" << endl;
    }

    return 0;
}
