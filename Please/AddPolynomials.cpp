#include <iostream>
using namespace std;

// Node structure to store a term of the polynomial
struct Node {
    int coeff;  // Coefficient of the term
    int pow;    // Power of the term
    Node* next;
};

// Function to create a new node
Node* createNode(int coeff, int pow) {
    Node* newNode = new Node();
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = nullptr;
    return newNode;
}

// Function to add a term to the polynomial linked list
void addTerm(Node*& poly, int coeff, int pow) {
    Node* newNode = createNode(coeff, pow);
    if (!poly) {
        poly = newNode;
    } else {
        Node* temp = poly;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = nullptr;
    while (poly1 && poly2) {
        if (poly1->pow > poly2->pow) {
            addTerm(result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            addTerm(result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        } else {
            int sumCoeff = poly1->coeff + poly2->coeff;
            addTerm(result, sumCoeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    
    // Add remaining terms of poly1, if any
    while (poly1) {
        addTerm(result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }

    // Add remaining terms of poly2, if any
    while (poly2) {
        addTerm(result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return result;
}

// Function to print the polynomial
void printPolynomial(Node* poly) {
    while (poly) {
        cout << poly->coeff << "x^" << poly->pow;
        poly = poly->next;
        if (poly) {
            cout << " + ";
        }
    }
    cout << endl;
}

int main() {
    Node* poly1 = nullptr;
    Node* poly2 = nullptr;

    // Example Polynomial 1: 5x^3 + 4x^2 + 2x^1
    addTerm(poly1, 5, 3);
    addTerm(poly1, 4, 2);
    addTerm(poly1, 2, 1);

    // Example Polynomial 2: 3x^3 + 1x^2 + 7x^0
    addTerm(poly2, 3, 3);
    addTerm(poly2, 1, 2);
    addTerm(poly2, 7, 0);

    cout << "Polynomial 1: ";
    printPolynomial(poly1);

    cout << "Polynomial 2: ";
    printPolynomial(poly2);

    // Add the two polynomials
    Node* result = addPolynomials(poly1, poly2);
    cout << "Resultant Polynomial after addition: ";
    printPolynomial(result);

    return 0;
}
