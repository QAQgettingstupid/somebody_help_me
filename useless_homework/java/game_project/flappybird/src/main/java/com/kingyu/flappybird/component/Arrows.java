package com.kingyu.flappybird.component;

import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;
import java.io.IOException;
import java.awt.Rectangle;

public class Arrows {
    private int arrowx;
    private int arrowy;
    private static int speed = 10;
    private static int falling_speed = 10;
    private static int arrow_WIDTH;
    private static int arrow_HEIGHT;
    private static BufferedImage attackimage;
    private boolean live;
    private boolean falling;

    Arrows(int x, int y) {
        arrowx = x;
        arrowy = y;
        live = true;
        falling = false;
        try {
            attackimage = ImageIO.read(Bird.class.getResourceAsStream("/img/attack.png"));
            arrow_WIDTH = attackimage.getWidth();
            arrow_HEIGHT = attackimage.getHeight();
        } catch (IOException e) {

        }
    }

    public void move_x(int add) {
        arrowx += add;
    }

    public void move_y(int add) {
        arrowy += add;
    }

    public int get_x() {
        return arrowx;
    }

    public int get_y() {
        return arrowy;
    }

    public int get_speed() {
        return speed;
    }

    public int get_falling_speed() {
        return falling_speed;
    }

    public boolean get_status() {
        return live;
    }

    public boolean get_falling() {
        return falling;
    }

    public BufferedImage get_Image() {
        return attackimage;
    }

    public void set_falling(boolean a) {
        falling = a;
        System.out.println("NOOOOOO~");
    }

    public Rectangle arrowRectangle() {
        return new Rectangle(arrowx, arrowy, arrow_WIDTH, arrow_HEIGHT);
    }

    /*
     * 圖片貼上大法
     * 
     * 
     * // 讀入attackimage(箭頭)
     * 
     * private BufferedImage attackimage;
     * 
     * try {
     * attackimage =
     * ImageIO.read(Bird.class.getResourceAsStream("/img/attack.png"));
     * } catch (IOException e) {
     * 
     * }
     * 
     */
}
