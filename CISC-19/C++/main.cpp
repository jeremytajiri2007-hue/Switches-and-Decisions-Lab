#Challenges
#I originally wrote all of this code and my reflections on the practice lab's repository, so all of this is fresh stuff that I just copied from there lol.
#At first I forgot how to use enum class. I thought it was just enum without class, and it took me a while to figure out the correct syntax and that I needed static_cast later.
#I kept forgetting to reset cin when the user typed letters. At first my program would just loop forever with wrong input until I learned to use cin.clear() and cin.ignore().
#I forgot to check if the menu number was in range (1–5). I only realized this was needed when I accidentally typed 99 and the program tried to run anyway.
#I wrote staticcast instead of static_cast, and also typed numericlimits instead of numeric_limits. These small spelling mistakes caused confusing compiler errors.
#I didn’t handle the input buffer correctly at first. My teacher recommended using cin.ignore(numeric_limits<streamsize>::max(), '\n'), which fixed the problem of leftover input.
#In the multiply case, I tried to use "x" instead of *, which caused an error.
#For division, I assumed dividing by zero would just give infinity, but instead it broke the program. I had to add a check for num2 == 0 to handle that case.

#include <iostream>
#include <limits>
using namespace std;

enum class MenuChoice { Add = 1, Subtract, Multiply, Divide, Quit };

int main() {
    bool keepRunning = true;

    while (keepRunning) {
        // show the menu
        cout << "\n=== Calculator Menu ===\n";
        cout << "1. Add\n";
        cout << "2. Subtract\n";
        cout << "3. Multiply\n";
        cout << "4. Divide\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
int menuInput;
        cin >> menuInput;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "That was not a number. Try again.\n";
            continue;
        }

        if (menuInput < 1 || menuInput > 5) {
            cout << "Invalid choice. Please pick 1 - 5.\n";
            continue;
        }

        MenuChoice choice = static_cast<MenuChoice>(menuInput);

        if (choice == MenuChoice::Quit) {
            cout << "Exiting program now.\n";
            keepRunning = false;
            break;
        }
double num1, num2;
        cout << "Enter first number: ";
        cin >> num1;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again.\n";
            continue;
        }

        cout << "Enter second number: ";
        cin >> num2;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again.\n";
            continue;
        }

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again.\n";
            continue;
        }
double result = 0;
        switch (choice) {
            case MenuChoice::Add:
                result = num1 + num2;
                cout << "Result: " << result << endl;
                break;

            case MenuChoice::Subtract:
                result = num1 - num2;
                cout << "Result: " << result << endl;
                break;

            case MenuChoice::Multiply:
                result = num1 * num2;
                cout << "Result: " << result << endl;
                break;

            case MenuChoice::Divide:
                if (num2 == 0) {
                    cout << "Error: cannot divide by zero.\n";
                } else {
                    result = num1 / num2;
                    cout << "Result: " << result << endl;
                }
                break;
default:
                cout << "Something went wrong.\n";
                break;
        }
    }
}
