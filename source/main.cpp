#include <borealis.hpp>
#include <string>

#include <ListItem.hpp>
#include <MainActivity.hpp>

using namespace brls::literals;

int main(int argc, char **argv)
{
    brls::Logger::setLogLevel(brls::LogLevel::DEBUG);

    if (!brls::Application::init())
    {
        brls::Logger::error("Unable to init Borealis");
        return EXIT_FAILURE;
    }

    brls::Application::createWindow("app/title"_i18n);

    brls::Application::setGlobalQuit(true);
    brls::Application::registerXMLView("ListItem", ListItem::create);
    
    MainActivity *activity = new MainActivity();
    brls::Application::pushActivity(activity);

    brls::BoundView<brls::Box> mainActivityBox = brls::BoundView<brls::Box>("MainActivityBox", activity->getContentView());

    ListItem *item1 = new ListItem();
    item1->setTitle("Hello");
    item1->setDescription(brls::getStr("app/choose_screen/date_added", "UNKNOWN"));
    mainActivityBox->addView(item1);

    while (brls::Application::mainLoop());

    return EXIT_SUCCESS;
}