//
// vertexArray.cpp
// jackbengine
//
// Created by Damien Bendejacq on 29/11/2019.
//

#include <stdexcept>

#include "core/render/renderer/glUtils.h"
#include "vertexArray.h"

namespace Jackbengine {

VertexArray::VertexArray()
{
    GL_CALL(glGenVertexArrays(1, &m_id));
    GL_CALL(glBindVertexArray(m_id));
}

VertexArray::~VertexArray()
{
    GL_CALL(glDeleteVertexArrays(1, &m_id));
}

void VertexArray::bind()
{
    GL_CALL(glBindVertexArray(m_id));
}

void VertexArray::unbind()
{
    GL_CALL(glBindVertexArray(0));
}

//constexpr int BufferElementTypeComponentCount(VertexAttributeType type)
//{
//    switch (type)
//    {
//        case VertexAttributeType::Float2:
//            return 2;
//        case VertexAttributeType::Float3:
//            return 3;
//    }
//
//    throw std::runtime_error("Unsupported buffer element type");
//}

//constexpr int BufferElementTypeSize(VertexAttributeType type)
//{
//    switch (type)
//    {
//        case VertexAttributeType::Float2:
//            return sizeof(float) * 2;
//        case VertexAttributeType::Float3:
//            return sizeof(float) * 3;
//    }
//
//    throw std::runtime_error("Unsupported buffer element type");
//}
//
//constexpr GLenum BufferElementTypeToGlType(VertexAttributeType type)
//{
//    switch (type)
//    {
//        case VertexAttributeType::Float2:
//        case VertexAttributeType::Float3:
//            return GL_FLOAT;
//    }
//
//    throw std::runtime_error("Unsupported buffer element type");
//}

}
