
package com.kingyu.flappybird.component;

import java.awt.Graphics;
import java.awt.List;
import java.awt.Rectangle;
import java.awt.image.BufferedImage;

import javax.imageio.ImageIO;

import com.kingyu.flappybird.util.Constant;

public class Coin {
    public int x, y, width, height;
    public boolean collected;
    public BufferedImage coinImage;
    int speed;
    public PipePool pipepool;
    

    public Coin(int x, int y) {
        this.x = x;
        this.y = y;
        this.width = 50;
        this.height = 50;

        this.collected = false; // 是否被吃到
        try {
            coinImage = ImageIO.read(Bird.class.getResourceAsStream("/img/coin2.png")); // 圖片路徑
        } catch (Exception e) {
            System.out.println("Error loading coin image: " + e.getMessage());
        }
    }

    public void movement() {
        x -= Constant.GAME_SPEED; // 金幣向左移動
        if (x + width < 0) { // 如果金幣完全移出螢幕
            resetPosition(); // 重置金幣位置
        }
    }

    public void resetPosition() {
        x = Constant.FRAME_WIDTH + (int) (Math.random() * 200);  // 隨機生成 x 位置（螢幕右側外）
        y = (int) (Math.random() * (Constant.FRAME_HEIGHT / 2)) + Constant.FRAME_HEIGHT / 4; // 隨機生成 y 位置
        System.out.println("y= " + y);
        collected = false; // 確保金幣可再次被收集
    }

    public void move(int speed) {
        x -= speed; // 金幣往左移動，類似障礙物
    }

    /*
     * public boolean isOffScreen() {
     * return x + width < 0; // 判斷金幣是否移出螢幕
     * }
     * 
     * public void checkCollision(Bird bird) {
     * if (getBounds().intersects(bird.getBounds()) && !collected) {
     * collected = true;
     * bird.incrementScore(); // 加分數
     * }
     * }
     */
    public void draw(Graphics g, Bird bird) {
        if (!collected) {
            if (coinImage != null) {
                g.drawImage(coinImage, x, y, width, height, null); // 繪製金幣圖片
            } else {
                g.setColor(java.awt.Color.YELLOW); // 如果圖片載入失敗，畫一個圓形代替
                g.fillOval(x,   y, width, height);
            }
        }
        if (bird.isDead()) {
            return;
        }
        movement();
        for (Pipe pipe : pipepool.pool) {
            checkPipeCollision(pipe); // 檢測金幣與水管的碰撞
        }
    
    }

    public Rectangle getBounds() {
        return new Rectangle(x, y, width, height); // 金幣的邊界，用於碰撞判定
    }

    public boolean isCollected() {
        return collected;
    }

    public void setCollected(boolean collected) {
        this.collected = collected;
    }
    // 檢測金幣是否與水管碰撞
    public void checkPipeCollision(Pipe pipe) {
    if (pipe.isVisible() && getBounds().intersects(pipe.getPipeRect())) {
        collected = true; // 金幣標記為已收集
    }
}


}
