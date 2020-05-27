//
// verteBuffer.h
// jackbengine
//
// Created by Damien Bendejacq on 28/11/2019.
//

#ifndef __VERTEX_BUFFER_H__
#define __VERTEX_BUFFER_H__

#include <initializer_list>

namespace Jackbengine {

enum class VertexAttributeType
{
    Float2,
    Float3,
};

class VertexBuffer
{
public:
    VertexBuffer(const float *vertices, unsigned int size, const std::initializer_list<VertexAttributeType> &layout);
    ~VertexBuffer();

    void bind();
    static void unbind();

private:
    unsigned int m_id;
};

}

#endif // __VERTEX_BUFFER_H__
