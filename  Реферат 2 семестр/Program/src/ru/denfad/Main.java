package ru.denfad;

import javax.swing.*;
import java.awt.*;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import java.util.ArrayList;
import java.util.List;

public class Main {

    //ui элементы
    //окно программы
    static JFrame frame;
    //материнский контейнер
    static Container pane;
    //слайдер угла XZ вращения (вращение по горизонтали)
    static JSlider headingSlider;
    //слайдер угла YZ вращения (вращение по вертикали)
    static JSlider pitchSlider;
    //панель отрисовки объекта
    static JPanel renderPanel;

    static Camera camera;

    static CameraFrame cFrame;

    static List<Polygon> polygons = new ArrayList<>();
    static List<Polygon> tetraider = new ArrayList<>();

    static double heading = 0;
    static double pitch = 0;

    static double delta = 400;

    static {
        //несколько полигонов

        polygons.add(new Polygon(new Vertex[]{new Vertex(100, 100, 100),
                new Vertex(100, -100, 100),
                new Vertex(-100, -100, 100),
                new Vertex(-100, 100, 100)},
                Color.WHITE));
        polygons.add(new Polygon(new Vertex[]{new Vertex(100, 100, -100),
                new Vertex(100, -100, -100),
                new Vertex(-100, -100, -100),
                new Vertex(-100, 100, -100)},
                Color.YELLOW));
        polygons.add(new Polygon(new Vertex[]{new Vertex(-100, 100, -100),
                new Vertex(-100, -100, -100),
                new Vertex(-100, -100, 100),
                new Vertex(-100, 100, 100)},
                Color.PINK));
        polygons.add(new Polygon(new Vertex[]{new Vertex(100, 100, -100),
                new Vertex(100, -100, -100),
                new Vertex(100, -100, 100),
                new Vertex(100, 100, 100)},
                Color.LIGHT_GRAY));
        polygons.add(new Polygon(new Vertex[]{new Vertex(100, 100, -100),
                new Vertex(-100, 100, -100),
                new Vertex(-100, 100, 100),
                new Vertex(100, 100, 100)},
                Color.RED));
        polygons.add(new Polygon(new Vertex[]{new Vertex(100, -100, -100),
                new Vertex(-100, -100, -100),
                new Vertex(-100, -100, 100),
                new Vertex(100, -100, 100)},
                Color.GREEN));
        tetraider.add(new Polygon(new Vertex[]{
                new Vertex(100, 100, 100),
                new Vertex(-100, -100, 100),
                new Vertex(-100, 100, -100)},
                Color.GREEN));
        tetraider.add(new Polygon(new Vertex[]{
                new Vertex(100, 100, 100),
                new Vertex(-100, -100, 100),
                new Vertex(100, -100, -100)},
                Color.RED));
        tetraider.add(new Polygon(new Vertex[]{
                new Vertex(-100, 100, -100),
                new Vertex(100, -100, -100),
                new Vertex(100, 100, 100)},
                Color.BLUE));
        tetraider.add(new Polygon(new Vertex[]{
                new Vertex(-100, 100, -100),
                new Vertex(100, -100, -100),
                new Vertex(-100, -100, 100)},
                Color.YELLOW));



    }

    public static void main(String[] args) {
        frame = new JFrame();

        pane = frame.getContentPane();
        pane.setLayout(new BorderLayout());


        tetraider = inflate(inflate(inflate(tetraider)));
       //for(Polygon p: tetraider) p.translate(-delta, 0, 0);
       for(Polygon p: polygons) p.translate(delta, 0, 0);
         polygons.addAll(tetraider);


        //координатные оси
        polygons.add(new Polygon(new Vertex[]{new Vertex(200, 0, 0), new Vertex(0, 0, 0)}, Color.BLUE));
        polygons.add(new Polygon(new Vertex[]{new Vertex(0, 200, 0), new Vertex(0, 0, 0)}, Color.RED));
        polygons.add(new Polygon(new Vertex[]{new Vertex(0, 0, 200), new Vertex(0, 0, 0)}, Color.GREEN));



        cFrame = new CameraFrame();
        camera = new Camera(0, 0, 0, 250, 250, polygons);


        renderPanel = new JPanel() {
            public void paintComponent(Graphics g) {
                super.paintComponent(g);
                Graphics2D g2 = (Graphics2D) g;
                camera.h = cFrame.distSlider.getValue();
                camera.f = cFrame.fSlider.getValue();


                camera.changeAngle(heading, pitch, 0);
                camera.draw(g2, getWidth(), getHeight());
            }
        };

        pane.add(renderPanel, BorderLayout.CENTER);
        frame.setSize(400, 400);
        frame.addKeyListener(new KeyListener() {
            @Override
            public void keyTyped(KeyEvent e) {

            }

            @Override
            public void keyPressed(KeyEvent e) {
                switch (e.getKeyCode()) {
                    case KeyEvent.VK_DOWN:
                        pitch -= Math.toRadians(3);
                        break;
                    case KeyEvent.VK_UP:
                        pitch += Math.toRadians(3);
                        break;
                    case KeyEvent.VK_LEFT:
                        heading += Math.toRadians(3);
                        break;
                    case KeyEvent.VK_RIGHT:
                        heading -= Math.toRadians(3);
                        break;

                }
                renderPanel.repaint();

            }

            @Override
            public void keyReleased(KeyEvent e) {

            }
        });
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);


        cFrame.fSlider.addChangeListener(e -> renderPanel.repaint());
        cFrame.distSlider.addChangeListener(e -> renderPanel.repaint());


    }

    //шар
    public static List<Polygon> inflate(List<Polygon> tris) {
        List<Polygon> result = new ArrayList<>();
        for (Polygon t : tris) {
            Vertex m1 = new Vertex((t.vertexes[0].x + t.vertexes[1].x) / 2, (t.vertexes[0].y + t.vertexes[1].y) / 2, (t.vertexes[0].z + t.vertexes[1].z) / 2);
            Vertex m2 = new Vertex((t.vertexes[1].x + t.vertexes[2].x) / 2, (t.vertexes[1].y + t.vertexes[2].y) / 2, (t.vertexes[1].z + t.vertexes[2].z) / 2);
            Vertex m3 = new Vertex((t.vertexes[0].x + t.vertexes[2].x) / 2, (t.vertexes[0].y + t.vertexes[2].y) / 2, (t.vertexes[0].z + t.vertexes[2].z) / 2);
            result.add(new Polygon(new Vertex[]{t.vertexes[0], m1, m3}, t.color));
            result.add(new Polygon(new Vertex[]{t.vertexes[1], m1, m2}, t.color));
            result.add(new Polygon(new Vertex[]{t.vertexes[2], m2, m3}, t.color));
            result.add(new Polygon(new Vertex[]{m1, m2, m3}, t.color));
        }
        for (Polygon t : result) {
            for (Vertex v : new Vertex[]{t.vertexes[0], t.vertexes[1], t.vertexes[2]}) {
                double l = Math.sqrt(v.x * v.x + v.y * v.y + v.z * v.z) / Math.sqrt(30000);
                v.x /= l;
                v.y /= l;
                v.z /= l;
            }
        }
        return result;
    }


}
