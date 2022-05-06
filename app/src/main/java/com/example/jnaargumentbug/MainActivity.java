package com.example.jnaargumentbug;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;

import com.sun.jna.IntegerType;
import com.sun.jna.Library;
import com.sun.jna.Native;

public class MainActivity extends Activity {
    private static final TestLibrary lib = Native.load("JnaArgumentBug", TestLibrary.class);

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        logValueFromJna();
    }

    private void logValueFromJna() {
        boolean on = lib.hello(new UINT16(0x8810));
        boolean off = lib.hello_optimizations_disabled(new UINT16(0x8810));
        Log.w("JNA-BUG", "hello returned correct value? " + on);
        Log.w("JNA-BUG", "hello_optimizations_disabled returned correct value? " + off);
    }

    public static class UINT16 extends IntegerType {

        @SuppressWarnings("unused")
        public UINT16() {
            this(0);
        }

        public UINT16(int value) {
            super(2, value, true);
        }
    }

    interface TestLibrary extends Library {
        boolean hello(UINT16 argument);

        boolean hello_optimizations_disabled(UINT16 argument);
    }
}