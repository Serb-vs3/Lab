#include "Student.h"

int Student::idCounter = 0; 

Student::Student(const std::string& name, int course, const std::string& group, const std::string& recordBookNumber)
    : id(++idCounter), name(name), course(course), group(group), recordBookNumber(recordBookNumber) {}

int Student::getId() const {
    return id;
}

const std::string& Student::getName() const {
    return name;
}

int Student::getCourse() const {
    return course;
}

const std::string& Student::getGroup() const {
    return group;
}

const std::string& Student::getRecordBookNumber() const {
    return recordBookNumber;
}

void Student::setName(const std::string& newName) {
    name = newName;
}

void Student::setCourse(int newCourse) {
    course = newCourse;
}

void Student::setGroup(const std::string& newGroup) {
    group = newGroup;
}

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "ID: " << student.id << "\n"
       << "Name: " << student.name << "\n"
       << "Course: " << student.course << "\n"
       << "Group: " << student.group << "\n"
       << "Record Book Number: " << student.recordBookNumber << "\n";
    return os;
}
