#include <bits/stdc++.h>
#include <ostream>

using namespace std;

struct Course {
    string name;
    int numberOfStudents;
    string Lecturer;
};

struct ACM {
    friend ostream &operator<<(ostream &os, const ACM &acm) {
        os << "topic: " << acm.topic << " numberOfPresentations: "
           << acm.numberOfPresentations;
        cout << " \nAll locations: \n";

        for(auto const &to : acm.Location){
            cout << to.first << " " << to.second << "\n";
        }

        return os;
    }

    friend istream &operator>>(istream &is, ACM &acm) {
        cout << "Input topic name:\n";
        is >> acm.topic;
        cout << "Input number of presentations:\n";
        is >> acm.numberOfPresentations;
        cout << "Input all cities and addrestudentses of presentations\n";
        cout << acm.numberOfPresentations << "\n";
        for(int i = 0; i < acm.numberOfPresentations; i++){
            string city, addrestudents;
            cin >> city >> addrestudents;
            acm.Location[city] = addrestudents;
        }
        return is;
    }

    ACM() {}

    string topic;
    map<string,string> Location;
    int numberOfPresentations;

    ACM(const string &topic, int numberOfPresentations) : topic(topic), numberOfPresentations(numberOfPresentations) {}
};

struct IEE {

    friend istream &operator>>(istream &is,  IEE &iee) {
        cout << "Enter conference name\n";
        is >> iee.conferenceName;
        cout << "Enter conference location\n";
        is >> iee.conferenceLocation;
        cout << "How many topics will be?:\n";
        int numberOftopics;
        cin >> numberOftopics;

        cout << "Enter all " << numberOftopics << " topic names:\n";
        while(numberOftopics--){
            string name;
            cin >> name;
            iee.topics.insert(name);
        }
        return is;
    }

    friend ostream &operator<<(ostream &os, const IEE &iee) {

        os << "IEE: conferenceName: " << iee.conferenceName << " conferenceLocation: " << iee.conferenceLocation
           << " topics: ";

        for(auto const &to : iee.topics){
            cout << to << " ";
        }

        return os;
    }

    IEE() {}

    string conferenceName;
    string conferenceLocation;
    set<string>topics;

    IEE(const string &conferenceName, const string &conferenceLocation) : conferenceName(conferenceName),
                                                                          conferenceLocation(conferenceLocation) {}
};

template<class T>
class  Student {
public:
    string name;
    int id;
    int age;
    string course;
    T activity;

    Student() {}

    Student(const string &name, int id, int age, const string &course, T activity) : name(name), id(id), age(age),
                                                                                     course(course),
                                                                                     activity(activity) {}

    friend ostream &operator<<(ostream &os, const Student &student) {
        os << "name: " << student.name << " id: " << student.id << " age: " << student.age << " course: "
           << student.course << " " << student.activity;
        return os;
    }

    friend istream &operator>>(istream &is, Student &student){
        cout << "Enter name:\n";
        is >> student.name;
        cout << "Enter age:\n";
        is >> student.age;
        cout << "Enter course:\n";
        is >> student.course;
        cout << "Enter ID\n";
        is >> student.id;
        is >> student.activity;
        return is;
    }
};

struct Stud {
    string name;
    int grade;

    Stud(const string &name, int grade) : name(name), grade(grade) {}

    Stud() {}

    bool operator==(const Stud &rhs) const {
        return name == rhs.name &&
               grade == rhs.grade;
    }

    bool operator!=(const Stud &rhs) const {
        return !(rhs == *this);
    }

};

bool isEven(Stud student){
    return student.grade % 2 == 0;
}

int main() {

    int taskNum;

    cout << "1: First Task\n";
    cout << "2: Second Task\n";

    cin >> taskNum;

    if(taskNum == 1) {
        Student<ACM> acmStudent;
        Student<IEE> ieeStudent;

        cin >> acmStudent >> ieeStudent;

        cout << acmStudent;
        cout << "\n";
        cout << ieeStudent;
    } else {
        Stud students[6];
        students[0] = *new Stud("Akzhol", 100);
        students[1] = *new Stud("Muha", 100);
        students[2] = *new Stud("Azamat", 80);
        students[3] = *new Stud("Yermek", 35);
        students[4] = *new Stud("Nikita", 67);
        students[5] = *new Stud("Amanzhol", 100);

        cout << "All students:\n";
        for (int i = 0; i < 6; i++) {
            cout << students[i].name << " " << students[i].grade << "\n";
        }
        cout << "\n";

        cout << "Search for [Akzhol, 100]\n";
        cout << count(students, students + 6, *new Stud("Akzhol", 100)) << "\n";

        cout << "Find [Muha, 100] and display name\n";
        cout << find(students, students + 6, *new Stud("Muha", 100))->name << "\n";

        // for each student add 50% to grade
        for_each(students, students + 6, [](Stud &stud) { stud.grade *= 1.5; });
        // display after adding bonus points
        for (int i = 0; i < 6; i++) {
            cout << students[i].name << " " << students[i].grade << "\n";
        }
        cout << "\n";

        // display number of students with even grade
        cout << count_if(students, students + 6, isEven);
    }


}

