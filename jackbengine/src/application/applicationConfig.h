//
// applicationConfig.h
// jackbengine
//
// Created by Damien Bendejacq on 17/08/2015.
//

#ifndef __APPLICATION_CONFIG_H__
#define __APPLICATION_CONFIG_H__

#include <string>

namespace Jackbengine {

struct ApplicationConfig
{
    std::string general_title {"<Insert title here!>"};

    unsigned int render_width {640};
    unsigned int render_height {480};
    bool render_fullscreen {false};

    unsigned int core_fps {60};
};

}

#endif // __APPLICATION_CONFIG_H__
