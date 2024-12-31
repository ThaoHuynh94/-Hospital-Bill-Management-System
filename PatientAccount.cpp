#include "PatientAccount.h"


PatientAccount::PatientAccount(): name(" "), gender(" "), age(0), patientID(0), daySpent(0),totalCharge(0.0), dailyRate(0.0), insuranceProvider(" "), coveragePercentage(0.0)
{
    admissionDate = std::chrono::system_clock::now();  // Current date and time
    dischargeDate = std::chrono::system_clock::now();  // Current date and time
}

PatientAccount:: PatientAccount(const std::string &name, const std::string  &gender,  int const &age, int patientID,
                                    std::string const &admissionDateStr, std::string const &dischargeDateStr, double const &dailyRate,
                                    std::string const &insuranceProvider, double const &coveragePercentage)
                                    : name(name), gender(gender), age(age), patientID(patientID), dailyRate(dailyRate),
                                    insuranceProvider(insuranceProvider), coveragePercentage(coveragePercentage)
{
    admissionDate = convertToTimePoint(admissionDateStr);

    dischargeDate = convertToTimePoint(dischargeDateStr);

}


//The convertToTimePoint function takes a date string in the format "MM/DD/YYYY" (e.g., "12/02/2024")
// and converts it into a std::chrono::system_clock::time_point
// which is a point in time that the C++ standard library uses for representing dates and times.
std::chrono::system_clock::time_point PatientAccount::convertToTimePoint(const std::string& dateStr) {
    int month, day, year; // hold the numeric values for the month, day, and year extracted from the input date string.

    char delimiter; //This variable will hold the delimiter character (/) between the date components (month, day, year)
                    // but it is not used after the extraction process.


    //std::istringstream is specifically designed to read data from a string as if it were a stream (like reading from a file or user input)
    //It makes extracting data (such as integers, characters, or even dates) from a string straightforward using the >> operator
    // which is typically used to read data from input streams

    std::istringstream dateStream(dateStr);

    //extracts the month, day, and year from the date string.
    dateStream >> month >> delimiter >> day >> delimiter >> year;

    //Step 1:  Create a std::tm structure and initialize it, The {} initializes all members of the std::tm structure to 0

    std::tm time = {};

    //Step 2: Set the individual components of the std::tm structure (year, month, and day)

    time.tm_year = year - 1900; // tm_year is years since 1900
    time.tm_mon = month - 1;    // tm_mon is 0-based (0 = January)
    time.tm_mday = day;

    // Convert the std::tm structure into a std::time_t object, which represents the time as seconds since the Unix epoch (January 1, 1970)
    //std::mktime is a function that converts a std::tm structure into a std::time_t object.
    //std::time_t represents time as the number of seconds since the "epoch"

    std::time_t time_since_epoch = std::mktime(&time);

    return std::chrono::system_clock::from_time_t(time_since_epoch);
}


// Method to calculate the number of days spent in the hospital
int PatientAccount::calculateDaysSpent() {
    // Calculate the duration between dischargeDate and admissionDate
    auto duration = dischargeDate - admissionDate;

    // Convert duration to hours, then to days
    auto durationInHours = std::chrono::duration_cast<std::chrono::hours>(duration);
    int daysSpent = static_cast<int>(durationInHours.count() / 24);

    // Include both admission and discharge dates
    daysSpent += 1;

    // Store the result in daySpent and return it
    daySpent = daysSpent;
    return daySpent;
}

// Display patient details

void PatientAccount::displayPatientDetails()  {
    double roomCharges = dailyRate * calculateDaysSpent();

    double totalCharges = roomCharges + calculateItemizedCharges();

    double taxAmount = (10.75*totalCharges)/100.0; // tax is 10.75%

    totalCharges += taxAmount;

    double insuranceDeduction = totalCharges * (coveragePercentage / 100.0);

    double totalAfterInsurance = totalCharges - insuranceDeduction;

    std::cout << "=======================================================" << std::endl;
    std::cout << "              HOSPITAL BILL STATEMENT         " << std::endl;
    std::cout << "=======================================================" << std::endl;

    std::cout << "\nPatient Information:" << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Name:               " << name << std::endl;
    std::cout << "Gender:             " << gender << std::endl;
    std::cout << "Age:                " << age << std::endl;
    std::cout << "Patient ID:         " << patientID << std::endl;
    std::cout << "Admission Date:     " << timePointToString(admissionDate) << std::endl;
    std::cout << "Discharge Date:     " << timePointToString(dischargeDate) << std::endl;
    std::cout << "Days Spent:         " << daySpent << std::endl;
    std::cout << "Insurance Provider: " << insuranceProvider << std::endl;
    std::cout << "Insurance Coverage: " << coveragePercentage << "%" << std::endl;
    std::cout << "Daily Rate:         $" << std::fixed << std::setprecision(2) << dailyRate << std::endl;

    std::cout << "\nHospital Charges:" << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    for (const Charge& charge : itemizedCharges) {
        std::cout << "- " << charge.description << std::setw(30 - charge.description.length())
                  << "$" << std::fixed << std::setprecision(2) << charge.amount << std::endl;
    }

    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Subtotal:                             $" << std::fixed << std::setprecision(2) << calculateItemizedCharges() << std::endl;
    std::cout << "Room Charges (" << daySpent << " days):               $" << roomCharges << std::endl<< std::endl;
    std::cout << "Tax Amount:                           $" << taxAmount << std::fixed << std::setprecision(2) <<std::endl;

    std::cout << "------------------------------------------------------" << std::endl;

    std::cout << "Total Before Insurance:               $" << totalCharges << std::endl;
    std::cout << "Insurance Coverage (" << coveragePercentage << "%):         -$" << insuranceDeduction << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Total Amount Due:                     $" << totalAfterInsurance << std::endl;

    std::cout << "\n=======================================================" << std::endl;
    std::cout << "               THANK YOU FOR CHOOSING US         " << std::endl;
    std::cout << "=======================================================" << std::endl;
}

double PatientAccount::calculateItemizedCharges() {

    double ItemizedCharges =0.0;

    for (Charge charge: itemizedCharges)
    {
        ItemizedCharges += charge.amount;
    }

    return ItemizedCharges;
}


void PatientAccount::addCharge(Charge const &charge){

    itemizedCharges.push_back(charge);
}




// Helper function to convert time_point to string format
std::string PatientAccount::timePointToString(std::chrono::system_clock::time_point &timePoint) {
    std::time_t timeT = std::chrono::system_clock::to_time_t(timePoint);

    // Use std::localtime to convert time_t to tm
    std::tm* tmPtr = std::localtime(&timeT);

    // Format the date (weekday month day year) using std::put_time
    std::ostringstream oss;
    oss << std::put_time(tmPtr, "%a %b %d %Y"); // Format to Mon Dec 02 2024

    return oss.str();
}