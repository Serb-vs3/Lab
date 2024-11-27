#include "StudentFirstSession.h"

StudentFirstSession::StudentFirstSession(const std::string& name, int course, const std::string& group, 
                                         const std::string& recordBookNumber, const std::array<int, 4>& grades)
    : Student(name, course, group, recordBookNumber), grades(grades) {}

double StudentFirstSession::calculateAverageGrade() const {
    int sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
    return static_cast<double>(sum) / grades.size();
}

int StudentFirstSession::getGrade(int index) const {
    return grades.at(index);
}

void StudentFirstSession::setGrade(int index, int grade) {
    grades.at(index) = grade;
}

std::ostream& operator<<(std::ostream& os, const StudentFirstSession& student) {
    os << static_cast<const Student&>(student);
    os << "Grades (First Session): ";
    for (int grade : student.grades) {
        os << grade << " ";
    }
    os << "\n";
    return os;
}
