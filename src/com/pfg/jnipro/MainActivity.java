package com.pfg.jnipro;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends Activity {
    /** Called when the activity is first created. */
	
	TextView text;
	
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        text = (TextView)findViewById(R.id.text);
        
        JniCom com = new JniCom();
        text.setText("add:"+com.add(10, 4)+"\nsub:"+com.sub(10, 4));
        com.startThread();
    }
}