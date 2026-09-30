#ifndef FUSION_INTERNAL_BUFFER_H
#define FUSION_INTERNAL_BUFFER_H
#include <Fusion/FusionBuffer.h>

struct FusBufferExecutable_T {
    FusExecMemAllocator* allocator;
    void* data;
    size_t size, offset;
};
#endif