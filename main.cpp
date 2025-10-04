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
            while (head != nullptr) {
                i++;
                cout << "Review " << i << ": " << endl;
                cout << "Rating: " << head->rating << endl;
                cout << "Comments: " << head->comment << endl << endl;
                head = head->next;
            }   
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
    int randint;
    ifstream file1("Movie1.txt");
    string line;
    vector<Movies> movies;

    // read first file
    if(file1.good()) {
        getline(file1, line);
        name = line;
        Movies temp = Movies(name);
        for (int i = 0; i < 3; i++) {
            getline(file1, line);
            comment = line;
            int randint = rand();
            rating = (double)(rand() * 10) - (randint / 5) + 5;
            temp.addHead(rating, comment);
        }
        movies.push_back(temp);
    }
    for(int i = 0; i < movies.size(); i++) {
        movies[i].printMovieReviews();
        movies[i].deleteList();
    }
    return 0;
}