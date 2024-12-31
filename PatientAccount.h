#ifndef PATIENTFEES_PATIENTACCOUNT_H
#define PATIENTFEES_PATIENTACCOUNT_H

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <sstream>
#include "Charge.h"
#include <iomanip>
#include <vector>

/**
 * @class PatientAccount
 * @brief Represents a patient account in a hospital system, including personal details, charges, and insurance information.
 */
class PatientAccount {
private:
    std::string name; ///< Patient's name
    std::string gender; ///< Patient's gender
    int age; ///< Patient's age
    int patientID; ///< Unique identifier for the patient
    int daySpent; ///< Number of days the patient spent in the hospital

    // Dates
    std::chrono::system_clock::time_point admissionDate; ///< Admission date of the patient
    std::chrono::system_clock::time_point dischargeDate; ///< Discharge date of the patient

    // Charges
    double totalCharge; ///< Total charge for the patient, including room fees and other services
    double dailyRate; ///< Daily room fee
    std::vector<Charge> itemizedCharges; ///< List of itemized charges, each containing a description and amount

    // Insurance
    std::string insuranceProvider; ///< Name of the insurance provider
    double coveragePercentage; ///< Percentage of the bill covered by insurance

    /**
     * @brief Converts a time point to a formatted string (MM/DD/YYYY).
     * @param timePoint The time point to be converted.
     * @return A formatted string representation of the time point.
     */
    std::string timePointToString(std::chrono::system_clock::time_point &timePoint);

public:
    /**
     * @brief Default constructor for PatientAccount.
     */
    PatientAccount();

    /**
     * @brief Parameterized constructor for PatientAccount.
     * @param name Patient's name.
     * @param gender Patient's gender.
     * @param age Patient's age.
     * @param patientID Unique patient ID.
     * @param admissionDateStr Admission date in MM/DD/YYYY format.
     * @param dischargeDateStr Discharge date in MM/DD/YYYY format.
     * @param dailyRate Daily room fee.
     * @param insuranceProvider Name of the insurance provider.
     * @param coveragePercentage Percentage of bill covered by insurance.
     */
    PatientAccount(const std::string &name, const std::string &gender, int const &age, int patientID,
                   std::string const &admissionDateStr, std::string const &dischargeDateStr, double const &dailyRate,
                   std::string const &insuranceProvider, double const &coveragePercentage);

    /**
     * @brief Converts a date string in MM/DD/YYYY format to a time_point object.
     * @param dateStr The date string to be converted.
     * @return The corresponding time_point object.
     */
    std::chrono::system_clock::time_point convertToTimePoint(const std::string& dateStr);

    /**
     * @brief Calculates the number of days the patient spent in the hospital.
     * @return The number of days spent.
     */
    int calculateDaysSpent();

    /**
     * @brief Displays the patient's details, including personal information, charges, and insurance.
     */
    void displayPatientDetails();

    /**
     * @brief Adds an itemized charge to the patient's account.
     * @param charge A Charge object containing the description and amount.
     */
    void addCharge(Charge const &charge);

    /**
     * @brief Calculates the total amount of itemized charges.
     * @return The total itemized charges.
     */
    double calculateItemizedCharges();
};

#endif //PATIENTFEES_PATIENTACCOUNT_H
