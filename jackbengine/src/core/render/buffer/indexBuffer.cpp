//
// indexBuffer.cpp
// jackbengine
//
// Created by Damien Bendejacq on 28/11/2019.
//

#include "core/render/renderer/glUtils.h"
#include "indexBuffer.h"

namespace Jackbengine {

IndexBuffer::IndexBuffer(const unsigned int* indices, unsigned int count)
    : m_count {count}
{
    (glGenBuffers(1, &m_id));
    GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id));
    GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indices, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer()
{
    GL_CALL(glDeleteBuffers(1, &m_id));
}

void IndexBuffer::bind()
{
    GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id));
}

void IndexBuffer::unbind()
{
    GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

unsigned int IndexBuffer::count()
{
    return m_count;
}

}
