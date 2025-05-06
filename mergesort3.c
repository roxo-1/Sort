#include <stdio.h>

#define maxN 100 // Defina o valor máximo para maxN

int aux[maxN];

int less(int a, int b) {
    return a < b;
}

void merge(int a[], int l, int m1, int m2, int r) {
    int i = l, j = m1 + 1, k = m2 + 1, idx = l;
    
    for (int x = l; x <= r; x++) aux[x] = a[x];
    
    while (i <= m1 && j <= m2 && k <= r) {
        if (less(aux[i], aux[j]) && less(aux[i], aux[k])) a[idx++] = aux[i++];
        else if (less(aux[j], aux[k])) a[idx++] = aux[j++];
        else a[idx++] = aux[k++];
    }
    
    while (i <= m1 && j <= m2) a[idx++] = less(aux[i], aux[j]) ? aux[i++] : aux[j++];
    while (j <= m2 && k <= r) a[idx++] = less(aux[j], aux[k]) ? aux[j++] : aux[k++];
    while (i <= m1 && k <= r) a[idx++] = less(aux[i], aux[k]) ? aux[i++] : aux[k++];
    while (i <= m1) a[idx++] = aux[i++];
    while (j <= m2) a[idx++] = aux[j++];
    while (k <= r) a[idx++] = aux[k++];
}

void mergesort(int a[], int l, int r){
    if (r <= l) return;
    
    int m1 = l + (r - l) / 3;
    int m2 = l + 2 * (r - l) / 3;
    
    mergesort(a, l, m1);
    mergesort(a, m1 + 1, m2);
    mergesort(a, m2 + 1, r);
    
    merge(a, l, m1, m2, r);
}

int main() {
    int n;
    printf("Digite o número de elementos: ");
    scanf("%d", &n);
    
    if (n > maxN) {
        printf("Número máximo de elementos excedido!\n");
        return 1;
    }
    
    int arr[maxN];
    printf("Digite os elementos:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    mergesort(arr, 0, n - 1);
    
    printf("Elementos ordenados:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}
