#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int exp;
    Node* next;

    Node(int c, int e) : coeff(c), exp(e), next(nullptr) {}
};

void insert(Node*& head, int coeff, int exp) {
    Node* newNode = new Node(coeff, exp);

    if (!head || head->exp < exp) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next && temp->next->exp >= exp) {
        temp = temp->next;
    }

    if (temp->exp == exp) {
        temp->coeff += coeff;
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = nullptr;

    while (poly1 && poly2) {
        if (poly1->exp > poly2->exp) {
            insert(result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            insert(result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            insert(result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1) {
        insert(result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2) {
        insert(result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

Node* subtractPolynomials(Node* poly1, Node* poly2) {
    Node* result = nullptr;

    while (poly1 && poly2) {
        if (poly1->exp > poly2->exp) {
            insert(result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            insert(result, -poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            insert(result, poly1->coeff - poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1) {
        insert(result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2) {
        insert(result, -poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

Node* multiplyPolynomials(Node* poly1, Node* poly2) {
    Node* result = nullptr;

    for (Node* ptr1 = poly1; ptr1 != nullptr; ptr1 = ptr1->next) {
        Node* temp = nullptr;
        for (Node* ptr2 = poly2; ptr2 != nullptr; ptr2 = ptr2->next) {
            insert(temp, ptr1->coeff * ptr2->coeff, ptr1->exp + ptr2->exp);
        }
        result = addPolynomials(result, temp);
    }

    return result;
}

// Function to print a polynomial
void printPolynomial(Node* poly) {
    while (poly) {
        cout << poly->coeff << "x^" << poly->exp;
        if (poly->next && poly->next->coeff >= 0) {
            cout << " + ";
        }
        poly = poly->next;
    }
    cout << endl;
}

int main() {
    Node* poly1 = nullptr;
    Node* poly2 = nullptr;

    insert(poly1, 3, 3);
    insert(poly1, 2, 2);
    insert(poly1, 1, 0);

    insert(poly2, 4, 2);
    insert(poly2, 2, 1);
    insert(poly2, 3, 0);

    cout << "Polynomial 1: ";
    printPolynomial(poly1);

    cout << "Polynomial 2: ";
    printPolynomial(poly2);

    Node* sum = addPolynomials(poly1, poly2);
    cout << "Sum: ";
    printPolynomial(sum);

    Node* difference = subtractPolynomials(poly1, poly2);
    cout << "Difference: ";
    printPolynomial(difference);

    Node* product = multiplyPolynomials(poly1, poly2);
    cout << "Product: ";
    printPolynomial(product);

    return 0;
}
