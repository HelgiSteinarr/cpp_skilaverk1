#pragma once
#include <iostream>
#include <optional>

using namespace std;

class Course
{
    private:
        int courseId;
        string courseName;
        float grade;

    public:
        Course();
        Course(int courseId, string courseName, float grade);
        void print();

        void setId(int idArg);
        int getId();

        void setName(string nameArg);
        string getName();

        void setGrade(float gradeArg);
        float getGrade();
};

class Student
{
    private:
        int studentId;
        string studentName;
        int coursesLength;
        int allocatedCourseLength;
        optional<Course>* courses;
        // Course* courses = new Course [2];

    public:
        Student(int studentId, string studentName);
        
        void registerCourse(int courseId, string courseName, float grade);
        void updateGrade(int courseId, float grade);        
        void print();

        void setId(int idArg);
        int getId();

        void setName(string nameArg);
        string getName();
};

