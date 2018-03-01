//c++11
#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
using namespace std;
int label = 1;
int RR = 10;
int CC = 10;
vector < vector < int >>matrix (RR, vector < int >(CC));

void
create_matrix ()
{

  for (int i = 0; i < RR; i++)
    {
      for (int j = 0; j < CC; j++)
	{
	  cout << "Enter the number for Matrix 1";
	  cin >> matrix[i][j];
	}
}}

void
display_matrix ()
{

  for (int i = 0; i < RR; i++)
    {
      for (int j = 0; j < CC; j++)
	{
	  cout << matrix[i][j];
	}
      cout << "\n";
}}

int
findlarg (int a, int b, int c, int d)
{
  if (a >= b && a >= c && a >= d)
    {
      return a;
    }
  else if (b >= c && b >= d)
    {
      return b;
    }
  else if (c >= d)
    {
      return c;
    }
  else
    {
      return d;
    }
}

int
findsmall (int a, int b, int c, int d, int temp)
{
  if (a >= b && a >= c && a >= d && a > temp)
    {
      return a;
    }
  else if (b >= c && b >= d && b > temp)
    {
      return b;
    }
  else if (c >= d && c > temp)
    {
      return c;
    }
  else if (d >= temp)
    {
      return d;
    }
  else
    return temp;
}

vector < int >
search_label (int r)
{
  int i, j, x, k = 0;
  vector < int >ar;
  for (i = 0; i < RR; i++)
    {
      for (j = 0; j < CC; j++)
	{
	  x = matrix[i][j];
	  if (x == r)
	    {
	      ar.push_back (i * 10 + j);
	    }
	}
    }
  return ar;
}

void
first_pass (int x, int y)
{
  int tmp = matrix[x][y];
  int a, b, c, d;
  if (tmp == 1)
    {
      int temp = matrix[x][y];
      a = matrix[x - 1][y];
      b = matrix[x][y - 1];
      c = matrix[x + 1][y];
      d = matrix[x][y + 1];
      int larg = findlarg (a, b, c, d);
      if (larg == 0 || larg == 1)
	{
	  label++;
	  temp = label;
	}
      else
	{
	  temp = larg;
	}
      matrix[x][y] = temp;
      if (matrix[x - 1][y] == 1)
	{
	  matrix[x - 1][y] = temp;
	}
      if (matrix[x + 1][y] == 1)
	{
	  matrix[x + 1][y] = temp;
	}
      if (matrix[x][y - 1] == 1)
	{
	  matrix[x][y - 1] = temp;
	}
      if (matrix[x][y + 1] == 1)
	{
	  matrix[x][y + 1] = temp;
	}
    }
}

void
second_pass (int x, int y)
{
  int a, b, c, d, e, t, w, o, i;
  vector < int >ar;
  int temp = matrix[x][y];
  if (temp != 0)
    {
      a = matrix[x - 1][y];
      b = matrix[x][y - 1];
      c = matrix[x + 1][y];
      d = matrix[x][y + 1];
      int larg = findsmall (a, b, c, d, temp);
      if (larg != 0)
	{
	  temp = larg;
	}
      if (a != 0 && a != temp)
	{
	  ar = search_label (a);
	  o = ar.size ();
	  for (i = 0; i <= o; i++)
	    {
	      e = ar[i];
	      t = e / 10;
	      w = e % 10;
	      matrix[t][w] = temp;
	    }
	}
      if (b != 0 && b != temp)
	{
	  ar = search_label (b);
	  o = ar.size ();
	  for (i = 0; i <= o; i++)
	    {
	      e = ar[i];
	      t = e / 10;
	      w = e % 10;
	      matrix[t][w] = temp;
	    }
	}
      if (c != 0 && c != temp)
	{
	  ar = search_label (c);
	  o = ar.size ();
	  for (i = 0; i <= o; i++)
	    {
	      e = ar[i];
	      t = e / 10;
	      w = e % 10;
	      matrix[t][w] = temp;
	    }
	}
      if (d != 0 && d != temp)
	{
	  ar = search_label (d);
	  o = ar.size ();
	  for (i = 0; i <= o; i++)
	    {
	      e = ar[i];
	      t = e / 10;
	      w = e % 10;
	      matrix[t][w] = temp;
	    }
	}




    }


}




int
main ()
{
//create_matrix();

  matrix[1][1] = matrix[1][2] = matrix[1][4] = matrix[1][5] = matrix[1][6] =
    matrix[1][8] = matrix[3][1] = matrix[3][2] = matrix[3][4] = matrix[3][8] =
    matrix[1][8] = 1;
  matrix[3][1] = matrix[3][2] = matrix[3][3] = matrix[3][4] = matrix[1][8] =
    matrix[4][8] = matrix[5][2] = matrix[5][1] = matrix[5][3] = matrix[5][4] =
    matrix[5][6] = 1;
  matrix[5][8] = matrix[6][4] = matrix[6][6] = matrix[6][8] = matrix[7][1] =
    matrix[7][2] = matrix[7][3] = matrix[7][4] = matrix[7][8] = matrix[8][1] =
    matrix[8][2] = 1;
  matrix[8][3] = matrix[8][4] = matrix[8][6] = matrix[8][8] = matrix[8][7] =
    matrix[2][1] = matrix[2][2] = matrix[2][4] = matrix[2][6] = matrix[2][8] =1;
  display_matrix ();
//int x,y;
//tie(x,y)=search_nolabel();
//cout<<x<<","<<y;
  for (int i = 8; i >= 1; i--)
    for (int j = 8; j >= 1; j--)
      {
	int tmp = matrix[i][j];
	cout << tmp << "  ";
	if (tmp)
	  first_pass (i, j);
      }
  cout << "\n";
  for (int i = 8; i >= 1; i--)
    for (int j = 8; j >= 1; j--)
      {
	second_pass (j, i);
      }
  display_matrix ();
  return 0;

}

