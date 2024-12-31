#ifndef PATIENTFEES_SURGERY_H
#define PATIENTFEES_SURGERY_H

#include <string>
#include <iostream>
#include <vector>
#include <limits>

/**
 * @class Surgery
 * @brief Represents the surgical services provided in a hospital, including available surgeries and their charges.
 */
class Surgery {
private:
    std::vector<std::string> surgeryNames; ///< List of available surgery names.
    std::vector<double> surgeryCharges; ///< List of charges corresponding to each surgery.
    int choice; ///< Stores the user's choice for a surgery from the menu.

public:
    /**
     * @brief Default constructor for Surgery.
     * Initializes the list of surgeries and their charges.
     */
    Surgery();

    /**
     * @brief Retrieves the charge for the selected surgery.
     * @return The charge for the selected surgery as a double.
     */
    double getSurgeryCharge() const;

    /**
     * @brief Displays a menu of available surgeries and their charges.
     * Prompts the user to make a selection and validates the input.
     */
    void displaySurgeryMenu();

    /**
     * @brief Retrieves the name of the selected surgery.
     * @return The name of the selected surgery as a string.
     */
    std::string getSurgeryType() const;
};

#endif //PATIENTFEES_SURGERY_H
