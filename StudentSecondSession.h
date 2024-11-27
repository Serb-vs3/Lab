#ifndef STUDENTSECONDSESSION_H
#define STUDENTSECONDSESSION_H

#include "StudentFirstSession.h"
#include <array>

class StudentSecondSession : public StudentFirstSession {
private:
    std::array<int, 5> gradesSecondSession;

public:
    StudentSecondSession(const std::string& name, int course, const std::string& group, 
                         const std::string& recordBookNumber, const std::array<int, 4>& firstSessionGrades,
                         const std::array<int, 5>& secondSessionGrades);
    double calculateAverageGrade() const override;

    int getGradeSecondSession(int index) const;
    void setGradeSecondSession(int index, int grade);

    friend std::ostream& operator<<(std::ostream& os, const StudentSecondSession& student);
};

#endif 
