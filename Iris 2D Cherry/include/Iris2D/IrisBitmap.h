#ifndef _H_IRISBITMAP_
#define _H_IRISBITMAP_

#include "../IrisCommon.h"

namespace Iris2D
{
	class IrisTexture;

#if ENGLISH
	/**
	* Bitmap class of Iris 2D
	*
	* A bitmap is a sequence of pixels in memory which can be created from image files in hard disk or created manually in memory directly.
	*
	* Every image in Iris 2D application is abstractly a bitmap. User can not only create bitmap but also can do some oparation on it such as draw text and so on.
	*/
#elif CHINESE
	/**
	* Iris 2D Bitmap ��
	*
	* һ�� Bitmap �����ڴ���һϵ�е����ص㣬��Щ���ص���ԴӴ����е�ͼ���ļ��д���Ҳ����ֱ�����ڴ����ֶ�������
	*
	* Iris 2D �е��κ�ͼ�γ������˵����һ�� Bitmap ���û��������Դ��� Bitmap �������Զ� Bitmap ����һЩ��������������ֵȡ�
	*/
#endif
	class IrisBitmap
	{
	private:
		IrisTexture* m_pTexture = nullptr;

	public:
#if ENGLISH
		/**
		* Create a bitmap from image file in hard disk.
		* @param wstrFileName The path of image file which can both be relative path and absolute path.
		* @return If bitmap has been created successfully pointer of IrisBitmap will be returned otherwise nullptr.
		*/
#elif CHINESE
		/**
		* �Ӵ����е�ͼ���ļ��д���һ�� Bitmap ��
		* @param wstrFileName ͼ���ļ���·�����ȿ��������·��Ҳ�����Ǿ���·����
		* @return ����ɹ����� Bitmap ����ô���᷵�ظ� IrisBitmap ��ָ�룬���򷵻� nullptr��
		*/
#endif
		static IrisBitmap* Create(const std::wstring& wstrFileName, IR_PARAM_RESULT);

#if ENGLISH
		/**
		* Create a blank bitmap.
		* @param nWidth The pixel width of created bitmap.
		* @param nHeight The pixel height of created bitmap.
		* @return If bitmap has been created successfully pointer of IrisBitmap will be returned otherwise nullptr.
		*/
#elif CHINESE
		/**
		* ����һ���հ׵�Bitmap��
		* @param nWidth ������ Bitmap �����ؿ�ȡ�
		* @param nHeight ������ Bitmap �����ظ߶ȡ�
		* @return ����ɹ����� Bitmap ����ô���᷵�ظ� IrisBitmap ��ָ�룬���򷵻� nullptr��
		*/
#endif

		static IrisBitmap* Create(unsigned int nWidth, unsigned int nHeight, IR_PARAM_RESULT);

#if ENGLISH
		/**
		 * Release a bitmap.
		 * @param pBitmap A pointer to bitmap object to be released. After this function called, pointer taken will be set to nullptr.
		 */
#elif CHINESE
		/**
		* �ͷ�һ�� Bitmap ��
		* @param pBitmap ָ��Ҫ���ͷŵ� Bitmap ��ָ�롣���ú���������֮�󣬴����ָ�뽫�ᱻ���ó� nullptr ��
		*/
#endif
		static void Release(IrisBitmap*& pBitmap);

#if ENGLISH
		/**
		* Get the pixel width of current bitmap's image.
		* @return Pixel width of current bitmap's image.
		*/
#elif CHINESE
		/**
		* ��ȡ��ǰ Bitmap �����ؿ�ȡ�
		* @return ��ǰ Bitmap �����ؿ�ȡ�
		*/
#endif
		unsigned int GetWidth();

#if ENGLISH
		/**
		* Get the pixel height of current bitmap's image.
		* @return Pixel height of current bitmap's image.
		*/
#elif CHINESE
		/**
		* ��ȡ��ǰ Bitmap �����ظ߶ȡ�
		* @return ��ǰ Bitmap �����ظ߶ȡ�
		*/
#endif
		unsigned int GetHeight();

		IrisTexture* GetTexture();		
	private:
		IrisBitmap() = default;
		~IrisBitmap();
	};

}
#endif // !_H_IRISBITMAP_
