package com.iheartradio.m3u8;

import java.io.InputStream;
import java.io.FileInputStream;
import java.util.*;

import com.iheartradio.m3u8.data.Playlist;

public class TestUtil {

    public static void main(String[] args) {
        String filepath = args[0];
        TestUtil testUtil = new TestUtil();
        testUtil.dumpPlayList(filepath);
    }

    public dumpPlayList(String filepath) {
       FileInputStream in = new FileInputStream(filepath);
       PlayListParser parse = new PlayListParser(in, Format.EXT_M3U, Encoding.UTF_8);
       PlayList playlist = parser.parse();
       System.out.println(playlist.toString());
    }
}
