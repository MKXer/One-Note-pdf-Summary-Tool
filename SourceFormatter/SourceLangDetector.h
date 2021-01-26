#pragma once

#include <QString>



class SourceLangDetector
{

public:
	static bool isJava	(QString const& source);
	static bool isCpp	(QString const& source);
	static bool isCSharp(QString const& source);
	static bool isXml	(QString const& source);

private:
	SourceLangDetector() = default;
};

