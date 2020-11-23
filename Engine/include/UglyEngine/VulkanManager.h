#pragma once

#include "Core.h"

namespace ugly
{
	/**
	 * \brief Vulkan manager.
	 */
	class VulkanManager
	{
	public:

		/**
		 * \brief Constructor.
		 */
		VulkanManager();

		/**
		 * \brief Destructor.
		 */
		virtual ~VulkanManager();

		/**
		 * \brief Initialize manager.
		 *
		 * \return False if error
		 */
		bool initialize();

		/**
		 * \brief Shutdown manager.
		 */
		void shutdown();

	private:

		/**
		 * \brief Create Vulkan instance.
		 *
		 * \return false if error
		 */
		bool createInstance();

	private:

		/*! Vulkan instance */
		VkInstance m_instance;
	};

}//namespace ugly