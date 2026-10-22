#include <iostream>
#include <fstream>
#include <random>
#include <string>

int main() {
    srand(time(0));
    int n = 0, m = 0;
    char alph[2] = {'.', '*'};
    while(true) {
        std::cout << "Enter the command: ";
        int command;
        std::cin >> command;
        if(command == 1) {
            std::cout << "\nEnter n and m: ";
            std::cin >> n >> m;

            char** field = new char*[n];
            for(int i = 0; i < n; i++) {
                field[i] = new char[m];
            }
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    field[i][j] = alph[rand() % 2];
                }
            }

            std::ofstream out("game_field.txt");

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    out << field[i][j];
                }
                out << '\n';
            }
            std::cout << std::endl << "Successful!\n";
        } else if(command == 5) {
            exit(0);
        } else if(command == 2) {
            std::ifstream in("game_field.txt");
            std::string line;
            while(std::getline(in, line)) {
                std::cout << line << '\n';
            }
        } else if(command == 3) {
            char** field = new char*[n];
            for(int i = 0; i < n; i++) {
                field[i] = new char[m];
            }
            std::ifstream in("game_field.txt");
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    in >> field[i][j];
                }
            }
            in.close();

            std::ofstream out("result.txt");

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(field[i][j] == '*') {
                        out << '*';
                        continue;
                    }
                    int cnt = 0;
                    cnt += field[i][j] == '*';
                    if(j > 0) cnt += field[i][j-1] == '*';
                    if(j < m - 1) cnt += field[i][j+1] == '*';
                    if(i > 0) {
                        cnt += field[i-1][j] == '*';
                        if(j > 0) cnt += field[i-1][j-1] == '*';
                        if(j < m - 1) cnt += field[i-1][j+1] == '*';
                    }
                    if(i < n - 1) {
                        cnt += field[i+1][j] == '*';
                        if(j > 0) cnt += field[i+1][j-1] == '*';
                        if(j < m - 1) cnt += field[i+1][j+1] == '*';
                    }
                    char mines = '0' + cnt;
                    out << mines;
                }
                out << std::endl;
            }
            std::cout << std::endl << "Successful!\n";
        } else if(command == 4) {
            std::ifstream in("result.txt");
            std::string line;
            while(std::getline(in, line)) {
                std::cout << line << '\n';
            }       
        } else {
            std::cout << "Incorrect command!" << std::endl;
        }
    }
    return 0;
}
