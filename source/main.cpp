#include <borealis.hpp>
#include <string>
#include <map>

#include <ListItem.hpp>
#include <MainActivity.hpp>

int main(int argc, char **argv)
{
    brls::Logger::setLogLevel(brls::LogLevel::DEBUG);

    if (!brls::Application::init())
    {
        brls::Logger::error("Unable to init Borealis");
        return EXIT_FAILURE;
    }

    brls::Application::createWindow("NotesNX");

    brls::Application::setGlobalQuit(true);
    brls::Application::registerXMLView("ListItem", ListItem::create);

    brls::getLightTheme().addColor("listitem/background", nvgRGB(255, 255, 255));
    brls::getDarkTheme().addColor("listitem/background", nvgRGB(80, 80, 80));

    MainActivity *activity = new MainActivity();
    brls::Application::pushActivity(activity);

    brls::BoundView<brls::Box> mainActivityBox = brls::BoundView<brls::Box>("MainActivityBox", activity->getContentView());
    
    ListItem *item1 = new ListItem();
    item1->setTitle("Hello");
    item1->setDescription("Date Added: UNKNOWN");
    mainActivityBox->addView(item1);
 
    while (brls::Application::mainLoop());

    return EXIT_SUCCESS;
}