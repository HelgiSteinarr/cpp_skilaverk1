#include <optional>
#include <iostream>
#include "main.h"

using namespace std;

// -STUDENT-
Student::Student(int studentId, string studentName)
{
    this->courses = new std::optional<Course>[2];
    coursesLength = 0;
    allocatedCourseLength = 2;
    this->setId(studentId);
    this->setName(studentName);
}
void Student::registerCourse(int courseId, string courseName, float grade)
{
    Course c = Course(courseId, courseName, grade);
    if(allocatedCourseLength < coursesLength + 1){ // "Extends" the courses array because all slots are full
        // Makes a new array 2 slot larger than the original
        std::optional<Course>* newCourses = new std::optional<Course> [allocatedCourseLength + 2];
         
        // "Coppies" everything from old array to the new one
        for(int i = 0; i < allocatedCourseLength; i++)
        {
            newCourses[i] = *this->courses[i];
        }

        allocatedCourseLength += 2;
        this->courses = newCourses;
    }
    this->courses[this->coursesLength] = c;
    this->coursesLength++;    
}

void Student::updateGrade(int courseId, float grade)
{
    for (int i = 0; i < coursesLength; i++) {
        auto& course = courses[i];
        if (course && course.value().getId() == courseId)
            course.value().setGrade(grade);
    }
}

void Student::print()
{
    cout << "Nemandi: " << studentName << "(id: " << studentId << "), " << ", áfangar" << endl;
    for (int i = 0; i < coursesLength; i++) {
        auto& course = courses[i];
        if (course)
            course.value().print();
    }
}
// Student gets/sets //
void Student::setId(int idArg) { this->studentId = idArg; }
int Student::getId() { return this->studentId; }

void Student::setName(string nameArg) { this->studentName = nameArg; }
string Student::getName() { return this->studentName; }
// ----------------- //


// -COURSE-
Course::Course()
{

}
Course::Course(int courseId, string courseName, float grade)
{
    this->setId(courseId);
    this->setName(courseName);
    this->setGrade(grade);
}
void Course::print()
{
    cout << "ID: " << courseId << ", nafn: " << courseName << ", einkunn " << grade << endl;
}


// Course gets/sets //
void Course::setId(int idArg) { this->courseId = idArg; }
int Course::getId() { return this->courseId; }

void Course::setName(string nameArg) { this->courseName = nameArg; }
string Course::getName() { return this->courseName; }

void Course::setGrade(float gradeArg) { this->grade = gradeArg; }
// ---------------- //



int main()
{
    Student geiri = Student(1, "Geiri Flotti");
    
    geiri.registerCourse(33, "GAGN", 2.43);
    geiri.registerCourse(34, "FORR", 3.59);
    geiri.registerCourse(35, "ROBO", 10);
    geiri.registerCourse(36, "KEST", 6.249);
    geiri.updateGrade(34, 4.49); 
    geiri.print(); 
    return 0;
}