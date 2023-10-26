#include <string>
#include <iostream>
#include <vector>


using namespace std;


bool check(int n, vector<int> nums) {
    for (int i : nums) {
        if (n == i) {
            return false;
        }
    }
    return true;
}


void find(int s, int start, vector<int> mini_answer, vector<int> numbers, int n) {
    if (s == 0) {
        if (mini_answer.size() == n) {
            for (int i : mini_answer) {
                cout << i << " ";
            }
            cout << endl;
        }
        mini_answer.clear();
        return;
    }
    for (int i = start; i < numbers.size(); i++) {
        if (numbers[i] <= s) {
            mini_answer.push_back(numbers[i]);
            find(s - numbers[i], i + 1, mini_answer, numbers, n);
        }
    }
    mini_answer.clear();
}


int main() {
    int s;
    cin >> s;
    int n;
    cin >> n;
    vector<int> banned_n = {3, 7};
    int numbers[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> clear_numbers;
    for (int i = 0; i < 9; i++) {
        if (check(numbers[i], banned_n)) {
            clear_numbers.push_back(numbers[i]);
        }
    }
    vector<int> mini_answer;
    find(s, 0, mini_answer, clear_numbers, n);
}
