//tower of hanoi using recursion

#include <iostream>
using namespace std;

const int amountOfPillars = 3;
const int amountOfDisks = 20;
int from = 0, to = 0, help = 0;
int tower [amountOfPillars][amountOfDisks];
int amountOfDisksChosen;

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

void allZero (int amountOfDisksChosen){
    for (int i = 0; i < amountOfDisks; i++)
    {
        for(int j = 0; j < amountOfPillars; j++){
            tower[j][i] = 0;
        }
    }
}

void initialize(int amountOfDisksChosen){
    std::cout << "-----" << endl;
    for (int i = 0; i < amountOfDisksChosen; i++)
    {
        for(int j = 0; j < amountOfPillars; j++){
            std::cout << tower[j][i] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "-----" << std::endl;

}

void moveDiskSimpleMultidim(int n, int from, int to)
{
    //n = chosen disk
    //from = from which pillar
    //to = to which pillar
    cout << "TO DO: Move disk " << n << " from " << from+1 << " to " << to+1 << endl;
    int i = 0;
    while(tower[to][i] == 0 && i < amountOfDisksChosen){
        i++;
    }
    int j = 0;
    for(j = 0; j < amountOfDisksChosen; j++){
        if(tower[from][j] == n){
            break;
        }
    }
    tower[to][i-1] = n;
    tower[from][j] = 0;
    cout << "RESULT : " << endl;
    initialize(amountOfDisksChosen);
}

void setzeTurm(int amountOfDiscsChosen, int from, int with, int to){
    if (amountOfDiscsChosen==1){
        moveDiskSimpleMultidim(amountOfDiscsChosen, from, to );
        return;
    }
    
    setzeTurm(amountOfDiscsChosen-1, from, to, with);// a- from, b - with, c - to
    moveDiskSimpleMultidim(amountOfDiscsChosen, from, to);
    setzeTurm(amountOfDiscsChosen-1, with, from, to); // 1, 2 , 0, 1

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
    cin >> amountOfDisksChosen;
    cout << "Enter the pillar to move from: " << endl;
    cin >> from;
    from-=1;
    cout << "Enter the pillar to move to: " << endl;
    cin >> to;
    to-=1;
    cout << "Enter the pillar to use as help: " << endl;
    cin >> help;
    help-=1;
    //Preparation
    allZero(amountOfDisksChosen);
    for (int i = 0; i < amountOfDisksChosen; i++)
    {
        tower[from][i] = i+1;
    }
    cout << "Initial state: " << endl;
    initialize(amountOfDisksChosen);

    //setzeScheibeSimple(amountOfDisks, 'A', 'B', 'C');
    
    setzeTurm(amountOfDisksChosen, from, help, to);

    return 0;
}
