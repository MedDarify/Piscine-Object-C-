#include "command.hpp"
#include "thuesdayDiscount.hpp"
#include "packageReductionDiscount.hpp"
#include <iostream>
#include <vector>


void printCommandPrice(Command* cmd) {
    std::cout << "--- Processing Command ---" << std::endl;
    double finalPrice = cmd->get_total_price();
    std::cout << "Final Price: " << finalPrice << " euros" << std::endl;
}

int main() {
    std::vector<Command*> commands;

    std::cout << "\n=== CASE 1: Tuesday Discount ===" << std::endl;
    ThuesdayDiscountCommand* cmd1 = new ThuesdayDiscountCommand(101, "Tuesday", "Client A");
    cmd1->addArticleToCommand("Laptop", 120.0, 1); 
    commands.push_back(cmd1); 

     
    std::cout << "\n=== CASE 2: Package Reduction (over 150) ===" << std::endl;
    PackageReductionDiscountCommand* cmd2 = new PackageReductionDiscountCommand(102, "Wednesday", "Client B");
    cmd2->addArticleToCommand("Monitor", 160.0, 1); 
    commands.push_back(cmd2); 

    
    std::cout << "\n=== CASE 3: Normal Command (no discount) ===" << std::endl;
    Command* cmd3 = new Command(103, "Monday", "Client C");
    cmd3->addArticleToCommand("Keyboard", 80.0, 1);
    commands.push_back(cmd3); 

    std::cout << "\n=== CASE 4: Package Reduction (under 150) ===" << std::endl;
    PackageReductionDiscountCommand* cmd4 = new PackageReductionDiscountCommand(104, "Thursday", "Client D");
    cmd4->addArticleToCommand("Mouse", 50.0, 1); 
    commands.push_back(cmd4); 


    std::cout << "\n\n=== PROCESSING ALL COMMANDS VIA POLYMORPHISM ===" << std::endl;
    for (size_t i = 0; i < commands.size(); ++i) {
        printCommandPrice(commands[i]);
    }

    
    std::cout << "\n\n--- CLEANING UP ---" << std::endl;
    for (size_t i = 0; i < commands.size(); ++i) {
        delete commands[i];
    }
    commands.clear();

    std::cout << "\n--- End of Test ---" << std::endl;
    return 0;
}