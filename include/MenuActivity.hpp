#pragma once

#include <borealis.hpp>

struct MenuActivity : public brls::Activity
{
    brls::AppletFrame *frame;

    brls::View *createContentView() override
    {
        frame = new brls::AppletFrame();
        frame->setTitle("NotesNX");
        frame->setContentView(brls::View::createFromXMLResource("activity/menu.xml"));

        return frame;
    }
};