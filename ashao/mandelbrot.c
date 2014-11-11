#include <stdlib.h>
#include <complex.h>
#include <stdio.h>
int mandel(double x, double y, int max_iter) {
	int i;

	double complex c = x + y * I;
	double complex z = 0;

	for(i=0;i<max_iter;i++) {
		z = z*z + c;
		if( cabs(z)>=2 ) return i;
	}
	return max_iter;

}

void create_fractal(int Nx, int Ny, double xmin, double xmax, double ymin, double ymax, int max_iter, int *image) {
	
	int i,j;

	double dx, dy;
	double realpart, imagpart;

	dx = (xmax-xmin)/Nx;
	dy = (ymax-ymin)/Ny;
	for(j=0;j<Nx;j++) {
		realpart = xmin + j*dx;
		for (i=0;i<Ny;i++) {
			
			imagpart = ymin + i*dy;
			image[i*Nx + j] = mandel(realpart,imagpart,max_iter);
		}

	}
}
