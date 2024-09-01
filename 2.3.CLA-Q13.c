#include <stdio.h>

struct Square {
    float area;
};

struct Rectangle {
    float length;
    float breadth;
};

struct Shape {
    struct Square square;
    struct Rectangle rectangle;
};

int main() {
    struct Shape shape;

    printf("Enter the area of the square: ");
    scanf("%f", &shape.square.area);

    printf("Enter the length of the rectangle: ");
    scanf("%f", &shape.rectangle.length);
    printf("Enter the breadth of the rectangle: ");
    scanf("%f", &shape.rectangle.breadth);

    printf("\nSquare Area: %.2f\n", shape.square.area);
    printf("Rectangle Length: %.2f\n", shape.rectangle.length);
    printf("Rectangle Breadth: %.2f\n", shape.rectangle.breadth);

    float rectangle_area = shape.rectangle.length * shape.rectangle.breadth;
    printf("Rectangle Area: %.2f\n", rectangle_area);

    return 0;
}
