package com.kingyu.flappybird.component;

public class Arrows {
    private int arrowx;
    private int arrowy;
    private boolean live;

    Arrows(int x, int y) {
        arrowx = x;
        arrowy = y;
        live = true;
    }

    public void move_x(int add) {
        arrowx += add;
    }

    public int get_x() {
        return arrowx;
    }

    public int get_y() {
        return arrowy;
    }

    public boolean get_status() {
        return live;
    }
}
