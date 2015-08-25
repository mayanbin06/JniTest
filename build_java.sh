#!/bin/sh

PROJECT_HOME=.
JAR_PATH=./lib/java
JDK_PATH=.
OUT_PATH=./out
SRC_PATH=./src

#find source files
find $SRC_PATH -iname *.java > $SRC_PATH/java_sources.list

#clean out files
rm -rf OUT_PATH/*

#compile java files
javac -d $OUT_PATH -classpath $JAR_PATH @$SRC_PATH/java_sources.list
#javac -classpath $JAR_PATH/webviewchromium.jar com/myb/helloworld.java 


