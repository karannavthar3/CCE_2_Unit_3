#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
    string question;
    Node* yes;
    Node* no;

    Node(string q) {
        question = q;
        yes = nullptr;
        no = nullptr;
    }
};

class Quiz {
private:
    Node* root;

    // Recursively conduct the quiz
    void takeQuiz(Node* node) {
        if (node == nullptr)
            return;

        // A leaf node contains a final result
        if (node->yes == nullptr && node->no == nullptr) {
            cout << "Result: " << node->question << endl;
            return;
        }

        char answer;
        cout << node->question << " (y/n): ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y') {
            takeQuiz(node->yes);
        } else if (answer == 'n' || answer == 'N') {
            takeQuiz(node->no);
        } else {
            cout << "Please enter y or n." << endl;
            takeQuiz(node);
        }
    }

    // Recursive preorder traversal: root, yes subtree, no subtree
    void preorder(Node* node) {
        if (node == nullptr)
            return;

        cout << node->question << endl;
        preorder(node->yes);
        preorder(node->no);
    }

    // Recursively count leaf nodes
    int countLeafNodes(Node* node) {
        if (node == nullptr)
            return 0;

        if (node->yes == nullptr && node->no == nullptr)
            return 1;

        return countLeafNodes(node->yes) + countLeafNodes(node->no);
    }

    // Recursively count internal nodes
    int countInternalNodes(Node* node) {
        if (node == nullptr)
            return 0;

        if (node->yes == nullptr && node->no == nullptr)
            return 0;

        return 1 + countInternalNodes(node->yes)
                 + countInternalNodes(node->no);
    }

    // Calculate height recursively (measured in nodes)
    int treeHeight(Node* node) {
        if (node == nullptr)
            return 0;

        int leftHeight = treeHeight(node->yes);
        int rightHeight = treeHeight(node->no);

        return 1 + max(leftHeight, rightHeight);
    }

    // Release dynamically allocated nodes
    void deleteTree(Node* node) {
        if (node == nullptr)
            return;

        deleteTree(node->yes);
        deleteTree(node->no);
        delete node;
    }

public:
    Quiz() {
        // Build the binary tree of questions and results
        root = new Node("Do you like outdoor activities?");

        root->yes = new Node("Do you like team sports?");
        root->no = new Node("Do you prefer indoor activities?");

        root->yes->yes = new Node("You may enjoy football.");
        root->yes->no = new Node("You may enjoy solo outdoor activities.");

        root->no->yes = new Node("You may enjoy indoor games.");
        root->no->no = new Node("You may enjoy reading.");
    }

    ~Quiz() {
        deleteTree(root);
    }

    void startQuiz() {
        cout << "\n===== YES/NO QUIZ =====" << endl;
        takeQuiz(root);
    }

    void displayQuestions() {
        cout << "\n===== PREORDER TRAVERSAL =====" << endl;
        preorder(root);
    }

    void displayStatistics() {
        cout << "\n===== BINARY TREE STATISTICS =====" << endl;
        cout << "Leaf Nodes: " << countLeafNodes(root) << endl;
        cout << "Internal Nodes: " << countInternalNodes(root) << endl;
        cout << "Tree Height: " << treeHeight(root) << endl;
    }
};

int main() {
    Quiz quiz;
    int choice;

    do {
        cout << "\n===== QUIZ APPLICATION =====" << endl;
        cout << "1. Start Quiz" << endl;
        cout << "2. Display Preorder Traversal" << endl;
        cout << "3. Display Tree Statistics" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                quiz.startQuiz();
                break;
            case 2:
                quiz.displayQuestions();
                break;
            case 3:
                quiz.displayStatistics();
                break;
            case 4:
                cout << "Exiting application..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
