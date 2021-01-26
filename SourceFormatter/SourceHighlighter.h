#pragma once
#include <QProcess>
#include <QCoreApplication>
#include <QDebug>
#include <QFile>



class SourceHighlighter
{
public:

	explicit SourceHighlighter();

	const QString highlight(QString const& codeSnippet, QString const& lang) const;

private:
	mutable QProcess consoleApp;
	const QString tempFilePath = QCoreApplication::applicationDirPath() + "/source.txt";

	const QStringList defaultArguments =
	{ "-i" , tempFilePath , "--stdout" , "--inline-css" , "--enclose-pre" , 
		"-f" , "-I" , "-u" , "utf-8" , "-l" , "-s" , "bclear" , "-j", 
		"5" , "-k" , "Courier New" , "-K" , "10" , "-O" , "html" };

};

