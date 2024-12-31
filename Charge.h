#ifndef PATIENTFEES_CHARGE_H
#define PATIENTFEES_CHARGE_H
#include <string>

struct Charge {


    std::string description; ///< Description of the charge (e.g., "Surgery: Appendectomy")

    double amount; ///<Cost of this charge


    //parameterized constructor
    Charge(std::string description, double amount);

};


#endif //PATIENTFEES_CHARGE_H
