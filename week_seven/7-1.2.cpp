    #include <iostream>
    #include <cstring>
    using namespace std;
    void getpre(int *post, int *in, int n) {
        if(n <= 0) return;
        int root = post[n - 1];
        int i;
        for(i = 0; i < n; i++) {
            if(in[i] == root) {
                break;
            }
        }
        cout << ' ' << root;
        getpre(post, in, i);
        getpre(post + i, in + i + 1, n - i - 1);
    }
    int main() {
        int post[40], in[40];
        int n;
        cin >> n;
        int i, j;
        for(i = 0; i < n; i++) {
            scanf("%d", &post[i]);
        }
        for(i = 0; i < n; i++) {
            scanf("%d", &in[i]);
        }
        printf("Preorder:");
        getpre(post, in, n);
        printf("\n");
        return 0;
    }
