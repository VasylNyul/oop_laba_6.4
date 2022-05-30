#include "pch.h"
#include "CppUnitTest.h"
#include "../oop_laba_6.4/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64oop
{
	TEST_CLASS(UnitTest64oop)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			arr<int> V(5);
			V[3] = 4;
			Assert::AreEqual(V[3], 4);
		}
	};
}
