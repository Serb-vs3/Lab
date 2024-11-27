#include "StudentSecondSession.h"
#include <numeric>

StudentSecondSession::StudentSecondSession(const std::string& name, int course, const std::string& group, 
                                           const std::string& recordBookNumber, const std::array<int, 4>& firstSessionGrades,
                                           const std::array<int, 5>& secondSessionGrades)
    : StudentFirstSession(name, course, group, recordBookNumber, firstSessionGrades), gradesSecondSession(secondSessionGrades) {}

double StudentSecondSession::calculateAverageGrade() const {
    double firstSessionAvg = StudentFirstSession::calculateAverageGrade();
    double secondSessionAvg = static_cast<double>(std::accumulate(gradesSecondSession.begin(), gradesSecondSession.end(), 0)) / gradesSecondSession.size();
    return (firstSessionAvg + secondSessionAvg) / 2;
}

int StudentSecondSession::getGradeSecondSession(int index) const {
    return gradesSecondSession.at(index);
}

void StudentSecondSession::setGradeSecondSession(int index, int grade) {
    gradesSecondSession.at(index) = grade;
}

std::ostream& operator<<(std::ostream& os, const StudentSecondSession& student) {
    os << static_cast<const StudentFirstSession&>(student);
    os << "Grades (Second Session): ";
    for (int grade : student.gradesSecondSession) {
        os << grade << " ";
    }
    os << "\n";
    return os;
}
