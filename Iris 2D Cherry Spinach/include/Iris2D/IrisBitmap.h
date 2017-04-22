#ifndef _H_IRISBITMAP_
#define _H_IRISBITMAP_

#include "../IrisCommon.h"

namespace Iris2D
{
	class IrisTexture;
	class IrisRect;

	/**
	* \~english
	* Bitmap class of Iris 2D
	*
	* A bitmap is a sequence of pixels in memory which can be created from image files in hard disk or created manually in memory directly.
	*
	* Every image in Iris 2D application is abstractly a bitmap. User can not only create bitmap but also can do some oparation on it such as draw text and so on.
	*/
	/**
	* \~chinese
	* Iris 2D Bitmap ��
	*
	* һ�� Bitmap �����ڴ���һϵ�е����ص㣬��Щ���ص���ԴӴ����е�ͼ���ļ��д���Ҳ����ֱ�����ڴ����ֶ�������
	*
	* Iris 2D �е��κ�ͼ�γ������˵����һ�� Bitmap ���û��������Դ��� Bitmap �������Զ� Bitmap ����һЩ��������������ֵȡ�
	*/
	class IrisBitmap
	{
	private:
		IrisTexture* m_pTexture = nullptr;

	public:

		/**
		* \~english
		* Create a bitmap from image file in hard disk.
		* @param wstrFileName The path of image file which can both be relative path and absolute path.
		* @return If bitmap has been created successfully pointer of IrisBitmap will be returned otherwise nullptr.
		*/
		/**
		* \~chinese
		* �Ӵ����е�ͼ���ļ��д���һ�� Bitmap ��
		* @param wstrFileName ͼ���ļ���·�����ȿ��������·��Ҳ�����Ǿ���·����
		* @return ����ɹ����� Bitmap ����ô���᷵�ظ� IrisBitmap ��ָ�룬���򷵻� nullptr��
		*/
		static IrisBitmap* Create(const std::wstring& wstrFileName, IR_PARAM_RESULT);

		/**
		* \~english
		* Create a blank bitmap.
		* @param nWidth The pixel width of created bitmap.
		* @param nHeight The pixel height of created bitmap.
		* @return If bitmap has been created successfully pointer of IrisBitmap will be returned otherwise nullptr.
		*/
		/**
		* \~chinese
		* ����һ���հ׵�Bitmap��
		* @param nWidth ������ Bitmap �����ؿ�ȡ�
		* @param nHeight ������ Bitmap �����ظ߶ȡ�
		* @return ����ɹ����� Bitmap ����ô���᷵�ظ� IrisBitmap ��ָ�룬���򷵻� nullptr��
		*/
		static IrisBitmap* Create(unsigned int nWidth, unsigned int nHeight, IR_PARAM_RESULT);

		/**
		* \~english
		* Release a bitmap.
		* @param pBitmap A pointer to bitmap object to be released. After this function called, pointer taken will be set to nullptr.
		*/
		/**
		* \~chinese
		* �ͷ�һ�� Bitmap ��
		* @param pBitmap ָ��Ҫ���ͷŵ� Bitmap ��ָ�롣���ú���������֮�󣬴����ָ�뽫�ᱻ���ó� nullptr ��
		*/
		static void Release(IrisBitmap*& pBitmap);

		/**
		* \~english
		* Get the pixel width of current bitmap's image.
		* @return Pixel width of current bitmap's image.
		*/
		/**
		* \~chinese
		* ��ȡ��ǰ Bitmap �����ؿ�ȡ�
		* @return ��ǰ Bitmap �����ؿ�ȡ�
		*/
		unsigned int GetWidth();

		/**
		* \~english
		* Get the pixel height of current bitmap's image.
		* @return Pixel height of current bitmap's image.
		*/
		/**
		* \~chinese
		* ��ȡ��ǰ Bitmap �����ظ߶ȡ�
		* @return ��ǰ Bitmap �����ظ߶ȡ�
		*/
		unsigned int GetHeight();

		/**
		* \~english
		* Copy part of source bitmap to destination bitmap.
		* 
		* @param nDestX X position in destination bitmap, which is the top left x position of copied area in source bitmap.
		* @param nDestY Y position in destination bitmap, which is the top left y position of copied area in source bitmap.
		* @param pSrcBitmap The pointer to source bitmap.
		* @param pSrcRect The copied area in source bitmap.
		* @param fOpacity The opacity of pixels in copied area whose value is in [0.0, 255.0f].
		* @return If copy operation has been successful true will be returned otherwise false.
		*/
		/**
		* \~chinese
		* ����Դ Btimap ��һ���ֵ�Ŀ�� Bitmap ֮�С�
		*
		* @param nDestX �� X Ŀ�� Bitmap �У�Դ Bitmap ��������������Ͻǵ� X ���ꡣ
		* @param nDestY �� Y Ŀ�� Bitmap �У�Դ Bitmap ��������������Ͻǵ� Y ���ꡣ
		* @param pSrcBitmap Դ Bitmap ��ָ�롣
		* @param pSrcRect Դ Bitmap �б�����������
		* @param fOpacity ���������ص�͸���ȣ���ֵ���� [0.0f, 255.0f]��
		* @return ������������ɹ������� true ���򷵻� false��
		*/
		bool Blt(unsigned int nDestX, unsigned int nDestY, IrisBitmap* pSrcBitmap, IrisRect* pSrcRect, float fOpacity, IR_PARAM_RESULT);

		/**
		* \~english
		* Copy part of source bitmap to destination bitmap allowing to scretch either destination area or source area.
		*
		* @param pDestRect The distination area in current bitmap.
		* @param pSrcBitmap The pointer to source bitmap.
		* @param pSrcRect The copied area in source bitmap.
		* @param fOpacity The opacity of pixels in copied area whose value is in [0.0, 255.0f].
		* @return If copy operation has been successful true will be returned otherwise false.
		*/
		/**
		* \~chinese
		* ����Դ Btimap ��һ���ֵ�Ŀ�� Bitmap ֮�У���������Ŀ���������Դ����
		*
		* @param pDestRect ��ǰ Bitmap ��Ŀ������
		* @param pSrcBitmap Դ Bitmap ��ָ�롣
		* @param pSrcRect Դ Bitmap �б�����������
		* @param fOpacity ���������ص�͸���ȣ���ֵ���� [0.0f, 255.0f]��
		* @return ������������ɹ������� true ���򷵻� false��
		*/
		bool StretchBlt(IrisRect* pDestRect, IrisBitmap* pSrcBitmap, IrisRect* pSrcRect, float fOpacity, IR_PARAM_RESULT);

		IrisTexture* GetTexture();		
	private:
		IrisBitmap() = default;
		~IrisBitmap();
	};

}
 // !_H_IRISBITMAP_
#endif