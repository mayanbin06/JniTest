package com.myb;

import java.lang.String;

public class helloworld {

    private static long mNativeTest = 0;

    public helloworld() {
        mNativeTest = init();
    }

    public static void run() {
        System.loadLibrary("test_jni");
        helloworld h = new helloworld();
        h.test(mNativeTest,"hello world!!!!");
        return;
    }
   
    public native String test(long NativeTest, String s);
    public native static long init();
}
