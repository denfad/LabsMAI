package ru.denfad;

import java.awt.*;

public class Polygon {
    Vertex[] vertexes;
    Color color;
    public Polygon(Vertex[] vertexes, Color color) {
        this.vertexes = vertexes;
        this.color = color;
    }

    public void translate(double dx, double dy, double dz) {
        for(Vertex v: vertexes) {
            v.x += dx;
            v.y += dy;
            v.z += dz;
        }
    }
}
