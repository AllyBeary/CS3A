// header file of classes
#include <iostream>
using namespace std;

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