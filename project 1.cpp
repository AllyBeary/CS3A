// Allison Hua
// 10/22/23
// Project 1 : This program will read data from text files the users chooses and input the data into a school array of courses and a student array of student information. Then, the user will be prompted to choose from a menu of options from 
// viewing all the students of all courses, viewing students taking all three courses, viewing students who take two of the three courses, and viewing the students who have the top three scores in all courses. 

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Student // objects have three sections (id, name, score) in one space
{
private: // objects can only be used by members of class Student
    int id; // id = id number of the student
    string name; // name = name of student
    int score; // score = student's score in the course
public: // members that can be used by any
    Student() {} // default constructor
    Student(int id, string name, int score) // non-default constructor
    {
        this->id = id;
        this->name = name;
        this->score = score;
    } 
    void setId(const int& id) { this->id = id; } // setter
    void setName(const string& name) { this->name = name; } // setter
    void setScore(const int& score) { this->score = score; } // setter
    int getId() const { return id; } // getter
    string getName() const { return name; } // getter
    int getScore() const { return score; } // getter
    void sort(Student* c, const int& size); // sorts students in a course by ascending order of id
    void menu1(const Student* c, const int& size, const string& title); // prints out students in all courses
    friend void menu2(const Student* c1, const int& size1, const string& title1, const Student* c2, const int& size2, const string& title2, const Student* c3, const int& size3, const string& title3); // students who take all three courses (friend for readability since it is working with more than one Student object in the function)
    friend void menu3(const Student* c1, const int& size1, const string& title1, const Student* c2, const int& size2, const string& title2, const Student* c3, const int& size3, const string& title3); // students who take two courses (friend for readability since it is working with more than one Student object in the function)
    void menu4(const Student* c, const int& size, const string& title); // students who have the top three scores of each course
};

struct Course // objects have three sections (title, number_of_students, *list) in one space
{
    string title; // title = course title 
    int number_of_students; // number_of_students = amount of students in course related to title
    Student* list; // *list = array of type Student that stores a student's id, name, and score in one index/space
};

Student* input(Course* school, int& index, string& title, int& num_of_st); // store course information (title, number of students, student list) in one index of school array, store student information (id, name, score) in one index of course array

int main()
{
    int index = 0, num_of_st1, num_of_st2, num_of_st3, menu_num; // index = index of school[], num_of_st# = amount of students in course #, menu_num = menu option
    string title1, title2, title3; // title# = title of course #
    char again; // again = whether user wants to choose another menu option
    Course* school = new Course[3]; // *school = array of type Course that stores title, number of students, and student list in one index/space
    Student* st_list1, *st_list2, *st_list3; // *st_list# = array of type Student that stores student id, name, and score in one index/space for course #

    st_list1 = input(school, index, title1, num_of_st1); // function call to initialize the list of students of course 1
    st_list2 = input(school, index, title2, num_of_st2); // function call to initialize the list of students of course 2
    st_list3 = input(school, index, title3, num_of_st3); // function call to initialize the list of students of course 3

    cout << "\n\n===============  Menu  ===============\n"
         << "  1. Show all course lists (sorting)\n"
         << "  2. List of students who take all courses\n"
         << "  3. List of students who take two courses\n"
         << "  4. Print out top three scores for each course\n"
         << "  5. Exit\n";

    do // runs loop at lest once
    {
        cout << "  ----> Select : ";
        cin >> menu_num;

        if (menu_num == 1) // if the user chose option 1
        {
            st_list1->menu1(st_list1, num_of_st1, title1); // function call to print out all the students of course 1
            st_list2->menu1(st_list2, num_of_st2, title2); // function call to print out all the students of course 2
            st_list3->menu1(st_list3, num_of_st3, title3); // function call to print out all the students of course 3
        }
        if (menu_num == 2) // if the user chose option 2
        {
            menu2(st_list1, num_of_st1, title1, st_list2, num_of_st2, title2, st_list3, num_of_st3, title3); // function call to print out the students taking all three courses
        }
        if (menu_num == 3) // if the user chose option 3
        {
            menu3(st_list1, num_of_st1, title1, st_list2, num_of_st2, title2, st_list3, num_of_st3, title3); // function call toprint out the students taking only course 1 and course 2
            menu3(st_list1, num_of_st1, title1, st_list3, num_of_st3, title3, st_list2, num_of_st2, title2); // function call to print out the students taking only course 1 and course 3
            menu3(st_list2, num_of_st2, title2, st_list3, num_of_st3, title3, st_list1, num_of_st1, title1); // function call to print out the students taking only course 2 and course 3
        }
        if (menu_num == 4) // if the user chose option 5
        {
            st_list1->menu4(st_list1, num_of_st1, title1); // function call to print out the students with the top three score in course 1
            st_list2->menu4(st_list2, num_of_st2, title2); // function call to print out the students with the top three score in course 2
            st_list3->menu4(st_list3, num_of_st3, title3); // function call to print out the students with the top three score in course 3
        }
        if (menu_num == 5) // if the user chose option 5
        {
            cout << "\n\n  Exiting....";
            exit(1); // exits program
        }

        cout << "\nWould you like to choose another option? (y/n) : ";
        cin >> again;
    } while (again == 'y'); // loops while the user enters 'y' to go again

    return 0;
}

Student* input(Course* school, int& index, string& title, int& num_of_st) // store course information (title, number of students, student list) in one index of school array, store student information (id, name, score) in one index of course array
{
    int id, score; // id = first group of integers from line read, score = third group of integers from line read
    string name; // name = second group of characters from line read
    ifstream infile; // infile = text file in cpp file
    char filename[20]; // filename[] = name of text file user wants to open

    cout << "Enter filename #" << index + 1 << " : "; // loop1 : 0 + 1, loop2: 1 + 1, loop3: 2 + 1
    cin >> filename;

    infile.open(filename); // open text file
    if (infile.fail())
    {
        cout << "Input file " << index + 1 << " did not open."; // loop1 : 0 + 1, loop2: 1 + 1, loop3: 2 + 1
        exit(1);
    }

    infile >> title >> num_of_st; // reads first line of text file // title = first group of characters is the title of the course, num_of_st = second group of integers is the number of students in the course
    school[index].title = title; // the title read from the text file is assigned to the first section of the index/space in the school array
    school[index].number_of_students = num_of_st; // the number of students read from the text file is assigned to the second section of the index/space in the school array
    Student* st_list = new Student[num_of_st]; // creates a dynamic array that will fill the number of students to the third section of the index/space
    school[index].list = st_list; // the array created is assigned to the third section of the index/space in the school array
    index++; // increments the index so the information for the next course in stored in the next index/space in the school array

    while (!infile.eof()) // loops while is it not the end of the text file
    {
        for (int i = 0; i < num_of_st; i++) // loop to assign student information to one index of the student list/array of course 1
        {
            infile >> id >> name >> score; // reads following lines of text file
            st_list[i].setId(id); // function call to assign the id read from the text file to the first section of the index/space in the st_list array
            st_list[i].setName(name); // function call to assign the name read from the text file to the second section of the index/space in the st_list array
            st_list[i].setScore(score); // function call to assign the score read from the ttext file to the third section of the index/space in the st_list array
        }
    }
    infile.close(); // close text file

    st_list->sort(st_list, num_of_st); // function call to sort the st_list array in ascending order of id

    return st_list; // returns the filled and organized st_list array
}

void Student::sort(Student* c, const int& size) // sorts students in a course by ascending order of id
{
    for (int i = 0; i < size; i++) // changes the index before
    {
        for (int j = i + 1; j < size; j++) // changes the index after
        {
            Student temp; // temp = temporary space to store the lesser id (type Student so it has three sections in one space)
            if (c[i].id > c[j].id) // the id of the student before is greater than the id of the student after
            {
                temp = c[i]; // the contents of the index before are temporarily assigned to temp
                c[i] = c[j]; // the contents of the index after are reassigned to the index before 
                c[j] = temp; // the contents of temp are moved to the index after
            }
        }
    }
}

void Student::menu1(const Student* c, const int& size, const string& title) // prints out students in all courses
{
    cout << "\n==========  " << title << "  ==========\n\n";
    for (int i = 0; i < size; i++)
    {
        cout << setw(8) << c[i].id << setw(10) << c[i].name << setw(3) << c[i].score << endl;
    }
}

void menu2(const Student* c1, const int& size1, const string& title1, const Student* c2, const int& size2, const string& title2, const Student* c3, const int& size3, const string& title3) // students who take all three courses
{
    int all_count = 0; // all_count = number of students taking all the courses
    // count how many students are taking all three courses
    for (int i = 0; i < size1; i++) // loop to change the index of st_list array for course 1
    {
        for (int j = 0; j < size2; j++) // loop to change the index of st_list array for course 2
        {
            if (c1[i].name == c2[j].name) // if the name of a student in course 1 is equivalent to a name in course 2
            {
                for (int k = 0; k < size3; k++) // loop to change the index of st_list array for course 3
                {
                    if (c2[j].name == c3[k].name) // if the name of the student in course 1 and course 2 is also in course 3
                    {
                        all_count++; // increments the number of students by one
                    }
                }
            }
        }
    }
    cout << "\n\t\tThere are " << all_count << " students who take 3 courses\n"
        << "-----------------------------------------------------------------------\n";
    // loop to print out the students who are taking all three courses
    for (int i = 0; i < size1; i++) // loop to change the index of st_list array for course 1
    {
        for (int j = 0; j < size2; j++) // loop to change the index of st_list array for course 2
        {
            if (c1[i].name == c2[j].name) // if the name of a student in course 1 is equivalent to a name in course 1
            {
                for (int k = 0; k < size3; k++) // loop to change the index of st_list array for course 3
                {
                    if (c2[j].name == c3[k].name) // if the name of the student in course 1 and course 2 is also in course 3
                    {
                        cout << setw(8) << c1[i].id << setw(10) << c1[i].name << setw(13) << title1 << "(" << c1[i].score << ")" << setw(13) << title2 << "(" << c2[j].score << ")" << setw(13) << title3 << "(" << c3[k].score << ")" << endl;
                    }
                }
            }
        }
    }
}

void menu3(const Student* c1, const int& size1, const string& title1, const Student* c2, const int& size2, const string& title2, const Student* c3, const int& size3, const string& title3) // students who take only two courses
{
    int two_count = 0; // two_count = number of students that are taking two courses
    bool two = false; // two = whether the student is in two courses
    // count how many students are taking the course passed in c1 and the course passed in c2
    for (int i = 0; i < size1; i++) // loop to change the index of the st_list array passed as c1
    {
        for (int j = 0; j < size2; j++) // loop to change the index of the st_list array passed as c2
        {
            if (c1[i].name == c2[j].name) // if the name a student in the first st_list array is equivalent to a name in the second st_list array
            {
                for (int k = 0; k < size3; k++) // loop to change the index of the st_list array passed as c3
                {
                    if (c2[j].name == c3[k].name) // if the name of a student in the first course and second course is also in the third course
                    {
                        two = false; // two remains set to false
                        break; // break the current loop
                    }
                    else // if the name of a student in the first course and second course is not in the third course
                    {
                        two = true; // two updates to true
                    }
                }

                if (two == true) // if two is true / if the student in only in the first course and second course
                {
                    two_count++; // increments the number of students taking only two courses
                    two = false; // two resets to false
                }
            }
        }
    }
    cout << "\n\tThere are " << two_count << " students who take " << title1 << " and " << title2
        << "\n-----------------------------------------------------------------------\n";  
    // print out the students taking course 1 and course 2
    for (int i = 0; i < size1; i++) // loop to change the index of first st_list array
    {
        for (int j = 0; j < size2; j++) // loop to change the index of second st_list array
        {
            if (c1[i].name == c2[j].name) // if the name of the student is in course 1 and course 2
            {
                for (int k = 0; k < size3; k++) // loop to change the index of the third st_list array
                {
                    if (c2[j].name == c3[k].name) // if the name of the student in course 1 and course 2 is also in course 3
                    {
                        two = false; // two remains set to false
                        break; // breaks current loop
                    }
                    else // if the name of the student in course 1 and course 2 is not in course 3
                    {
                        two = true; // two updates to true
                    }
                }

                if (two == true) // if two is true / if the student in only in the first and second course
                {
                    cout << setw(8) << c1[i].id << setw(10) << c1[i].name << setw(13) << title1 << "(" << c1[i].score << ")" << setw(13) << title2 << "(" << c2[j].score << ")" << endl;
                    two = false; // two resets to false
                }
            }
        }
    }
}

void Student::menu4(const Student* c, const int& size, const string& title) // students who have the top three scores of each course
{
    int max_count = 1, prev_max = 0, max = 0; // max_count = the first, second, or third top score, prev_max = the max before the one being searched for, max = current max

    while (max_count < 4) // loops while the max_count is less than 4 / stops when max_count is 4 because the last top score being searched for is the third one
    {
        if (max_count == 1) // if the max_count is 1 / if this is searching for the first top score
        {
            for (int i = 0; i < size; i++) // loop to find the first top score
            {
                if (c[i].score > max) // if the score of a student in greater than the current max
                {
                    max = c[i].score; // the score of the student is assigned as the new max
                } 
            }
            cout << "\n[ " << title << " Top Three Scores ]\n";
        }

        if (max_count != 1) // if the max_count is not 1 / if this is searching for the second or third top score
        {
            prev_max = max; // the current max is assigned as the previous max
            max = 0; // max is reset to 0
            for (int i = 0; i < size; i++) // loop to find the following top scores
            {
                if (c[i].score > max && c[i].score < prev_max) // if the score of a student is greater than the current max and less than the previous max
                {
                    max = c[i].score; // the score of the student is assigned at the current max
                } 
            }
        }

        cout << max_count << ". " << max << endl;
        for (int i = 0; i < size; i++) // loop to print out the students who have the highest score
        {
            if (c[i].score == max) // if the score of a student is equivalent to the value of the max
            {
                cout << setw(8) << c[i].id << setw(10) << c[i].name << endl;
            } 
        }

        max_count++; // increments the max_count so the loop will find the next top score
    }
}