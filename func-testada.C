#include <stdio.h>
#include <math.h>

// Função para calcular os valores da função quadrática f(x) = ax² + bx + c
double quadratic(double a, double b, double c, double x) {
    return a * x * x + b * x + c;
}

// Função para calcular o vértice da parábola
void find_vertex(double a, double b, double c, double *vertex_x, double *vertex_y) {
    *vertex_x = -b / (2 * a);
    *vertex_y = quadratic(a, b, c, *vertex_x);
}

// Função para calcular as raízes da equação quadrática
int find_roots(double a, double b, double c, double *root1, double *root2) {
    double delta = b * b - 4 * a * c;
    if (delta >= 0) {
        *root1 = (-b + sqrt(delta)) / (2 * a);
        *root2 = (-b - sqrt(delta)) / (2 * a);
        return 1;
    } else {
        return 0;
    }
}

// Função principal
int main() {
    double a, b, c;
    printf("Insira os coeficientes da função quadrática (a, b, c):\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    // Plotagem simples dos valores da função
    printf("\nValores da função quadrática:\n");
    for (int x = -10; x <= 10; x++) {
        double y = quadratic(a, b, c, x);
        printf("f(%d) = %.2lf\n", x, y);
    }

    // Calcular vértice
    double vertex_x, vertex_y;
    find_vertex(a, b, c, &vertex_x, &vertex_y);
    printf("\nVértice: (%.2lf, %.2lf)\n", vertex_x, vertex_y);

    // Calcular raízes
    double root1, root2;
    if (find_roots(a, b, c, &root1, &root2)) {
        printf("Raízes: %.2lf e %.2lf\n", root1, root2);
    } else {
        printf("A função não possui raízes reais.\n");
    }

    return 0;
}
