#include <iostream>
using namespace std;

class Sparse{
    int arr[10][10];
    int sp[50][3];
    int r, c, n;

public:
    void accept();
    void convert();
    void display();
    void add(Sparse m1, Sparse& result);
    void multiply(Sparse m1, Sparse& result);
    void fastTranspose(Sparse& result);
    void standardTranspose(Sparse& result);
};

void Sparse::accept(){
    cout<<"Enter number of rows: ";
    cin >> r;
    cout<<"Enter number of columns: ";
    cin >> c;

    cout<<"Enter the matrix elements: "<<endl;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> arr[i][j];
        }
    }
}

void Sparse::convert(){
    n = 1;
    sp[0][0] = r;
    sp[0][1] = c;
    sp[0][2] = 0;

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (arr[i][j] != 0){
                sp[n][0] = i;
                sp[n][1] = j;
                sp[n][2] = arr[i][j];
                n++;
            }
        }
    }
    sp[0][2] = n - 1;
}

void Sparse::display(){
    cout<<"Sparse Matrix representation:\n";
    cout<<"Row\tColumn\tValue\n";
    for (int i = 0; i < n; i++){
        cout<<sp[i][0]<<"\t"<<sp[i][1]<<"\t"<<sp[i][2]<<endl;
    }
}

void Sparse::add(Sparse m1, Sparse& result){
    if (r != m1.r || c != m1.c){
        cout<<"invalid addition"<<endl;
        return;
    }

    int i = 1, j = 1, k = 1;
    result.sp[0][0] = r;
    result.sp[0][1] = c;

    while (i < n && j < m1.n){
        if (sp[i][0] == m1.sp[j][0] && sp[i][1] == m1.sp[j][1]){
            result.sp[k][0] = sp[i][0];
            result.sp[k][1] = sp[i][1];
            result.sp[k][2] = sp[i][2] + m1.sp[j][2];
            i++;
            j++;
        } else if (sp[i][0] < m1.sp[j][0] || (sp[i][0] == m1.sp[j][0] && sp[i][1] < m1.sp[j][1])){
            result.sp[k][0] = sp[i][0];
            result.sp[k][1] = sp[i][1];
            result.sp[k][2] = sp[i][2];
            i++;
        } else{
            result.sp[k][0] = m1.sp[j][0];
            result.sp[k][1] = m1.sp[j][1];
            result.sp[k][2] = m1.sp[j][2];
            j++;
        }
        k++;
    }

    while (i < n){
        result.sp[k][0] = sp[i][0];
        result.sp[k][1] = sp[i][1];
        result.sp[k][2] = sp[i][2];
        i++;
        k++;
    }

    while (j < m1.n){
        result.sp[k][0] = m1.sp[j][0];
        result.sp[k][1] = m1.sp[j][1];
        result.sp[k][2] = m1.sp[j][2];
        j++;
        k++;
    }

    result.sp[0][2] = k - 1;
    result.n = k;
}

void Sparse::multiply(Sparse m1, Sparse& result){
    if (c != m1.r){
        cout<<"invalid multiplication"<<endl;
        return;
    }

    int temp[10][10] ={0};

    for (int i = 1; i < n; i++){
        for (int j = 1; j < m1.n; j++){
            if (sp[i][1] == m1.sp[j][0]){
                temp[sp[i][0]][m1.sp[j][1]] += sp[i][2] * m1.sp[j][2];
            }
        }
    }

    result.r = r;
    result.c = m1.c;
    result.n = 1;
    result.sp[0][0] = r;
    result.sp[0][1] = m1.c;
    result.sp[0][2] = 0;

    for (int i = 0; i < r; i++){
        for (int j = 0; j < m1.c; j++){
            if (temp[i][j] != 0){
                result.sp[result.n][0] = i;
                result.sp[result.n][1] = j;
                result.sp[result.n][2] = temp[i][j];
                result.n++;
            }
        }
    }

    result.sp[0][2] = result.n - 1;
}

void Sparse::fastTranspose(Sparse& result){
    int rowTerms[10] ={0};
    int startPos[10];

    result.sp[0][0] = c;
    result.sp[0][1] = r;
    result.sp[0][2] = sp[0][2];

    for(int i=1; i<n; i++){
        rowTerms[sp[i][1]]++;
    }

    startPos[0] = 1;
    for (int i = 1; i < c; i++){
        startPos[i] = startPos[i-1] + rowTerms[i-1];
    }

    for (int i=1; i<n; i++){
        int j = startPos[sp[i][1]]++;
        result.sp[j][0] = sp[i][1];
        result.sp[j][1] = sp[i][0];
        result.sp[j][2] = sp[i][2];
    }

    result.n = n;
}

void Sparse::standardTranspose(Sparse& result){
    int temp[10][10] ={0};

    result.sp[0][0] = c;
    result.sp[0][1] = r;
    result.sp[0][2] = sp[0][2];

    for (int i=1; i<n; i++){
        int row = sp[i][1];
        int col = sp[i][0];
        int value = sp[i][2];
        temp[row][col] = value;
    }

    int index = 1;
    for (int i = 0; i < c; i++){
        for (int j = 0; j < r; j++){
            if (temp[i][j] != 0){
                result.sp[index][0] = i;
                result.sp[index][1] = j;
                result.sp[index][2] = temp[i][j];
                index++;
            }
        }
    }

    result.n = index;
}

int main(){
    Sparse m1, m2, result;
    int choice;

    while (true){
        cout<<"Menu:"<<endl;
        cout<<"1. Read matrix1"<<endl;
        cout<<"2. Read matrix2"<<endl;
        cout<<"3. Display matrix1"<<endl;
        cout<<"4. Display matrix2"<<endl;
        cout<<"5. Addition"<<endl;
        cout<<"6. Multiplication"<<endl;
        cout<<"7. Fast Transpose of matrix1"<<endl;
        cout<<"8. Fast Transpose of matrix2"<<endl;
        cout<<"9. Transpose of matrix1"<<endl;
        cout<<"10.Transpose of matrix2"<<endl;
        cout<<"11.Exit\n";
        cout<<"Enter your choice: ";
        cin >> choice;

        switch (choice){
            case 1:
                cout<<"matrix1: "<<endl;
                m1.accept();
                m1.convert();
                break;

            case 2:
                cout<<"matrix2: "<<endl;
                m2.accept();
                m2.convert();
                break;

            case 3:
                cout<<"matrix1: "<<endl;
                m1.display();
                break;

            case 4:
                cout<<"matrix2:"<<endl;
                m2.display();
                break;

            case 5:
                cout<<"Addition of matrix1 and matrix2:"<<endl;
                m1.add(m2, result);
                result.display();
                break;

            case 6:
                cout<<"Multiplication of matrix1 and matrix2:"<<endl;
                m1.multiply(m2, result);
                result.display();
                break;

            case 7:
                cout<<"Fast Transpose of matrix1: "<<endl;
                m1.fastTranspose(result);
                result.display();
                break;

            case 8:
                cout<<"Fast Transpose of matrix2: "<<endl;
                m2.fastTranspose(result);
                result.display();
                break;

            case 9:
                cout<<"Transpose of matrix1:"<<endl;
                m1.standardTranspose(result);
                result.display();
                break;

            case 10:
                cout<<"Transpose of matrix2: "<< endl;
                m2.standardTranspose(result);
                result.display();
                break;

            case 11:
                exit(0);

            default:
                cout<<"Invalid choice!\n";
        }
    }

    return 0;
}