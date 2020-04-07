#include <jni.h>
#include <string>
#include <sys/mman.h>
#include <unistd.h>
#include <android/log.h>

// {{-->> /* Android Logging */
#define  LOG_TAG    "Shm-Client-Native"
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define  LOGW(...)  __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
// <<--}}

struct Memory {
    int size;
    char* buffer;
} shmObj {0, nullptr};

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jboolean JNICALL
Java_com_example_shmclientandroidq_SharedMemoryClientLibrary_mapShm(
        JNIEnv *env, jclass clazz, jint fd, jint size) {

    shmObj.size = size;
    shmObj.buffer = reinterpret_cast<char*>(::mmap(nullptr, size,
            PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0));
    if (shmObj.buffer == MAP_FAILED) {
        LOGD("%s :: Buffer => MAP_FAILED", __func__);
        shmObj.buffer = nullptr;
        return false;
    }
    LOGD("%s :: Shared memory mapped ! addr. = %p, size = %d, fd = %d",
         __func__, shmObj.buffer, shmObj.size, fd);
    return true;
}

JNIEXPORT void JNICALL
Java_com_example_shmclientandroidq_SharedMemoryClientLibrary_setShmData(
        JNIEnv *env, jclass clazz, jstring data) {
    const char* buffer =  env->GetStringUTFChars(data, nullptr);
    if (strlen(buffer) > shmObj.size) {
        LOGD("%s, {Error} Data size > shared memory size.", __func__);
        return;
    }
    char* buffer_ptr = shmObj.buffer;
    strcpy(buffer_ptr, buffer);
    env->ReleaseStringUTFChars(data, buffer);
}

JNIEXPORT jstring JNICALL
Java_com_example_shmclientandroidq_SharedMemoryClientLibrary_getShmData(
        JNIEnv *env, jclass clazz) {
    std::string buffer = shmObj.buffer;
    return env->NewStringUTF(buffer.c_str());
}

#ifdef __cplusplus
};
#endif