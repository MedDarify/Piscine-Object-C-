#include <iostream>
#include <vector>

#include "Person.hpp"
#include "Course.hpp"
#include "Room.hpp"
#include "Form.hpp"
#include "Event.hpp"
#include "Staff.hpp"
#include "Student.hpp"
#include "Headmaster.hpp"

int main()
{
    std::vector<Student *> studentList;
    std::vector<Course *> courseList;
    std::vector<Room *> roomList;

    std::cout << "--- Creating People ---" << std::endl;
    Student *s1 = new Student("Harry Potter");
    studentList.push_back(s1);

    std::cout << "\n--- Creating Courses ---" << std::endl;
    Course *c1 = new Course("Transfiguration");
    c1->subscribe(s1);
    courseList.push_back(c1);

    std::cout << "\n--- Creating Rooms ---" << std::endl;
    Room *classroom1 = new Classroom();
    Room *office = new HeadmasterOffice();
    roomList.push_back(classroom1);
    roomList.push_back(office);

    std::cout << "\n--- Listing All Students ---" << std::endl;
    for (std::size_t i = 0; i < studentList.size(); ++i)
    {
        std::cout << " - " << studentList[i]->getName() << std::endl;
    }

    std::cout << "\n--- Demonstrating Form Interaction ---" << std::endl;
    for (std::size_t i = 0; i < studentList.size(); ++i)
        delete studentList[i];

    for (std::size_t i = 0; i < courseList.size(); ++i)
        delete courseList[i];

    for (std::size_t i = 0; i < roomList.size(); ++i)
        delete roomList[i];
    return 0;
}