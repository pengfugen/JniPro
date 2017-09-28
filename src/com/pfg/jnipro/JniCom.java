package com.pfg.jnipro;

import android.util.Log;

public class JniCom {
	static
	{
		System.loadLibrary("pfg_jni");
	}
	
	public native int add(int a, int b);
	public native int sub(int a, int b);
	
	public native void startThread();
	
	public void callBack(int value)
	{
		Log.d("JniCom", "java callback value:"+value);
	}
}
