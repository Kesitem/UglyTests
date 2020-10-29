#pragma once

#include "Core.h"

namespace ugly
{
	class Application;

	/**
	 * \brief Main class of UglyEngine.
	 */
	class Engine
	{
	public:

		/**
		 * \brief Constructor.
		 */
		Engine();

		/**
		 * \brief Destructor.
		 */
		virtual ~Engine();

		/**
		 * \brief Run the application.
		 *
		 * \param _application	Application to run
		 * \return Program return code
		 */
		int run(Application* _application);

	private: 

		/**
		 * \brief Initialize plog.
		 */
		void initializePLog();

		/**
		 * \brief Initialize engine.
		 * 
		 * \return False if error
		 */
		bool initialize();

		/**
		 * \brief Shutdown engine.
		 */
		void shutdown();

		/**
		 * \brief Main loop.
		 *
		 * \return False if error
		 */
		bool mainLoop();

	private:

		/*! GLFW window. */
		GLFWwindow* m_window{ nullptr };
	};

}//namespace ugly
