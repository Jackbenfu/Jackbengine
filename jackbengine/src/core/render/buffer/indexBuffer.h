//
// indexBuffer.h
// jackbengine
//
// Created by Damien Bendejacq on 28/11/2019.
//

#ifndef __INDEX_BUFFER_H__
#define __INDEX_BUFFER_H__

namespace Jackbengine {

class IndexBuffer
{
public:
    IndexBuffer(const unsigned int *indices, unsigned int size);
    ~IndexBuffer();

    void bind();
    static void unbind();

    unsigned int count();

private:
    unsigned int m_id;
    unsigned int m_count;
};

}

#endif // __INDEX_BUFFER_H__
