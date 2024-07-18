#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    vector<string> games = {"The Legend of Zelda", "Super Mario Odyssey"};
    string input;

    cout << "Welcome to the favorite games manager!" << endl;

    while (true) {
        cout << "What would you like to do? (Add, Edit, Delete, Show, Quit): ";
        getline(cin, input);

        if (input == "Add" || input == "add") {
            cout << "What game would you like to add? ";
            getline(cin, input);
            games.push_back(input);
        } else if (input == "Edit" || input == "edit") {
            cout << "What game would you like to edit? ";
            getline(cin, input);
            auto it = find(games.begin(), games.end(), input);
            if (it != games.end()) {
                cout << "What would you like to change it to? ";
                getline(cin, input);
                *it = input;
            } else {
                cout << "Game not found." << endl;
            }
        } else if (input == "Delete" || input == "delete") {
            cout << "What game would you like to remove? ";
            getline(cin, input);
            auto it = find(games.begin(), games.end(), input);
            if (it != games.end()) {
                games.erase(it);
                cout << "Game removed." << endl;
            } else {
                cout << "Game not found." << endl;
            }
        } else if (input == "Show" || input == "show") {
            sort(games.begin(), games.end());
            for (size_t i = 0; i < games.size(); ++i) {
                cout << i + 1 << ". " << games[i] << endl;
            }
        } else if (input == "Quit" || input == "quit") {
            cout << "Are you sure you want to quit? (yes/no): ";
            getline(cin, input);
            if (input == "yes") {
                cout << "Thank you for using the program!" << endl;
                return 0;
            }
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}
