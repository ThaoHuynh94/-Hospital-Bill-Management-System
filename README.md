# Hospital Bill Management System

## Overview
The **Hospital Bill Management System** is a C++ console-based application designed to simplify the management of patient accounts and billing processes in a hospital environment. It provides functionalities for managing patient details, calculating charges for surgeries and pharmacy items, and integrating insurance coverage to produce an accurate and detailed bill.

---

## Features

1. **Patient Account Management**
   - Collects and validates patient information such as name, gender, age, ID, admission/discharge dates, and daily room rates.

2. **Surgery and Pharmacy Charges**
   - Allows the user to choose from predefined surgery and pharmacy options.
   - Calculates and adds charges to the patient account.

3. **Insurance Integration**
   - Accounts for insurance coverage percentage in calculating the total payable amount.

4. **Input Validation**
   - Ensures that user inputs are valid, including string inputs, numerical ranges, and date formats (MM/DD/YYYY).

5. **Billing Summary**
   - Displays a detailed breakdown of patient charges, including itemized surgery and pharmacy charges.

---

## How It Works

### Menu Options
1. **Create and Process Patient Account**: Collects patient details and calculates the total charges based on selected services.
2. **Exit**: Closes the program.

### Workflow
1. Input patient information such as name, gender, age, ID, admission/discharge dates, and daily room rates.
2. Select surgery and pharmacy options to add to the patient account.
3. Calculate the final charges considering itemized costs and insurance coverage.
4. Display the detailed bill summary.

---

## Project Structure

```plaintext
Hospital Bill Management System/
├── Charge.h
├── PatientAccount.h
├── PatientAccount.cpp
├── Pharmacy.h
├── Pharmacy.cpp
├── Surgery.h
├── Surgery.cpp
├── main.cpp
```

### Main Components
- **`Charge`**: Represents individual charges (description and amount).
- **`PatientAccount`**: Manages patient details and aggregates all charges.
- **`Pharmacy`**: Provides options for pharmacy items and calculates their charges.
- **`Surgery`**: Provides options for surgery types and calculates their charges.

---

## Input Validation
The system validates user inputs for:
- **String Fields**: Ensures non-empty inputs.
- **Integer Fields**: Validates numerical ranges.
- **Double Fields**: Validates numerical ranges for charges and rates.
- **Date Fields**: Validates the format as `MM/DD/YYYY`.

---

## Prerequisites
- **C++ Compiler**: A C++17 or later compiler is recommended.
- **Build Tools**: Tools such as `make` or an IDE (e.g., Visual Studio, CLion) to build the project.

---

## Compilation and Execution

### Using `g++`:
1. Navigate to the project directory.
2. Run the following command:
   ```bash
   g++ -std=c++17 -o HospitalBill main.cpp PatientAccount.cpp Pharmacy.cpp Surgery.cpp
   ```
3. Execute the program:
   ```bash
   ./HospitalBill
   ```

---

## Example Usage

### Sample Menu
```plaintext
========================================
           HOSPITAL BILL SYSTEM          
========================================
1. Create and Process Patient Account
2. Exit
```

### Input Example
```plaintext
Enter Patient Name: John Doe
Enter Patient Gender (Male/Female/Other): Male
Enter Patient Age: 30
Enter Patient ID: 12345
Enter Admission Date (MM/DD/YYYY): 12/01/2024
Enter Discharge Date (MM/DD/YYYY): 12/10/2024
Enter Daily Rate ($): 500
Enter Insurance Provider: BlueShield
Enter Insurance Coverage Percentage: 80
```

### Output Example
```plaintext
Patient Details:
Name: John Doe
Gender: Male
Age: 30
Patient ID: 12345
Admission Date: 12/01/2024
Discharge Date: 12/10/2024
Days Spent: 9

Charges:
1. Surgery: Appendectomy - $5000.00
2. Pharmacy: Painkillers - $200.00

Insurance Coverage: 80%
Total Charges Before Insurance: $9800.00
Total Payable Amount: $1960.00
```
