#include <iostream>
#include <string>
#include <cmath>
#include <Windows.h>
#include <stdlib.h>
using namespace std;
int carnum = 1;
int hits = 15;
int funamm = 1;
int points = 0;
int price = 10 * carnum * abs((hits-1)-(15*carnum));
string sel;

string lower(string sel) {
    char sel2 = sel.at(0);
    sel2 = tolower(sel2);
    string sel3(1, sel2);
    return sel3;
}

void shop() {
    system("CLS");
    cout << "C to buy better car (" << 1000 * carnum << " Funny points)\nM to gain more Funny points per minor car mistake (" << 50 * carnum * funamm << " Funny points)\nS to shorten the amount of hits per minor car mistake (" << 10 * carnum * abs((hits - 1)-(15*carnum)) << " Funny points)\nE to escape\n";
    cin >>  sel;
    if (lower(sel) == "c"){
        if (points >= 1000 * carnum){
            if (carnum >= 7) {
                cout << "\nYou already have the best car!";
                Sleep(1000);
            } else {
                points -= 1000*carnum;
                carnum += 1;
                hits = 15;
                hits *= carnum;
                funamm *= carnum;
                cout << "\nPurchase successful!";
                Sleep(1000);
            }
        } else{
            cout << "\nYou don't have enough Funny points!";
            Sleep(1000);
        }
    } else if (lower(sel) == "s") {
        price = 10 * carnum * abs((hits-1)-(15*carnum));
        if (points >= price) {
            if (hits >= 1) {
                points -= price;
                hits -= 1;
            } else {
                cout << "You are at the minimum amount of hits!";
                Sleep(1000);
            }
        } else {
            cout << "\nYou don't have enough Funny points!";
            Sleep(1000);
        }
    } else if (lower(sel) == "m"){
        if (points >= 50 *carnum * funamm){
            funamm += 1;
            points -= 50 * carnum * funamm;
        } else {
            cout << "\nYou don't have enough Funny points!";
            Sleep(1000);
        }
    }

}

int main() {

    while (true) {
        system("CLS");
        cout << "You have car " << carnum << "\nYou have " << points << " Funny points\nPress S to go to the shop\nPress M for a minor car mistake\nPress T to get a tutorial on how to do minor car mistakes\n";
        cin >> sel;
        if (lower(sel) == "t"){
            cout << "After pressing M and then Enter in the menu, you must then type any key and then press enter to perform a single hit (because c++)\nType any key and press enter to continue\n";
            cin >> sel;
        }
        if (lower(sel) == "s"){
            shop();
        }
        if (lower(sel) == "m") {
            system("CLS");
            for (int i=0; i<=hits; i++) {
                system("CLS");
                cout << "Hits: " << i << "/" << hits << "\n";
                cin >> sel;
                }
            points += funamm;
            }
        }
    return 0;
}

