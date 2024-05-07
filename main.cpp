//tower of hanoi using recursion

#include <iostream>
using namespace std;

int amountOfPillars = 3;
int amountOfDisks = 0;
void moveDiskSimple(int n, char A, char B)
{
    cout << "Move disk " << n << " from " << A << " to " << B << endl;
}

void setzeScheibeSimple(int n, char A, char B, char C) // A = F, B = T, W = C
{
    //cout << "To do: Move disk" << n << " von " << A << " nach " << C << endl;
    if (n==1){
        moveDiskSimple(n, A, C);
        return;
    }
    setzeScheibeSimple(n-1, A, C, B);
    moveDiskSimple(n, A, C);
    setzeScheibeSimple(n-1, B, A, C);
    
}

void setzeScheibeMultidimensionalWay(int n, int from, int to, int help)
{
    int amountOfPillars = 3;
    int amountOfDisks = n;
    int tower[amountOfPillars][amountOfDisks];
    //make array 0
    for(int i = 0; i < amountOfDisks; i++)
    {
        for(int j = 0; j < amountOfPillars; j++)
        {
            tower[i][j] = 0;
        }
    }
    
    //set disks on first pillar
    for(int i = 0; i < amountOfDisks; i++)
    {
        tower[i][from] = i+1;
    }

    //print tower
    for(int i = 0; i < amountOfDisks; i++)
    {
        for(int j = 0; j < amountOfPillars; j++)
        {
            cout << tower[i][j] << " " ;
        }
        cout << endl;
    }
}


int main(int argc, char const *argv[])
{
    /**
     * @brief 
     * if (n=1)
     * {
     *  move 1 disk from A to C
     * }
     * setze Turn(n-1, A, C, B)
     * setze Scheibe(A, B)
     * setze Turm(n-1, C, B, A)
     * 
     */
    cout << "Enter the amount of disks: ";
    cin >> amountOfDisks;

    //setzeScheibeSimple(amountOfDisks, 'A', 'B', 'C');
    setzeScheibeMultidimensionalWay(amountOfDisks, 0, 1, 2);


    return 0;
}
