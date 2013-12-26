/* Kruskal Program to Find Minimum Spanning Tree */

#include <iostream>
#include <cstdlib>
#include <ctime>
#define max 20

using namespace std;

int main(int argc, char** argv) {
	srand(time(NULL));
	int node;
	int edge[max][max];
	char s[max][max], d[max][max];	
	
	printf("Jumlah Node : "); scanf("%i",&node);
	printf("\n   ");
	
	for(int i=0; i<node; i++) printf(" %2c ",(i%26)+'a');
	printf("\n\n");	
	
	for(int i=0; i<node; i++){
		printf(" %c ",(i%26)+'a');
		for(int j=0; j<node; j++){
			if(i != j){
				edge[i][j] = rand()%2;
				s[i][j] = (i%26)+'a';
				d[i][j] = (j%26)+'a';				
			}else{
				edge[i][j] = 0;
			}
			printf(" %2i ",edge[i][j]);
		}
		putchar('\n');
	}		
	
	printf("\n\n   ");
	
	for(int i=0; i<node; i++) printf(" %3c ",(i%26)+'a');
	printf("\n\n");		
	
	for(int i=0; i<node; i++){
		printf(" %c ",(i%26)+'a');
		for(int j=0; j<node; j++){
			if(edge[i][j] == 1){
				edge[i][j] = rand()%99+1;
			}
			printf("  %2i ",edge[i][j]);
		}	
		putchar('\n');	
	}	
	
	printf("\n\n   Minimum Sort \n ---------------- \n   Edge   Value \n\n");
		
	for(int i=0; i<node; i++){	 
		for(int j=0; j<node; j++){
			if(edge[i][j] != 0){
				for(int k=node-1; k>=i; k--){
					for(int l=node-1; l>=0; l--){
						if(edge[k][l] != 0){						
							if(edge[k][l] < edge[i][j]){
								int z = edge[i][j];
								char y = s[i][j];
								char x = d[i][j];
								edge[i][j] = edge[k][l];
								s[i][j] = s[k][l];
								d[i][j] = d[k][l];
								edge[k][l] = z;
								s[k][l] = y;
								d[k][l] = x;
							}
							if(k == i && l == j) break;						
						}
					}
				}
				printf(" %2c -- %-2c %4i\n",s[i][j],d[i][j],edge[i][j]);
			}
		}
	}	
			
	printf("\n\n Min Spanning Tree \n ----------------- \n   Edge   Value \n\n");
	
	int root[max];
	int r = 0;
	int mst[max][max];
	char src[max][max], dst[max][max];
	
	for(int i=0; i<node; i++){
		for(int j=0; j<node; j++){
			if(edge[i][j] != 0){
				root[s[i][j]] = 0;
				root[d[i][j]] = 0;
			}
			mst[i][j] = 0;
		}
	}
	
	for(int i=0; i<node; i++){
		for(int j=0; j<node; j++){
			if(edge[i][j] != 0){
				if(root[s[i][j]] == 0 && root[d[i][j]] == 0){
					r++;
					root[s[i][j]] = r;
					root[d[i][j]] = r;
				}else if(root[s[i][j]] == 0 && root[d[i][j] != 0]){
					root[s[i][j]] = root[d[i][j]];
				}else if(root[s[i][j]] != 0 && root[d[i][j]] == 0){
					root[d[i][j]] = root[s[i][j]];
				}else if(root[s[i][j]] != root[d[i][j]]){					
					if(root[s[i][j]] < root[d[i][j]]){
						for(int k=0; k<=i; k++){
							for(int l=0; l<node; l++){
								if(mst[k][l] != 0){
									if(root[s[k][l]] == root[d[i][j]] || root[d[k][l]] == root[d[i][j]]){
										root[s[k][l]] = root[s[i][j]];
										root[d[k][l]] = root[s[i][j]];
									}
								}
							}
						}												
					}else{
						for(int k=0; k<=i; k++){
							for(int l=0; l<node; l++){
								if(mst[k][l] != 0){
									if(root[s[k][l]] == root[s[i][j]] || root[d[k][l]] == root[s[i][j]]){
										root[s[k][l]] = root[d[i][j]];
										root[d[k][l]] = root[d[i][j]];
									}
								}
							}
						}												
					}
				}else if(root[s[i][j]] == root[d[i][j]]){
					edge[i][j] = 0;
					continue;
				}
				mst[i][j] = edge[i][j];
				src[i][j] = s[i][j];
				dst[i][j] = d[i][j];				
				printf(" %2c -- %-2c %4i\n",src[i][j],dst[i][j],mst[i][j]);
			}
		}
	}	
	return 0;
}
