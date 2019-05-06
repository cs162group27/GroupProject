/*******************************************************************************
 ** Author:       Victoria Fisher
 ** Date:         4/28/2019
 ** Description:  Menu functions for OSU Information System.
 *******************************************************************************/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "menuFunc.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
#include "University.hpp"
#include "Building.hpp"

University uni;
//***********************FUNCTION THAT DISPLAYS THE MENU**********************//
void showMenu() {
    std::cout << "Welcome to the " << uni.getUniversityName() << " information system!" << std::endl;
    std::cout << "What would you like to do?\n" << std::endl;
    std::cout << "1. Print information about the buildings." << std::endl;
    std::cout << "2. Print information of everybody at the university." << std::endl;
    std::cout << "3. Choose a person to do work." << std::endl;
    std::cout << "4. Add a building." << std::endl;
    std::cout << "5. Add a person." << std::endl;
    std::cout << "6. Get info from file." << std::endl;
    std::cout << "7. Save info to file." << std::endl;
    std::cout << "8. Exit." << std::endl;
}

//***********************FUNCTION THAT CONTAINS THE MENU**********************//
void menu() {
    int choice;
    Student stu;
    Instructor inst;
    Building bui;
    int userInput, ageInput, buiSize;
    std::string nameInput, buiName, buiAddress, fileName;
    float gpaInput, ratingInput;
    do {
        showMenu();
        std::cin >> choice;
        if (choice == 1) {
            // we will print Building details.
            uni.printBuildingDeets();
        }
        else if (choice == 2) {
            // we will print People details.
            uni.printPeopleDeets();
        }
        else if (choice == 3) {
            // we will choose a Person to do work.
            bool personFound = false;
            std::cout << "Choose the type of Person you would like to do work:" << std::endl;
            std::cout << "1. Student." << std::endl;
            std::cout << "2. Instructor." << std::endl;
            while (personFound == false) {
                std::cin >> userInput;
                // used to add a Student
                if (userInput == 1) {
                    std::cout << "Please enter the student's name." << std::endl;
                    std::cin.ignore();
                    std::getline(std::cin, nameInput);
                    stu = Student(nameInput);
                    uni.exe_do_work(&stu);
                    personFound = true;
                }
                // used to add an Instructor
                else if (userInput == 2) {
                    std::cout << "Please enter the instructor's name." << std::endl;
                    std::cin.ignore();
                    std::getline(std::cin, nameInput);
                    inst = Instructor(nameInput);
                    uni.exe_do_work(&inst);
                    personFound = true;
                }
                // used if invalid input
                else {
                    std::cout << "That is not a valid input. Please try again." << std::endl;
                    std::cin.clear();
                    std::cin.ignore();
                }
            }
        }
        else if (choice == 4) {
            bool buiChoice = false;
            std::cout << "Enter the name of the building." << std::endl;
            std::cin.ignore();
            std::getline(std::cin, buiName);
            std::cout << "Enter the size of the building (in sqft)." << std::endl;
            while (buiChoice == false) {
                std::cin >> buiSize;
                if (buiSize > 0 && buiSize < 1000000)
                    buiChoice = true;
                else {
                    std::cout << "That is not a valid input. Please try again." << std::endl;
                    std::cin.clear();
                    std::cin.ignore();
                }
            }
            std::cout << "Please enter the address of the building." << std::endl;
            std::cin.ignore();
            std::getline(std::cin, buiAddress);
            Building bui(buiName, buiAddress, buiSize);
            uni.addBuilding(bui);
        }
        else if (choice == 5) {
            // we will add a Person.
            bool personChoice = false;
            
            std::cout << "Choose the type of Person you would like to add:" << std::endl;
            std::cout << "1. Student." << std::endl;
            std::cout << "2. Instructor." << std::endl;
            while (personChoice == false) {
                std::cin >> userInput;
                // used to add a Student
                if (userInput == 1) {
                    std::cout << "Please enter the student's name." << std::endl;
                    std::cin.ignore();
                    std::getline(std::cin, nameInput);
                    std::cout << "Please enter the student's age (16 - 90)." << std::endl;
                    do {
                        std::cin >> ageInput;
                    } while (ageInput < 16 || ageInput > 90);
                    std::cout << "Please enter the student's GPA (0.0 - 4.0)." << std::endl;
                    do {
                        std::cin >> gpaInput;
                    } while (gpaInput < 0 || gpaInput > 4.0);
                    Person *p1 = new Student(nameInput, ageInput, gpaInput);
                    uni.addPerson(p1);
                    personChoice = true;
                }
                // used to add an Instructor
                else if (userInput == 2) {
                    std::cout << "Please enter the instructor's name." << std::endl;
                    std::cin.ignore();
                    std::getline(std::cin, nameInput);
                    std::cout << "Please enter the instructor's age (25 - 90)." << std::endl;
                    do {
                        std::cin >> ageInput;
                    } while (ageInput < 25 || ageInput > 90);
                    std::cout << "Please enter the instructor's rating (0.0 - 5.0)." << std::endl;
                    do {
                        std::cin >> ratingInput;
                    } while (ratingInput < 0 || ratingInput > 5.0);
                    Person *p1 = new Instructor(nameInput, ageInput, ratingInput);
                    uni.addPerson(p1);
                    personChoice = true;
                }
                // used if invalid input
                else {
                    std::cout << "That is not a valid input. Please try again." << std::endl;
                    std::cin.clear();
                    std::cin.ignore();
                }
            }
        }
        else if (choice == 6) {
            std::cout << "Please enter the name of the file you would like to read." << std::endl;
            std::cin >> fileName;
            uni.readData(fileName);
        }
        else if (choice == 7) {
            std::cout << "Please enter the name of the file you would like to write to." << std::endl;
            std::cin >> fileName;
            uni.writeData(fileName);
            
        }
        else if (choice == 8) {
            std::cout << "You have chosen to quit. Goodbye!" << std::endl;
            exit(0);
        }
        else {
            std::cout << "That is not a valid input. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    } while (choice != 8);
}

void initialize() {
    // Initialize by adding people.
    Person *p1 = new Student ("Jacqueline", 19, 3.75);
    Person *p2 = new Student ("Jack", 27, 2.5);
    Person *p3 = new Student ("Jackie", 45, 1.6);
    Person *p4 = new Instructor ("Bob", 71, 2.6);
    Person *p5 = new Instructor ("Gleason", 55, 3.2);
    Person *p6 = new Instructor ("Nellie", 31, 4.7);
    
    // Initialize by adding buildings.
    Building bui ("DxRC", "425 SW 26th Street", 6500);
    Building bui2 ("Wlkn", "2601 SW Orchard Avenue", 4200);
    Building bui3 ("BATES", "110 SW 26th Street", 2400);
    
    // Add the people and buildings.
    uni.addPerson(p1);
    uni.addPerson(p2);
    uni.addPerson(p3);
    uni.addPerson(p4);
    uni.addPerson(p5);
    uni.addPerson(p6);
    uni.addBuilding(bui);
    uni.addBuilding(bui2);
    uni.addBuilding(bui3);
}
