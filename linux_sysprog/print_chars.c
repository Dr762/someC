//
// Created by abondar on 2/16/17.
//

int main(void) {
    int i;
    int n = 10;
    char c = "dfdsfsfc";

    for (i = 0; i < n; i++) {
        char *s;
        int j;


        s = calloc(i + 2, 1);
        if (!s) {
            perror("calloc");
            break;
        }

        for (j = 0; j < i + 1; j++) {
            s[j] = c;
        }

        printf("%s\n", s);

        free(s);

    }

    return 0;
}