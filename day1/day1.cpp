#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

vector<int> input;
string line;
ifstream file("day1.txt");

int part1();
int part2();

int main (void) {

    while(getline(file, line)) {
        input.push_back(stoi(line));
    }

    cout << part1() << "\n";

    cout << part2();

    return 0;
}

int part1() {
    for(int i = 0; i < input.size(); ++i) {
        for(int j = i; j < input.size(); ++j) {
            if(input[i] + input[j] == 2020) {
                return input[i] * input[j];
            }
        }
    }
    return -1;
}

int part2() {
    for(int i = 0; i < input.size(); ++i) {
        for(int j = i; j < input.size(); ++j) {
            for(int k = j; k < input.size(); ++k) {
                if(input[i] + input[j] + input[k] == 2020) {
                    return input[i] * input[j] * input[k];
                }
            }

        }
    }

    return -1;
}