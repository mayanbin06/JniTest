##compile
#-ljvm must be the last. The way GCC finds symbols was changed fairly recently: now the units to be linked are processed strictly from left to right, and references to libraries (-lYourLibrary) are silently ignored if nothing to their left in the command line needs them.
#To fix this, move -ljvm after the compilation units that use it, for example to the very end of the command line:

## to run the program. export LD_LIBRARY_PATH = [path of libjvm.so].
all:test test_jni.so

# to call java static method
test:JniTest.cpp
	g++ -g -I/usr/local/jdk1.6/include -I/usr/local/jdk1.6/include/linux -L/usr/local/jdk1.6/jre/lib/amd64/server/ JniTest.cpp -ljvm -o test_start

# java call native method
test_jni.so:test.h test_jni.c com_myb_helloworld.h
	g++ -g -I/usr/local/jdk1.6/include -I/usr/local/jdk1.6/include/linux -L/usr/local/jdk1.6/jre/lib/amd64/server/ test_jni.c -ljvm -fpic -shared -o libtest_jni.so	
