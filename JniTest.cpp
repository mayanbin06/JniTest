#include<stdio.h>
#include<jni.h>
/* -I/JAVA_HOME/include -I/JAVA_HOME/include/linux */

JNIEnv* Vnpt_JavaCreateVM();

JavaVM * g_jvm;

void Vnpt_JavaInvokeClass(JNIEnv* env);

int main(){
    JNIEnv* env = 0;
    env = Vnpt_JavaCreateVM();
    Vnpt_JavaInvokeClass(env);

    getchar();
}
JNIEnv* Vnpt_JavaCreateVM() {
    jint res;   
    JavaVM* jvm;
    JNIEnv* env;
    JavaVMInitArgs args;
    JavaVMOption options[3];

    args.version = JNI_VERSION_1_6; //  JNI_VERSION_1_2 is interchangeable for this example
    args.nOptions = 3;
    /*java class path*/
    options[0].optionString = "-Djava.class.path=.:./test.jar";
    /*native lib path*/
    options[1].optionString = "-Djava.library.path=.";
    // 用于跟踪运行时的信息
    options[2].optionString = "-verbose:jni";
    args.options = options;
    args.ignoreUnrecognized = JNI_FALSE;
    res = JNI_CreateJavaVM(&g_jvm, (void **)&env, &args);
    if(res < 0)
    {
        printf("JNI_CREATEJAVAVM RES = %d\n",res);
    }
    return env;
}
void Vnpt_JavaInvokeClass(JNIEnv* env) {
    jclass mainClass;
    jmethodID mainMethod;

    mainClass = env->FindClass("com/myb/helloworld");
    mainMethod = env->GetStaticMethodID(mainClass, "run", "()V");
    printf("mainClass(%p)\n",mainClass);
    printf("mainMethod(%p)\n",mainMethod);
    if (mainMethod) 
        env->CallVoidMethod(mainClass, mainMethod);
    else 
        printf("find jmethodId fail\n");
}
