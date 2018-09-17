
#include "Scene.h"

class CTextBox;
class CSetting :
	public CScene
{
private:
	CTextBox* pTextBox;

	float DeltaTime=0;
	int Frame=0;

public:
	CSetting();
	virtual ~CSetting();

	virtual void Update(float fDeltaTime) override;


	virtual void Render() override;

};
