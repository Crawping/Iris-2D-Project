#ifndef _H_IRISAPP_
#define _H_IRISAPP_

#include "../IrisCommon.h"

/**
 * \~english
 * Namespace of Iris 2D
 */
/**
 * \~chinese
 * Iris 2D 的命名空间
 */
namespace Iris2D
{
	/**
	* \~english
	* Application Class of Iris 2D.
	*
	* This class provides a singleton instance to maintain the Iris 2D application, including initializing Iris 2D, releasing resouce and so on.
	*/
	/**
	* \~chinese
	* Iris 2D Application类。
	*
	* 这个类提供了一个单例对象来维护 Iris 2D 应用，包括初始化 Iris 2D，释放资源等。
	*/
	class IrisApplication
	{
	private:
		enum class IrisAppState {
			Uninitialized = 0,
			Initialized,
			Running,
			Quited,
		};

	private:
		IrisAppState m_eAppState = IrisAppState::Uninitialized;

	private:
		IrisApplication() = default;
		~IrisApplication() = default;

	public:

		/**
		* \~english
		* Type of call-back function of Iris 2D application.
		*/
		/**
		* \~chinese
		* Iris 2D 回调函数的类型。
		*/
		typedef bool(*GameFunc)();

		/**
		* \~english
		* Startup information structure of Iris 2D application.
		* @see Initialize(const IrisAppStartInfo* pInfo)
		*/
		/**
		* \~chinese
		* Iris 2D 启动信息的结构体。
		* @see Initialize(const IrisAppStartInfo* pInfo)
		*/
		struct IrisAppStartInfo {
			HINSTANCE m_hInstance = nullptr; 
			/**< \~english Instance handle of Windows application taken from WinMain as a parameter. */
			/**< \~chinese Windows 应用的 Instance 句柄，来自于 WinMain 的参数。 */
			int nShowCmd = 0;
			/**< \~english Show command of Windows application taken from WinMain as a parameter. */
			/**< \~chinese Windows 应用的 Show command，来自于 WinMain 的参数。 */
			unsigned int m_nX = 0;
			/**< \~english Initial X Position of the window of Iris 2D application. */
			/**< \~chinese Iris 2D 窗口初始化 X 坐标。 */
			unsigned int m_nY = 0;
			/**< \~english Initial Y Position of the window of Iris 2D application. */
			/**< \~chinese Iris 2D 窗口初始化 Y 坐标。 */
			unsigned int m_nWidth = 0;
			/**< \~english Initial width of the window of Iris 2D application. */
			/**< \~chinese Iris 2D 窗口初始化宽度。 */
			unsigned int m_nHeight = 0;
			/**< \~english Initial height of the window of Iris 2D application. */
			/**< \~chinese Iris 2D 窗口初始化高度。 */
			GameFunc m_pfFunc = nullptr;
			/**< \~english Initial call-back function pointer of Iris 2D application, user's code of game should be written in this function */
			/**< \~chinese Iris 2D 回调函数指针，用户游戏代码应该被写在此函数之中。 */
			std::wstring m_wstrTitle = L"";
			/**< \~english Initial title of the window of Iris 2D application. */
			/**< \~chinese Iris 2D 窗口的初始化标题。 */
		};

	private:
		GameFunc m_pfGameFunc = nullptr;
		HWND m_hWindow = nullptr;
		int m_nShowCmd = 0;

	public:

		/**
		* \~english
		* Get the singleton instance pointer of IrisApplication.
		* @return The singleton instance pointer of IrisApplication.
		*/
		/**
		* \~chinese
		* 获取 IrisApplication 的单例指针。
		* @return IrisApplication 的单例指针。
		*/
		static IrisApplication* Instance();

	public:

		/**
		* \~english
		* Initialize resource and components of Iris 2D application required.
		*
		* This function has to be called before all the oparation related to Iris 2D APIs.
		*
		* This function is NO recommended because it is just be provided for being downward compatible with old Iris 2D API.
		*
		* Position of created window will defaultly be (0, 0) and Show Command will defautly be 0.
		* @param hInstance Instance handle of Windows application taken from WinMain as a parameter.
		* @param nWidth Initial width of the window of Iris 2D application.
		* @param nHeight Initial height of the window of Iris 2D application.
		* @param pfGameFunc Initial call-back function pointer of Iris 2D application, user's code of game should be written in this function.
		* @param wszTitle Initial title of the window of Iris 2D application.
		* @return If application successfully initialized true will be returned otherwise false. If initialization has been failed, Release() should be called to terminate current application.
		* @see Initialize(const IrisAppStartInfo* pInfo)
		* @see GameFunc
		*/
		/**
		* \~chinese
		* 初始化Iris 2D 所需要的资源以及组件。
		*
		* 该函数必须在所有和 Iris 2D 相关的操作执行之前被调用。
		*
		* 该函数不再被推荐，这是因为该函数只是用来向下兼容老的 Iris 2D API。
		*
		* 生成的游戏窗口的坐标将会默认为 (0 ,0) 并且 Show Command 将会默认为 0 。
		* @param hInstance Windows 应用的 Instance 句柄，来自于 WinMain 的参数。
		* @param nWidth Iris 2D 窗口初始化宽度。
		* @param nHeight Iris 2D 窗口初始化高度。
		* @param pfGameFunc Iris 2D 回调函数指针，用户游戏代码应该被写在此函数之中。
		* @param wszTitle Iris 2D 窗口的初始化标题。
		* @return 如果 Iris 2D 成功初始化，那么返回 true 否则返回 false 。如果初始化失败，那么必须调用 Release() 来结束当前程序。
		* @see Initialize(const IrisAppStartInfo* pInfo)
		* @see GameFunc
		*/
		bool Initialize(HINSTANCE hInstance, unsigned int nWidth, unsigned int nHeight, GameFunc pfGameFunc, const std::wstring& wszTitle);

		/**
		* \~english
		* Initialize resource and components of Iris 2D application required.
		*
		* This function has to be called before all the oparation related to Iris 2D APIs. (Recommanded)
		* @return If application successfully initialized true will be returned otherwise false. If initialization has been failed, Release() should be called to terminate current application.
		* @see Release()
		* @see Initialize(HINSTANCE hInstance, unsigned int nWidth, unsigned int nHeight, GameFunc pfGameFunc, const std::wstring& wszTitle)
		* @see IrisAppStartInfo
		*/
		/**
		* \~chinese
		* 初始化Iris 2D 所需要的资源以及组件。
		*
		* 该函数必须在所有和 Iris 2D 相关的操作执行之前被调用。（推荐）
		* @return 如果 Iris 2D 成功初始化，那么返回 true 否则返回 false 。如果初始化失败，那么必须调用 Release() 来结束当前程序。
		* @see Release()
		* @see Initialize(HINSTANCE hInstance, unsigned int nWidth, unsigned int nHeight, GameFunc pfGameFunc, const std::wstring& wszTitle)
		* @see IrisAppStartInfo
		*/
		bool Initialize(const IrisAppStartInfo* pInfo);

		/**
		* \~english
		* To start Iris 2D game logic, whose code has been written in call-back function in Initialize().
		* @see Initialize(HINSTANCE hInstance, unsigned int nWidth, unsigned int nHeight, GameFunc pfGameFunc, const std::wstring& wszTitle)
		* @see Initialize(const IrisAppStartInfo* pInfo)
		*/
		/**
		* \~chinese
		* 启动 Iris 2D 游戏逻辑，游戏逻辑代码是写在 Initialize() 的回调函数中的。
		* @see Initialize(HINSTANCE hInstance, unsigned int nWidth, unsigned int nHeight, GameFunc pfGameFunc, const std::wstring& wszTitle)
		* @see Initialize(const IrisAppStartInfo* pInfo)
		*/
		bool Run();

		/**
		* \~english
		* Release all the resource maintained by Iris 2D such as Sprites/Viewports/Bitmaps and other DirectX-related resource.
		*/
		/**
		* \~chinese
		* 释放所有由 Iris 2D 维护的资源（如 Sprite/Viewport/Bitmap ），以及其他和 DirectX 相关的资源。
		*/
		void Release();

		/**
		* \~english
		* Check if current application state is Uninitialized.
		* @return If Initialize() has not been called or initialization of Iris 2D application has been failed, false will been returned otherwise true.
		*/
		/**
		* \~chinese
		* 检查当前应用状态是否为未初始化。
		* @return 如果 Initialize() 没有被调用或者 Iris 2D 初始化失败，那么将会返回 false ，否则返回 true 。
		*/
		bool IsUninitialized() const;

		/**
		* \~english
		* Check if current application state is Initialized.
		* @return If initialization of Iris 2D application has been successful and function of Run() has not been called true will be returned otherwise false.
		* @see Initialize(HINSTANCE hInstance, unsigned int nWidth, unsigned int nHeight, GameFunc pfGameFunc, const std::wstring& wszTitle)
		* @see Initialize(const IrisAppStartInfo* pInfo)
		*/
		/**
		* \~chinese
		* 检查当前应用状态是否为已初始化。
		* @return 如果 Iris 2D 初始化成功并且 Run() 没有被调用，那么返回 true 否则返回 false 。
		* @see Initialize(HINSTANCE hInstance, unsigned int nWidth, unsigned int nHeight, GameFunc pfGameFunc, const std::wstring& wszTitle)
		* @see Initialize(const IrisAppStartInfo* pInfo)
		*/
		bool IsInitiatlize() const;

		/**
		* \~english
		* Check if current application state is Running.
		* @return If function Run() has been called true will be returned otherwise false.
		*/
		/**
		* \~chinese
		* 检查当前应用状态是否为正在运行。
		* @return 如果 Run() 被调用，那么将会返回 true 否则返回 false。
		*/
		bool IsRunning() const;

		/**
		* \~english
		* Check if current application state is Quited.
		*
		* Quite will happend when the window of Iris 2D application has been closed or the state of IrisApplication singleton instance has been manually set to Quite.
		* @return If window of Iris 2D application has been closed true will be returned otherwise false.
		* @see Quite()
		*/
		/**
		* \~chinese
		* 检查当前应用状态是否为已退出。
		*
		* 当 Iris 2D 的窗口被关闭或者 IrisApplication 单例的状态被手动改变成 Quite ，那么将会发生退出。
		* @return 如果 Iris 2D 程序的窗口被关闭，那么返回 true 否则返回 false 。
		* @see Quite()
		*/
		bool IsQuited() const;

		/**
		* \~english
		* Set current state of IrisApplication sington instance Quite manually.
		* @see IsQuited()
		*/
		/**
		* \~chinese
		* 手动设置当前 IrisApplication 的状态为 Quite 。
		* @see IsQuited()
		*/
		void Quite();

		/**
		* \~english
		* Get delta time between two frame in Iris 2D.
		*
		* This can be helpful for user to ensure speed of the game.
		* @return Time delta (in milliseconds).
		*/
		/**
		* \~chinese
		* 获取 Iris 2D 两帧之间的时间间隔。
		*
		* 该方法有助于用户确定游戏速度。
		* @return 以毫秒为单位的时间间隔。
		*/
		float GetTimeDelta();

	private:
		static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	private:
		bool InitializeWindow(const IrisAppStartInfo* pInfo);
	};

}
#endif