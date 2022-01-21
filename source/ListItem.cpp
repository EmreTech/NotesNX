#include <ListItem.hpp>

ListItem::ListItem()
{
    this->inflateFromXMLRes("xml/views/ListItem.xml");

    this->forwardXMLAttribute("title", this->title, "text");
    this->forwardXMLAttribute("description", this->descript, "text");

    this->registerClickAction( [this](brls::View *view){ return onClick(); } );
}

void ListItem::draw(NVGcontext* vg, float x, float y, float width, float height, brls::Style style, brls::FrameContext* ctx)
{
    // Render text
    this->title->frame(ctx);
    this->descript->frame(ctx);

    // Separators
    nvgFillColor(vg, ctx->theme["brls/sidebar/separator"]);

    // Bottom
    nvgBeginPath(vg);
    nvgRect(vg, x, y - 1, width, 1);
    nvgFill(vg);

    // Top
    nvgBeginPath(vg);
    nvgRect(vg, x, y + height + 1, width, 1);
    nvgFill(vg);
}

void ListItem::setTitle(const std::string title)
{
    this->title->setText(title);
}

void ListItem::setDescription(const std::string description)
{
    this->descript->setText(description);
}

std::string ListItem::getTitle()
{
    return this->title->getFullText();
}

std::string ListItem::getDescription()
{
    return this->descript->getFullText();
}

brls::GenericEvent* ListItem::getClickEvent()
{
    return &this->clickEvent;
}

bool ListItem::onClick()
{
    return this->clickEvent.fire(this);
}

brls::View* ListItem::create()
{
    return new ListItem();
}