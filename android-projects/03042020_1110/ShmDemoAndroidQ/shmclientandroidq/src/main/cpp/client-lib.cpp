#include <jni.h>
#include <string>
#include <sys/mman.h>
#include <unistd.h>
#include <android/log.h>
#include <android/sharedmem.h>
#include <android/sharedmem_jni.h>

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
Java_com_example_shmclientandroidq_SharedMemoryClientNativeLib_mapShm(
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
Java_com_example_shmclientandroidq_SharedMemoryClientNativeLib_setShmData(
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
Java_com_example_shmclientandroidq_SharedMemoryClientNativeLib_getShmData(
        JNIEnv *env, jclass clazz, int data_size) {
    std::string buffer = "";
    if (data_size == -1) {
        buffer = shmObj.buffer;
    } else {
        char* buffer_ptr = shmObj.buffer;
        strncpy(buffer_ptr, shmObj.buffer, data_size);
        buffer = buffer_ptr;
    }
    LOGD("Native buff:: %s", buffer.c_str());
    return env->NewStringUTF(buffer.c_str());
}

JNIEXPORT jboolean JNICALL
Java_com_example_shmclientandroidq_SharedMemoryClientNativeLib_mapSharedMemory(
        JNIEnv *env, jclass clazz,
        jobject shm, jint fd, jint size) {
    int file_descriptor = ASharedMemory_dupFromJava(env, shm);
    shmObj.size = size;
    shmObj.buffer = reinterpret_cast<char*>(::mmap(nullptr, size,
                                                   PROT_READ | PROT_WRITE, MAP_SHARED, file_descriptor, 0));
    if (shmObj.buffer == MAP_FAILED) {
        LOGD("%s :: (android.os.SharedMemory) Buffer => MAP_FAILED", __func__);
        shmObj.buffer = nullptr;
        return false;
    }
    LOGD("%s :: (android.os.SharedMemory) Shared memory mapped ! addr. = %p, size = %d, fd = %d",
         __func__, shmObj.buffer, shmObj.size, file_descriptor);
    return true;
}

#ifdef __cplusplus
};
#endif