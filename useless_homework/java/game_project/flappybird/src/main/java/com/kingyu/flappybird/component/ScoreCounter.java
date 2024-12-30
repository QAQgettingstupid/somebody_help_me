package com.kingyu.flappybird.component;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.List;

import com.kingyu.flappybird.util.Constant;
import com.kingyu.flappybird.util.MusicUtil;

/**
 * 游戏计时器, 使用静态内部类实现了单例模式
 *
 * @author Kingyu
 *
 */
public class ScoreCounter {

	private static class ScoreCounterHolder {
		private static final ScoreCounter scoreCounter = new ScoreCounter();
	}

	public static ScoreCounter getInstance() {
		return ScoreCounterHolder.scoreCounter;
	}

	private long score = 0; // 分数
	private long bestScore; // 最高分数

	private ScoreCounter() {
		bestScore = -1;
		try {
			loadBestScore();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	// 装载最高纪录
	private void loadBestScore() throws Exception {
		File file = new File(Constant.SCORE_FILE_PATH);
		if (file.exists()) {
			DataInputStream dis = new DataInputStream(new FileInputStream(file));
			bestScore = dis.readLong();
			dis.close();
		}
	}

	public void saveScore() {
		bestScore = Math.max(bestScore, getCurrentScore());
		try {
			File file = new File(Constant.SCORE_FILE_PATH);
			DataOutputStream dos = new DataOutputStream(new FileOutputStream(file));
			dos.writeLong(bestScore);
			dos.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public void score(Bird bird) {
		if (!bird.isDead()) {
			MusicUtil.playScore();
			score += 1;
		}
	}

	public long getBestScore() {
		return bestScore;
	}

	public long getCurrentScore() {
		return score;
	}

	public void reset() {
		score = 0;
	}

	public void checkCoinCollision(Bird bird, Coin coin) {
		if (!bird.isDead() && !coin.isCollected() && coin.getBounds().intersects(bird.getBirdCollisionRect())) {
			coin.resetPosition(); // 重置金幣位置
			coin.setCollected(true); // 設置金幣為已收集
			score += 2; // 假設每個金幣加 2 分
			MusicUtil.playScore(); // 播放加分音效（如果需要）
		}
	}

	public void checkCoin_ArrowCollision(List<Arrows> arrows, Coin coin, Bird bird) {

		for (Arrows a : arrows) {
			if (!bird.isDead() && !coin.isCollected() && coin.getBounds().intersects(a.arrowRectangle())) {
				a.set_falling(true); //箭頭下落
				coin.resetPosition(); // 重置金幣位置
				coin.setCollected(true); // 設置金幣為已收集
				score += 2; // 假設每個金幣加 2 分
				MusicUtil.playScore(); // 播放加分音效（如果需要）
			}
		}
	}

}