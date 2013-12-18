///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			Vector4UTests.cpp
// Author:			Ian Rich
// Date Created:	2013
// Brief:			Test vector4 functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Vector4UTests.h"

// tests vector equality, returns bool -------------------------------------------------------------
void V4EqualTest::SetData(Vector4 a_oV1, Vector4 a_oV2, bool a_bExpResult)
{
	m_oVector1 = a_oV1;
	m_oVector2 = a_oV2;
	m_bResult = a_bExpResult;
}

bool V4EqualTest::DoTest()
{
	bool Result = (m_oVector1 == m_oVector2);
	cout<< "\n---------------V4EqualTest---------------\n";
	return (Result == m_bResult);
}

// returns magnitude of vector -------------------------------------------------------------
void V4MagnitudeTest::SetData(Vector4 a_oVector, float a_fExpResult)
{
	m_oVector = a_oVector;
	m_fResult = a_fExpResult;
}

bool V4MagnitudeTest::DoTest()
{
	float Result = m_oVector.GetMagnitude();
	cout<< "\n---------------V4MagnitudeTest---------------\n";
	return AreEqual(Result, m_fResult);
}

// normalize a vector -------------------------------------------------------------
void V4NormalizeTest::SetData(Vector4 a_oVector, Vector4 a_oExpResult)
{
	m_oVector = a_oVector;
	m_oResult = a_oExpResult;
}

bool V4NormalizeTest::DoTest()
{
	m_oVector.Normalize();
	cout<< "\n---------------V4NormalizeTest---------------\n";
	return (m_oVector == m_oResult);
}

// returns a normalized version of vector -------------------------------------------------------------
void V4RetNormalizedTest::SetData(Vector4 a_oVector, Vector4 a_oExpResult)
{
	m_oVector = a_oVector;
	m_oResult = a_oExpResult;
}

bool V4RetNormalizedTest::DoTest()
{
	Vector4 TempVec = m_oVector.ReturnNormalized();
	cout<< "\n---------------V4RetNormalizedTest---------------\n";
	return (TempVec == m_oResult);
}

// converts hex code to rgb floats and returns vector4 with alpha as well -------------------------------------------------------------
void V4HexToRGBTest::SetData(string a_sHex, float a_fAlpha, Vector4 a_oExpResult)
{
	m_sHex = a_sHex;
	m_fAlpha = a_fAlpha;
	m_oResult = a_oExpResult;
}

bool V4HexToRGBTest::DoTest()
{
	Vector4 TempVec = HexToRGB(m_sHex, m_fAlpha);
	cout<< "\n---------------V4HexToRGBTest---------------\n";
	return (TempVec == m_oResult);
}
