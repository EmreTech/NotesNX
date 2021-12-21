#include <ListItem.hpp>

ListItem::ListItem()
{
    this->inflateFromXMLRes("xml/views/ListItem.xml");

    this->forwardXMLAttribute("title", this->title, "text");
    this->forwardXMLAttribute("description", this->descript, "text");
}

void ListItem::draw(NVGcontext* vg, float x, float y, float width, float height, brls::Style style, brls::FrameContext* ctx)
{
    /*
    float height = style["brls/sidebar/separator_height"];
    float midY = y + height / 2;
    */

    // Render text
    this->title->frame(ctx);
    this->descript->frame(ctx);

    // Separators
    nvgFillColor(vg, ctx->theme["brls/sidebar/separator"]);

    nvgBeginPath(vg);
    nvgRect(vg, x, y - 1, width, 1);
    nvgFill(vg);

    nvgBeginPath(vg);
    nvgRect(vg, x, y + height + 1, width, 1);
    nvgFill(vg);
}

brls::View* ListItem::create()
{
    return new ListItem();
}