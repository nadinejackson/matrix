#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  clear_screen(s);
  struct matrix *m1;
  struct matrix *m2;
  struct matrix *edges;

  m2 = new_matrix(4, 2);
  
  
  add_point(m2, 1.0, 2.0, 3.0);
  add_point(m2, 4.0, 5.0, 6.0);
  
  printf("Populated a 2x4 matrix with values 1-6 (bottom row is 1's)\n");

  print_matrix(m2);

  m1 = new_matrix(4,4);
  m1->lastcol = 4;
  ident(m1);
  printf("\nTesting ident. m1=\n");
  print_matrix(m1);

  matrix_mult(m1, m2);
  printf("\nTesting matrix mult. m1 * m2=\n");
  print_matrix(m2);
  
  m1->lastcol = 0;
  add_point(m1, 1.0, 2.0, 3.0);
  add_point(m1, 4.0, 5.0, 6.0);
  add_point(m1, 7.0, 8.0, 9.0);
  add_point(m1, 10.0, 11.0, 12.0);

  printf("\ntesting matrix mult. m1=\n");
  print_matrix(m1);

  printf("\ntesting matrix mult. m1 * m2 =\n");
  matrix_mult(m1,m2);
  print_matrix(m2);

  edges = new_matrix(4, 144);
  int i;
  
  for (i = 0 ; i < 72; i++)
    {
      add_edge(edges,
	       250 + 200 * cos(M_PI * i/ 36), 250 + 200 * sin(M_PI * i/ 36), 0,
	       250 + 200 * cos(2 * i * M_PI/ 36), 250 + 200 * sin(2 * i * M_PI/ 36), 0);
    }
  
  color c;
  c.red = 255;
  c.blue = 100;
  c.green = 75;
  draw_lines(edges, s, c);
  save_ppm(s, "matrix.ppm");
  save_extension(s, "matrix.png");
  display(s);
  free_matrix( m1 );
  free_matrix( m2 );
  free_matrix( edges );
}  
