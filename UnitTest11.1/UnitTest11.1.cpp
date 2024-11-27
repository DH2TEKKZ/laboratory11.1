#include "pch.h"
#include "CppUnitTest.h"
#include "C:\laboratory works\laboratory11.1\lab11.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest111
{
	TEST_CLASS(UnitTest111)
	{
	public:
		
        TEST_METHOD(TestFindThirdComa_Found)
        {

            ofstream testFile("test.txt");
            testFile << "one,two,three,four\n";
            testFile.close();

            ifstream t1("test.txt");

            ComaPosition result = findComa(t1);
 
            Assert::AreEqual(result.pos, 14);   

            t1.close();
        }

	};
}
