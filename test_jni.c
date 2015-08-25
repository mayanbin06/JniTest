#include "com_myb_helloworld.h"
#include "test.h"
#include <stdio.h>
#include <string>

JNIEXPORT jstring JNICALL Java_com_myb_helloworld_test
  (JNIEnv * env, jobject jo, jlong jl, jstring js) {
   const char * a = env->GetStringUTFChars(js, NULL);
   myspace::Test * t = reinterpret_cast<myspace::Test * >(jl);
   t->print(std::string(a));
}    

JNIEXPORT jlong JNICALL Java_com_myb_helloworld_init
  (JNIEnv * env, jclass jc) {
    myspace::Test *t = new myspace::Test();
    return reinterpret_cast<jlong >(t);
}
