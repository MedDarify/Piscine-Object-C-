#include <iostream>
#include <vector>

#include "Person.hpp"
#include "Course.hpp"
#include "Room.hpp"
#include "Form.hpp"
#include "Event.hpp"

int main()
{
    std::vector<Student *> studentList;
    std::vector<Staff *> staffList;
    std::vector<Course *> courseList;
    std::vector<Room *> roomList;

    std::cout << "--- Creating People ---" << std::endl;
    Student *s1 = new Student("Harry Potter");
    Student *s2 = new Student("Ron Weasley");

    Headmaster *hm = new Headmaster("Albus Dumbledore");
    Professor *p1 = new Professor("Minerva McGonagall");
    Secretary *sec = new Secretary("Poppy Pomfrey");

    studentList.push_back(s1);
    studentList.push_back(s2);
    staffList.push_back(hm);
    staffList.push_back(p1);
    staffList.push_back(sec);

    std::cout << "\n--- Creating Courses ---" << std::endl;
    Course *c1 = new Course("Transfiguration");
    c1->assign(p1);
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

    std::cout << "\n--- Listing All Staff ---" << std::endl;
    for (std::size_t i = 0; i < staffList.size(); ++i)
    {
        std::cout << " - " << staffList[i]->getName() << std::endl;
    }

    std::cout << "\n--- Demonstrating Form Interaction ---" << std::endl;

    Form *newCourseForm = sec->createForm(NeedCourseCreation);

    hm->receiveForm(newCourseForm);

    std::cout << "Attempting to execute form before signing:" << std::endl;
    newCourseForm->execute();

    std::cout << "Headmaster validating forms..." << std::endl;
    hm->validateForms();

    std::cout << "\n--- Cleaning up ---" << std::endl;

    for (std::size_t i = 0; i < studentList.size(); ++i)
        delete studentList[i];
    for (std::size_t i = 0; i < staffList.size(); ++i)
        delete staffList[i];

    for (std::size_t i = 0; i < courseList.size(); ++i)
        delete courseList[i];

    for (std::size_t i = 0; i < roomList.size(); ++i)
        delete roomList[i];

    delete newCourseForm;

    return 0;
}