
#include "Pharmacy.h"



Pharmacy::Pharmacy(){

    medicationNames= {"Antibiotics","Painkillers", "Antacids", "Blood Thinners", "Anti-inflammatory ","Insulin", "Omeprazole", "Steroids", "Diuretics","Beta-blockers "};

    medicationCharges={200.00, 150.00, 50.00, 250.00, 100.00, 180.00, 350.00, 300.00, 120.00, 220.00};

}



void Pharmacy::displayPharmacyMenu(){
    int userChoice;

    std::cout << "Select Medication:\n";
    for (int i = 0; i < medicationNames.size(); i++) {
        std::cout << i + 1 << ". " << medicationNames[i] << " - $" << medicationCharges[i] << "\n";
    }
    std::cout << "Enter your choice (1-10): ";

    while (!(std::cin >> userChoice) || userChoice < 1 || userChoice > 10) {
        std::cout << "Invalid choice! Please try again: " << std::endl;
        std::cin.clear(); // Clear the fail state of input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    choice = userChoice - 1;  // Adjusting to zero-indexed


}


double Pharmacy::getPharmacyCharge() const{

    return medicationCharges[choice];

}

std::string Pharmacy::getPharmacyType() const{

    return medicationNames[choice];
}




