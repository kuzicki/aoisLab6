#include "pch.h"
#include "CppUnitTest.h"
#include "HashTable.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab6test
{
	TEST_CLASS(lab6test)
	{
	public:
		
		TEST_METHOD(Insert)
		{
			HashTable<std::string, std::string, 15> tb;
			tb.Add("Nick", "Kuzicki");
			tb.Add("Kate", "Young");
			tb.Add("Nicole", "Adams");
			tb.Add("Justin", "Brenner");
			tb.Add("Y", "G");
			std::string expected = "Kuzicki";
			Assert::AreEqual(expected, tb["Nick"].GetData());
		}

		TEST_METHOD(IncorrectArgument)
		{
			HashTable<std::string, std::string, 15> tb;
			tb.Add("Nick", "Kuzicki");
			tb.Add("Kate", "Young");
			tb.Add("Nicole", "Adams");
			tb.Add("Justin", "Brenner");
			tb.Add("Y", "G");
			auto func = [&]{tb["Nick1"]; };
			Assert::ExpectException<std::runtime_error>(func);
		}

		TEST_METHOD(RemoveElement)
		{
			HashTable<std::string, std::string, 15> tb;
			tb.Add("Nick", "Kuzicki");
			tb.Add("Kate", "Young");
			tb.Add("Nicole", "Adams");
			tb.Add("Justin", "Brenner");
			tb.Add("Y", "G");
			tb.Remove("Nick");
			auto func = [&] {tb["Nick"]; };
			Assert::ExpectException<std::runtime_error>(func);
		}

		TEST_METHOD(RemoveElementWithBrackets)
		{
			HashTable<std::string, std::string, 15> tb;
			tb.Add("Nick", "Kuzicki");
			tb.Add("Kate", "Young");
			tb.Add("Nicole", "Adams");
			tb.Add("Justin", "Brenner");
			tb.Add("Y", "G");
			tb["Nick"].Remove();
			auto func = [&] {tb["Nick"]; };
			Assert::ExpectException<std::runtime_error>(func);
		}

		TEST_METHOD(UpdateElement)
		{
			HashTable<std::string, std::string, 15> tb;
			tb.Add("Nick", "Kuzicki");
			tb.Add("Kate", "Young");
			tb.Add("Nicole", "Adams");
			tb.Add("Justin", "Brenner");
			tb.Add("Y", "G");
			tb.Update("Nick", "Other");
			std::string expected = "Other";
			Assert::AreEqual(expected, tb["Nick"].GetData());
		}

		TEST_METHOD(RemoveHead)
		{
			HashTable<std::string, std::string, 15> tb;
			tb.Add("Nick", "Kuzicki");
			tb.Add("Kate", "Young");
			tb.Add("Nicole", "Adams");
			tb.Add("Justin", "Brenner");
			tb.Add("Y", "G");
			tb["Justin"].Remove();
			auto func = [&] {tb["Justin"]; };
			Assert::ExpectException<std::runtime_error>(func);
			std::string expected = "Kuzicki";
			Assert::AreEqual(expected, tb["Nick"].GetData());
		}
	};
}
