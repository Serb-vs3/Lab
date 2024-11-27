#ifndef STUDENTFIRSTSESSION_H
#define STUDENTFIRSTSESSION_H

#include "Student.h"
#include <array>

class StudentFirstSession : public Student {
private:
    std::array<int, 4> grades;

public:
    StudentFirstSession(const std::string& name, int course, const std::string& group, 
                        const std::string& recordBookNumber, const std::array<int, 4>& grades);
    double calculateAverageGrade() const override;

    int getGrade(int index) const;
    void setGrade(int index, int grade);

    friend std::ostream& operator<<(std::ostream& os, const StudentFirstSession& student);
};

#endif 
