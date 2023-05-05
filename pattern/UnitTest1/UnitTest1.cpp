#include "pch.h"
#include "CppUnitTest.h"
#include "..\pattern\pattern.cpp"
#include <stdlib.h>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(TestStructureNumber)
	{

	public:
		
		TEST_METHOD(TestConstructorNumber)
		{
			srand(time(NULL));
			Number* number = new Number(static_cast <double> (rand()));
			double number1 = number->value();
			Assert::IsTrue(number->value() == number1);
		}
		TEST_METHOD(TestEvulateNumber)
		{
			srand(time(NULL));
			Number* number = new Number(static_cast <double> (rand()));
			double number1 = number->value();
			Assert::IsTrue(number->evaluate() == number1);
		}
	};

	TEST_CLASS(TestBinaryOperation)
	{

	public:

		TEST_METHOD(TestConstuctorBinaryOperation)
		{
			Number* n32 = new Number(32.0);
			Number* n16 = new Number(16.0);
			BinaryOperation* minus = new BinaryOperation(n32, BinaryOperation::MINUS, n16);
			Assert::IsTrue(minus->left() == n32 && minus->operation() == BinaryOperation::MINUS && minus->right() == n16);
		}

		TEST_METHOD(TestBinaryOperationPlus) {
			srand(time(NULL));
			Number* left_n = new Number(static_cast <double> (rand()));
			Number* right_n= new Number(static_cast <double> (rand()));
			double number_left = left_n->value();
			double number_right = right_n->value();
			BinaryOperation* plus = new BinaryOperation(left_n, BinaryOperation::PLUS, right_n);
			Assert::IsTrue(plus->evaluate() == number_left+number_right);
		}
		TEST_METHOD(TestBinaryOperationMinus) {
			srand(time(NULL));
			Number* left_n = new Number(static_cast <double> (rand()));
			Number* right_n = new Number(static_cast <double> (rand()));
			double number_left = left_n->value();
			double number_right = right_n->value();
			BinaryOperation* plus = new BinaryOperation(left_n, BinaryOperation::MINUS, right_n);
			Assert::IsTrue(plus->evaluate() == number_left - number_right);
		}
		TEST_METHOD(TestBinaryOperationDivision) {
			srand(time(NULL));
			Number* left_n = new Number(static_cast <double> (rand()));
			Number* right_n = new Number(static_cast <double> (rand()));
			double number_left = left_n->value();
			double number_right = right_n->value();
			BinaryOperation* plus = new BinaryOperation(left_n, BinaryOperation::DIV, right_n);
			Assert::IsTrue(plus->evaluate() == number_left/ number_right);
		}
		TEST_METHOD(TestBinaryOperationMultiplication) {
			srand(time(NULL));
			Number* left_n = new Number(static_cast <double> (rand()));
			Number* right_n = new Number(static_cast <double> (rand()));
			double number_left = left_n->value();
			double number_right = right_n->value();
			BinaryOperation* plus = new BinaryOperation(left_n, BinaryOperation::MUL, right_n);
			Assert::IsTrue(plus->evaluate() == number_left * number_right);
		}
		TEST_METHOD(TestBinaryOperationDivisionByZero) {
			srand(time(NULL));
			Number* number = new Number(static_cast <double> (rand()));
			Number* n0 = new Number(0.0);
			BinaryOperation* div_by_zero = new BinaryOperation(number, BinaryOperation::DIV, n0);
			Assert::ExpectException<std::invalid_argument>([div_by_zero]() {div_by_zero->evaluate(); });

		}

	};
	TEST_CLASS(TestFunctionCallStructure)
	{

	public:
		TEST_METHOD(TestConstructorFunctionCallSqrt) {
			srand(time(NULL));
			Number* number = new Number(static_cast <double> (rand()));
			FunctionCall* callSqrt = new FunctionCall("sqrt", number);
			Assert::IsTrue(callSqrt->arg() == number && callSqrt->name() == "sqrt");

		}
		TEST_METHOD(TestConstructorFunctionCallAbs) {
			srand(time(NULL));
			Number* number = new Number(static_cast <double> (rand()));
			FunctionCall* callSqrt = new FunctionCall("abs", number);
			Assert::IsTrue(callSqrt->arg() == number && callSqrt->name() == "abs");

		}
		TEST_METHOD(TestEvaluteFuncCallSQRT) {
			srand(time(NULL));
			Number* number = new Number(static_cast <double> (rand()));
			double number1 = number->value();
			FunctionCall* callSqrt = new FunctionCall("sqrt", number);
			Assert::IsTrue(callSqrt->evaluate() == sqrt(number1));
		}
		TEST_METHOD(TestEvaluteFuncCallAbs) {
			srand(time(NULL));
			Number* number = new Number(static_cast <double> (-rand()));
			double number1 = number->value();
			FunctionCall* callSqrt = new FunctionCall("abs", number);
			Assert::IsTrue(callSqrt->evaluate() == abs(number1));
		}
		TEST_METHOD(TestEvaluteNegativeSQRTFunctionalCall) {
			srand(time(NULL));
			Number* number = new Number(static_cast <double> (-rand()));
			FunctionCall* callSqrt = new FunctionCall("sqrt", number);
			Assert::ExpectException<std::invalid_argument>([callSqrt]() {callSqrt->evaluate(); });

		}

	};
	TEST_CLASS(TestVariableStructure)
	{

	public:

		TEST_METHOD(TestConstructorVariable) {
			Variable* variable = new Variable("variable");
			Assert::IsTrue(variable->name() == "vaiable");
		}

		TEST_METHOD(TestEvaluateVariable) {
			Variable* variable = new Variable("variable");
			Assert::IsTrue(variable->evaluate() == 0.0);
		}
		TEST_METHOD(TestConstructorFunctionCallAbs) {
			srand(time(NULL));
			Number* number = new Number(static_cast <double> (rand()));
			FunctionCall* callSqrt = new FunctionCall("abs", number);
			Assert::IsTrue(callSqrt->arg() == number && callSqrt->name() == "abs");

		}

	};
}
