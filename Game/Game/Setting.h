
#include "Scene.h"

class CTextBox;
class CSetting :
	public CScene
{
private:
	CTextBox* pTextBox;

public:
	CSetting();
	virtual ~CSetting();

	virtual void Update(float fDeltaTime) override;


	virtual void Render() override;

};
