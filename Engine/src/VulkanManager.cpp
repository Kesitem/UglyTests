#include "VulkanManager.h"

/**
 * \brief Constructor.
 */
ugly::VulkanManager::VulkanManager()
{
}


/**
 * \brief Destructor.
 */
ugly::VulkanManager::~VulkanManager()
{
}


/**
 * \brief Initialize manager.
 *
 * \return False if error
 */
bool ugly::VulkanManager::initialize()
{
	PLOG_INFO << "Initialize Vulkan manager";

    if (!createInstance())
        return false;

	return true;
}

/**
 * \brief Shutdown manager.
 */
void ugly::VulkanManager::shutdown()
{
	PLOG_INFO << "Shutdown Vulkan manager";

    vkDestroyInstance(m_instance, nullptr);
}


/**
 * \brief Create Vulkan instance.
 * 
 * \return false if error
 */
bool ugly::VulkanManager::createInstance()
{
    PLOG_INFO << "Create Vulkan instance...";
    //TODO: Complete program version and name
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "UglyEngine";
    appInfo.engineVersion = VK_MAKE_VERSION(ugly::version::MAJOR , ugly::version::MINOR, ugly::version::BUILD);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;
    createInfo.enabledLayerCount = 0;

    if (vkCreateInstance(&createInfo, nullptr, &m_instance))
    {
        PLOG_ERROR << "Failed to create vulkan instance";
        return false;
    }

    uint32_t extension_count = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extension_count, nullptr);
    std::vector<VkExtensionProperties> extensions(extension_count);
    vkEnumerateInstanceExtensionProperties(nullptr, &extension_count, extensions.data());
    PLOG_INFO << "Available extensions:";
    for (const auto& extension : extensions) {
        PLOG_INFO << " - " << extension.extensionName;
    }

    return true;
}