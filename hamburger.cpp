#include <iostream>
#include <string>
#include <iomanip>

int main(){

    const double pchburger = 5.50;
    const double pburger = 4.00;
    const double pbacon = 7.00;
    const double ponion = 0.50;
    const double plargefries = 4.00;
    const double psmalfries = 3.25;

    int burgerchoice = 0, burgerquantity = 0, onionquantity = 0, friesquantity = 0;
    std::string onionchoice, frieschoice, friessize;
    double burgerprice = 0.0;
    std::string burgertype;

    std::cout << "Welcome to NextBurger House! which kind of burger would you like?\n";
    std::cout << "Please choose your hamburger:\n";
    std::cout << "1. Cheeseburger ($5.50)\n";
    std::cout << "2. Classic ($4.00)\n";
    std::cout << "3. Bacon Burger ($7.00)\n";
    std::cout << "Enter the hamburger of your choice: (1-3)";
    std::cin >> burgerchoice;

    switch (burgerchoice) {

        case 1:
            burgerprice = pchburger;
            burgertype = "Cheeseburger";
            break;
        case 2:
            burgerprice = pburger;
            burgertype = "Classic";
            break;
        case 3:
            burgerprice = pbacon;
            burgertype = "Bacon Burger";
            break;
        default:
            std::cout << "Invalid choice. Please select a valid burger option.\n";
            return 1;
    }

    std::cout << "How many " << burgertype << "(s) would you like? ";
    std::cin >> burgerquantity;
    if (burgerquantity < 0 || burgerquantity > 10) {
        std::cout << "Invalid quantity. Please enter a number between 0 and 10.\n";
        return 1;  
    }

    std::cout << "Would you like to add onions for $0.50 each? (yes/no): ";
    std::cin >> onionchoice;
    if(onionchoice == "yes" || frieschoice == "yes"){
        onionquantity = burgerquantity;
    }

    std::cout << "Would you like to add fries? (yes/no): ";
    std::cin >> frieschoice;
    if (frieschoice == "yes" || frieschoice == "Yes"){
        std::cout << "What size of fries would you like? (small/large): ";
        std::cin >> friessize;
        std::cout << "How many orders of " << friessize << " fries would you like? ";
        std::cin >> friesquantity;
        if (friesquantity < 0 || friesquantity > 10) {
            std::cout << "Invalid quantity. Please enter a number between 0 and 10.\n";
            return 1;  
        }
    }

    double subtotalburger = burgerquantity * burgerprice;
    double subtotalonion = onionquantity * ponion;
    double subtotalfries = 0.0;

    if (frieschoice == "yes") {
        if (friessize == "small") {
            subtotalfries = friesquantity * psmalfries;
        } else if (friessize == "large") {
            subtotalfries = friesquantity * plargefries;
        }
    }
    double subtotal = subtotalburger + subtotalonion + subtotalfries;
    double tax = subtotal * 0.13;
    double total = subtotal + tax;

    std::cout << "\n----- TAKEOUT ORDER -----\n";
    if (burgerquantity > 0)
        std::cout << burgerquantity << " x " << burgertype << "(s) @ $"  << burgerprice << " ea: $" << std::fixed << std::setprecision(2) << subtotalburger << "\n";
    if (onionquantity > 0)
        std::cout << onionquantity << " x Onions @ $0.50 ea: $" << std::fixed << std::setprecision(2) << subtotalonion << "\n";
    if (friesquantity > 0)
        std::cout << friesquantity << " x " << friessize << " Fries @ $" << (friessize == "small" ? psmalfries : plargefries) << " ea: $" << std::fixed << std::setprecision(2) << subtotalfries << "\n";
    std::cout << "---------------------\n";
    std::cout << "---------------------\n";
    std::cout << "Subtotal: $" << std::fixed << std::setprecision(2) << subtotal << "\n";
    std::cout << "Tax (13%): $" << std::fixed << std::setprecision(2) << tax << "\n";
    std::cout << "Total: $" << std::fixed << std::setprecision(2) << total << "\n";
    std::cout << "---------------------\n";
    std::cout << "---------------------\n";

}