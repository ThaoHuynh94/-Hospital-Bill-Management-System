# Hospital Bill Management System

## Project Description
This Hospital Bill Management System is designed to assist hospitals in efficiently managing patient accounts, calculating bills, and handling charges for surgeries and medications. The system offers features like insurance coverage calculations, itemized charges, and patient details display. It ensures accurate and user-friendly management of hospital billing processes.

## Features
- Create and process patient accounts with detailed information.
- Calculate total hospital charges, including room charges, medications, and surgeries.
- Incorporate insurance coverage for bill adjustments.
- Validate user inputs for accuracy and reliability.
- Display comprehensive hospital bill statements.

## Requirements
- C++17 or later
- Standard Template Library (STL)

## Usage
To use the system, compile the provided code files and execute the program. Follow the on-screen menu to create and process patient accounts or exit the program.

## Input and Output Example
### Example Interaction
```
========================================
           HOSPITAL BILL SYSTEM          
========================================
1. Create and Process Patient Account
2. Exit
Enter your choice: 1
Enter Patient Name: Hoang Tran
Enter Patient Gender (Male/Female/Other): Male
Enter Patient Age: 33
Enter Patient ID: 1234
Enter Admission Date (MM/DD/YYYY): 12/2/2024
Invalid date format. Please enter in MM/DD/YYYY format.
Enter Admission Date (MM/DD/YYYY): 12/02/2024
Enter Discharge Date (MM/DD/YYYY): 12/30/2024
Enter Daily Rate ($): 200
Enter Insurance Provider: Kaiser
Enter Insurance Coverage Percentage: 30
Select Medication:
1. Appendectomy - $5000
2. Gallbladder Removal - $4500
3. Knee Replacement - $7000
4. Hip Replacement - $8000
5. Cataract Surgery - $3000
6. Heart Bypass Surgery - $12000
7. Spinal Fusion Surgery - $11000
8. Hysterectomy - $7500
9. C-section - $4000
10. Laparoscopic Surgery - $6000
Enter your choice (1-10): 9
Select Medication:
1. Antibiotics - $200
2. Painkillers - $150
3. Antacids - $50
4. Blood Thinners - $250
5. Anti-inflammatory  - $100
6. Insulin - $180
7. Omeprazole - $350
8. Steroids - $300
9. Diuretics - $120
10. Beta-blockers  - $220
Enter your choice (1-10): 10
=======================================================
              HOSPITAL BILL STATEMENT         
=======================================================

Patient Information:
------------------------------------------------------
Name:               Hoang Tran
Gender:             Male
Age:                33
Patient ID:         1234
Admission Date:     Mon Dec 02 2024
Discharge Date:     Mon Dec 30 2024
Days Spent:         29
Insurance Provider: Kaiser
Insurance Coverage: 30%
Daily Rate:         $200.00

Hospital Charges:
------------------------------------------------------
- Pharmacy: Beta-blockers      $220.00
- Surgery: C-section           $4000.00
------------------------------------------------------
Subtotal:                             $4220.00
Room Charges (29 days):               $5800.00

Tax Amount:                           $1077.15
------------------------------------------------------
Total Before Insurance:               $11097.15
Insurance Coverage (30.00%):         -$3329.14
------------------------------------------------------
Total Amount Due:                     $7768.00

=======================================================
               THANK YOU FOR CHOOSING US         
=======================================================

========================================
           HOSPITAL BILL SYSTEM          
========================================
1. Create and Process Patient Account
2. Exit
Enter your choice: 3
Invalid input. Please enter a number between 1 and 2.
Enter your choice: 2
Exiting program. Thank you!
```

## File Structure
- **PatientAccount.h**: Handles patient details and bill calculations.
- **Pharmacy.h**: Manages pharmacy charges.
- **Surgery.h**: Manages surgery charges.
- **Charge.h**: Represents individual charges with descriptions and amounts.
- **main.cpp**: Contains the main program logic and user interface.

