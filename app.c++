#include <iostream>
#include <random>
#include <thread>

using namespace std;

int main() {

  int guess = 0;
  int num = 0;
  int wrongCount = 0;

  random_device rd;
  mt19937 mt(rd());
  uniform_int_distribution<int> dist(0, 10);

  while (true) {
    cout << "Enter A Number: ";
    cin >> num;
    guess = dist(mt);

    if (num > guess) {
      cout << "Lower" << endl;
      wrongCount++;
    }

    else if (num < guess) {
      cout << "Higher" << endl;
      wrongCount++;
    } else {
      cout << "You Got It" << endl;
      break;
    }

    this_thread::sleep_for(chrono::seconds(1));

    if (wrongCount == 3) {
      cout << "You Lose";
      break;
    }
  }

  return 0;
}
