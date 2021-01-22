#pragma once

#include <QString>



class SourceLangDetector
{
public:
	static bool isJava(QString const& source) 
	{
		return source.contains("super(")
			|| source.contains(" extends ")
			|| source.contains("java")
			|| source.contains("import ")
			|| source.contains("interface ");
	}
	static bool isCpp(QString const& source) 
	{
		return source.contains(" const& ")
			|| source.contains(" & ")
			|| source.contains("struct ")
			|| source.contains("virtual ");
	}
	static bool isCSharp(QString const& source) 
	{
		return source.contains("var ");
	}
	static bool isXml(QString const& source) 
	{
		return source.contains("</");
	}




private:
	SourceLangDetector()
	{

	}
};

