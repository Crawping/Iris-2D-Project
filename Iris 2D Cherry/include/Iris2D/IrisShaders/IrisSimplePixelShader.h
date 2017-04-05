#ifndef _H_IRISSIMPLEPIXELSHADER_
#include "IrisPixelShaderBase.h"

namespace Iris2D
{
	class IrisSimplePixelShader : public IrisPixelShaderBase
	{
	private:
		ID3D11PixelShader* m_pPixelShader = nullptr;

	public:
		static IrisSimplePixelShader* Instance();

	public:
		~IrisSimplePixelShader();
		virtual ID3D11PixelShader * GetPixelShader() override;
		virtual bool Release() override;

	protected:
		// ͨ�� IrisShaderBase �̳�
		virtual std::wstring ShaderFileDefine() override;
		virtual std::string ShaderEntryFuncDefine() override;
		virtual std::string ShaderVersionDefine() override;
		virtual bool ShaderSubResourceDefine() override;
		virtual bool CreateShader(ID3DBlob * pBlob) override;
		virtual bool SetToContext() override;

	private:
		IrisSimplePixelShader() = default;

		// ͨ�� IrisPixelShaderBase �̳�
	};
}

#endif // !_H_IRISSIMPLEPIXELSHADER_
