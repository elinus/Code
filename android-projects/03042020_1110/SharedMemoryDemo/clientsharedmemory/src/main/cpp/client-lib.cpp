#include <jni.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <android/log.h>

// {{-->> /* Android Logging */
#define  LOG_TAG    "ShmClient"
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define  LOGW(...)  __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
// <<--}}

struct SharedMemoryArea {
    int *map;
    int fd;
    int size;
} shmObj;


static void setMap(JNIEnv *env, jclass cl, jint fd, jint size) {
    LOGD("%s :: fd = %d, size = %d", __func__, fd, size);
    shmObj.fd = fd;
    shmObj.size = size;
    shmObj.map = (int *)mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
}

static jint setVal(JNIEnv *env, jclass cl, int fd, jint num) {
    LOGD("%s :: fd = %d, num = %d", __func__, fd, num);
    if (shmObj.size == fd) {
        *(shmObj.map) = num;
        return 0;
    }
    return -1;
}

static jint getVal(JNIEnv *env, jclass cl, int fd) {
    LOGD("%s :: fd = %d", __func__, fd);
    if (shmObj.fd == fd) return *(shmObj.map);
    return -1;
}

static JNINativeMethod method_table[] = {
        { "setVal", "(II)I", (void *) setVal },
        { "getVal", "(I)I", (void *) getVal },
        { "setMap", "(II)V", (void *) setMap }

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