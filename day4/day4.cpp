#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

vector<string> input;
string line;
ifstream file("day4.txt");

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
    bool byr = false;
    bool iyr = false;
    bool eyr = false;
    bool hgt = false;
    bool hcl = false;
    bool ecl = false;
    bool pid = false;
    int count = 0;
    int i = 0;

    for(string s : input) {
        if(s != "\0") {
            while(s[i] != '\0') {
                if(s[i] == ':') {
                    switch(s[i - 3]) {
                        case 'b':
                            byr = true;
                            break;
                        case 'i':
                            iyr = true;
                            break;
                        case 'e':
                            if(s[i - 2] == 'y') eyr = true;
                            else ecl = true;
                            break;
                        case 'h':
                            if(s[i - 2] == 'g') hgt = true;
                            else hcl = true;
                            break;
                        case 'p':
                            pid = true;
                            break;
                        default:
                            break;
                    }
                }
                i++;
            }
            i = 0;
        }
        else {
            if(byr && iyr && eyr && hgt && hcl && ecl && pid) count++;
            byr = false;
            iyr = false;
            eyr = false;
            hgt = false;
            hcl = false;
            ecl = false;
            pid = false;
        }
    }

    // last passport does not increment because there is no newline after it
    if(byr && iyr && eyr && hgt && hcl && ecl && pid) count++;

    return count;
}

int part2() {
    bool byr = false;
    bool iyr = false;
    bool eyr = false;
    bool hgt = false;
    bool hcl = false;
    bool ecl = false;
    bool pid = false;
    int count = 0;
    int i = 0;
    int j = 0;
    vector<string> valid_eyes{"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
    bool flag = true;

    // need to add newline to end of input in order to correctly count last passport
    for(string s : input) {
        if(s != "\0") {
            while(s[i] != '\0') {
                if(s[i] == ':') {
                    switch(s[i - 3]) {
                        case 'b':
                            if(stoi(s.substr(i + 1, 4)) >= 1920 && stoi(s.substr(i + 1, 4)) <= 2002) byr = true;
                            break;
                        case 'i':
                            if(stoi(s.substr(i + 1, 4)) >= 2010 && stoi(s.substr(i + 1, 4)) <= 2020) iyr = true;
                            break;
                        case 'e':
                            if(s[i - 2] == 'y') {
                                if(stoi(s.substr(i + 1, 4)) >= 2020 && stoi(s.substr(i + 1, 4)) <= 2030) eyr = true;
                            }
                            else {
                                if(find(valid_eyes.begin(), valid_eyes.end(), s.substr(i + 1, 3)) != valid_eyes.end()) ecl = true;
                            }
                            break;
                        case 'h':
                            if(s[i - 2] == 'g') {
                                while((s[i + j] != 'i') && (s[i + j] != 'c')) {
                                    j++;
                                }
                                if(s[i + j] == 'i') {
                                    if((stoi(s.substr(i + 1, j)) >= 59) && (stoi(s.substr(i + 1, j)) <= 76)) hgt = true;
                                }
                                else {
                                    if((stoi(s.substr(i + 1, j)) >= 150) && (stoi(s.substr(i + 1, j)) <= 193)) hgt = true;
                                }
                                j = 0;
                            }
                            else {
                                if(s[i + 1] == '#') {
                                    for(int k = 0; k < 6; ++k) {
                                        if(s[i + 2 + k] > 102 || s[i + 2 + k] < 48) flag = false;
                                    }
                                    if((s[i + 8] == ' ') || (s[i + 8] == '\0'))
                                        if(flag) hcl = true;
                                    flag = true;
                                }
                            }
                            break;
                        case 'p':
                            while((s[i + 1 + j] != ' ') && (s[i + 1 + j] != '\0')) {
                                j++;
                            }
                            if(j == 9) pid = true;
                            j = 0;
                            break;
                        default:
                            break;
                    }
                }
                i++;
            }
            i = 0;
        }
        else {
            if(byr && iyr && eyr && hgt && hcl && ecl && pid) count++;
            byr = false;
            iyr = false;
            eyr = false;
            hgt = false;
            hcl = false;
            ecl = false;
            pid = false;
        }
    }

    return count;
}