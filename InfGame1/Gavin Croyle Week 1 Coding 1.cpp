#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

  cout << "Hello there!\n";
  cout << "I am your narrator, and I will be guiding you through this story.\n";
  cout << "What is your name?\n";\

    string playerName;
    cout << "Enter your character's name: ";
    cin >> playerName;
  cout << "Hello " << playerName << "!\n";
  cout << "Welcome to our lovely little village called Meguopolis!\n";
  cout << "Oh? What's that?.. You don't want to be in the village?..\n";
  cout << "Well I mean.. There's allways the pathway of Greed on the other side of the village.\n";
  cout << " Do you want to go through there? It's got scary monsters!";

    bool continueAdventure = true;
    int encounterCount = 0;
    int playerHP = 10;
    int playerGold = 0;

    while (continueAdventure && playerHP > 0) {
        encounterCount++;
        int enemyStrength = rand() % 5; // Random enemy strength between 0 and 4
        cout << "\nEncounter " << encounterCount << ": An enemy with strength " << enemyStrength << " appears!\n";

        cout << "Do you want to (1) Fight the enemy or (2) Run away? ";
        int playerChoice;
        cin >> playerChoice;

        if (playerChoice == 1) {
            cout << "Do you want to (1) Attack or (2) Block? ";
            int combatChoice;
            cin >> combatChoice;

            if (combatChoice == 1) {
                int playerStrength = rand() % 5; // Random player strength between 0 and 4
                cout << "You decide to attack! Your strength is " << playerStrength << ".\n";
                if (playerStrength >= enemyStrength) {
                    cout << "You defeated the enemy!\n";
                    int goldReward = rand() % 11; // Random gold reward between 0 and 10
                    playerGold += goldReward;
                    cout << "You found " << goldReward << " gold. Total gold: " << playerGold << "\n";
                } else {
                    cout << "The enemy defeated you. You lose 1 HP.\n";
                    playerHP -= 1;
                    if (playerHP <= 0) {
                        cout << "You have been defeated. Game over.\n";
                        break;
                    }
                }
            } else if (combatChoice == 2) {
                cout << "You decide to block. You reduce incoming damage by half.\n";
                int damage = enemyStrength / 2;
                playerHP -= damage;
                cout << "You take " << damage << " damage. Your current HP: " << playerHP << "\n";
                if (playerHP <= 0) {
                    cout << "You have been defeated. Game over.\n";
                    break;
                }
            } else {
                cout << "Invalid choice. The enemy attacks you while you hesitate. You lose 1 HP.\n";
                playerHP -= 1;
                if (playerHP <= 0) {
                    cout << "You have been defeated. Game over.\n";
                    break;
                }
            }
        } else if (playerChoice == 2) {
            cout << "You decide to run away and live to fight another day.\n";
        } else {
            cout << "Invalid choice. The enemy attacks you while you hesitate. You lose 1 HP.\n";
            playerHP -= 1;
            if (playerHP <= 0) {
                cout << "You have been defeated. Game over.\n";
                break;
            }
        }

        cout << "Do you want to continue the adventure? (1) Yes (2) No: ";
        int continueChoice;
        cin >> continueChoice;

        if (continueChoice != 1) {
            continueAdventure = false;
        }
    }

    cout << "Thank you for playing, " << playerName << "! You had " << encounterCount << " encounters.\n";
    cout << "You collected " << playerGold << " gold.\n";
    return 0;
}
