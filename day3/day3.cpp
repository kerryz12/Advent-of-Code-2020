#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

vector<string> input;
string line;
ifstream file("day3.txt");

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
    int x;
    int count = 0;

    for(int i = 0; i < 323; ++i) {
        x = i * 3;

        if((input[i][x % 31]) == '#' && (i != 0)) {
            count++;
        }
    }

    return count;
}

int part2() {
    int x;
    int count1 = 0;
    int count3 = 0;
    int count5 = 0;
    int count7 = 0;
    int count1_2 = 0;

    for(int i = 0; i < 323; ++i) {
        x = i;

        if((input[i][x % 31]) == '#' && (i != 0)) {
            count1++;
        }
    }

    for(int i = 0; i < 323; ++i) {
        x = i * 3;

        if((input[i][x % 31]) == '#' && (i != 0)) {
            count3++;
        }
    }

    for(int i = 0; i < 323; ++i) {
        x = i * 5;

        if((input[i][x % 31]) == '#' && (i != 0)) {
            count5++;
        }
    }

    for(int i = 0; i < 323; ++i) {
        x = i * 7;

        if((input[i][x % 31]) == '#' && (i != 0)) {
            count7++;
        }
    }

    for(int i = 0; i < 323; i += 2) {
        x = i / 2;

        if((input[i][x % 31]) == '#' && (i != 0)) {
            count1_2++;
        }
    }

    return count1 * count3 * count5 * count7 * count1_2;
}