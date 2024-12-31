//
// Created by Iris on 12/30/24.
//

#include "Surgery.h"

Surgery::Surgery(){

    surgeryNames= {"Appendectomy","Gallbladder Removal", "Knee Replacement", "Hip Replacement", "Cataract Surgery", "Heart Bypass Surgery", "Spinal Fusion Surgery","Hysterectomy", "C-section","Laparoscopic Surgery" };

    surgeryCharges= {5000.00, 4500.00, 7000.00, 8000.00, 3000.00, 12000.00, 11000.00, 7500.00, 4000.00, 6000.00};

}



void Surgery::displaySurgeryMenu(){

    int userChoice;

    std::cout << "Select Medication:\n";
    for (int i = 0; i < surgeryNames.size(); i++) {
        std::cout << i + 1 << ". " << surgeryNames[i] << " - $" << surgeryCharges[i] << "\n";
    }
    std::cout << "Enter your choice (1-10): ";


    while(!(std::cin>>userChoice)|| userChoice<0 || userChoice>10)
    {
        std::cout<<"Invalid choice! Please try again:"<<std::endl;
        std::cin.clear();//clear the fail state of input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    choice = userChoice-1;


}


double Surgery::getSurgeryCharge() const{

    return surgeryCharges[choice];

}

std::string Surgery::getSurgeryType() const{

    return surgeryNames[choice];
}
