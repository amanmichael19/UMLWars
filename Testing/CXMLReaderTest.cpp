#include "pch.h"
#include "CppUnitTest.h"
#include "XMLReader.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CXMLReaderTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestCXMLLoad)
		{
			CXMLReader reader;
			reader.Load();

			TestNames(reader);
			TestAttributes(reader);
			TestOperations(reader);
			TestInherits(reader);

		}

		void TestNames(CXMLReader reader)
		{
			// Get good and bad names, with reasons
			auto goodNames = reader.GetNames();
			auto badNames = reader.GetBadNames();

			// Test to make sure all names were added to appropriate vectors
			Assert::IsTrue(goodNames.size() == 4);
			Assert::IsTrue(badNames.size() == 4);

			// Check for specific good and bad names
			// Good was arbitrary
			// Bad was chosen as it is a special case
			Assert::IsTrue(goodNames.at(2) == L"Picture");
			Assert::IsTrue(badNames.at(1).at(0) == L"");
			Assert::IsTrue(badNames.at(1).at(1) == L"Missing class name");
		}

		void TestAttributes(CXMLReader reader)
		{
			// Get good and bad attributes, with reasons
			auto goodAttributes = reader.GetAttributes();
			auto badAttributes = reader.GetBadAttributes();

			// Test to make sure all attributes were added to appropriate vectors
			Assert::IsTrue(goodAttributes.size() == 6);
			Assert::IsTrue(badAttributes.size() == 10);

			// Check for specific good and bad attributes
			// Good was arbitrary
			// Bad was chosen because of use of <> characters
			Assert::IsTrue(goodAttributes.at(2) == L"description: string");
			Assert::IsTrue(badAttributes.at(5).at(0) == L"v: vector<double>");
			Assert::IsTrue(badAttributes.at(5).at(1) == L"Language artifact");
		}

		void TestOperations(CXMLReader reader)
		{
			// Get good and bad operations, with reasons
			auto goodOperations = reader.GetOperations();
			auto badOperations = reader.GetBadOperations();

			// Test to make sure all operations were added to appropriate vectors
			Assert::IsTrue(goodOperations.size() == 7);
			Assert::IsTrue(badOperations.size() == 3);

			// Check for specific good and bad operations
			// Good was arbitrary
			// Bad was chosen because of use of <> characters
			Assert::IsTrue(goodOperations.at(2) == L"Save(image: Image, filename: string)");
			Assert::IsTrue(badOperations.at(0).at(0) == L"GetActors(): vector<Actor>");
			Assert::IsTrue(badOperations.at(0).at(1) == L"Language artifact");
		}

		void TestInherits(CXMLReader reader)
		{
			// Get good and bad inherits, with reasons
			auto goodInherits = reader.GetInherits();
			auto badInherits = reader.GetBadInherits();

			// Test to make sure all inherits were added to appropriate vectors
			Assert::IsTrue(goodInherits.size() == 3);
			Assert::IsTrue(badInherits.size() == 4);

			// Check for specific good and bad inherits
			// Good was arbitrary
			// Bad was chosen because of use of "up" direction value
			Assert::IsTrue(goodInherits.at(2).at(0) == L"Fish");
			Assert::IsTrue(goodInherits.at(2).at(1) == L"StinkyFish");
			Assert::IsTrue(goodInherits.at(2).at(2) == L"down");
			Assert::IsTrue(badInherits.at(3).at(0) == L"Insect");
			Assert::IsTrue(badInherits.at(3).at(1) == L"Fly");
			Assert::IsTrue(badInherits.at(3).at(2) == L"down");
			Assert::IsTrue(badInherits.at(3).at(3) == L"Upside down");
		}
	};
}