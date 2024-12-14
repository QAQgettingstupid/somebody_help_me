package com.kingyu.flappybird.util;

import javax.sound.sampled.*;
import java.io.File;
import java.io.IOException;

/**
 * 音樂工具類
 *
 * @author Kingyu
 * 支援播放 WAV 音頻，使用 javax.sound.sampled
 */
public class MusicUtil {

    private static void playSound(String filePath) {
        try {
            // 加載音頻文件
            File audioFile = new File(filePath);
            AudioInputStream audioStream = AudioSystem.getAudioInputStream(audioFile);

            // 獲取音頻格式並檢查是否支持
            AudioFormat format = audioStream.getFormat();
            DataLine.Info info = new DataLine.Info(Clip.class, format);

            // 創建 Clip 並打開音頻流
            Clip audioClip = (Clip) AudioSystem.getLine(info);
            audioClip.open(audioStream);

            // 播放音頻
            audioClip.start();

            // 添加播放完成後釋放資源的監聽器
            audioClip.addLineListener(event -> {
                if (event.getType() == LineEvent.Type.STOP) {
                    audioClip.close();
                }
            });
        } catch (UnsupportedAudioFileException e) {
            System.out.println("音頻格式不受支持: " + filePath);
        } catch (LineUnavailableException e) {
            System.out.println("音頻線路不可用: " + filePath);
        } catch (IOException e) {
            System.out.println("讀取音頻文件時出錯: " + filePath);
        }
    }

    public static void playFly() {
        playSound("resources/wav/fly.wav");
    }

    public static void playCrash() {
        playSound("resources/wav/crash.wav");
    }

    public static void playScore() {
        playSound("resources/wav/score.wav");
    }
}