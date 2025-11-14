#include <iostream>

#include "Course.hpp"
#include "singletons.hpp"
#include "Person.hpp"
#include "Room.hpp"
#include "Form.hpp"

typedef SingletonList<Student> StudentList;
typedef SingletonList<Staff> StaffList;
typedef SingletonList<Course> CourseList;
typedef SingletonList<Room> RoomList;

int main()
{
    std::cout << "--- Accessing Singletons ---" << std::endl;
    StudentList &sList = StudentList::getInstance();
    StaffList &stList = StaffList::getInstance();
    CourseList &cList = CourseList::getInstance();
    RoomList &rList = RoomList::getInstance();

    StudentList &sList_again = StudentList::getInstance();

    std::cout << "StudentList Address: " << &sList << std::endl;
    std::cout << "StudentList (again): " << &sList_again << std::endl;
    std::cout << std::endl;

    std::cout << "--- Populating Lists ---" << std::endl;
    Student *s1 = new Student("Harry Potter");
    Student *s2 = new Student("Ron Weasley");

    Staff *p1 = new Professor("Minerva McGonagall");
    Staff *sec1 = new Secretary("Argus Filch");

    Course *c1 = new Course("Transfiguration");

    Room *r1 = new Classroom();
    Room *r2 = new HeadmasterOffice();

    sList.add(s1);
    sList.add(s2);

    stList.add(p1);
    stList.add(sec1);

    cList.add(c1);

    rList.add(r1);
    rList.add(r2);

    std::cout << "Lists populated." << std::endl;
    std::cout << std::endl;

    std::cout << "--- Retrieving from Lists ---" << std::endl;

    std::cout << "Students:" << std::endl;
    const std::vector<Student *> &students = sList.getList();
    for (std::size_t i = 0; i < students.size(); ++i)
    {
        std::cout << " - " << students[i]->getName() << std::endl;
    }

    std::cout << "\nStaff:" << std::endl;
    const std::vector<Staff *> &staff = stList.getList();
    for (std::size_t i = 0; i < staff.size(); ++i)
    {
        std::cout << " - " << staff[i]->getName() << std::endl;
    }

    std::cout << "\nCourses:" << std::endl;
    const std::vector<Course *> &courses = cList.getList();
    for (std::size_t i = 0; i < courses.size(); ++i)
    {
        std::cout << " - " << courses[i]->getName() << std::endl;
    }

    std::cout << "\nRooms:" << std::endl;
    const std::vector<Room *> &rooms = rList.getList();
    for (std::size_t i = 0; i < rooms.size(); ++i)
    {
        std::cout << " - Room ID: " << rooms[i]->getId() << std::endl;
    }

    delete s1;
    delete s2;
    delete p1;
    delete sec1;
    delete c1;
    delete r1;
    delete r2;

    return 0;
}