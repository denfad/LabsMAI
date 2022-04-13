package ru.denfad;

import java.awt.*;
import java.awt.geom.Path2D;
import java.awt.image.BufferedImage;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Camera {
    double x;
    double y;
    double z;
    double h; //distance from coords
    double f; //distance of projection plane
    double xz = 0, yz = 0, xy = 0;
    List<Polygon> polygons;
    double[][] zBuffer;


    public Camera(double x, double y, double z, double h, double f, List<Polygon> polygons) {
        this.x = x;
        this.y = y;
        this.z = z;
        this.h = h;
        this.f = f;
        this.polygons = new ArrayList<>(polygons);

    }


    void changeAngle(double angleX, double angleY, double angleZ) {
        this.xz = angleX;
        this.yz = angleY;
        this.xy = angleZ;
    }

    Graphics2D draw(Graphics2D g2, int width, int height) {
        g2.setColor(Color.BLACK);
        g2.fillRect(0, 0, width, height);

        //вращение XZ
        double heading = xz;
        Matrix headingTransform = new Matrix(new double[]{
                Math.cos(heading), 0, Math.sin(heading),
                0, 1, 0,
                -Math.sin(heading), 0, Math.cos(heading)});
        //вращение YZ
        double pitch = yz; //берём угл из слайдера
        Matrix pitchTransform = new Matrix(new double[]{
                1, 0, 0,
                0, Math.cos(pitch), Math.sin(pitch),
                0, -Math.sin(pitch), Math.cos(pitch)});
        //итоговая матрица вращения
        Matrix transform = headingTransform.multiply(pitchTransform);
        //визуализация работы камеры
        g2.setColor(Color.RED);
        g2.drawOval(100, 50, 10, 10);
        g2.setColor(Color.WHITE);
        g2.drawLine((int) (100 - (h / 1000) * 100), 50, 100, 50);
        g2.setColor(Color.GREEN);
        g2.drawLine((int) (100 - (h / 1000) * 100 + (f / 1000) * 100), 5, (int) (100 - (h / 1000) * 100 + (f / 1000) * 100), 95);
        g2.setColor(Color.YELLOW);
        g2.drawLine((int) (100 - (h / 1000) * 100 + (f / 1000) * 100), 50, (int) (100 - (h / 1000) * 100), 50);

        BufferedImage img = new BufferedImage(width, height, BufferedImage.TYPE_INT_ARGB);
        zBuffer = new double[width][height];
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                zBuffer[i][j] = Double.POSITIVE_INFINITY;
            }
        }

        for (Polygon p : polygons) {
            drawPolygon(p, img, transform);
        }
        g2.drawImage(img, 0, 0, null);

        return g2;
    }


    Vertex perspective(Vertex v, Matrix transform) {
        Vertex trans = new Vertex(v.x, v.y, v.z);
        trans.x += x;
        trans.y += y;
        trans.z += z;
        trans = transform.transform(trans);
        trans.x = (trans.x * f) / (trans.z + h);
        trans.y = (trans.y * f) / (trans.z + h);
        return trans;
    }

    void drawLine(Vertex v1, Vertex v2, Color c, BufferedImage img, List<double[]> border) {
        int dx = (int) (v2.x - v1.x);
        int dy = (int) (v2.y - v1.y);
        if (Math.abs(dx) > Math.abs(dy)) {
            //для более горизонтальных прямых
            int x1 = (int) Math.floor(v1.x);
            int x2 = (int) Math.floor(v2.x);
            if (x1 > x2) {
                int a = x1;
                x1 = x2;
                x2 = a;
                Vertex b = v1;
                v1 = v2;
                v2 = b;

            }
            double d = (v2.y - v1.y) / (x2 - x1);
            double y = v1.y;
            double dz = (v2.z - v1.z) / (x2 - x1);
            double z = v1.z;
            int lastx = x1 + img.getWidth() / 2;
            for (int i = x1 + img.getWidth() / 2; i <= x2 + img.getWidth() / 2; i++) {
                int pixelY = (int) Math.floor(y + img.getHeight() / 2);
                if (i < img.getWidth() && i > 0 && pixelY < img.getHeight() && pixelY > 0) {
                    if (z < zBuffer[i][pixelY]) {
                        zBuffer[i][pixelY] = z;
                        img.setRGB(i, pixelY, c.getRGB());
                    }
                }
                if (lastx != i) {
                    border.add(new double[]{i - img.getWidth() / 2, y, z});
                    lastx = i;
                }


                y += d;
                z += dz;
            }
        } else {
            //для более вертикальных
            int y1 = (int) Math.floor(v1.y);
            int y2 = (int) Math.floor(v2.y);
            if (y1 > y2) {
                int a = y1;
                y1 = y2;
                y2 = a;
                Vertex b = v1;
                v1 = v2;
                v2 = b;

            }
            double d = (v2.x - v1.x) / (y2 - y1);
            double x = v1.x;
            double dz = (v2.z - v1.z) / (y2 - y1);
            double z = v1.z;
            int lastx = (int) Math.floor(x + img.getWidth() / 2);
            for (int i = y1 + img.getHeight() / 2; i <= y2 + img.getHeight() / 2; i++) {
                int pixelX = (int) Math.floor(x + img.getWidth() / 2);
                if (i < img.getHeight() && i > 0 && pixelX < img.getWidth() && pixelX > 0) {
                    if (z < zBuffer[pixelX][i]) {
                        zBuffer[pixelX][i] = z;
                        img.setRGB(pixelX, i, c.getRGB());
                    }
                }
                if (lastx != pixelX) {
                    lastx = pixelX;
                    border.add(new double[]{pixelX - img.getWidth() / 2, i - img.getHeight() / 2, z});
                }
                x += d;
                z += dz;
            }
        }
    }


    void drawPolygon(Polygon p, BufferedImage img, Matrix transform) {
        List<Vertex> vertexes = new ArrayList<>();
        for (Vertex v : p.vertexes) {
            Vertex v2 = perspective(v, transform);
            vertexes.add(v2);
        }
        Color c = p.color;
        //поиск угла наклона полигона
        //направляющие векторы
        if(vertexes.size() >=3) {
            Vertex p1 = new Vertex(vertexes.get(1).x - vertexes.get(0).x, vertexes.get(1).y - vertexes.get(0).y, vertexes.get(1).z - vertexes.get(0).z);
            Vertex p2 = new Vertex(vertexes.get(2).x - vertexes.get(0).x, vertexes.get(2).y - vertexes.get(0).y, vertexes.get(2).z - vertexes.get(0).z);
            //вектор нормали
            Vertex n = new Vertex(
                    p1.y * p2.z - p1.z * p2.y,
                    p1.x * p2.z - p1.z * p2.x,
                    p1.x * p2.y - p1.y * p2.x);
            //угол наклона к плоскости
            double length = Math.sqrt(n.x*n.x + n.y*n.y + n.z*n.z);
            float cosAngle =(float) (Math.abs(n.z) / length);
            c = getShadeColor(p.color, cosAngle);
        }



        Vertex start = vertexes.get(0);
        Vertex last = start;
        List<double[]> border = new ArrayList<>(); //border buffer;
        for (Vertex v : vertexes) {
            drawLine(last, v, c, img, border);
            last = v;
        }
        drawLine(last, start, c, img, border);
        border.sort(new Comparator<double[]>() {
            @Override
            public int compare(double[] o1, double[] o2) {
                if (o1[0] > o2[0]) return 1;
                else if (o1[0] < o2[0]) return -1;
                else if (o1[0] == o2[0]) {
                    if (o1[1] > o2[1]) return 1;
                    else if (o1[1] < o2[1]) return -1;
                }
                return 0;
            }
        });
        for (int i = 0; i < border.size() - 1; i += 2) {
            Vertex v1 = new Vertex(border.get(i)[0], border.get(i)[1], border.get(i)[2]);
            Vertex v2 = new Vertex(border.get(i + 1)[0], border.get(i + 1)[1], border.get(i + 1)[2]);
            drawLine(v1, v2, c, img, new ArrayList<>());
        }
    }

    Color getShadeColor(Color c, float cosAngle) {
        float[] hsb = new float[3];
        hsb = Color.RGBtoHSB(c.getRed(), c.getGreen(), c.getBlue(), hsb);
        hsb[2] = 0.3f + 0.7f * cosAngle;
        return Color.getHSBColor(hsb[0], hsb[1], hsb[2]);
    }
}
