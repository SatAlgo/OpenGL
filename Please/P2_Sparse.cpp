#include <iostream>
using namespace std;
class sparcematrix
{
private:
    int row, col, n;
    int triplet[10][3];

public:
    sparcematrix(int r1, int c1, int n1)
    {
        row = r1;
        col = c1;
        n = n1;
    }

    void getTriplet();
    void displayTriplet();
    void addTriplet(sparcematrix s2);
    void transpose();
    void fastTranspose();
    void multiplication(sparcematrix s2);
};

void sparcematrix::getTriplet()
{

    triplet[0][0] = row;
    triplet[0][1] = col;
    triplet[0][2] = n;
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter the row, column, and value for element " << i << endl;
        cin >> triplet[i][0] >> triplet[i][1] >> triplet[i][2];
    }
}

void sparcematrix::displayTriplet()
{
    cout << endl<< "Matrix  :-  " << endl;

    for (int i = 0; i <= n; i++)
    {
        cout << triplet[i][0] << " " << triplet[i][1] << " " << triplet[i][2] << endl;
    }
}
void sparcematrix::addTriplet(sparcematrix s2) {
    if (triplet[0][0] != s2.triplet[0][0] || triplet[0][1] != s2.triplet[0][1]) {
        cout << "Matrix dimensions do not match" << endl;
        return;
    }

    int result[15][3];

    result[0][0] = triplet[0][0];
    result[0][1] = triplet[0][1];
    result[0][2] = 0; 

    int i = 1, j = 1, k = 1;


    while (i <= triplet[0][2] && j <= s2.triplet[0][2]) {
        if (triplet[i][0] == s2.triplet[j][0] && (triplet[i][1] == s2.triplet[j][1])) {
            result[k][0] = triplet[i][0];
            result[k][1] = triplet[i][1];
            result[k][2] = triplet[i][2] + s2.triplet[j][2];
            i++;
            j++;
        } else if (s2.triplet[j][0] < triplet[i][0] ||(s2.triplet[j][0] == triplet[i][0] && s2.triplet[j][1] < triplet[i][1])) {
            result[k][0] = s2.triplet[j][0];
            result[k][1] = s2.triplet[j][1];
            result[k][2] = s2.triplet[j][2];
            j++;
        } else {
            // If both positions are the same, add their values
            result[k][0] = triplet[i][0];
            result[k][1] = triplet[i][1];
            result[k][2] = triplet[i][2];
            i++;
        }
        k++;
    }

    // Add remaining elements from the first matrix
    while (i <= triplet[0][2]) {
        result[k][0] = triplet[i][0];
        result[k][1] = triplet[i][1];
        result[k][2] = triplet[i][2];
        i++;
        k++;
    }

    // Add remaining elements from the second matrix
    while (j <= s2.triplet[0][2]) {
        result[k][0] = s2.triplet[j][0];
        result[k][1] = s2.triplet[j][1];
        result[k][2] = s2.triplet[j][2];
        j++;
        k++;
    }

    result[0][2] = k - 1;

    cout << "Resultant matrix addition in triplet form:" << endl;
    for (int l = 0; l <= result[0][2]; l++) {
        cout << result[l][0] << " " << result[l][1] << " " << result[l][2] << endl;
    }
}

void sparcematrix::transpose()
{
    int result[50][3];
    int k = 1;

    for (int i = 0; i < triplet[0][1]; i++)
    {
        for (int j = 1; j <= triplet[0][2]; j++)
        {
            if (i == triplet[j][1])
            {
                result[k][0] = triplet[j][1];
                result[k][1] = triplet[j][0];
                result[k][2] = triplet[j][2];
                k++;
            }
        }
    }

    result[0][0] = triplet[0][1];
    result[0][1] = triplet[0][0];
    result[0][2] = k - 1;

    cout << "Transpose of the matrix in triplet form:" << endl;
    for (int l = 0; l < k; l++)
    {
        cout << result[l][0] << " " << result[l][1] << " " << result[l][2] << endl;
    }
}

void sparcematrix::fastTranspose()
{
    int loc;
    int in = 0;
    int transpose[50][3];
    int total[50] = {0};
    int index[50];

    for (int i = 1; i <= triplet[0][2]; i++)
    {
        total[triplet[i][1]]++;
    }

    index[0] = 1;
    for (int i = 1; i < triplet[0][1]; i++)
    {
        index[i] = index[i - 1] + total[i - 1];
    }

    for (int i = 1; i <= triplet[0][2]; i++)
    {
        loc = index[triplet[i][1]]++;
        transpose[loc][0] = triplet[i][1];
        transpose[loc][1] = triplet[i][0];
        transpose[loc][2] = triplet[i][2];
        in++;
    }


    transpose[0][0] = triplet[0][1];
    transpose[0][1] = triplet[0][0];
    transpose[0][2] = in;


    cout << "Fast Transpose of the matrix in triplet form:" << endl;
    for (int l = 0; l <= in; l++)
    {
        cout << transpose[l][0] << " " << transpose[l][1] << " " << transpose[l][2] << endl;
    }
}

void sparcematrix::multiplication(sparcematrix s2)
{

    if (triplet[0][1] == s2.triplet[0][0])
    {
        int k = 1;
        int result[50][3];

        for (int i = 1; i <= triplet[0][2]; i++)
        {
            for (int j = 1; j <= s2.triplet[0][2]; j++)
            {

                if (triplet[i][1] == s2.triplet[j][0])
                {
                    result[k][0] = triplet[i][0];
                    result[k][1] = s2.triplet[j][1];
                    result[k][2] = triplet[i][2] * s2.triplet[j][2];
                    k++;
                }
            }
        }
    //checking for same elements
        for (int i = 1; i < k - 1; i++)
        {
            for (int j = i + 1; j < k; j++)
            {
                if (result[i][0] == result[j][0] && result[i][1] == result[j][1])
                {
                    result[i][2] += result[j][2];
                    for (int x = j; x < k - 1; x++)
                    {
                        result[x][0] = result[x + 1][0];
                        result[x][1] = result[x + 1][1];
                        result[x][2] = result[x + 1][2];
                    }
                    k--;
                    j--;
                }
            }
        }

        result[0][0] = triplet[0][0];
        result[0][1] = s2.triplet[0][1];
        result[0][2] = k - 1;

        cout << "Multiplication : " << endl;
        for (int i = 0; i < k; i++)
        {
            cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;
        }
    }
    else
    {
        cout << "Multiplication is not possible !! " << endl;
    }
}

int main()
{
    int r, c, n;

    cout << "Enter the number of rows, columns, and elements of the first matrix: "<<endl;
    cin >> r >> c >> n;
    sparcematrix s1(r, c, n);
    s1.getTriplet();
    cout << "Enter the number of rows, columns, and elements of the second matrix: ";
    cin >> r >> c >> n;
    sparcematrix s2(r, c, n);
    s2.getTriplet();
    int choice = 1, ch = 1;
    do
    {
        cout << "Enter 1 for displaying 1st matrix" << endl;
        cout << "Enter 2 for displaying 2nd matrix" << endl;
        cout << "Enter 3 for transpose of 1st matrix" << endl;
        cout << "Enter 4 for fast-transpose of 2nd matrix" << endl;
        cout << "Enter 5 for addition of two matrix" << endl;
        cout << "Enter 6 for multiplication of two matrix" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1: // display of 1 matrix
            s1.displayTriplet();
            break;
        case 2: // display of matrix 2
            s2.displayTriplet();
            break;
        case 3: // transpose of 1
            s1.transpose();
            break;
        case 4: // fast-transpose of 2
            s2.fastTranspose();
            break;
        case 5: // add
            s1.addTriplet(s2);
            break;
        case 6: // multiply
            s1.multiplication(s2);
            break;
        default:
            cout << "Invalid choice entered " << endl;
        }
        cout << "Enter 1 if you want to continue " << endl;
        cin >> ch;
    } while (ch == 1);
    return 0;
}


// 5 0 8
// 0 3 0
// 6 0 0

// 3 3 4
// 0 0 5
// 0 2 8
// 1 1 3
// 2 0 6

// 0 7 6
// 2 0 0
// 0 0 1

// 3 3 4
// 0 1 7
// 0 2 6
// 1 0 2
// 2 2 1
