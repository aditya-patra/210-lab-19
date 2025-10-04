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
#include <fstream>
#include <vector>
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

        void setName(string newName) {
            name = newName;
        }

        void addHead(float rating, string comment) {
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

        void printMovieReviews() {
            cout << "Movie: " << name << endl;
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

        void deleteList() {
            Review * temp;
            while (head != nullptr) {
                temp = head;
                head = head->next;
                delete temp;
            }
            head = nullptr;
        }
};


int main() {
    Review *head = nullptr;
    string name;
    float rating;
    string comment;
    ifstream file("Movie1.txt");
    string line;
    vector<Movies> movies;
    if(file.good()) {
        getline(file, line);
        name = line;
        for (int i = 0; i < 3; i++) {
            getline(file, line);
            comment = line;
        }
    }

    return 0;
}