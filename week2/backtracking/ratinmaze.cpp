
#include <iostream>
using namespace std;
bool issafe(int srcx,int srcy,int newx,int newy,int maze[][4],int row,int col){
    if((newx>=0 && newx<row) && (newy>=0 && newy<col) && (maze[newx][newy]==1)) return true;
    return false;
}
void printallpath(int maze[4][4], int row, int col, int srcx, int srcy, string output) {
    if(maze[srcx][srcy]==0) {
        cout<<"Not possible"<<endl;
        return ;
    }
    // Base case: If we reach the bottom-right corner, print the path
    if (srcx == row - 1 && srcy == col - 1) {
        cout << output << " "<<endl;
        return;
    }

    // Mark the current cell as visited by setting it to 0 (blocked)
    maze[srcx][srcy] = 0;

    // Move up
    int newx = srcx - 1;
    int newy = srcy;
    if (issafe(srcx, srcy, newx, newy, maze, row, col)) {
        printallpath(maze, row, col, newx, newy, output + 'U');
    }

    // Move down
    newx = srcx + 1;
    newy = srcy;
    if (issafe(srcx, srcy, newx, newy, maze, row, col)) {
        printallpath(maze, row, col, newx, newy, output + 'D');
    }

    // Move left
    newx = srcx;
    newy = srcy - 1;
    if (issafe(srcx, srcy, newx, newy, maze, row, col)) {
        printallpath(maze, row, col, newx, newy, output + 'L');
    }

    // Move right
    newx = srcx;
    newy = srcy + 1;
    if (issafe(srcx, srcy, newx, newy, maze, row, col)) {
        printallpath(maze, row, col, newx, newy, output + 'R');
    }

    // Unmark the current cell to allow for other paths (backtracking)
    maze[srcx][srcy] = 1;
}
int main()
{
    int maze[4][4]={
        {1,0,0,0},
        {1,1,0,0},
        {1,1,1,0},
        {1,1,1,1}
    };
    
    int row = 4 ;
    int col = 4 ;
    int srcx= 0 ;
    int srcy= 0 ;
    string output="";
    printallpath(maze,row,col,srcx,srcy,output);

    return 0;
}