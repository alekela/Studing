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


void find(int s, int start_s, int start, vector<int> &answer, vector<int> &numbers, int n) {
    if (s == 0) {
        int sum = 0;
        for (int i : answer) {
            sum += i;
        }
        if (answer.size() == n && sum == start_s) {
            for (int i : answer) {
                cout << i << " ";
            }
            cout << endl;
        }
        answer.clear();
        return;
    }
    for (int i = start; i < numbers.size(); i++) {
        if (numbers[i] <= s) {
            answer.push_back(numbers[i]);
            find(s - numbers[i], start_s, i + 1, answer, numbers, n);
        }
    }
    answer.clear();
}


int main() {
    string tmp;
    vector<int> banned_n;
    cout << "Введите забаненные цифры: " << endl;
    std::getline(std::cin, tmp);
    int s;
    cout << "Введите сумму, которую надо получить: " << endl;
    cin >> s;
    int n;
    cout << "Введите количество цифр: " << endl;
    cin >> n;
    for (int i = 0; i < tmp.size(); i++) {
        if (isdigit(tmp[i])) {
            banned_n.push_back(tmp[i] - '0');
        }
    }
    int numbers[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> clear_numbers;
    for (int i = 0; i < 9; i++) {
        if (check(numbers[i], banned_n)) {
            clear_numbers.push_back(numbers[i]);
        }
    }
    vector<int> answer;
    find(s, s, 0, answer, clear_numbers, n);
}
