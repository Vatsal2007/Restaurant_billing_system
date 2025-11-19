#include <stdio.h>

int main() {
//menu
    //categories
    char category[4][20] = {
        "starters",
        "Main Course",
        "Desserts",
        "Beverages"
    };

    // Items 
    char items[4][3][30] = {
        { "Spring Roll" , "Paneer Tikka" , "Manchurian" },               // Starters
        { "Veg Thali", "Paneer Butter Masala", "Fried Rice" },        // Main Course
        { "Ice Cream"  , "Brownie", "Gulab Jamun" },                    // Desserts
        { "Coffee", "Cold Drink", "Juice" }                           // Beverages
    };

    // Prices for each item
    int price[4][3] = {
        { 80, 120, 100 },   // Starters
        { 180, 150, 130 },  // Main Course
        { 70, 90, 60 },     // Desserts
        { 50, 40, 60 }      // Beverages
    };

   