#include "Matrix.h"

int main()
{
    int option;
    bool continueProgram = true;
    MatrixType Matrix[10];
    int matrixCount = 0;

    while (continueProgram)
    {
        cout << "Enter the corresponding number for your desired operation: "; 
        cout << "1 - get a new matrix;  ";
        cout << "2 - add two matrices;  ";
        cout << "3 - subtract a matrix from another;  ";
        cout << "4 - multiply two matrices;  ";
        cout << "5 - print matrix;  ";
        cout << "6 - end the program;" << endl;

        cin >> option;

        switch (option)
        {
            case 1:
            {
                int r, c, item;

                cout << "A matrix with 0X0 is created. Enter the number of rows and columns for this new matrix: " << endl;
                cin >> r >> c;
                Matrix[matrixCount].SetSize(r, c);

                cout << "Enter the values: " << endl;

                for (int i = 0; i < r; i++)
                {
                    for (int j = 0; j < c; j++)
                    {
                        cin >> item;
                        Matrix[matrixCount].StoreItem(item, i, j);
                    }
                }

                matrixCount++;
                cout << "Thank you. You now have total " << matrixCount << " matrices in system." << endl;
            }
            break;

            case 2:
            {
                int a, b , c;
                cout << "Suppose that you want to perform A+B=C. Enter A, B and C: " << endl;
                cin >> a >> b >> c;

                if (a >= matrixCount || b >= matrixCount || c >= 10)
                {
                    cout << "Error: One or more operand matrices does not exist. " << endl;
                }
                else if (Matrix[a].AddSubCompatible(Matrix[b]) == false)
                {
                    cout << "The operation is not compatible. " << endl;
                }
                else
                {
                    Matrix[a].Add(Matrix[b], Matrix[c]);

                    cout << "Matrices " << a << " and " << b << " are added and the result is stored in matrix " << c << "." << endl;
                }
            }
            break;

            case 3:
            {
                int a, b , c;
                cout << "Suppose that you want to perform A-B=C. Enter A, B and C: " << endl;
                cin >> a >> b >> c;

                if (a >= matrixCount || b >= matrixCount || c >= 10)
                {
                    cout << "Error: One or more operand matrices does not exist. " << endl;
                }
                else if (Matrix[a].AddSubCompatible(Matrix[b]) == false)
                {
                    cout << "The operation is not compatible. " << endl;
                }
                else
                {
                    Matrix[a].Sub(Matrix[b], Matrix[c]);

                    cout << "Matrix " << a << " is subtracted from matrix " << b << ", and the result is stored in matrix " << c << "." << endl;
                }
            }
            break;

            case 4:
            {
                int a, b , c;
                cout << "Suppose that you want to perform A*B=C. Enter A, B and C: " << endl;
                cin >> a >> b >> c;

                if (a >= matrixCount || b >= matrixCount || c >= 10)
                {
                    cout << "Error: One or more operand matrices does not exist. " << endl;
                }
                else if (Matrix[a].MultCompatible(Matrix[b]) == false)
                {
                    cout << "The operation is not compatible. " << endl;
                }
                else
                {
                    Matrix[a].Mult(Matrix[b], Matrix[c]);

                    cout << "Matrices " << a << " and " << b << " are multiplied and the result is stored in matrix " << c << "." << endl;
                }
            }
            break;

            case 5:
            {
                int matrixNum;
                cout << "Enter the matrix number for printing: " << endl;
                cin >> matrixNum;

                if (matrixNum >= matrixCount)
                {
                    cout << "The input is invalid. " << endl;
                    break;
                }

                cout << "The matrix " << matrixNum << " is: " << endl;
                Matrix[matrixNum].Print();
            }
            break;

            case 6:
            {
                continueProgram = false;
            }
            break;

            default:
            cout << "Invalid input, please try again." << endl;
        }
    }
}
