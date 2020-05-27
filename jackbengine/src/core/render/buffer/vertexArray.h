//
// vertexArray.h
// jackbengine
//
// Created by Damien Bendejacq on 29/11/2019.
//

#ifndef __VERTEX_ARRAY_H__
#define __VERTEX_ARRAY_H__

namespace Jackbengine {

class VertexArray
{
public:
    VertexArray();
    ~VertexArray();

    void bind();
    static void unbind();

private:
    unsigned int m_id;
};

}

#endif // __VERTEX_ARRAY_H__
