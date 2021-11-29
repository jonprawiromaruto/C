// Jonathan Prawiromaruto
// 09/22/2021
// Solution to Problem: countingstars

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solve(char **table, int n, int m);
void floodfill(char **table, int n, int m, int x, int y, char oldfill, char newfill);

int main(void) 
{
  //scanf until EOF
  int c, n, m, i;

  while(scanf("%d %d", &n, &m) != EOF)
  {
    char **table = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) 
    {        
      table[i] = malloc(m * sizeof(char) + 1);
      scanf("%s", table[i]);
    } 

    int stars;  
    stars = solve(table, n, m);
    printf("Case %d: %d\n", c+1, stars);

    free(table);
    c++;
  }
  return 0;
}

int solve(char **table, int n, int m) 
{
  int i, j, numregions = 0;

  // Going through each pixel
  for (i=0; i<n; i++) 
  {
    for (j=0; j<m; j++) 
    {
      // Found a new star, then run a floodfill function
      if (table[i][j] == '-') 
      {
        numregions++;
        floodfill(table, n, m, i, j, '-', '#');
      }
    }
  }
  return numregions;
}

void floodfill(char **table, int n, int m, int x, int y, char oldfill, char newfill) 
{
  // out of bounds control
  if (x < 0 || x >= n || y < 0 || y >= m)
  {
    return;
  }
  // Not filling a character
  if (table[x][y] != oldfill)
  {
    return;
  }
  // Filling with the new character.
  table[x][y] = newfill;

  floodfill(table, n, m, x-1, y, oldfill, newfill);
  floodfill(table, n, m, x+1, y, oldfill, newfill);
  floodfill(table, n, m, x, y-1, oldfill, newfill);
  floodfill(table, n, m, x, y+1, oldfill, newfill);
}