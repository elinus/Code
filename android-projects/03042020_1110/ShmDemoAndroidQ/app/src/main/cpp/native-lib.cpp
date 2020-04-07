#include <jni.h>
#include <string>
#include <android/sharedmem.h>
#include <android/sharedmem_jni.h>
#include <sys/mman.h>
#include <unistd.h>
#include <android/log.h>

// {{-->> /* Android Logging */
#define  LOG_TAG    "Shm-Server-Native"
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define  LOGW(...)  __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
// <<--}}

class SharedMemory {
private:
    int mSize;
    char* mBuffer;
    int mFD;
public:
    SharedMemory(std::string shm_name, int size) : mSize(0), mBuffer(nullptr), mFD(-1) {
        mFD = ASharedMemory_create(shm_name.c_str(), size);
        if (mFD < 0 || ASharedMemory_getSize(mFD) != size) {
            LOGD("%s :: fd = %d", __func__, mFD);
            return;
        }
        mSize = size;
        mBuffer = reinterpret_cast<char *>(::mmap(nullptr, mSize,
                PROT_READ | PROT_WRITE, MAP_SHARED, mFD, 0));
        if (mBuffer == MAP_FAILED) {
            LOGD("%s :: Buffer => MAP_FAILED", __func__);
            mBuffer = nullptr;
            return;
        }
        LOGD("%s :: Shared memory created ! addr. = %p, size = %d, fd = %d",
                __func__, mBuffer, mSize, mFD);
    }

    ~SharedMemory() {
        if (mBuffer != nullptr) {
            ::munmap(mBuffer, mSize);
            mBuffer = nullptr;
            LOGD("%s :: Buffer addr. set to null", __func__);
        }
        if (mFD > 0) {
            ::close(mFD);
            mFD = -1;
            LOGD("%s :: File descriptor closed successfully!", __func__);
        }
        mSize = 0;
        if (mFD > 0 || mSize != 0 || mBuffer != nullptr) {
            LOGD("%s :: Shared memory destruction failed ! addr. = %p, size = %d, fd = %d",
                 __func__, mBuffer, mSize, mFD);
        }
    }

    int getSize() const {
        return mSize;
    }

    int getSharedMemoryFd() const {
        return mFD;
    }

    char* getBuffer() const {
        return mBuffer;
    }
};

SharedMemory *shmHandle = nullptr;

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jboolean JNICALL
Java_com_example_shmdemoandroidq_SharedMemoryServerLibrary_createShm(
        JNIEnv *env, jclass clazz) {
    if (shmHandle == nullptr) {
        shmHandle = new SharedMemory("SysIntDemoShm", 1024);
    }
    if (shmHandle != nullptr) return true;
    return false;
}

JNIEXPORT jboolean JNICALL
Java_com_example_shmdemoandroidq_SharedMemoryServerLibrary_releaseShm(
        JNIEnv *env, jclass clazz) {
    if (shmHandle != nullptr) {
        delete shmHandle;
        shmHandle = nullptr;
    }
    if (shmHandle == nullptr) return true;
    return false;
}

JNIEXPORT void JNICALL
Java_com_example_shmdemoandroidq_SharedMemoryServerLibrary_setShmData(
        JNIEnv *env, jclass clazz, jstring data) {
    const char* buffer =  env->GetStringUTFChars(data, nullptr);
    if (strlen(buffer) > shmHandle->getSize()) {
        LOGD("%s, {Error} Data size > shared memory size.", __func__);
        return;
    }
    char* buffer_ptr = shmHandle->getBuffer();
    strcpy(buffer_ptr, buffer);
    env->ReleaseStringUTFChars(data, buffer);
}

JNIEXPORT jint JNICALL
Java_com_example_shmdemoandroidq_SharedMemoryServerLibrary_getShmSize(
        JNIEnv *env, jclass clazz) {
    return shmHandle->getSize();
}

JNIEXPORT jstring JNICALL
Java_com_example_shmdemoandroidq_SharedMemoryServerLibrary_getShmData(
        JNIEnv *env, jclass clazz) {
    std::string buffer = shmHandle->getBuffer();
    return env->NewStringUTF(buffer.c_str());
}

JNIEXPORT jint JNICALL
Java_com_example_shmdemoandroidq_SharedMemoryServerLibrary_getShmFd(
        JNIEnv *env, jclass clazz) {
    return shmHandle->getSharedMemoryFd();
}

#ifdef __cplusplus
};
#endif
