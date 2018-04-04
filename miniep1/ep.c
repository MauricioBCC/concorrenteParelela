/* Mauricio Luiz Abreu Cardoso NUSP: 6796479 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void atualizaMatrizLinha(int** v, int totalVetores, int intPorVetor) {
	clock_t start_t, end_t;
	int i, j;
	double total_t;

	start_t = clock();
	for (i = 0; i < totalVetores; i++) {		
		for (j = 0; j < intPorVetor; j++) {
			v[i][j] = i;

		}	
		
	}
	end_t = clock();	
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("Tempo para atualizar a matriz %dx%d  varrendo por linha :   %.2f micro segundos\n", totalVetores, intPorVetor, total_t * 1000);
}

void atualizaMatrizColuna(int** v, int totalVetores, int intPorVetor) {
	clock_t start_t, end_t;
	int i, j;
	double total_t;

	start_t = clock();
	for (j = 0; j < intPorVetor; j++) {
		for (i = 0; i < totalVetores; i++) {
			v[i][j] = i;

		}
	}
	end_t = clock();	
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("Tempo para atualizar a matriz %dx%d varrendo por coluna  :   %.2f micro segundos\n", totalVetores, intPorVetor, total_t * 1000);
}

int main () {
	int **v;
	int totalVetores = 100;
	int intPorVetor = 1000000;
	int i;

	v = malloc (totalVetores * sizeof (int*));



	for (i = 0; i < totalVetores; i++) {
		v[i] = malloc(intPorVetor * sizeof (int));
	}

	atualizaMatrizLinha(v, totalVetores, intPorVetor);
	atualizaMatrizColuna(v, totalVetores, intPorVetor);


	for (i = 0; i < totalVetores; i++) {
		free(v[i]);
	}
	free(v);
	return EXIT_SUCCESS;

}
