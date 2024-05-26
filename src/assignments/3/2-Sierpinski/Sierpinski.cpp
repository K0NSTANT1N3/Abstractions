/*
 * File: Sierpinski.cpp
 * --------------------------
 * Name: Konstantine Endeladze
 * This file is the starter project for the Sierpinski problem
 * on Assignment #3.
 */

#include <iostream>
#include "gwindow.h"
#include "math.h"
#include "console.h"

using namespace std;

/* Function: drawSierpinskiTriangle
 * Usage: drawSierpinskiTriangle(window, x, y, size, order);
 * ----------------------------------------------------------
 * This function draws a Sierpinski triangle of the specified order
 * inside the bounds given by the point (x, y) and the specified size.
 * The order of the triangle determines the number of levels of recursion
 * used to draw the triangle.
 */
void drawSierpinskiTriangle(GWindow &window, double x, double y, double height, int order);

int main() {
    // test drawSierpinskiTriangle
    GWindow window(900, 900);
    drawSierpinskiTriangle(window, 30, 30, 200, 1);

    return 0;
}

void drawSierpinskiTriangle(GWindow &window, double x, double y, double side, int order) {
    window.drawPolarLine(x, y, side, 0);
    window.drawPolarLine(x, y, side, 60);
    window.drawPolarLine(x + side, y, side, 120);
    if (order != 0) {
        drawSierpinskiTriangle(window, x, y, side / 2, order - 1);
        drawSierpinskiTriangle(window, x + side / 2, y, side / 2, order - 1);
        drawSierpinskiTriangle(window, x + side / 4, y - side * sqrt(3) / 4, side / 2, order - 1);
    }
}