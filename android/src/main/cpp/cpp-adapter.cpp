#include <jni.h>
#include "NitroEventKitOnLoad.hpp"

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void*) {
  return margelo::nitro::eventkit::initialize(vm);
}
