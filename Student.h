#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student {
protected:
    static int idCounter;
    const int id;
    std::string name;
    int course;
    std::string group;
    const std::string recordBookNumber;

public:
    Student(const std::string& name, int course, const std::string& group, const std::string& recordBookNumber);
    virtual ~Student() = default;

    int getId() const;
    const std::string& getName() const;
    int getCourse() const;
    const std::string& getGroup() const;
    const std::string& getRecordBookNumber() const;

    void setName(const std::string& newName);
    void setCourse(int newCourse);
    void setGroup(const std::string& newGroup);

    virtual double calculateAverageGrade() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Student& student);
};

#endif 
