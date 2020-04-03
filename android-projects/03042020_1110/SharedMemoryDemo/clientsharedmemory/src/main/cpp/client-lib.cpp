#include <jni.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>

int *map ;
int size;

static void setMap(JNIEnv *env, jclass cl, jint fd, jint sz) {
    size = sz;
    map = (int *)mmap(0,size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
}

static jint setVal(JNIEnv *env, jclass cl, jint pos,jint num)
{
    if(pos < (size/ sizeof(int))) {
        map[pos] = num;
        return 0;
    }
    return -1;
}

static jint getVal(JNIEnv *env, jclass cl, jint pos) {
    if(pos < (size/ sizeof(int))) {
        return map[pos];
    }
    return -1;
}


static JNINativeMethod method_table[] = {
        { "setVal", "(II)I", (void *) setVal },
        { "getVal", "(I)I", (void *) getVal },
        { "setMap", "(II)V", (void *)setMap }

};


extern "C" jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv* env;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    } else {
        jclass clazz = env->FindClass("com/example/clientsharedmemory/SharedMemoryClientLib");
        if (clazz) {
            jint ret = env->RegisterNatives(clazz, method_table, sizeof(method_table) / sizeof(method_table[0]));
            env->DeleteLocalRef(clazz);
            return ret == 0 ? JNI_VERSION_1_6 : JNI_ERR;
        } else {
            return JNI_ERR;
        }
    }
}