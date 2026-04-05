#include <iostream>
#include <iomanip>

const double DISCOUNT_10_PERCENT = 0.10;
const double DISCOUNT_20_PERCENT = 0.20;
const double DISCOUNT_30_PERCENT = 0.30;
const double ADDITIONAL_DISCOUNT_5_PERCENT = 0.05;

int main() {
    double costPerNight, salesTax;
    int numRooms, numDays;

    std::cout << "Enter the cost of renting one room: $";
    std::cin >> costPerNight;

    std::cout << "Enter the number of rooms booked: ";
    std::cin >> numRooms;

    std::cout << "Enter the number of days the rooms are booked: ";
    std::cin >> numDays;

    std::cout << "Enter the sales tax (as a percent): ";
    std::cin >> salesTax;

    double subtotal = costPerNight * numRooms * numDays;
    double roomDiscount = 0.0;

    if (numRooms >= 30) {
        roomDiscount = DISCOUNT_30_PERCENT;
    } else if (numRooms >= 20) {
        roomDiscount = DISCOUNT_20_PERCENT;
    } else if (numRooms >= 10) {
        roomDiscount = DISCOUNT_10_PERCENT;
    }

    subtotal *= (1.0 - roomDiscount);

    if (numDays >= 3) {
        subtotal *= (1.0 - ADDITIONAL_DISCOUNT_5_PERCENT);
    }

    double taxAmount = subtotal * (salesTax / 100.0);
    double totalAmount = subtotal + taxAmount;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nCost per room per night: $" << costPerNight << '\n';
    std::cout << "Room discount applied: " << roomDiscount * 100 << "%\n";
    std::cout << "Number of rooms booked: " << numRooms << '\n';
    std::cout << "Number of days booked: " << numDays << '\n';
    std::cout << "Total cost of rooms: $" << subtotal << '\n';
    std::cout << "Sales tax: $" << taxAmount << '\n';
    std::cout << "Total billing amount: $" << totalAmount << '\n';

    return 0;
}
