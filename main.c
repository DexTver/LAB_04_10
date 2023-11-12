#include <stdio.h>

void pprint(int n, int m, int a[n][m]) {
    for (int i = 0; i < n; ++i) {
        printf("\n");
        for (int j = 0; j < m; ++j) {
            printf("%i ", a[i][j]);
        }
    }
}

int counts(int m, const int a[m]) {
    int b[m], ans = 0;
    for (int i = 0; i < m; ++i) {
        b[i] = 0;
        for (int j = 0; j < m; ++j) {
            if (a[i] == a[j]) {
                ++b[i];
            }
        }
        if (b[i] > ans) {
            ans = b[i];
        }
    }
    return ans;
}

int main() {
    printf("Enter size of matrix (n m):\n");
    int n, m, k, cnt, ind;
    scanf("%i %i", &n, &m);
    int a[n][m];
    for (int i = 0; i < n; ++i) {
        printf("Enter line %i:", i + 1);
        for (int j = 0; j < m; ++j) {
            scanf("%i", &a[i][j]);
        }
    }

    printf("Enter the number of equal items:");
    scanf("%i", &k);
    pprint(n, m, a);

    cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (counts(m, a[i]) >= k) {
            ++cnt;
        }
    }
    if (cnt == 0) {
        printf("\nThe matrix is empty!");
    } else {
        ind = 0;
        int res[m][cnt];
        for (int i = 0; i < n; ++i) {
            if (counts(m, a[i]) >= k) {
                for (int j = 0; j < m; ++j) {
                    res[j][ind] = a[i][j];
                }
                ++ind;
            }
        }
        printf("\nRequired matrix:");
        pprint(m, cnt, res);
    }
    return 0;
}
