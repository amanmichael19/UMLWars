#include "pch.h"
#include "CppUnitTest.h"
#include <GameObject.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CGameObjectTest)
	{
	public:
		
		TEST_METHOD(TestNothing)
		{
			// This is an empty test just to ensure the system is working
		}

		TEST_METHOD(TestPositioning)
		{
			//Test positioning of a GameObject
			CGameObject obj;

			Assert::IsTrue(obj.GetX() == 0 && obj.GetY() == 0,
				L"Testing default positioning");

			obj.SetLocation(1, 2);

			Assert::IsTrue(obj.GetX() == 1 && obj.GetY() == 2,
				L"Testing changed positioning");
		}

	};
}