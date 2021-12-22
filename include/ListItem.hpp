#pragma once

#include <borealis.hpp>

#include <string>

struct ListItem : public brls::Box
{
    ListItem();

    void draw(NVGcontext* vg, float x, float y, float width, float height, brls::Style style, brls::FrameContext* ctx) override;

    void setTitle(const std::string title);
    void setDescription(const std::string description);
    std::string getTitle();
    std::string getDescription();
    brls::GenericEvent* getClickEvent();
    bool onClick();

    static brls::View* create();

    private:
    BRLS_BIND(brls::Label, title, "title");
    BRLS_BIND(brls::Label, descript, "description");

    brls::GenericEvent clickEvent;
};