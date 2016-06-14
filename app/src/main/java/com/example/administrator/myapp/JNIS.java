package com.example.administrator.myapp;

/**
 * Created by Administrator on 2016/6/13.
 */
public class JNIS {
    static {
        System.loadLibrary("HelloJni");
    }
    public native String helloJNI();
    public native int[] increaseArrayEles(int[] intArray);
    public native int checkPwd(String pwd);
}

