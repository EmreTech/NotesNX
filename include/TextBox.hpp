#pragma once

#include <borealis.hpp>

#include <string>

struct TextBox : public brls::Box
{
    TextBox();

    void draw(NVGcontext* vg, float x, float y, float width, float height, brls::Style style, brls::FrameContext* ctx) override;
    bool edit();

    static brls::View* create();

    private:
    BRLS_BIND(brls::Label, RawText, "text");
};