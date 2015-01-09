#include <libplayerc++/playerc++.h>
#include <iostream>
#include <pthread.h>
#include "math.h"
#include <fstream>
#include <istream>

using namespace PlayerCc;
using namespace std;

int main(int argc, char** argv)
{
  PlayerClient robot("127.0.0.1", 6665);
  Position2dProxy pp(&robot,0);
  LaserProxy lp(&robot,0);

  //Read processed bitmap from MATLAB
  fstream g_map;
  g_map.open("map.txt");

  int row = 0, col = 0;
  bool colcheck = true;
	
  while (g_map.good())
    {
      char c = g_map.get();
      if(c != '\n' && colcheck) {
	col++;
      } else if(c == '\n') {
	row++;
	colcheck = false;
      }
    }

  col++;
  col /= 2;


  g_map.close();
  
  //Convert to internal matrix
  g_map.open("map.txt");

  int grid[row][col];
  int count = 0, rowPos = 0, colPos = 0;

  while (g_map.good())
    {
      char c;
      g_map >> c;
      if(c == ',' || c == '\n') {
	continue;
      }

      int number = (int) (c - '0');

      colPos = count % col;
      rowPos = count / col;
      grid[rowPos][colPos] = number;
      count++;	
    }

  ofstream ofs("grid_proof.txt");
  for(int i = 0 ; i < row ; i++ ) {
    for(int j = 0 ; j < col ; j++ ) 
      ofs << grid[i][j] << " ";
    ofs << endl;
  }
  ofs.close();

  return 0;
}
