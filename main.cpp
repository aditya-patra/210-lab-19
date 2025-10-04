/*
Aditya Patra
Movie Review List
Lab 19

Purpose:
Create linked list of movie Review
Create vector of movies that have been reviewed from file of movie comments
*/
#include <iostream>
#include <string>
using namespace std;

const int SIZE = 7;  

struct Review {
    float rating;
    string comment;
    Review *next;
};

class Movies {
    private:
        string name;
        Review * head;
    public:
        Movies(string title) {
            name = title;
            head = nullptr;
        } 
        string getName() {
            return name;
        }
        Review addHead(float rating, string comment) {
            Review * temp = new Review;
            if (!head) {
                head = temp;
                temp->next = nullptr;
                temp->rating = rating;
                temp->comment = comment;
            }
            else {
                temp->next = head;
                temp->rating = rating;
                temp->comment = comment;
                head = temp;
            }   
        }
};

void printList(Review *);
void addHead(Review * &, float, string);
void deleteList(Review *);

int main() {
    Review *head = nullptr;
    float rating;
    string comment;
    string dummy; //flush input
    string cont;
    while (true) {
        cout << "Enter your rating of the movie: ";
        cin >> rating;
        cout << "Enter your review of the movie: ";
        getline(cin, dummy);
        getline(cin, comment);
        addHead(head, rating, comment);
        cout << "Would you like to enter another review?(Y/n) ";
        cin >> cont;
        if (cont == "n") {
            break;
        }
    }
    printList(head);
    deleteList(head);

    return 0;
}

void printList(Review * head) {
    if (head == nullptr) {
        return;
    }
    int i = 0;
    float sum = 0;
    while (head != nullptr) {
        i++;
        sum += head->rating;
        cout << "Review " << i << ": " << endl;
        cout << "Rating: " << head->rating << endl;
        cout << "Comments: " << head->comment << endl << endl;
        head = head->next;
    }
    cout << endl << "Average Rating: " << (sum / i) << endl;
}

void addHead(Review * &head, float rating, string comment) {
    Review * temp = new Review;
    if (!head) {
        head = temp;
        temp->next = nullptr;
        temp->rating = rating;
        temp->comment = comment;
    }
    else {
        temp->next = head;
        temp->rating = rating;
        temp->comment = comment;
        head = temp;
    }
}

void deleteList(Review * head) {
    Review * temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
}