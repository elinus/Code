#include <jni.h>
#include <sys/shm.h>
#include <string>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <android/log.h>

// {{-->> /* Android Logging */
#define  LOG_TAG    "ShmServer"
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define  LOGW(...)  __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
// <<--}}

// {{-->> /* Values: /bionic/libc/kernel/uapi/linux/ashmem.h */
#define ASHMEM_NAME_LEN 256
#define ASHMEM_NAME_DEF "/dev/ashmem"
#define __ASHMEMIOC 0x77
#define ASHMEM_SET_NAME _IOW(__ASHMEMIOC, 1, char[ASHMEM_NAME_LEN])
#define ASHMEM_GET_NAME _IOR(__ASHMEMIOC, 2, char[ASHMEM_NAME_LEN])
#define ASHMEM_SET_SIZE _IOW(__ASHMEMIOC, 3, size_t)
#define ASHMEM_GET_SIZE _IO(__ASHMEMIOC, 4)
// <<--}}

struct SharedMemoryArea {
    int *map;
    int fd;
    int size;
} shmObj;


static jint getFD(JNIEnv *env, jclass clazz, jstring path,
                  jint size) {
    const char *name = env->GetStringUTFChars(path, NULL);
    jint fd = open(ASHMEM_NAME_DEF, O_RDWR);
    ioctl(fd, ASHMEM_SET_NAME, name);
    ioctl(fd, ASHMEM_SET_SIZE, size);

    LOGD("%s :: fd = %d, path = %s", __func__, fd, name);

    shmObj.size = size;
    shmObj.fd = fd;
    shmObj.map = (int *) mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    env->ReleaseStringUTFChars(path, name);
    return fd;
}

static jint setVal(JNIEnv *env, jclass clazz, jint fd, jint num) {
    LOGD("%s :: fd = %d, num = %d", __func__, fd, num);
    if (shmObj.fd == fd) {
        *(shmObj.map) = num;
        return 0;
    }
    return -1;
}

static jint getVal(JNIEnv *env, jclass clazz, jint fd) {
    LOGD("%s :: fd = %d", __func__, fd);
    if (shmObj.fd == fd) {
        return *(shmObj.map);
    }
    return -1;
}

static JNINativeMethod method_table[] = {
        { "setVal", "(II)I", (void *) setVal },
        { "getVal", "(I)I", (void *) getVal },
        { "getFD", "(Ljava/lang/String;I)I", (void *)getFD }
};

extern "C" jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv* env;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    } else {
        jclass clazz = env->FindClass("com/example/sharedmemorydemo/SharedMemoryLib");
        if (clazz) {
            jint ret = env->RegisterNatives(clazz, method_table, sizeof(method_table) / sizeof(method_table[0]));
            env->DeleteLocalRef(clazz);
            return ret == 0 ? JNI_VERSION_1_6 : JNI_ERR;
        } else {
            return JNI_ERR;
        }
    }
}