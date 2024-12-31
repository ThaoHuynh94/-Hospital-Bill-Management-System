#include <iostream>
#include <string>
#include <vector>
#include "PatientAccount.h"
#include "Pharmacy.h"
#include "Surgery.h"
#include "Charge.h"

// Function prototypes for input validation

/**
 * @brief Prompts the user for a validated string input.
 * @param prompt The message to display when asking for input.
 * @return A non-empty validated string input.
 */
std::string getValidatedString(const std::string& prompt);

/**
 * @brief Prompts the user for a validated integer input within a specified range.
 * @param prompt The message to display when asking for input.
 * @param min The minimum valid value.
 * @param max The maximum valid value.
 * @return A validated integer within the range [min, max].
 */
int getValidatedInt(const std::string& prompt, int min, int max);

/**
 * @brief Prompts the user for a validated double input within a specified range.
 * @param prompt The message to display when asking for input.
 * @param min The minimum valid value.
 * @param max The maximum valid value.
 * @return A validated double within the range [min, max].
 */
double getValidatedDouble(const std::string& prompt, double min, double max);

/**
 * @brief Prompts the user for a validated date in MM/DD/YYYY format.
 * @param prompt The message to display when asking for input.
 * @return A validated date string in MM/DD/YYYY format.
 */
std::string getValidatedDate(const std::string& prompt);

/**
 * @brief Handles the creation and processing of a patient account.
 * Gathers patient details, calculates charges, and displays the patient's details.
 */
void createAndProcessPatient();

/**
 * @brief Displays the main menu for the hospital billing system.
 */
void displayMenu();

int main() {
    int choice;

    do {
        displayMenu();
        choice = getValidatedInt("Enter your choice: ", 1, 2);

        switch (choice) {
            case 1:
                createAndProcessPatient();
                break;
            case 2:
                std::cout << "Exiting program. Thank you!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 2);

    return 0;
}

// Menu display function

void displayMenu() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "           HOSPITAL BILL SYSTEM          " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "1. Create and Process Patient Account" << std::endl;
    std::cout << "2. Exit" << std::endl;
}

// Main logic to create and process a patient account

void createAndProcessPatient() {
    std::string name = getValidatedString("Enter Patient Name: ");
    std::string gender = getValidatedString("Enter Patient Gender (Male/Female/Other): ");
    int age = getValidatedInt("Enter Patient Age: ", 0, 120);
    int patientID = getValidatedInt("Enter Patient ID: ", 1, 1000000);
    std::string admissionDate = getValidatedDate("Enter Admission Date (MM/DD/YYYY): ");
    std::string dischargeDate = getValidatedDate("Enter Discharge Date (MM/DD/YYYY): ");
    double dailyRate = getValidatedDouble("Enter Daily Rate ($): ", 50.0, 5000.0);
    std::string insuranceProvider = getValidatedString("Enter Insurance Provider: ");
    int coveragePercentage = getValidatedInt("Enter Insurance Coverage Percentage: ", 0, 100);

    // Create PatientAccount object
    PatientAccount patient(name, gender, age, patientID, admissionDate, dischargeDate, dailyRate, insuranceProvider, coveragePercentage);

    Surgery surgery;
    Pharmacy pharmacy;

    // Collect surgery charges
    surgery.displaySurgeryMenu();
    Charge surgeryCharge = {"Surgery: " + surgery.getSurgeryType(), surgery.getSurgeryCharge()};

    // Collect pharmacy charges
    pharmacy.displayPharmacyMenu();
    Charge pharmacyCharge = {"Pharmacy: " + pharmacy.getPharmacyType(), pharmacy.getPharmacyCharge()};

    // Add charges to patient account
    patient.addCharge(pharmacyCharge);
    patient.addCharge(surgeryCharge);

    // Display patient details
    patient.displayPatientDetails();
}

// Input validation functions

std::string getValidatedString(const std::string& prompt) {
    std::string input;
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
    } while (input.empty());
    return input;
}


int getValidatedInt(const std::string& prompt, int min, int max) {
    int input;
    while (true) {
        std::cout << prompt;
        std::cin >> input;
        if (std::cin.fail() || input < min || input > max) {
            std::cin.clear(); // Clear error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a number between " << min << " and " << max << "." << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
            return input;
        }
    }
}


double getValidatedDouble(const std::string& prompt, double min, double max) {
    double input;
    while (true) {
        std::cout << prompt;
        std::cin >> input;
        if (std::cin.fail() || input < min || input > max) {
            std::cin.clear(); // Clear error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a number between " << min << " and " << max << "." << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
            return input;
        }
    }
}


std::string getValidatedDate(const std::string& prompt) {
    std::string input;
    do {
        std::cout << prompt;
        std::cin >> input;
        if (input.size() != 10 || input[2] != '/' || input[5] != '/') {
            std::cout << "Invalid date format. Please enter in MM/DD/YYYY format." << std::endl;
        } else {
            return input;
        }
    } while (true);
}
