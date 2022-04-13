package ru.denfad;

import javax.swing.*;
import java.awt.*;

public class CameraFrame {
    //слайдер расстояния до объекта
    static JSlider distSlider;
    //слайдер растояния от точки фокуса до плоскости проекции
    static JSlider fSlider;
    CameraFrame() {

        JFrame frame = new JFrame();

        Container pane = frame.getContentPane();
        pane.setLayout(new BorderLayout());
        distSlider = new JSlider(50, 1000, 250);
        pane.add(distSlider, BorderLayout.NORTH);

        fSlider = new JSlider(SwingConstants.VERTICAL,50, 1000, 100);
        pane.add(fSlider, BorderLayout.WEST);
        frame.setSize(100, 200);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
