#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cmath>

std::vector<float>coordinates(2, 0);
std::vector<std::vector<float>> movementHistory;
std::vector<std::vector<float>> undoMovements;

void printDashes(int length);
void simulationMenu();
void gerak(float x, float y);
void save();
void load();
void gerak_2(float v, float t, float theta);

int main(void) {
    simulationMenu();    
}

void printMenuTitle() {
    const std::string& message = "DRONE SIMULATION";
    printDashes(message.length() + 4);
    std::cout << '\t' << "| " << message << " |" << '\n';
    printDashes(message.length() + 4); 
    std::cout << '\n';
}

void printDashes(int length) {
    std::cout << '\t';
    for (int i = 0; i < length; i++) {
        std::cout << '-';
    }
    std::cout << '\n';
}

void gerak_2(float v, float t, float theta) {
    double pi = M_PI;
    float x = cos(pi * (theta / 180)) * v * t;
    float y = sin(pi * (theta / 180)) * v * t;

    gerak(x, y);
}


void undo() {
    if (!movementHistory.empty()) {
        undoMovements.push_back(movementHistory.back());

        coordinates[0] -= movementHistory.back()[0];
        coordinates[1] -= movementHistory.back()[1];
        movementHistory.pop_back();
        save();
        std::cout << "Undo berhasil!" << '\n' << '\n';
    } else {
        coordinates[0] = 0.00f;
        coordinates[1] = 0.00f;
        std::cout << "Tidak dapat undo!" << '\n' << '\n';
    }
}

void redo() {
    if (!undoMovements.empty()) {
        movementHistory.push_back(undoMovements.back());
        coordinates[0] += undoMovements.back()[0];
        coordinates[1] += undoMovements.back()[1];
        undoMovements.pop_back();
        std::cout << "Redo berhasil!" << '\n' << '\n';
        save();
    } else {
        std::cout << "Tidak dapat redo!" << '\n' << '\n';
    }
}

void load() {
    std::ifstream file("movementLog.txt");

    if (file.is_open()) {        
        std::string line, coordinateStr;
        float coordinate;

        // Read and print each line of the file
        while (std::getline(file, line)) {
            std::stringstream token(line);
            std::getline(token, coordinateStr, ',');
            coordinates[0] = std::strtof(coordinateStr.c_str(), nullptr);

            std::getline(token, coordinateStr, ',');
            coordinates[1] = std::strtof(coordinateStr.c_str(), nullptr);
        }

        // Close the file after reading
        file.close();
    } else {
        std::cerr << "Unable to open the file." << std::endl;
    }

}

void save() {
    std::ofstream file("movementLog.txt", std::ofstream::out | std::ofstream::trunc);

    if (file.is_open()) {
        file << coordinates[0] << "," << coordinates[1] << '\n';
    }
    else {
        std::cout << "There is a problem opening the file.";
    }
    file.close();
}

void gerak(float x, float y) {
    coordinates[0] += x;
    coordinates[1] += y;

    std::vector<float> newCoordinates = {x, y};

    movementHistory.push_back(newCoordinates);
    undoMovements.clear();
    save();
}

void lokasi() {
    std::cout << "Lokasi: ";
    std::cout << "(" << std::fixed << std::setprecision(2) << coordinates[0] << ", " << coordinates[1] << ")" << '\n' << '\n';
}

void simulationMenu() {
    printMenuTitle();

    int option;

    load();

    while (option != 6) {
        std::cout << "Please select one of the following options: " << '\n';
        std::cout << 
        "1. Check drone's current location\n" 
        << "2. Move drone \n" 
        << "3. Move drone (with speed and time)\n" 
        << "4. Undo movement\n" 
        << "5. Redo movement\n" 
        << "6. Quit" << '\n';

        do {
            std::cout << "Option: ";
            std::cin >> option;

            std::cout << '\n';

            if (option < 1 && option > 6) {
                std::cout << "Invalid: Input can only be 1 - 4.\n";
            }
        } while (option < 1 && option > 6);

        if (option == 1) {
            lokasi();
        } 
        else if (option == 2) {
            float x, y;
            std::cout << "x: ";
            std::cin >> x;

            std::cout << "y: ";
            std::cin >> y;

            std::cout << '\n';

            gerak(x, y);
        }
        else if (option == 3) {
            float velocity, time, theta;
            std::cout << "v: ";
            std::cin >> velocity;

            std::cout << "t: ";
            std::cin >> time;

            std::cout << "theta: ";
            std::cin >> theta;

            std::cout << '\n';

            gerak_2(velocity, time, theta);
        }
        else if (option == 4) {
            undo();
        }
        else if (option == 5) {
            redo();
        }
    }
}