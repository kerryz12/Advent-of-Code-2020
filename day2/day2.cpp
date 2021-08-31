#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

vector<string> input;
string line;
ifstream file("day2.txt");

int part1();
int part2();

int main (void) {

    while(getline(file, line)) {
        input.push_back(line);
    }

    cout << part1() << "\n";
    cout << part2();

    return 0;
}

int part1() {
    int valid = 0;
    int count = 0;
    string s_min;
    string s_max;
    int min;
    int max;
    char chosen;
    string password;

    for(string s : input) {
        count = 0;
        int i = 0;
        s_min.clear();
        s_max.clear();
        password.clear();
        while(s[i] != '-') {
            s_min.push_back(s[i]);
            i++;
        }
        min = stoi(s_min);
        i++;
        while(s[i] != ' ') {
            s_max.push_back(s[i]);
            i++;
        }
        max = stoi(s_max);
        i++;
        chosen = s[i];
        i += 3;
        while(s[i] != '\0') {
            password.push_back(s[i]);
            i++;
        }

        for(char c : password) {
            if(c == chosen) {
                count++;
            }
        }
        if(count >= min && count <= max) {
            valid++;
        }
    }

    return valid;
}

int part2() {
    int valid = 0;
    int count = 0;
    string s_min;
    string s_max;
    int min;
    int max;
    char chosen;
    string password;

    for(string s : input) {
        count = 0;
        int i = 0;
        s_min.clear();
        s_max.clear();
        password.clear();
        while(s[i] != '-') {
            s_min.push_back(s[i]);
            i++;
        }
        min = stoi(s_min);
        i++;
        while(s[i] != ' ') {
            s_max.push_back(s[i]);
            i++;
        }
        max = stoi(s_max);
        i++;
        chosen = s[i];
        i += 3;
        while(s[i] != '\0') {
            password.push_back(s[i]);
            i++;
        }

        if((password[min - 1] == chosen) ^ (password[max - 1] == chosen)) {
            valid++;
        }
    }

    return valid;
}