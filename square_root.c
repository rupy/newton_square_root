#include <stdio.h>
#include <gmp.h>

#define PROC 1000000
#define ROOT_A 2

int newton1(){

	double x = 3.0;
	int i;
	for (i = 0; i < 100; ++i){
		x = 1.0 / 2.0 * ( x + 2.0 / x );
		printf("%20.50lf\n", x);
	}

}

int gmp_newton1(){

	mpf_t x,y,z;
	mpf_set_default_prec(PROC);
	mpf_init_set_d(x,2.0);
	mpf_sqrt(x,x);
	gmp_printf ("%.*Ff\n", 1000, x);
	mpf_clear(x);
}

int gmp_newton2(){

	mpf_t con1_5,con2,x,y,z;
	int i;
	mpf_set_default_prec(PROC);
	mpf_init_set_d(con1_5,1.5);
	mpf_init_set_d(con2,2.0);
	mpf_init_set_d(x,0.5);
	mpf_init(z);

	//gmp_printf ("%.*Ff\n", 100, x);
	for (i = 0; i < 20; ++i)
	{
		printf("%d\n", i);
		mpf_mul(z, x, x);// x * x
		mpf_sub(z, con1_5, z);// 1.5 - z
		mpf_mul(x, x, z);// x * z
		//gmp_printf ("%.*Ff\n", 1000, z);
	}
	mpf_mul(z, x, con2);// x * z
	gmp_printf ("%.*Ff\n", 10000, z);

}

int main(){

	newton1();
	return 0;
}