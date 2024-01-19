#include "Solution2.h"

#include <ostream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <fstream>

// Don't forget to enable the exercise in the SudentConfiguration.h file !
#include "StudentConfiguration.h"
#ifdef COMPILE_EXERCICE_2

float Solution2::GetBalance(const std::string& accountName)
{
    std::ifstream file("BankAccount/" + accountName + ".txt");
    if (!file.is_open()) {
        throw std::runtime_error("Fichier non trouve");
    }

    float balance = 0.0f;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string operation;
        float amount;

        if (!(iss >> operation >> amount)) {
            throw std::invalid_argument("Format invalide");
        }

        if (operation == "DEPOSIT") {
            balance += amount;
        }
        else if (operation == "WITHDRAW") {
            balance -= amount;
        }
        else {
            throw std::invalid_argument("Operation invalide");
        }
    }

    file.close();
    return balance;
}

#endif
