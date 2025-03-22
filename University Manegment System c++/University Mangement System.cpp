#include <iostream>
#include <string>
#include <conio.h>
#include <limits>
using namespace std;

class SLL;
class course_management;
class HashTable;




class EnrollmentRecord {
public:
    int courseID;
    string courseName;

    EnrollmentRecord(int id, string name)
        : courseID(id), courseName(name) {
    }
};


class EnrollmentNode {
public:
    EnrollmentRecord data;
    EnrollmentNode* prev;
    EnrollmentNode* next;

    EnrollmentNode(EnrollmentRecord record)
        : data(record), prev(NULL), next(NULL) {
    }
};


class EnrollmentHistory {
private:
    EnrollmentNode* head;
    EnrollmentNode* tail;

public:
    EnrollmentHistory() : head(NULL), tail(NULL) {}


    void addRecord(int courseID, string courseName) {
        EnrollmentRecord newRecord(courseID, courseName);
        EnrollmentNode* newNode = new EnrollmentNode(newRecord);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }


    void displayHistory() {
        if (head == NULL) {
            cout << "No enrollment history found." << endl;
            return;
        }

        EnrollmentNode* temp = head;
        while (temp != NULL) {
            cout << "Course ID: " << temp->data.courseID
                << ", Course Name: " << temp->data.courseName << endl;

            temp = temp->next;
        }
    }

    friend class course_management;
};

class students {
public:
    int student_id;
    string name;
    string email;
    string phone;
    string address;
    string password;
    EnrollmentHistory history;

    students(int id, string n, string e, string p, string a, string pass) {
        student_id = id;
        name = n;
        email = e;
        phone = p;
        address = a;
        password = pass;
    }
};

class Node
{
public:
    Node* prev;
    Node* next;
    students data;
    Node(students s) : data(s), next(NULL), prev(NULL) {

    }
};

class queueNODE {
public:
    students* student;
    queueNODE* next;

    queueNODE(students* s) {
        student = s;
        next = nullptr;
    }
};

class QUEUE {

private:
    queueNODE* front;
    queueNODE* rear;

public:

    QUEUE() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }



    void enqueueS(students* student) {
        queueNODE* newN = new queueNODE(student);

        if (rear == nullptr)
        {
            front = newN;
            rear = newN;
        }
        else {
            rear->next = newN;
            rear = newN;
        }

    }

    students* dequeueS() {
        if (isEmpty())
        {
            cout << "Wait list is empty." << endl;
            return nullptr;
        }
        queueNODE* temp = front;
        students* student = temp->student;

        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        cout << "Student " << student->name << " removed from the waitlist." << endl;
        return student;
    }



    void dispaly() {
        if (isEmpty())
        {
            cout << "waitlist is empty." << endl;
            return;
        }

        queueNODE* current = front;
        cout << "Waitlist: ";
        while (current != nullptr) {
            cout << current->student->name << " (" << current->student->student_id << ") ";
            current = current->next;
        }

    }


};

class StackN {
public:
    int cID;
    StackN* next;

    StackN(int id) {
        cID = id;
        next = nullptr;
    }
};

class Stack {
private:
    StackN* top;

public:
    Stack() {

        top = nullptr;

    }


    bool isEmpty() {
        return top == nullptr;
    }

    void push(int cID) {
        StackN* newNode = new StackN(cID);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }
        StackN* temp = top;
        top = top->next;
        delete temp;
    }

    int peak() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return -1;
        }
        return top->cID;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        StackN* temp = top;
        while (temp) {
            cout << "Course ID: " << temp->cID << "\n";
            temp = temp->next;
        }
    }
};

class SLL
{
public:
    Node* head;
    Node* tail;
    int length;
    SLL()
    {
        head = NULL;
        length = 0;
    }

    void add(students s)
    {
        Node* new_Node = new Node(s);
        if (head == NULL)
        {
            head = tail = new_Node;
            length++;
        }
        else
        {
            tail->next = new_Node;
            tail = new_Node;
            length++;
        }

    }

    void deleteNode(int value)
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        Node* temp2 = NULL;

        if (temp != NULL && temp->data.student_id == value)
        {
            head = temp->next;
            delete temp;
            length--;
            cout << "Student with ID: " << value << " deleted (: " << endl;
            return;
        }

        while (temp != NULL && temp->data.student_id != value)
        {
            temp2 = temp;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "No student with this ID is found" << endl;
            return;
        }
        temp2->next = temp->next;
        delete temp;
        length--;
        cout << "Student with ID: " << value << " deleted (: " << endl;
    }


    void display()
    {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL)
        {
            cout << "ID: " << temp->data.student_id << ", Name: " << temp->data.name
                << ", Email: " << temp->data.email << ", Phone: " << temp->data.phone
                << ", Address: " << temp->data.address << ", Password: " << temp->data.password << endl;

            temp = temp->next;
        }
        cout << endl;
    }

    students* findStudent(int student_id) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data.student_id == student_id) {
                return &(temp->data);
            }
            temp = temp->next;
        }
        return NULL;
    }
    void insertionsort()
    {
        if (head == tail || head == NULL)
        {
            return;
        }
        Node* sorted = NULL;

        Node* current = head;

        while (current) {
            Node* next = current->next;

            if (!sorted || sorted->data.student_id >= current->data.student_id)
            {
                current->next = sorted;
                sorted = current;
            }
            else
            {

                Node* temp = sorted;
                while (temp->next && temp->next->data.student_id < current->data.student_id)
                {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }

            current = next;
        }
        head = sorted;

        tail = head;
        while (tail != NULL && tail->next != NULL) {
            tail = tail->next;
        }

    }
    students* findStudent_binsearch(int student_id, Node* start, Node* end) {

        if (start == NULL || end == NULL || start == end) {
            return NULL;
        }


        Node* slow = start;
        Node* fast = start->next;

        while (fast != end && fast->next != end) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* middle = slow;


        if (middle->data.student_id == student_id) {
            return &(middle->data);
        }

        else if (middle->data.student_id > student_id) {
            return findStudent_binsearch(student_id, start, middle);
        }

        else {
            return findStudent_binsearch(student_id, middle->next, end);
        }
    }
};

class HashTable
{
private:
    static const int TABLE_SIZE = 10;
    SLL table[TABLE_SIZE];

    int hashFunction(int student_id) {
        return student_id % TABLE_SIZE;
    }
public:
    HashTable() {

        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = SLL();
        }
    }

    void addStudent(students s) {
        int index = hashFunction(s.student_id);
        table[index].add(s);
        cout << "Student " << s.name << " added to bucket " << index << endl;
    }
    students* findStudent(int student_id) {
        int index = hashFunction(student_id);
        return table[index].findStudent(student_id);
    }

    void deleteStudent(int student_id) {
        int index = hashFunction(student_id);
        table[index].deleteNode(student_id);
    }

    void displayTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << ":" << endl;
            table[i].display();
            cout << endl;
        }
    }
};

class prereNode {
public:
    int courseID;
    prereNode* next;

    prereNode(int id) {
        courseID = id;
        next = nullptr;
    }

};

class course {
public:
    int courseID;
    int courseCredits;
    string courseName;
    string courseInstructor;
    Stack prere;
    QUEUE waitlist;
    int max;
    int N;

    course(int id, string name, int credits, string instructor, int capacity) {
        courseID = id;
        courseName = name;
        courseCredits = credits;
        courseInstructor = instructor;
        max = capacity;
        N = 0;
    }


    void addprere(int prereID) {
        prere.push(prereID);
        cout << "Prerequisite has been added (:" << endl;
    }


    bool hasprere() {
        return prere.isEmpty();

    }

    Stack& getprere() {
        return prere;
    }



    bool full() {
        return N >= max;

    }

    bool studentEnrolment(students* student) {
        if (full())
        {
            waitlist.enqueueS(student);
            return 0;
        }
        else
        {
            N++;
            return 1;
        }
    }

    void drop() {
        if (N > 0)
        {
            N--;
            if (!waitlist.isEmpty())
            {
                students* nextstudnet = waitlist.dequeueS();
                if (nextstudnet)
                {
                    N++;
                    nextstudnet->history.addRecord(courseID, courseName);
                    cout << "Enrolled " << nextstudnet->name << " from waitlist " << endl;
                }
            }
        }
    }



};

class BST_Node {
public:
    course data;
    BST_Node* left;
    BST_Node* right;

    BST_Node(course c) : data(c), left(NULL), right(NULL) {}
};

class course_management {
private:
    BST_Node* root;
    int size;

public:
    course_management() {
        root = NULL;
        size = 0;
    }

    BST_Node* addCourse(BST_Node* r, course c) {
        if (r == NULL) {
            BST_Node* newNode = new BST_Node(c);
            size++;
            return newNode;
        }

        if (c.courseID < r->data.courseID) {
            r->left = addCourse(r->left, c);
        }
        else if (c.courseID > r->data.courseID) {
            r->right = addCourse(r->right, c);
        }

        return r;
    }


    BST_Node* findMin(BST_Node* r) {
        while (r->left != NULL) {
            r = r->left;
        }
        return r;
    }


    bool deleteNode(BST_Node*& r, int courseID) {
        if (r == NULL) {

            return false;
        }

        if (courseID < r->data.courseID) {

            return deleteNode(r->left, courseID);
        }
        else if (courseID > r->data.courseID) {

            return deleteNode(r->right, courseID);
        }
        else {

            if (r->left == NULL) {
                BST_Node* temp = r->right;
                delete r;
                r = temp;
                size--;
                return true;
            }
            else if (r->right == NULL) {
                BST_Node* temp = r->left;
                delete r;
                r = temp;
                size--;
                return true;
            }


            BST_Node* temp = findMin(r->right);


            r->data = temp->data;


            return deleteNode(r->right, temp->data.courseID);
        }
    }


    void displayCourses(BST_Node* r) {
        if (r == NULL) {
            return;
        }

        displayCourses(r->left);
        cout << "Course ID: " << r->data.courseID << ", Name: " << r->data.courseName
            << ", Credits: " << r->data.courseCredits << ", Instructor: " << r->data.courseInstructor << endl;
        displayCourses(r->right);
    }


    void addCourse(course c) {
        root = addCourse(root, c);
    }

    void deleteCourse(int courseID) {
        if (deleteNode(root, courseID)) {
            cout << "Course with ID " << courseID << " deleted successfully!" << endl;
        }
        else {
            cout << "Course with ID " << courseID << " not found." << endl;
        }
    }


    void displayAllCourses() {
        displayCourses(root);
    }



    course* findCourse(int courseID) {
        BST_Node* temp = root;
        while (temp != NULL) {
            if (courseID == temp->data.courseID) {
                return &(temp->data);
            }
            else if (courseID < temp->data.courseID) {
                temp = temp->left;
            }
            else {
                temp = temp->right;
            }
        }
        return NULL;
    }

    void addPrere(int courseID, int prerequistID) {
        course* c = findCourse(courseID);

        if (c != NULL)
        {
            c->addprere(prerequistID);

        }
        else
        {
            cout << "course not found " << endl;
        }
    }


    bool prereCOMPLETED(int sID, int cID, SLL& stuedntL) {
        course* c = findCourse(cID);
        if (c == NULL)
        {
            cout << "course is not found ):" << endl;
            return 0;
        }

        students* student = stuedntL.findStudent(sID);
        if (student == NULL)
        {
            cout << "student is not found ):" << endl;
            return 0;
        }

        Stack temp = c->getprere();
        while (!temp.isEmpty()) {
            int prereqID = temp.peak();
            temp.pop();

            bool found = 0;
            EnrollmentNode* enrollment = student->history.head;

            while (enrollment != NULL) {
                if (enrollment->data.courseID == prereqID)
                {
                    found = 1;
                    break;
                }
                enrollment = enrollment->next;
            }

            if (!found)
            {
                cout << "prerequists with ID " << prereqID << " is not completed" << endl;
                return 0;
            }
        }

        cout << "All prerequists are completd" << endl;
        return 1;
    }

    void displayWaitlist(int courseID) {
        course* c = findCourse(courseID);
        if (c != NULL) {
            cout << "Waitlist for Course ID " << courseID << " (" << c->courseName << "):" << endl;
            c->waitlist.dispaly();
        }
        else {
            cout << "Course with ID " << courseID << " not found." << endl;
        }
    }

    void dropCourse(int sID, int cID, SLL& studentlist) {
        course* c = findCourse(cID);
        if (c == NULL)
        {
            cout << "course is not found." << endl;
            return;
        }

        students* student = studentlist.findStudent(sID);
        if (student == NULL) {
            cout << "Student not found." << endl;
            return;
        }

        bool enrolled = 0;
        EnrollmentNode* enrollment = student->history.head;
        while (enrollment != NULL) {
            if (enrollment->data.courseID == cID)
            {
                enrolled = 1;
                break;
            }
            enrollment = enrollment->next;
        }

        if (!enrollment)
        {
            cout << "student is not enrolled in the course" << endl;
            return;
        }


        c->drop();

        EnrollmentNode* prev = nullptr;
        EnrollmentNode* cuurent = student->history.head;
        while (cuurent != nullptr) {
            if (cuurent->data.courseID == cID)
            {
                if (prev == nullptr)
                {
                    student->history.head = cuurent->next;
                }
                else {
                    prev->next = cuurent->next;
                }
                delete cuurent;
                cout << "Course has been dropped (:" << endl;
                return;
            }
            prev = cuurent;
            cuurent = cuurent->next;
        }



    }
};




int getValidInteger() {
    int value;
    while (true) {
        string input;
        getline(cin, input); 
        try {
            value = stoi(input); 
            break; 
        }
        catch (...) { 
            cout << "Invalid input! Please enter a valid number -_- : ";
        }
    }
    return value; 
}







void welcome_screen() {

    system("cls");

    cout << "\n";
    cout << "\t\t\t_______________________________________\n\n";
    cout << "\t\t\t        University Manegment Sysytem \n\n";
    cout << "\t\t\t---------------------------------------\n";
    cout << "\t\t\t             Made by:\n";
    cout << "\t\t\t             Omar Salama Salem\n";
    cout << "\t\t\t             ID: 231000674\n";
    cout << "\t\t\t_______________________________________\n\n\n";
    cout << "Press any key to enter the Universirty system ";
    _getch();

    system("cls");
}


void exit_screen() {
    system("cls");

    cout << "\n";
    cout << "\t\t\t*********************************\n\n";
    cout << "\t\t\tThank you for using Our university system\n";
    cout << "\t\t\tHave a great day!\n\n";
    cout << "\t\t\t*********************************\n\n";
}




void studentManagement(SLL& list, course_management& cm) {
    system("cls");
    while (true) {
        cout << "\n\t\t\tStudent Management System\n";
        cout << "\t\t\t-------------------------\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Display All Students\n";
        cout << "4. Search Student (Linear)\n";
        cout << "5. Search Student (Binary)\n";
        cout << "6. Return to Main Menu\n";
        cout << "Enter your choice: ";
        int choice = getValidInteger();

        int student_id;
        string name, email, phone, address, password;

        switch (choice) {

        case 1:
            cout << "Enter Student ID: ";
            student_id = getValidInteger();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Email: ";
            getline(cin, email);
            cout << "Enter Phone: ";
            getline(cin, phone);
            cout << "Enter Address: ";
            getline(cin, address);
            cout << "Enter Password: ";
            getline(cin, password);

            list.add(students(student_id, name, email, phone, address, password));
            cout << "Student " << name << " has been added (: " << endl;
            break;

        case 2:
            cout << "Enter Student ID to delete: ";
            student_id = getValidInteger();
            list.deleteNode(student_id);
            break;

        case 3:
            list.insertionsort();
            list.display();
            break;

        case 4: {
            cout << "Enter Student's ID: ";
            student_id = getValidInteger();
            students* foundStudent = list.findStudent(student_id);
            if (foundStudent) {
                cout << "Student found using linear search:\n";
                cout << "ID: " << foundStudent->student_id << ", Name: " << foundStudent->name
                    << ", Email: " << foundStudent->email << ", Phone: " << foundStudent->phone
                    << ", Address: " << foundStudent->address << ", Password: " << foundStudent->password << endl;
            }
            else {
                cout << "Student is not found ): " << endl;
            }
            break;
        }

        case 5: {
            cout << "Enter Student's ID: ";
            student_id = getValidInteger();
            list.insertionsort();
            students* foundStudent = list.findStudent_binsearch(student_id, list.head, list.tail);
            if (foundStudent) {
                cout << "Student found using binary search:\n";
                cout << "ID: " << foundStudent->student_id << ", Name: " << foundStudent->name
                    << ", Email: " << foundStudent->email << ", Phone: " << foundStudent->phone
                    << ", Address: " << foundStudent->address << ", Password: " << foundStudent->password << endl;
            }
            else {
                cout << "Student with ID " << student_id << " not found." << endl;
            }
            break;
        }

        case 6:
            return;

        default:
            cout << "Invalid choice -_-" << endl;
        }
    }
}

void courseManagement(SLL& list, course_management& cm) {
    int student_id, courseID, courseCredits, prerequisiteID, cap;
    string courseName, courseInstructor;
    system("cls");

    while (true) {
        cout << "\n\t\tCourse Management System\n";
        cout << "\t\t-------------------------\n";
        cout << "1. Add Course\n";
        cout << "2. Delete Course\n";
        cout << "3. Display All Courses\n";
        cout << "4. Add Prerequisite\n";
        cout << "5. Enroll Student\n";
        cout << "6. View Enrollment History\n";
        cout << "7. View Waitlist\n";
        cout << "8. Drop Course\n";
        cout << "9. Search Course\n";
        cout << "10. Return to Main Menu\n";
        cout << "Enter your choice: ";
        int choice = getValidInteger();

        switch (choice) {
        case 1: {
            cout << "Enter Course ID: ";
            courseID = getValidInteger();
            cout << "Enter Course Name: ";
            getline(cin, courseName);
            cout << "Enter Course Credits: ";
            courseCredits = getValidInteger();
            cout << "Enter Course Instructor: ";
            getline(cin, courseInstructor);
            cout << "Enter Course capacity: ";
            cap = getValidInteger();

            cm.addCourse(course(courseID, courseName, courseCredits, courseInstructor, cap));
            cout << "Course added successfully (: " << endl;
            break;
        }

        case 2: {
            cout << "Enter Course ID to delete: ";
            courseID = getValidInteger();
            cm.deleteCourse(courseID);
            break;
        }

        case 3: {
            cout << "All Courses:" << endl;
            cm.displayAllCourses();
            break;
        }

        case 4: {
            cout << "Enter Course ID: ";
            courseID = getValidInteger();
            cout << "Enter Prerequisite Course ID: ";
            prerequisiteID = getValidInteger();
            cm.addPrere(courseID, prerequisiteID);
            break;
        }

        case 5: {
            cout << "Enter Student ID: ";
            student_id = getValidInteger();
            cout << "Enter Course ID: ";
            courseID = getValidInteger();

            if (cm.prereCOMPLETED(student_id, courseID, list)) {
                students* student = list.findStudent(student_id);
                course* course = cm.findCourse(courseID);

                if (student == NULL) {
                    cout << "Student not found ):" << endl;
                }
                else if (course == NULL) {
                    cout << "Course not found ):" << endl;
                }
                bool enroll = course->studentEnrolment(student);
                if (enroll) {
                    student->history.addRecord(course->courseID, course->courseName);
                    cout << "Student enrolled in course successfully (:" << endl;
                }
                else {
                    cout << "...but course is full, student has been added to waitlist" << endl;
                }
            }
            else {
                cout << "Enrollment failed ): " << endl;
            }
            break;
        }

        case 6: {
            cout << "Enter Student ID: ";
            student_id = getValidInteger();
            students* student = list.findStudent(student_id);
            if (student == NULL) {
                cout << "Student not found ):" << endl;
            }
            else {
                cout << "Enrollment History for Student " << student->name << ":" << endl;
                student->history.displayHistory();
            }
            break;
        }

        case 7: {
            cout << "Enter course ID: ";
            courseID = getValidInteger();
            cm.displayWaitlist(courseID);
            cout << endl;
            break;
        }

        case 8: {
            cout << "Enter Student ID: ";
            student_id = getValidInteger();
            cout << "Enter course ID: ";
            courseID = getValidInteger();
            cm.dropCourse(student_id, courseID, list);
            break;
        }

        case 9: {
            cout << "Enter course ID: ";
            courseID = getValidInteger();
            course* foundCourse = cm.findCourse(courseID);
            if (foundCourse) {
                cout << "Course found:\n";
                cout << "Course ID: " << foundCourse->courseID << ", Name: " << foundCourse->courseName
                    << ", Credits: " << foundCourse->courseCredits << ", Instructor: " << foundCourse->courseInstructor << endl;
            }
            else {
                cout << "Course with ID " << courseID << " not found." << endl;
            }
            break;
        }

        case 10:
            return;

        default:
            cout << "Invalid choice -_-" << endl;
        }
    }
}



void hashTableOperations(HashTable& ht) {
    int student_id;
    string name, email, phone, address, password;
    system("cls");

    while (true) {
        cout << "\n\t\tHash Table Operations\n";
        cout << "\t\t----------------------\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Display Contents\n";
        cout << "4. Search Student\n";
        cout << "5. Return to Main Menu\n";
        cout << "Enter your choice: ";
        int choice = getValidInteger();

        int student_id;
        switch (choice) {
        case 1: {
            cout << "Enter Student ID: ";
            student_id = getValidInteger();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Email: ";
            getline(cin, email);
            cout << "Enter Phone: ";
            getline(cin, phone);
            cout << "Enter Address: ";
            getline(cin, address);
            cout << "Enter Password: ";
            getline(cin, password);

            ht.addStudent(students(student_id, name, email, phone, address, password));
            break;
        }

        case 2: {
            cout << "Enter Student ID to delete: ";
            student_id = getValidInteger();
            ht.deleteStudent(student_id);
            break;
        }
        case 3:
            ht.displayTable();
            break;


        case 4: {
            cout << "Enter Student ID to search: ";
            student_id = getValidInteger();
            students* found = ht.findStudent(student_id);
            if (found) {
                cout << "Student Found\n";
                cout << "Name: " << found->name << "\n";
                cout << "Email: " << found->email << "\n";
            }
            else {
                cout << "Student not found in HashTable\n";
            }
            break;
        }

        case 5:
            return;
        default: cout << "Invalid choice -_-" << endl;
        }
    }
}






int main() {
    SLL list;
    HashTable ht;
    course_management cm;
    list.insertionsort();



    welcome_screen();


    while (true) {
        system("cls");
        cout << "\nUniversity Management System - Main Menu\n";
        cout << "1. Student Management\n";
        cout << "2. Course Management\n";
        cout << "3. Hash Table Operations\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        int mainChoice = getValidInteger();

        switch (mainChoice) {
        case 1: studentManagement(list, cm); break;
        case 2: courseManagement(list, cm); break;
        case 3: hashTableOperations(ht); break;
        case 4:
            exit_screen();
            return 0;
        default:
            cout << "Invalid choice. Please try again -_-" << endl;
        }
    }
    return 0;
}
