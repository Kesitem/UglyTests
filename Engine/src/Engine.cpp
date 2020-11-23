#include "Engine.h"
#include "LogFormatter.h"
#include "VulkanManager.h"


/**
 * \brief Constructor.
 */
ugly::Engine::Engine()
{
}


/**
 * \brief Destructor.
 */
ugly::Engine::~Engine()
{
}


/**
 * \brief Run the application.
 *
 * \param _application	Application to run
 * \return Program return code
 */
int ugly::Engine::run(Application* _application)
{
    // Initialize plog
    initializePLog();

    // initialize engine
    if (!initialize())
    {
        PLOG_ERROR << "Failed to initialized engine";
        shutdown();
        return -1;
    }

    // Run main loop
    if (!mainLoop())
    {
        PLOG_ERROR << "Error while running main loop";
        shutdown();
        return -2;
    }

    // Shutdown engine
    shutdown();

	return 0;
}


/**
 * \brief Initialize plog.
 */
void ugly::Engine::initializePLog()
{
    // Remove log file if exists
    struct stat buffer;
    if (stat(LOG_FILENAME.c_str(), &buffer) == 0)
    {
        if (remove(LOG_FILENAME.c_str()) != 0)
        {
            LOG_ERROR << "Cannnot remove log file";
        }
    }

    // Create log
    static plog::RollingFileAppender<plog::LogFormatter> fileAppender(LOG_FILENAME.c_str(), 0, 0);
    static plog::ConsoleAppender<plog::LogFormatter> consoleAppender;

    plog::init(plog::debug, &consoleAppender).addAppender(&fileAppender);

    PLOG_INFO << "----- UglyEngine Log";
    PLOG_INFO << "----- Version: " << ugly::version::FULLVERSION_STRING;
}


/**
 * \brief Initialize engine.
 *
 * \return False if error
 */
bool ugly::Engine::initialize()
{
    PLOG_INFO << "--- Initialize engine";

    PLOG_INFO << "Initialize GLFW";
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    m_window = glfwCreateWindow(m_display_width, m_display_height, m_title.c_str(), nullptr, nullptr);
    if (!m_window)
    {
        PLOG_ERROR << "Failed to create GLFW window";
        return false;
    }

    PLOG_INFO << "Initialize Vulkan";
    m_vulkan_manager.reset(new VulkanManager);
    if (!m_vulkan_manager->initialize())
    {
        PLOG_ERROR << "Failed to initialize vulkan manager";
        return false;
    }

    return true;
}


/**
 * \brief Shutdown engine.
 */
void ugly::Engine::shutdown()
{
    PLOG_INFO << "--- Shutdown engine";

    PLOG_INFO << "Shutdown vulkan";
    if (m_vulkan_manager.get() != nullptr)
    {
        m_vulkan_manager->shutdown();
        m_vulkan_manager.reset(nullptr);
    }

    PLOG_INFO << "Shutdown GLFW";
    if (m_window)
    {
        glfwDestroyWindow(m_window);
        m_window = nullptr;
    }
    glfwTerminate();
}


/**
 * \brief Main loop.
 *
 * \return False if error
 */
bool ugly::Engine::mainLoop()
{
    PLOG_INFO << "Entering main loop";

    return true;
}