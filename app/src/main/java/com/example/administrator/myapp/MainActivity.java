package com.example.administrator.myapp;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        JNIS jnis = new JNIS();
        String jni = jnis.helloJNI();
        Log.e("TAG", "result=" + jni);

        int arr[] = {1,2,3};
        jnis.increaseArrayEles(arr);
        for (int i=0;i<arr.length;i++){
            Log.e("TAG", "result------>"+arr[i]);
        }
        int pwd = jnis.checkPwd("123456");
        Log.e("TAG", "<------->"+pwd);
    }
    public void button(View v) {
        callbackShowToast();
    }

    public native void callbackShowToast();

    public void showToast() {
        Toast.makeText(this, "点我了调用了", Toast.LENGTH_SHORT).show();
    }
    static {
        System.loadLibrary("HelloJni");
    }
}
