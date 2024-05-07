//tower of hanoi using recursion

#include <iostream>
using namespace std;

const int amountOfPillars = 3 ;
const int amountOfDisks = 3;
int tower [amountOfPillars][amountOfDisks];

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

void allZero(){
    for (int i = 0; i < amountOfDisks; i++)
    {
        for(int j = 0; j < amountOfPillars; j++){
            tower[j][i] = 0;
        }
    }
}

void initialize(){
    cout << endl;
    for (int i = 0; i < amountOfDisks; i++)
    {
        for(int j = 0; j < amountOfPillars; j++){
            std::cout << tower[j][i];
        }
        std::cout << std::endl;
    }

}
void moveDiskSimpleMultidim(int n, int from, int to)
{
    int remember = 0;
    for(int i = 0; i < amountOfDisks; i++){
        if(tower[from][i] != 0){
            remember = tower[from][i];
            tower[from][i] = 0;
            break;
        }
    }
    remember = 0;
}

void setzeTurm(int n, int from, int to, int with){
    allZero();
    for (int i = 0; i < amountOfDisks; i++)
    {
        tower[from][i] = i+1;
    }
    initialize();
    if (n==1){
        moveDiskSimpleMultidim(n, from, to);
        return;
    }
    setzeTurm(n-1, from, with, to);
    moveDiskSimpleMultidim(n, from, to);
    setzeTurm(n-1, with, to, from);
    initialize();
    //setzeTurm(n-1, from, with, to);
    //moveDiskSimpleMultidim(n, from, to);
    //setzeTurm(n-1, with, to, from);
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
    cout << "Enter the amount of disks: " << endl;
    //cin >> amountOfDisks;

    //setzeScheibeSimple(amountOfDisks, 'A', 'B', 'C');

    setzeTurm(3, 0, 1, 2);


    return 0;
}
