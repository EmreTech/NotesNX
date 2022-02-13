#include <TextBox.hpp>

#include <borealis/platforms/switch/swkbd.hpp>

const std::string TextBoxXML = R"xml(
    <brls:Box
        width="auto"
        height="auto"
        axis="column"
        focusable="true"
        alignItems="center"
        justifyContent="center"
        paddingTop="@style/brls/button/padding_top_bottom"
        paddingRight="@style/brls/button/padding_sides"
        paddingBottom="@style/brls/button/padding_top_bottom"
        paddingLeft="@style/brls/button/padding_sides"
        cornerRadius="@style/brls/button/corner_radius"
        highlightCornerRadius="@style/brls/button/corner_radius">

        <brls:Label
            id="text"
            width="100%"
            height="100%"/>

    </brls:Box>
)xml";

TextBox::TextBox()
{
    this->inflateFromXMLString(TextBoxXML);

    this->forwardXMLAttribute("default", this->RawText, "text");
    this->forwardXMLAttribute("fontSize", this->RawText);

    this->registerClickAction( [this](brls::View *view){ return edit(); } );
}

void TextBox::draw(NVGcontext* vg, float x, float y, float width, float height, brls::Style style, brls::FrameContext* ctx)
{
    // Render text
    this->RawText->frame(ctx);

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

bool TextBox::edit()
{
    brls::Swkbd::openForText(
        [this](std::string s){ RawText->setText(s); }, 
        "Enter the text here", 
        "", 
        0x100, 
        this->RawText->getFullText()
    );
}

brls::View* TextBox::create()
{
    return new TextBox();
}