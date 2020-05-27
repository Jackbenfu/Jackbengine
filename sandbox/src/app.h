//
// app.h
// sandbox
//
// Created by Damien Bendejacq on 13/08/2019.
//

#ifndef __APP_H__
#define __APP_H__

#include "jackbengine.h"

namespace Sandbox {

class App : public Jackbengine::Application
{
public:
    explicit App(Jackbengine::ApplicationConfig &config);
    ~App() override = default;

    void update(float delta) final;
};

}

#endif // __APP_H__
