#include <stdio.h>
#include <stdlib.h>
#define M 100
int main(void){

    int n;
    int m;
    int p;

    int i, j;
    printf("vertices: ");
    scanf("%d", &m);
    printf("edges: ");
    scanf("%d", &n);
    p = 0.5 * (m - 1) * (m - 2);
    if (n > p) {
        printf("Graph is connected\n");
    }
    if (n <= p) {
        printf("Graph is not connected\n");
    }

    int *arr = (int *)malloc(n * m * sizeof(int));

    FILE *s;
    s = fopen("platon.dot", "w");
    fprintf(s, "digraph G {\n");
    for (i = 0; i < m; i++){
        for (j = 0; j < m; j++){
            scanf("%d", &arr[i*m + j]);
		}
	}
	
	int *pow = (int *)calloc(m + 1, sizeof(int));
	    
    for (i = 0; i < m; i++){
        for (j = 0; j < m; j++) {
            if (arr[i*m + j] != 0){
                while(arr[i*m + j] >= 1){
                    fprintf(s, "%d -> %d; \n", i + 1, j + 1);
                    --arr[i*m + j];
                    ++pow[i + 1];
                }
            }
        }
    }
    fprintf(s, "}");
	
    fclose(s);
    
	p = 0;
	for(i = 1; i <= m; i++){
		if(pow[i] % 2 == 1){
			++p;
		}
	}
	pow[0] = 1000;
	while(p != 0){
		for(i = 1; i <= m; i++){
			if((pow[0] > pow[i]) && (pow[i] % 2 == 1)){
				pow[0] = pow[i];
				j = i;
			}
		}
		printf("%d -- %d\n", j, pow[0]);
		--p;
		pow[0] = 1000;
		pow[j] = 1000;
	}
    
    system("dot -Tpng -O platon.dot");                                                                                       
	system("xdg-open platon.dot.png");
    free(arr);

    return 0;
}
