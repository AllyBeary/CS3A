// Allison Hua
// 12/14/23
// Project 2 : This program will prompt the user with menu and execute the options possible. 
// includes class inheritance, virtual functions, abstract classes, linked lists, polymorphism, exception handling, pointers, fstream, ifstream, algorithm, replace, iomanip, setw

#include <iostream> // standard library for input and output streams, count, cin
#include <fstream> // library for file streams, ifstream
#include <algorithm> // library for searching, replace()
#include <iomanip> // library for formatting, setw()
using namespace std; // object names from standard library, string, ifstream, cout, cin, endl

class Book // abstract class (bc of pure virtual fxns, cannot create objects)
{
private: // members can only be used by this parent class and its child classes
    int code; 
    string title;
    int available;
    int rented;
public: // members can be used anywhere
    Book() {}; // default constructor
    Book(int code, string title, int available, int rented) // constructor with parameters
    {
        this->code = code; // this bc object passed as argument is assigned to object in class (same object name)
        this->title = title;
        this->available = available;
        this->rented = rented; 
    }
    void setCode(int code) { this->code = code; } // setter
    void setTitle(string title) { this->title = title; } // setter
    void setAvailable(int available) { this->available = available; } // setter
    void setRented(int rented) { this->rented = rented; } // setter
    int getCode() { return code; } // getter
    string getTitle() { return title; } // getter
    int getAvailable() { return available; } // getter
    int getRented() { return rented; } // getter
    virtual void setAge(int age) = 0; // pure virtual function (bc = 0)
    virtual int getAge() = 0; // pure virtual function
    virtual void setPublisher(string publisher) = 0; // pure virtual function
    virtual string getPublisher() = 0; // pure virtual function
    virtual void setPublish_Date(int publish_date) = 0; // pure virtual function
    virtual int getPublish_Date() = 0; // pure virtual function
};

class ChildrenBook : public Book // child class of parent class (not abstract class because pure virtual functions are overridden so not inherited), objects are created with member objects from child class and parent class, can use member function from parent class bc they are inherited as public
{
private:
    int age;
public:
    ChildrenBook() {}
    ChildrenBook(int age)
    {
        this->age = age;
    }
    void setAge(int age) { this->age = age; }
    int getAge() { return age; }
    void setPublisher(string publisher) { }; // void implementation
    string getPublisher() { return " "; };
    void setPublish_Date(int publish_date) { }; // void implementation
    int getPublish_Date() { return 0; };
};

class ComputerBook : public Book // child class of parent class Book
{
private:
    string publisher;
public:
    ComputerBook() {}
    ComputerBook(string publisher)
    {
        this->publisher = publisher;
    }
    void setPublisher(string publisher) { this->publisher = publisher; }
    string getPublisher() { return publisher; }
    void setAge(int age) { };
    int getAge() { return 0; };
    void setPublish_Date(int publish_date) { };
    int getPublish_Date() { return 0; };
};

class Novel : public Book // child class of parent class Book
{
private:
    int publish_date;
public:
    Novel() {}
    Novel(int publish_date)
    {
        this->publish_date = publish_date;
    }
    void setPublish_Date(int publish_date) { this->publish_date = publish_date; }
    int getPublish_Date() { return publish_date; }
    virtual void setAge(int age) { };
    virtual int getAge() { return 0; };
    virtual void setPublisher(string publisher) { };
    virtual string getPublisher() { return " "; };
};

class Person // parent class with child class Teacher and child class Student
{
private:
    int id;
    string name;
    int count;
public:
    Person() {}
    Person(int id, string name, int count) 
    {
        this->id = id;
        this->name = name;
        this->count = count;
    }
    void setId(int id) { this->id = id; }
    void setName(string name) { this->name = name; }
    void setCount(int count) { this->count = count; }
    int getId() { return id; }
    string getName() { return name; }
    int getCount() { return count; }
    virtual void setCode(int* code) = 0;
    virtual int* getCode() = 0;
};

class Teacher : public Person // child class of parent class Person
{
private:
    int code[3];   
public:
    Teacher() {}
    Teacher(int* code)
    {
        for (int i = 0; i < 3; i++)
        {
            this->code[i] = code[i];
        }
    }
    void setCode(int* code)
    {
        for (int i = 0; i < 3; i++)
        {
            this->code[i] = code[i];
        }
    }
    int* getCode() { return code; }
};

class Student : public Person // child class of parent class Person
{
private:
    int code[2];
public:
    Student() {}
    Student(int* code)
    {
        for (int i = 0; i < 2 ; i++)
        {
            this->code[i] = code[i];
        }
    }
    void setCode(int* code)
    {
        for (int i = 0; i < 2; i++)
        {
            this->code[i] = code[i];
        }
    }
    int* getCode() { return code; }
};

class NodeBk // class for nodes of type class Book
{
private:
    Book* data;
    NodeBk* link;
public:
    NodeBk() {}
    NodeBk(Book* data, NodeBk* link)
    {
        this->data = data;
        this->link = link;
    }
    void setData(Book* data) { this->data = data; }
    void setLink(NodeBk* link) { this->link = link; }
    Book* getData() { return data; }
    NodeBk* getLink() { return link; }
};

class NodePs // class for nodes of type class Person
{
private:
    Person* data;
    NodePs* link;
public:
    NodePs() {}
    NodePs(Person* data, NodePs* link)
    {
        this->data = data;
        this->link = link;
    }
    void setData(Person* data) { this->data = data; }
    void setLink(NodePs* link) { this->link = link; }
    Person* getData() { return data; }
    NodePs* getLink() { return link; }
};

void menu1(NodeBk** library); // declaration of function to search for a book in library
void menu2(NodeBk** library, NodePs** person); // declaration of function to rent a book from library to person
void menu3(NodeBk** library, NodePs** person); // declaration of function to return a book from person to library
void menu4(NodePs** person, NodeBk** library); // declaration of function to show information of person 
void menu5(NodeBk** library); // declration of function to show all books in library

int main()
{
    int code = 0, age = 0, publish_date = 0, available = 0, rented = 0, id = 0, count = 0, bookCode = 0, menu_num = 0; // objects to sore data from text file in cpp file, menu_num = menu option user entered
    char again = ' '; // again = user's answer to choosing another menun option
    string title = " ", publisher = " ", name = " "; // objects to store data from text file in cpp file
    NodeBk* childHead = NULL, * compHead = NULL, * novelHead = NULL, * childTail = NULL, * compTail = NULL, * novelTail = NULL, * currBk = NULL, * prevBk = NULL; // _Head = head pointer of linked list, _Tail = last node of linked list, curr_ = current node being checked, prev_ = node last checked
    NodePs* teachHead = NULL, * studHead = NULL, * teachTail = NULL, * studTail = NULL, * currPs = NULL, * prevPs = NULL;
    ifstream infile; // infile = text file in cpp file
    NodeBk** library = new NodeBk*[3]; // library = static array for books (library[0] for linked list of children books, library[1] = linked list for computer books, library[2] = linked list for novels), pointer library that points to pointer that points to static array created in the heap
    NodePs** person = new NodePs*[2]; // person = static array for people (person[0] = linked list of teachers, person[1] = linked lists of students)

    infile.open("book.txt"); // opens text file of books
    if (infile.fail()) // if text file fails to open
    {
        cout << "Input file of book did not open.";
        exit(1); // exits program (1 means true, file did fail to open)
    }
    while (!infile.eof()) 
    {
        infile >> code; // inputs first group of data 
        if (code >= 1001 && code < 2000) // if the code is that of a children book
        {
            infile >> title >> age >> available >> rented; // inputs rest of groups of data in the line
            Book *bk = new ChildrenBook; // polymorphism (object is allowed to use members from parent class Book and child class ChildrenBook), pointer bk points to a space created in the heap for object
            bk->setCode(code); // member object from parent class Book, assigns the value in code to the space of code in object bk of polymorphic type (created with member objects of class Book and class ChildrenBook), arrow bc obecting calling is a pointer
            bk->setTitle(title); // member object from parent class Book
            bk->setAge(age); // member object from child class ChildrenBook
            bk->setAvailable(available); // member object from parent class Book
            bk->setRented(rented); // member object from parent class Book
            NodeBk *ptr = new NodeBk; // ptr points to a space in the heap created for object
            ptr->setData(bk); // assigns object bk to the space of data of ptr
            ptr->setLink(NULL); // assigns NULL to space of link of ptr
            if (childHead != NULL) // if the head pointer of the linked list is not null
            {
                currBk = childHead; // assigns the address of the head node pointed to by the head pointer to the pointer currBk
                prevBk = childHead;
                while (ptr->getData()->getCode() > currBk->getData()->getCode() && currBk->getLink() != NULL) // loops while the value in the space of code in the space of data in object ptr is greater than the value in the space of code in the space of data in object currBk AND while the space of link in object currBk is not null
                {
                    prevBk = currBk; // address of the node of currBk to the pointer of prevBk
                    currBk = currBk->getLink(); // assigns the address of the next node in the space of link in node that is currBk to currBk
                }
                if (ptr->getData()->getCode() > childTail->getData()->getCode()) // if the value in the space of code in the space of data in space of ptr is greater than the code of the last node of the linked list, insertion at end
                { // head->...->tail->ptr
                    childTail->setLink(ptr); // assigns the address of ptr to the space of link in the node of childTail
                    childTail = ptr; // address of ptr is assigned to childTail
                }
                if (ptr->getData()->getCode() < currBk->getData()->getCode() && currBk != childHead) // if the value in the space of code in the space of data in the space of ptr is less than the code of the node that is currBk AND currBk is not the head node,  insertion at middle
                { // head->...->prev->ptr->curr->...->tail
                    ptr->setLink(currBk); // assigns the address of the node that is currBk to the space of link in object ptr
                    prevBk->setLink(ptr); // assigns the address of ptr to the space of link of the node of prevBk 
                }
                if (ptr->getData()->getCode() < childHead->getData()->getCode()) // insertion at beginning
                { // head->ptr->...->tail
                    ptr->setLink(childHead); // assigns the address of the head node pointed by the head pointer to the space of link in ptr
                    childHead = ptr; // the address of ptr is assigned to the head pointer
                }
            } 
            else // first node
            {
                childHead = ptr; // assigns the address of ptr to the head pointer
                childTail = ptr; // assigns the address of ptr to the tail pointer
            }
        }
        if (code >= 2001 && code < 3000) // if the code is that of a computer book
        {
            infile >> title >> publisher >> available >> rented;
            Book *bk = new ComputerBook;
            bk->setCode(code);
            bk->setTitle(title);
            bk->setPublisher(publisher); // member object from child class ComputerBook
            bk->setAvailable(available);
            bk->setRented(rented);
            NodeBk *ptr = new NodeBk;
            ptr->setData(bk);
            ptr->setLink(NULL);
            if (compHead != NULL) 
            {
                currBk = compHead;
                prevBk = compHead;
                while (ptr->getData()->getCode() > currBk->getData()->getCode() && currBk->getLink() != NULL) 
                {
                    prevBk = currBk;
                    currBk = currBk->getLink();
                }
                if (ptr->getData()->getCode() > compTail->getData()->getCode()) // insertion at end
                {
                    compTail->setLink(ptr);
                    compTail = ptr;
                }
                if (ptr->getData()->getCode() < currBk->getData()->getCode() && currBk != compHead) // insertion at middle
                {
                    ptr->setLink(currBk);
                    prevBk->setLink(ptr);
                }
                if (ptr->getData()->getCode() < compHead->getData()->getCode()) // insertion at beginning
                {
                    ptr->setLink(compHead);
                    compHead = ptr;
                }
            } 
            else // first node
            {
                compHead = ptr;
                compTail = ptr;
            }
        }
        if (code >= 3001 && code < 4000) // if the code is that of a novel
        {
            infile >> title >> publish_date >> available >> rented;
            Book *bk = new Novel;
            bk->setCode(code);
            bk->setTitle(title);
            bk->setPublish_Date(publish_date); // member object from child class Novel
            bk->setAvailable(available);
            bk->setRented(rented);
            NodeBk *ptr = new NodeBk;
            ptr->setData(bk);
            ptr->setLink(NULL);
            if (novelHead != NULL) 
            {
                currBk = novelHead;
                prevBk = novelHead;
                while (ptr->getData()->getCode() > currBk->getData()->getCode() && currBk->getLink() != NULL) 
                {
                    prevBk = currBk;  
                    currBk = currBk->getLink(); 
                }
                if (ptr->getData()->getCode() > novelTail->getData()->getCode()) // insertion at end
                {
                    novelTail->setLink(ptr);
                    novelTail = ptr;
                }
                if (ptr->getData()->getCode() < currBk->getData()->getCode() && currBk != novelHead) // insertion at middle
                {
                    ptr->setLink(currBk);
                    prevBk->setLink(ptr);
                }
                if (ptr->getData()->getCode() < novelHead->getData()->getCode()) // insertion at beginning
                {
                    ptr->setLink(novelHead);
                    novelHead = ptr;
                }
            } 
            else // first node
            {
                novelHead = ptr;
                novelTail = ptr;
            }
        }
    }
    infile.close(); // closes text file of books

    library[0] = childHead; // assigns the address of the head node pointed to by the head pointer for the linked list of children books to the space in index 0 of the array library
    library[1] = compHead; // assigns the address of the head node pointed to by the head pointer for the linked list of computer books to the space in index 1 of the array library
    library[2] = novelHead; // assigns the address of the head node pointed to by the head pointer for the linked list of novels to the space in index 2 of the array library

    infile.open("person.txt"); // opens text file of people
    if (infile.fail())
    {
        cout << "Input file of person did not open.";
        exit(1);
    }
    while (!infile.eof())
    {
        int i;
        infile >> id;
        if (id >= 1 && id < 100) // if the id is of a teacher
        {
            infile >> name >> count;
            Person* ps = new Teacher;
            ps->setId(id); // member object of parent class Person
            ps->setName(name); // member object of parent class Person
            ps->setCount(count); // member object of parent class Person
            int* bookTc = new int[3]; // bookTc points to a static array created in the heap, max # of books a teacher can rent is 3
            for (i = 0; i < count; i++) // loop changes the index of the array, index variable starts at 0, loops while the index value is less than the value of count, index value increments by one after each loop
            {
                infile >> bookCode;
                bookTc[i] = bookCode; // assigns the bookCode to the space of index i of array bookTc
            }
            for (i; i < 3; i++) // loop to assign the rest of the spaces in array bookTc with zeros
            {
                bookTc[i] = 0;
            }
            ps->setCode(bookTc); // member object of child class Teacher
            NodePs *ptr = new NodePs;
            ptr->setData(ps);
            ptr->setLink(NULL);
            if (teachHead != NULL) 
            {
                currPs = teachHead;
                prevPs = teachHead;
                while (ptr->getData()->getCode() > currPs->getData()->getCode() && currPs->getLink() != NULL) 
                {
                    prevPs = currPs;
                    currPs = currPs->getLink();
                }
                if (ptr->getData()->getCode() > teachTail->getData()->getCode()) // insertion at end
                {
                    teachTail->setLink(ptr);
                    teachTail = ptr;
                }
                if (ptr->getData()->getCode() < currPs->getData()->getCode() && currPs != teachHead) // insertion at middle
                {
                    ptr->setLink(currPs);
                    prevPs->setLink(ptr);
                }
                if (ptr->getData()->getCode() < teachHead->getData()->getCode()) // insertion at beginning
                {
                    ptr->setLink(teachHead);
                    teachHead = ptr;
                }
            }
            else // first node
            {
                teachHead = ptr;
                teachTail = ptr;
            }
        }
        if (id >= 101 && id < 300) // if the id is of a student
        {
            infile >> name >> count;
            Person* ps = new Student;
            ps->setId(id); // member object of parent class Person
            ps->setName(name); // member object of parent class Person
            ps->setCount(count); // member object of parent class Person
            int* bookSt = new int[2]; // max # of books a student can rent is 2
            for (i = 0; i < count; i++) // loop changes the index of the array, index variable starts at 0, loops while the index value is less than the value of count, index value increments by one after each loop
            {
                infile >> bookCode;
                bookSt[i] = bookCode; // assigns the bookCode to the space of index i of array bookTc
            }
            for (i; i < 2; i++)
            {
                bookSt[i] = 0;
            }
            ps->setCode(bookSt); // member object of child class Student
            NodePs *ptr = new NodePs;
            ptr->setData(ps);
            ptr->setLink(NULL);
            if (studHead != NULL) 
            {
                currPs = studHead;
                prevPs = studHead;
                while (ptr->getData()->getCode() > currPs->getData()->getCode() && currPs->getLink() != NULL) 
                {
                    prevPs = currPs;
                    currPs = currPs->getLink();
                }
                if (ptr->getData()->getCode() > studTail->getData()->getCode()) // insertion at end
                {
                    studTail->setLink(ptr);
                    studTail = ptr;
                }
                if (ptr->getData()->getCode() < currPs->getData()->getCode() && currPs != studHead) // insertion at middle
                {
                    ptr->setLink(currPs);
                    prevPs->setLink(ptr);
                }
                if (ptr->getData()->getCode() < studHead->getData()->getCode()) // insertion at beginning
                {
                    ptr->setLink(studHead);
                    studHead = ptr;
                }
            } 
            else // first node
            {
                studHead = ptr;
                studTail = ptr;
            }
        }
    }

    person[0] = teachHead; // assigns the address of the head node pointed to by the head pointer of the linked list of teachers to the space of index 0 of array person
    person[1] = studHead; // assigns the address of the the head node pointed to by the head pointer of the linked list of students to the space of index 1 of array person

    do // does this loop at least once
    {
        cout << "----------------------------\n"
        << "\tMenu\n"
        << "----------------------------\n"
        << " 1. Search a book\n"
        << " 2. Rent a book\n"
        << " 3. Return a book\n"
        << " 4. Show my information\n"
        << " 5. Show all books\n"
        << " 6. Exit\n";

        cout << "\nSelect (1~6) : ";
        cin >> menu_num;
        if (menu_num == 1) // if the user inputted 1 for menu option 1
        {
            menu1(library); // call to function menu1(), passes library as an argument
        }
        if (menu_num == 2) // if the user inputted 2 for menu option 2
        {
            menu2(library, person); // call to function menu2(), passes library and person as arguments
        }
        if (menu_num == 3) // if the user inputted 3 for menu option 3
        {
            menu3(library, person); // call to function menu3(), passes library and person as arguments
        }
        if (menu_num == 4) // if the user inputted 4 for menu option 4
        {
            menu4(person, library); // call to function menu4(), passes person and library as arguments
        }
        if (menu_num == 5) // if the user inputted 5 for menu option 5
        {
            menu5(library); // call to function menu5(), passes library as an argument
        }
        if (menu_num == 6) // if the user inputted 6 for menu option 6
        {
            exit(1); // exits program
        }
        if (menu_num < 1 || menu_num > 6)
        {
            cout << "Not a possible menu option." << endl;
        }

        cout << "\nWould you like to choose another menu option? (y/n) : ";
        cin >> again;
    } while (again == 'y'); // continues to loop while the user inputs 'y' for yes to choose a menu option again

    return 0;
}

void menu1(NodeBk** library) // defintion of function to search for a book in library
{
    int code = 0;
    string title = " ", category = " ";
    NodeBk* curr = NULL;

    try // tries code to check for exceptions
    {
        cout << endl << "Enter code  : ";
        cin >> code;
        cout << "Enter title : ";
        cin >> title;

        if (code >= 1001 && code < 2000) // if children book
        {
            category = "children"; // assigns book type to category
            curr = library[0]; // assigns the head pointer of linked list for children books to pointer curr
        }
        if (code >= 2001 && code < 3000) // if computer book
        {
            category = "computer";
            curr = library[1]; // assigns the head pointer of linked list for computer books to pointer curr
        }
        if (code >= 3001 && code < 4000) // if novel
        {
            category = "novel";
            curr = library[2]; // assigns the head pointer of linked list for novels to pointer curr
        }
        while (curr->getData()->getCode() != code && curr->getData()->getTitle() != title && curr->getLink() != NULL) // loops while the string in the space of title in the space of data in the object curr is not equivalent to the title the user inputted AND while the space of link of object curr is not null
        {
            curr = curr->getLink(); // curr updates to next node
        }
        if (curr->getData()->getCode() != code || curr->getData()->getTitle() != title) // if the title of all nodes fails to match titles of books from the category of the code the user inputted
        {
            throw "Code and Title do not match."; // throws exception (code after in try is not ran)
        }
        // code runs if the title entered by the user matches the code entered by the user
        cout << endl << curr->getData()->getTitle() << "(" << curr->getData()->getCode() << ") exists."
            << "\ncategory : " << category 
            << "\npublisher : " << curr->getData()->getPublisher() 
            << "\n" << curr->getData()->getAvailable() << " avaliable, " << curr->getData()->getRented() << " rented" << endl;
    }

    catch (const char* e) // catches exception
    {
        cout << e << endl;
    }
}

void menu2(NodeBk** library, NodePs** person) // defintion of function to rent a book from library to person
{
    int id = 0, count = 0, size = 0;
    char rent = ' ';
    string title = " ";
    NodePs* currPs = NULL;
    NodeBk* currBk = NULL, * prevBk = NULL; 

    try
    {
        cout << endl << "Enter your id    : ";
        cin >> id;

        if (id >= 1 && id < 100) // if the code the user entered is a code of a teacher
        {
            currPs = person[0]; // assigns the head pointer of the linked list of teachers to the pointer currPs
            size = 3; // assigns 3 to the space of object size
        }
        if (id >= 101 && id < 300) // if the code the user entered is a code of a student
        {
            currPs = person[1]; // assigns the head pointer of the linked list of students to the pointer currPs
            size = 2; // assigns 2 to the space of object size
        }
        while (currPs->getData()->getId() != id && currPs->getLink() != NULL) // loops while the value in the space of id in the space of data of the node that is currPs is not equivalent to the id entered by the user AND while the space of link of the node that is currPs is not null
        {
            currPs = currPs->getLink();
        }
        if (currPs->getData()->getCount() == size) // if the integer in the space of count in the space of data of the node that is curr Ps is equivalent to the size correlated to the status as a person, the person is at their max allowed book renting
        {
            throw "max"; // throws exception
        }
        // runs code if exception has not been thrown
        cout << "Enter book title : ";
        cin >> title;

        do // loop to search for the book with the title in array library
        {
            currBk = library[count];
            while (currBk->getData()->getTitle() != title && currBk->getLink() != NULL)
                {
                    currBk = currBk->getLink();
                }
                if (currBk->getData()->getTitle() != title && count < 3) // if the string in the space of title in the space of data of the node that is currBk is not equivalent to the title entered by the user AND if the count is less than 3
                {
                    count++; // increments the count by one, updates the index of array library to search the next linked list
                }
            } while (currBk->getData()->getTitle() != title && count < 3); // continues to loop while the title of any book is not equivalent to the title entered by the user AND while the count is less than 3 (entire library has been searched)
       
        if (currBk->getData()->getAvailable() == 0) // if the integer in the space of available in the space of data of the node that currBk is equivalent to 0, all books by the title have been rented out
        {
            throw "out"; // throws exception
        }
        // runs code if exception has not been thrown
        cout << endl << "You are " << currPs->getData()->getName() << ". You rented " << currPs->getData()->getCount() << " book."
            << "\nDo you want to rent '" << title << "' (y/n)? ";
        cin >> rent; 

        if (rent == 'y') // if the user entered 'y' to confirm that they want to rent the book with the title
        {
            currBk->getData()->setAvailable(currBk->getData()->getAvailable() - 1); // updates the number of available for the book to one less
            int* c = currPs->getData()->getCode(); // assigns the array code of the person to pointer c
            int i = 0;
            while ((c[i] >= 1001 && c[i] <= 4000) && i < size) // loops while the code in index i of array c is a possible book code AND while index i is less than the possible number of books the person can rent, finds next possible index of the array to store the code of the book the user wants to rent
            {
                i++; // increments i by one
            }
            c[i - 1] = currBk->getData()->getCode(); // assigns the code of the book the user wants to rent to the array
            currPs->getData()->setCode(c); // assigns the updated array of books the person has rented to the space of code for the person
            currPs->getData()->setCount(currPs->getData()->getCount() + 1); // updates the number of books rented for the person to one more
            currBk->getData()->setRented(currBk->getData()->getRented() + 1); // updates the number rented for the book to one more
            cout << "***** Rent succeed. Check your info!" << endl;
        }
    }
    catch(const char* e) // catches exception
    {
        if (e == "max")
        {
            cout << "You already rented " << size << " books." << endl;
        }
        if (e == "out")
        {
            cout << "The book is not avaliable (all rented out)." << endl;
        }
    }
}

void menu3(NodeBk** library, NodePs** person) // defintion of function to return a book from person to library
{
    int id, code, count = 0, size, i = 0;
    char rtrn;
    NodePs* currPs = NULL;
    NodeBk* currBk = NULL, * prevBk = NULL; 

    try
    {
        cout << endl << "Enter your id    : ";
        cin >> id;
        cout << "Enter the book code to return : ";
        cin >> code;

        do // loop to search for the book with the code the user entered in array library
        {
            currBk = library[count];
            while (currBk->getData()->getCode() != code && currBk->getLink() != NULL)
            {
                currBk = currBk->getLink();
            }
            if (currBk->getData()->getCode() != code && count < 3)
            {
                count++;
            }
        } while (currBk->getData()->getCode() != code && count < 3);

        if (id >= 1 && id < 100) // if teacher
        {
            currPs = person[0];
            size = 3;
        }
        if (id >= 101 && id < 300) // if student
        {
            currPs = person[1];
            size = 2;
        }
        while (currPs->getData()->getId() != id && currPs->getLink() != NULL) // loop to search for the person with the id the user inputted
        {
            currPs = currPs->getLink();
        }
        int* c = currPs->getData()->getCode();
        while (c[i] != code && i < size) // loop to find the index of the code of the book the user wants to return
        {
            i++;
        }
        if (i == 3) // if array c was searched entirely and the code of the book the user wants to return was not found
        {
            throw " did not rent the book."; // throws exception
        }
        c[i] = 0; // assigns 0 to the index with the code of the book the user wants to return
        for (i = 0; i < size; i++) // loop to push book codes to the front of the array
        {
            for (int j = i + 1; j < size; j++)
            {
                int temp;
                if (c[j] > c[i]) // if the value in space of index j of array c is greater than value in space of index i of array c
                {
                    temp = c[j]; // value in space of index j is stored in space of temp
                    c[j] = c[i]; // value in space of index i is assigned to space of index j
                    c[i] = temp; // values stored in temp is assigned to index i
                }
            }
        }

        cout << endl << "Do you want to return '" << currBk->getData()->getTitle() << "' (y/n)? ";
        cin >> rtrn; 

        if (rtrn == 'y') // if the user entered 'y' to confirm that they want to return the book with the code they entered
        {
            currBk->getData()->setRented(currBk->getData()->getRented() - 1); // updates the number of rented for the book to one less
            currPs->getData()->setCode(c); // assigns the updates array of codes of the books the person has rented
            currPs->getData()->setCount(currPs->getData()->getCount() - 1); // updates the number of books rented for the person to one less
            currBk->getData()->setAvailable(currBk->getData()->getAvailable() + 1); // updates the number of the book available to rent to one more
            cout << "***** Return succeed. Check your info!" << endl;
        }
    }
    catch(const char* e) // catches exception
    {
        cout << id << e << endl;
    }
}

void menu4(NodePs** person, NodeBk** library) // definition of function to show information of person
{
    int id = 0, count = 0, size = 0, code = 0; 
    string name = " ";
    NodePs* currPs = NULL;
    NodeBk* currBk = NULL;

    try
    {
        cout << endl << "Enter your id   : ";
        cin >> id;
        cout << "Enter your name : ";
        cin >> name;
        
        do // loop to find the person with the id the user entered in array person
        {
            currPs = person[count];
            while (currPs->getData()->getId() != id && currPs->getLink() != NULL)
            {
                currPs = currPs->getLink();
            }
            if (currPs->getData()->getId() != id && count < 2)
            {
                count++;
            }
        } while (currPs->getData()->getId() != id && count < 2);
        if (currPs->getData()->getId() != id || currPs->getData()->getName() != name) // if the value in space of id of space of data of node pointed to by curr Ps is not equivalent to the value entered by the user stored in id OR if the book title does not match the title entered
        {
            throw "Id and name do not match."; // throws exception
        }
        cout << endl << "You rented " << currPs->getData()->getCount() << " book.\n";

        int* c = currPs->getData()->getCode();
        for (int i = 0; c[i] != 0; i++) // loop to print the books rented by the person, while the value in index i of array c is not 0
        {
            count = 0; // resets count to 0
            do // loop to search for the book with the code the user entered
            {
                currBk = library[count];
                while (currBk->getData()->getCode() != c[i] && currBk->getLink() != NULL)
                {
                    currBk = currBk->getLink();
                }
                if (currBk->getData()->getCode() != c[i] && count < 3)
                {
                    count++;
                }
            } while (currBk->getData()->getCode() != c[i] && count < 3);

            cout << "* " << currBk->getData()->getTitle() << "(" << currBk->getData()->getCode() << ") - ";
            if (c[i] >= 1001 && c[i] < 2000) // if children book
            {
                cout << "age " << currBk->getData()->getAge() << endl;
            }
            if (c[i] >= 2001 && c[i] < 3000) // if computer book
            {
                cout << "publisher " << currBk->getData()->getPublisher() << endl;
            }
            if (c[i] >= 3001 && c[i] < 4000) // if novel
            {
                cout << "publish date " << currBk->getData()->getPublish_Date() << endl;
            }
        }
    }
    catch (const char* e) // catches exception
    {
        cout << e << endl;
    }
}

void menu5(NodeBk** library) // definition of function to show all books in library
{
    for (int i = 0; i < 3; i++) // loop to print each linked list in array library
    {
        if (i == 0)
        {
            cout << "\n========================================================\n"
                << "\t\tChildren Books\n"
                << "========================================================\n"
                << "code" << setw(25) << "title\t" << setw(6) << "age" << setw(10) << "available" << setw(8) << "rented\n"
                << "--------------------------------------------------------\n";
        }
        if (i == 1)
        {
            cout << "\n========================================================================\n"
                << "\t\tComputer Books\n"
                << "========================================================================\n"
                << "code" << setw(25) << "title\t" << setw(22) << "publisher" << setw(10) << "available" << setw(8) << "rented\n"
                << "------------------------------------------------------------------------\n";
        }
        if (i == 2)
        {
            cout << "\n==================================================================\n"
                << "\t\tNovel Books\n"
                << "==================================================================\n"
                << "code" << setw(25) << "title\t" << setw(16) << "publish date" << setw(10) << "available" << setw(8) << "rented\n"
                << "------------------------------------------------------------------\n";
        }
        for (NodeBk* tempBk = library[i]; tempBk; tempBk = tempBk->getLink()) // loop to go through linked list, pointer tempBk starts at head pointer in index i of array library, loops while tempBk exists (while tempBk is not null), assigns the address in the space of link of node that is tempBk to pointer tempBk
        {
            cout << tempBk->getData()->getCode();
            string title = tempBk->getData()->getTitle();
            replace(title.begin(), title.end(), '_', ' '); // function to replace underscores with spaces in a string
            cout << setw(30) << title;
            if (i == 0)
            {
                cout << setw(3) << tempBk->getData()->getAge();
            }
            if (i == 1)
            {
                cout << setw(20) << tempBk->getData()->getPublisher();
            }
            if (i == 2)
            {
                cout << setw(10) << tempBk->getData()->getPublish_Date();
            }
            cout << setw(8) << tempBk->getData()->getAvailable() << setw(8) << tempBk->getData()->getRented() << endl;
        }
    }
}