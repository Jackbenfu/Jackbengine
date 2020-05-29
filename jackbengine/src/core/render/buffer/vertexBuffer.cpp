//
// vertexBuffer.cpp
// jackbengine
//
// Created by Damien Bendejacq on 28/11/2019.
//

#include "core/render/renderer/glUtils.h"
#include "vertexBuffer.h"

namespace Jackbengine {

VertexBuffer::VertexBuffer(const float* vertices, unsigned int size, const std::initializer_list<VertexAttributeType>& layout)
{
    GL_CALL(glGenBuffers(1, &m_id));
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, m_id));
    GL_CALL(glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW));

//    m_stride = 0;
//    auto offset = 0;
//    for (auto attribute : m_attributes)
//    {
//        attribute.offset = offset;
//        offset += attribute.size;
//        m_stride += attribute.size;
//    }
}

VertexBuffer::~VertexBuffer()
{
    GL_CALL(glDeleteBuffers(1, &m_id));
}

void VertexBuffer::bind()
{
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, m_id));
}

void VertexBuffer::unbind()
{
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

}
