#pragma once

namespace ugly
{
	/**
	 * \brief An application must inherit from this class.
	 */
	class Application
	{
	public:

		/**
		 * \brief Constructor.
		 */
		Application();

		/**
		 * \brief Destructor.
		 */
		virtual ~Application();

		/**
		 * \brief Initialize application.
		 *
		 * \return False if error.
		 */
		virtual bool initialize();

		/**
		 * \brief Shutdown application.
		 */
		virtual void shutdown();

		/**
		 * \brief Update application.
		 */
		virtual void update();

	};

}//namespace ugly