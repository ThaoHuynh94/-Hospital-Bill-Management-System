cmake_minimum_required(VERSION 3.27)
project(PatientFees)

set(CMAKE_CXX_STANDARD 17)

add_executable(PatientFees main.cpp
        PatientAccount.cpp
        PatientAccount.h
        Surgery.cpp
        Surgery.h
        Pharmacy.cpp
        Pharmacy.h
        PatientFeesDriver.cpp
        Charge.cpp
        Charge.h)
