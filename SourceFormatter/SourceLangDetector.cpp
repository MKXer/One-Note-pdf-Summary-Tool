#include "SourceLangDetector.h"


bool SourceLangDetector::isJava(QString const& source)
{
	return source.contains("super(")
		|| source.contains(" extends ")
		|| source.contains("java")
		|| source.contains("import ")
		|| source.contains("interface ");
}

bool SourceLangDetector::isCpp(QString const& source)
{
	return source.contains(" const& ")
		|| source.contains(" & ")
		|| source.contains("struct ")
		|| source.contains("virtual ");
}

bool  SourceLangDetector::isCSharp(QString const& source)
{
	return source.contains("var ");
}

bool  SourceLangDetector::isXml(QString const& source)
{
	return source.contains("</");
}
