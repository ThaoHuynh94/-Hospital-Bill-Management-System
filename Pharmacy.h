#ifndef PATIENTFEES_PHARMACY_H
#define PATIENTFEES_PHARMACY_H

#include <string>
#include <iostream>
#include <vector>
#include <limits>

/**
 * @class Pharmacy
 * @brief Represents the pharmacy services provided in a hospital, including medication options and their charges.
 */
class Pharmacy {
private:
    std::vector<std::string> medicationNames; ///< List of available medication names.
    std::vector<double> medicationCharges; ///< List of charges corresponding to each medication.
    int choice; ///< Stores the user's choice for a medication from the menu.

public:
    /**
     * @brief Default constructor for Pharmacy.
     * Initializes the list of medications and their charges.
     */
    Pharmacy();

    /**
     * @brief Displays a menu of available medications and their charges.
     * Prompts the user to make a selection and validates the input.
     */
    void displayPharmacyMenu();

    /**
     * @brief Retrieves the charge for the selected medication.
     * @return The charge for the selected medication as a double.
     */
    double getPharmacyCharge() const;

    /**
     * @brief Retrieves the name of the selected medication.
     * @return The name of the selected medication as a string.
     */
    std::string getPharmacyType() const;
};

#endif //PATIENTFEES_PHARMACY_H
