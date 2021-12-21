#pragma once

#include <borealis.hpp>

struct ListItem : public brls::Box
{
    ListItem();

    void draw(NVGcontext* vg, float x, float y, float width, float height, brls::Style style, brls::FrameContext* ctx) override;

    static brls::View* create();

    private:
    BRLS_BIND(brls::Label, title, "title");
    BRLS_BIND(brls::Label, descript, "description");
};