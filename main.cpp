#include "Student.h"
#include "StudentFirstSession.h"
#include "StudentSecondSession.h"
#include <vector>
#include <memory>
#include <numeric>
#include <iostream>

void testStudents() {
    StudentFirstSession student1("Ivan", 1, "Group A", "12345", {5, 4, 3, 4});
    StudentFirstSession student2("Serb", 1, "Group A", "54321", {4, 3, 4, 5});
    StudentSecondSession student3("Sasha", 2, "Group B", "67890", {4, 4, 5, 5}, {3, 4, 5, 4, 5});

    std::cout << student1 << std::endl;
    std::cout << student2 << std::endl;
    std::cout << student3 << std::endl;

    std::cout << "Student 1 (After First Session): " << student1.calculateAverageGrade() << std::endl;
    std::cout << "Student 2 (After First Session): " << student2.calculateAverageGrade() << std::endl;
    std::cout << "Student 3 (After Second Session): " << student3.calculateAverageGrade() << std::endl;

    std::vector<std::unique_ptr<Student>> students;
    students.push_back(std::make_unique<StudentFirstSession>(student1));
    students.push_back(std::make_unique<StudentFirstSession>(student2));
    students.push_back(std::make_unique<StudentSecondSession>(student3));

    double totalAverage = 0.0;
    for (const auto& student : students) {
        totalAverage += student->calculateAverageGrade();
    }
    totalAverage /= students.size();


    student1.setName("Ivan ");
    student1.setGroup("Group Z");
    std::cout << student1 << std::endl;

    student1.setGrade(0, 5);
    std::cout << "Updated Grade 1 for Student 1: " << student1.getGrade(0) << std::endl;
}

int main() {
    testStudents();
    return 0;
}
